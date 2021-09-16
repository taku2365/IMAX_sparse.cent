
/* EMAX6 Compiler                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* conv-a2c.y   2012/6/15 */

%{

#include "yacc_lex_util.h"
#include "lex.yy.c"
void yyerror(char *s)
{
  if (++y_errornum == 1)
    fprintf(stderr, "\n");
#if 0
  fprintf(stderr, "line %d: \"%s\": %s.\n", y_lineno, yytext, s);
#endif
  /* lex -l により,yylinenoが使える */
  fprintf(stderr, "err%d: line %d: \"%s\": %s.\n", y_errornum, yylineno, yytext, s);
}

%}

%token  EOL
%token  ARMV8
%token  EMAX6ABEGIN  EMAX6ASTATEM  EMAX6AEND  EMAX6ADRAIN
%token  EMAX6TBEGIN  EMAX6TSTATEM  EMAX6TEND

/* CGRA */
%token  CGRA_ULL     CGRA_UINT     CGRA_SLL   CGRA_SRL
%token  CGRA_WHILE   CGRA_FOR      CGRA_CEX
%token	CGRA_EX4     CGRA_EXE      CGRA_MO4   CGRA_MOP
%token	CGRA_DECR    CGRA_INCR

/* TRANSACTION */
%token  TRAN_READ       TRAN_WRITE

/* COMMON */
%token  IMMEDIATE
%token  EXRNO
%token  ALRNO
%token  BDRNO
%token  CHIP
%token  INITNO
%token  LOOPNO
%token  VARIABLE
%token  ASIS

%start  program
%%
program : program line
        | line
        ;

line :  EOL {
		printf("reading line %d\n",y_lineno);
        }
        | ARMV8 {
          fprintf(ofile, "%s\n", yytext);
        }
        | EMAX6ABEGIN VARIABLE expr { /* reset conf[][] */
          printf("==EMAX6AB reading line=%d name=%s\n", y_lineno, id[$2].name);
          current_prefix  = $2;
          current_mapdist = id[$3].val;
          current_nchip   = 1; /* default */
          current_lmmwb   = 0;
          last_insn = 0;
	  bzero(&insn, sizeof(insn));
	  bzero(&dec,  sizeof(dec));
	  bzero(&bus,  sizeof(bus));
	  bzero(&conf, sizeof(conf));
	  bzero(&lmmi, sizeof(lmmi));
	  bzero(&lmmx, sizeof(lmmx));
	  bzero(&regv, sizeof(regv));
          fprintf(ofile, "volatile emax6_conf_%s();\n", id[current_prefix].name);
#if 0
          fprintf(ofile, "volatile struct { struct regv_breg breg[%d][%d] ;} *emax6_breg_%s  = emax6.reg_breg;\n",  EMAX_DEPTH, EMAX_WIDTH, id[current_prefix].name);
          fprintf(ofile, "volatile struct { struct regv_addr addr[%d][%d] ;} *emax6_addr_%s  = emax6.reg_addr;\n",  EMAX_DEPTH, EMAX_WIDTH, id[current_prefix].name);
          fprintf(ofile, "volatile struct { struct lddmr     lddmr[%d][%d];} *emax6_lddmr_%s = emax6.reg_lddmr;\n", EMAX_DEPTH, EMAX_WIDTH, id[current_prefix].name);
          fprintf(ofile, "volatile struct { struct lddmw     lddmw[%d][%d];} *emax6_lddmw_%s = emax6.reg_lddmw;\n", EMAX_DEPTH, EMAX_WIDTH, id[current_prefix].name);
#endif
        }
        | EMAX6ASTATEM EMAX6ABODY {
        }
        | EMAX6AEND {
	  emit_emax6a(0);
	  hash_clear();
        }
        | EMAX6ADRAIN {
	  emit_emax6a(1);
	  hash_clear();
        }
        | EMAX6TBEGIN VARIABLE { /* reset tconf[][] */
          printf("==EMAX6TB reading line=%d name=%s\n", y_lineno, id[$2].name);
          current_prefix = $2;
          trans_pc = 0;
	  bzero(&trans, sizeof(trans));
	  bzero(&tconf, sizeof(tconf));
	}
        | EMAX6TSTATEM EMAX6TBODY {
	}
        | EMAX6TEND {
	  emit_emax6t(0);
	  hash_clear();
	}
        ;

EMAX6ABODY : EMAX6AUNIT {
        }
        | EMAX6ABODY EMAX6AUNIT {
        }
        ;

EMAX6AUNIT : CGRA_WHILE '(' VARIABLE CGRA_DECR ')' '{' {
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 1; /* WHILE */
	  insn[last_insn].iheader.row  = 0; /* top */
	  insn[last_insn].iheader.col  = 0; /* top */
	  insn[last_insn].iexe.op1     = OP_WHILE;
	  insn[last_insn].iexe.updt    = 1;
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.src1h   = $3;
	  insn[last_insn].iexe.src1s   = -1; /* no suffix */
	  insn[last_insn].iexe.src1e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.src2v   = T_IMMEDIATE; /* variable */
	  insn[last_insn].iexe.src2h   = $4; /* -1 */
	  insn[last_insn].iexe.src2s   = -1; /* no suffix */
	  insn[last_insn].iexe.src2e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.exedv   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.exedh   = $3;
	  insn[last_insn].iexe.exeds   = -1; /* no suffix */
          last_insn++;
	}
        | CGRA_FOR '(' CHIP '=' expr ';' CHIP '<' expr ';' CHIP CGRA_INCR ')' '{' {
	  if (id[$5].val != 0) {
	    fprintf(stderr, "in %s: for(CHIP=0;;) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
          current_nchip = id[$9].val; /* should be <= EMAX_NCHIP */
	  if (current_nchip > EMAX_NCHIP) {
	    fprintf(stderr, "in %s: for(;CHIP<NCHIP;) NCHIP(%d) should be <= EMAX_NCHIP(%d)\n", id[current_prefix].name, current_nchip, EMAX_NCHIP);
            exit(1);
	  }
	  fprintf(ofile, "\t  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].mcid = %d; // NCHIP-1\n", current_nchip-1);
	}
        | CGRA_FOR '(' INITNO '=' expr ',' LOOPNO '=' ASIS ',' XVARIABLE '=' ASIS ';' LOOPNO CGRA_DECR ';' INITNO '=' expr ')' '{' {
	  int loop_no = id[$3].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no > 1) {
	    fprintf(stderr, "in %s: for() is limited to INIT0 or INIT1\n", id[current_prefix].name);
            exit(1);
	  }
	  if (loop_no != id[ $7].val || loop_no != id[$15].val || loop_no != id[$18].val || loop_no != id[$7].val) {
	    fprintf(stderr, "in %s: for() includes INIT#/LOOP# mismatch\n", id[current_prefix].name);
            exit(1);
	  }
	  if (id[$5].val != 1 || id[$20].val != 0) {
	    fprintf(stderr, "in %s: for(INIT#=1,...; LOOP#--; INIT#=0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  fprintf(ofile, "\t%s = %s;\n", id[ $7].name, id[ $9].name);
	  if (id[$11].cidx) {
	    int c, len, i; char *buf;
	    len = strlen(id[$13].name);
	    buf = malloc(len+1);
	    buf[len] = 0;
	    for (c=0; c<current_nchip; c++) {
	      strncpy(buf, id[$13].name, len);
	      for (i=0; i<len; i++) {
		if (!strncmp(id[$13].name+i, "CHIP", 4)) {
		  *(buf+i+0) = ' ';
		  *(buf+i+1) = ' ';
		  *(buf+i+2) = ' ';
		  *(buf+i+3) = '0'+c;
		  i += 4;
		}
	      }
	      fprintf(ofile, "\t%s[%d] = %s;\n", id[$11].name, c, buf);
	    }
	    free(buf);
	  }
	  else
	    fprintf(ofile, "\t%s = %s;\n", id[$11].name, id[$13].name);
	  insn[last_insn].iheader.type = 2; /* FOR */
	  insn[last_insn].iheader.row  = 0; /* top */
	  insn[last_insn].iheader.col  = loop_no;
	  insn[last_insn].iexe.op1     = OP_FOR;
	  insn[last_insn].iexe.updt    = 1;
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.src1h   = $15;
	  insn[last_insn].iexe.src1s   = -1; /* no suffix */
	  insn[last_insn].iexe.src1e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.src2v   = T_IMMEDIATE; /* variable */
	  insn[last_insn].iexe.src2h   = $16; /* -1 */
	  insn[last_insn].iexe.src2s   = -1; /* no suffix */
	  insn[last_insn].iexe.src2e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.exedv   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.exedh   = $15;
	  insn[last_insn].iexe.exeds   = -1; /* no suffix */
          last_insn++;
	}
        | CGRA_CEX '(' expr ',' cex_dst ',' cex_src ',' cex_src ',' cex_src ',' cex_src ',' expr ')' ';' {
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 3; /* CEX */
	  insn[last_insn].iheader.row  = -1;
	  insn[last_insn].iheader.col  = -1;
	  insn[last_insn].icex.op      = id[ $3].val;
	  insn[last_insn].icex.bit0v   = id[$13].type;
	  insn[last_insn].icex.bit0h   = $13;
	  insn[last_insn].icex.bit1v   = id[ $11].type;
	  insn[last_insn].icex.bit1h   = $11;
	  insn[last_insn].icex.bit2v   = id[ $9].type;
	  insn[last_insn].icex.bit2h   = $9;
	  insn[last_insn].icex.bit3v   = id[ $7].type;
	  insn[last_insn].icex.bit3h   = $7;
	  insn[last_insn].icex.table   = id[$15].val;
	  insn[last_insn].icex.cexdv   = id[$5].type;
	  insn[last_insn].icex.cexdh   = $5;
          last_insn++;
        }
        | CGRA_EX4 '(' expr ',' ex4_dstd ',' ex4_src ',' expr ',' ex4_src ',' expr ',' ex4_src ',' expr ',' expr ',' ex4_src ',' expr ',' ex4_src ')' ';' {
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &BR[r][c], NULL); followed by next ex */
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &AR[r],    NULL); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val):id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(        -1):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$19].val;
	  insn[last_insn].iexe.op3     = id[$23].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1s   = 4; /* all suffix */
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $11].type;
	  insn[last_insn].iexe.src2h   = $11;
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[$13].val;
	  insn[last_insn].iexe.src3v   = id[$15].type;
	  insn[last_insn].iexe.src3h   = $15;
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[$17].val;
	  insn[last_insn].iexe.src4v   = id[$21].type;
	  insn[last_insn].iexe.src4h   = $21;
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[$25].type;
	  insn[last_insn].iexe.src5h   = $25;
	  insn[last_insn].iexe.src5s   = 4; /* all suffix */
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
	  insn[last_insn].iexe.exeds   = 4; /* all suffix */
          last_insn++;
        }
        | CGRA_EX4 '(' expr ',' exe_dstd ',' exe_src1 ',' expr ',' ex4_src ',' expr ',' ex4_src ',' expr ',' expr ',' ex4_src ',' expr ',' exe_src5 ')' ';' {
	  /* ex4(OP_SFMA, &b00, b00, EXP_H3210, BR[r][1], EXP_H3210, BR[r][2], EXP_H3210, OP_NOP, 0LL, OP_NOP, 32LL) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$19].val;
	  insn[last_insn].iexe.op3     = id[$23].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $11].type;
	  insn[last_insn].iexe.src2h   = $11;
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[$13].val;
	  insn[last_insn].iexe.src3v   = id[$15].type;
	  insn[last_insn].iexe.src3h   = $15;
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[$17].val;
	  insn[last_insn].iexe.src4v   = id[$21].type;
	  insn[last_insn].iexe.src4h   = $21;
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[$25].type;
	  insn[last_insn].iexe.src5h   = $25;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_EX4 '(' expr ',' exe_dstd ',' INITNO '?' exe_src1 ':' exe_src1 ',' expr ',' ex4_src ',' expr ',' ex4_src ',' expr ',' expr ',' ex4_src ',' expr ',' exe_src5 ')' ';' {
	  /* ex4(OP_SFMA, &b00, INIT0?b00:b00, EXP_H3210, BR[r][1], EXP_H3210, BR[r][2], EXP_H3210, OP_NOP, 0LL, OP_NOP, 32LL) */
	  int loop_no0 = id[$7].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if ($9 != $11) {
	    fprintf(stderr, "in %s: exe(INIT0?src1:src1) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$23].val;
	  insn[last_insn].iexe.op3     = id[$27].val;
	  insn[last_insn].iexe.updt    = ($5 == $9)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 1; /* activate INIT0?src1 */
	  insn[last_insn].iexe.src1v   = id[ $9].type;
	  insn[last_insn].iexe.src1h   = $9;
	  insn[last_insn].iexe.src1e   = id[ $13].val;
	  insn[last_insn].iexe.src2v   = id[ $15].type;
	  insn[last_insn].iexe.src2h   = $15;
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[$17].val;
	  insn[last_insn].iexe.src3v   = id[$19].type;
	  insn[last_insn].iexe.src3h   = $19;
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[$21].val;
	  insn[last_insn].iexe.src4v   = id[$25].type;
	  insn[last_insn].iexe.src4h   = $25;
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[$29].type;
	  insn[last_insn].iexe.src5h   = $29;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_EXE '(' expr ',' exe_dstd ',' exe_src1 ',' expr ',' exe_src2 ',' expr ',' exe_src3 ',' expr ',' expr ',' exe_src4 ',' expr ',' exe_src5 ')' ';' {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$19].val;
	  insn[last_insn].iexe.op3     = id[$23].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $11].type;
	  insn[last_insn].iexe.src2h   = $11;
	  insn[last_insn].iexe.src2e   = id[$13].val;
	  insn[last_insn].iexe.src3v   = id[$15].type;
	  insn[last_insn].iexe.src3h   = $15;
	  insn[last_insn].iexe.src3e   = id[$17].val;
	  insn[last_insn].iexe.src4v   = id[$21].type;
	  insn[last_insn].iexe.src4h   = $21;
	  insn[last_insn].iexe.src5v   = id[$25].type;
	  insn[last_insn].iexe.src5h   = $25;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_EXE '(' expr ',' exe_dstd ',' INITNO '?' exe_src1 ':' exe_src1 ',' expr ',' exe_src2 ',' expr ',' exe_src3 ',' expr ',' expr ',' exe_src4 ',' expr ',' exe_src5 ')' ';' {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
	  int loop_no0 = id[$7].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if ($9 != $11) {
	    fprintf(stderr, "in %s: exe(INIT0?src1:src1) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$23].val;
	  insn[last_insn].iexe.op3     = id[$27].val;
	  insn[last_insn].iexe.updt    = ($5 == $9)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 1; /* activate INIT0?src1 */
	  insn[last_insn].iexe.src1v   = id[ $9].type;
	  insn[last_insn].iexe.src1h   = $9;
	  insn[last_insn].iexe.src1e   = id[ $13].val;
	  insn[last_insn].iexe.src2v   = id[ $15].type;
	  insn[last_insn].iexe.src2h   = $15;
	  insn[last_insn].iexe.src2e   = id[$17].val;
	  insn[last_insn].iexe.src3v   = id[$19].type;
	  insn[last_insn].iexe.src3h   = $19;
	  insn[last_insn].iexe.src3e   = id[$21].val;
	  insn[last_insn].iexe.src4v   = id[$25].type;
	  insn[last_insn].iexe.src4h   = $25;
	  insn[last_insn].iexe.src5v   = id[$29].type;
	  insn[last_insn].iexe.src5h   = $29;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_EXE '(' expr ',' exe_dstd ',' exe_src1 ',' expr ',' INITNO '?' exe_src2 ':' expr ',' expr ',' exe_src3 ',' expr ',' expr ',' exe_src4 ',' expr ',' exe_src5 ')' ';' {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
	  int loop_no0 = id[$11].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if (id[$15].val != 0) {
	    fprintf(stderr, "in %s: exe(INIT0?src2:expr) expr should be zero\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[$5].type==T_ALRNO?(id[$5].val)                :id[$5].type==T_BDRNO?(id[$5].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$5].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[$5].type==T_BDRNO?(id[$5].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ $3].val;
	  insn[last_insn].iexe.op2     = id[$23].val;
	  insn[last_insn].iexe.op3     = id[$27].val;
	  insn[last_insn].iexe.updt    = ($5 == $7)?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 2; /* activate s2+INIT0 */
	  insn[last_insn].iexe.src1v   = id[ $7].type;
	  insn[last_insn].iexe.src1h   = $7;
	  insn[last_insn].iexe.src1e   = id[ $9].val;
	  insn[last_insn].iexe.src2v   = id[ $13].type;
	  insn[last_insn].iexe.src2h   = $13;
	  insn[last_insn].iexe.src2e   = id[$17].val;
	  insn[last_insn].iexe.src3v   = id[$19].type;
	  insn[last_insn].iexe.src3h   = $19;
	  insn[last_insn].iexe.src3e   = id[$21].val;
	  insn[last_insn].iexe.src4v   = id[$25].type;
	  insn[last_insn].iexe.src4h   = $25;
	  insn[last_insn].iexe.src5v   = id[$29].type;
	  insn[last_insn].iexe.src5h   = $29;
	  insn[last_insn].iexe.exedv   = id[$5].type;
	  insn[last_insn].iexe.exedh   = $5;
          last_insn++;
        }
        | CGRA_MO4 '(' expr ',' mop_ex ',' mo4_srcdst ',' mop_base ',' mop_offset ',' expr ',' mop_top ',' mop_len ',' expr ',' force ',' mop_top ',' mop_len ')' ';' {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 6; /* MO4 */
	  insn[last_insn].iheader.row  = id[$7].type==T_ALRNO?(id[$7].val):id[$7].type==T_BDRNO?(id[$7].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$7].type==T_ALRNO?(        -1):id[$7].type==T_BDRNO?(id[$7].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ $3].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ $3].val);
	  insn[last_insn].imop.exv     = id[ $5].type;
	  insn[last_insn].imop.exh     = $5;
	  insn[last_insn].imop.mopdv   = id[ $7].type;
	  insn[last_insn].imop.mopdh   = $7;
	  insn[last_insn].imop.mopds   = 4; /* all suffix */
	  insn[last_insn].imop.basev   = id[ $9].type;
	  insn[last_insn].imop.baseh   = $9;
	  insn[last_insn].imop.offsv   = id[$11].type;
	  insn[last_insn].imop.offsh   = $11;
	  if (insn[last_insn].imop.updt) { /* addr++ */
	    if (insn[last_insn].imop.offsv != T_IMMEDIATE || id[insn[last_insn].imop.offsh].val) { /* != zero */
	      fprintf(stderr, "in %s: incremental base=%s requires offset=0 (specified type=%d val=%d)\n",
		      id[current_prefix].name, id[insn[last_insn].imop.baseh].name, insn[last_insn].imop.offsv, id[insn[last_insn].imop.offsh].val);
	      exit(1);
	    }
	    else {
	      Ull size;
	      switch (insn[last_insn].imop.op) {
	      case OP_LDRQ: case OP_STRQ: size = 32LL; break;
	      default:
		fprintf(stderr, "in %s: incremental base=%s is available with OP_LDRQ and OP_STRQ\n",
			id[current_prefix].name, id[insn[last_insn].imop.baseh].name);
		exit(1);
	      }
	      /* one_shotを使用し,アドレス計算の初回は,immediateを０として扱う */
	      insn[last_insn].imop.offsv   = T_IMMEDIATE;
	      insn[last_insn].imop.offsh   = hash_reg_immediate(size);
	    }
	  }
	  else if (insn[last_insn].imop.op == OP_LDDMQ) {
	    insn[last_insn].imop.updt    = 1; /* force automatic imcrement */
	    /* basev -> dexu->ex1v */
	    /* offsv -> dexu->ex2v */
	  }
	  else if (insn[last_insn].imop.op == OP_TR) {
	    insn[last_insn].imop.updt    = 1; /* force automatic imcrement */
	    insn[last_insn].imop.basev   = T_IMMEDIATE;
	    insn[last_insn].imop.baseh   = hash_reg_immediate(0LL); /* start from lmm_0 */
	    insn[last_insn].imop.bases   = -1;
	    insn[last_insn].imop.offsv   = T_IMMEDIATE;
	    insn[last_insn].imop.offsh   = hash_reg_immediate(32LL);
	    insn[last_insn].imop.offss   = -1;
	  }
	  insn[last_insn].imop.offsm   = id[$13].val;
	  insn[last_insn].imop.topv    = id[$15].type;
	  insn[last_insn].imop.toph    = $15;
	  insn[last_insn].imop.lenv    = id[$17].type;
	  insn[last_insn].imop.lenh    = $17;
	  insn[last_insn].imop.blk     = id[$19].val;
	  insn[last_insn].imop.forcev  = id[$21].type; /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.forceh  = $21;          /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.ptopv   = id[$23].type;
	  insn[last_insn].imop.ptoph   = $23;
	  insn[last_insn].imop.plenv   = id[$25].type;
	  insn[last_insn].imop.plenh   = $25;
          last_insn++;
        }
        | CGRA_MOP '(' expr ',' mop_ex ',' mop_srcdst ',' mop_base ',' mop_offset ',' expr ',' mop_top ',' mop_len ',' expr ',' force ',' mop_top ',' mop_len ')' ';' {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, , blockforce, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 7; /* MOP */
	  insn[last_insn].iheader.row  = id[$7].type==T_ALRNO?(id[$7].val)                :id[$7].type==T_BDRNO?(id[$7].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[$7].type==T_ALRNO?(insn[last_insn].imop.mopds):id[$7].type==T_BDRNO?(id[$7].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ $3].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ $3].val);
	  insn[last_insn].imop.exv     = id[ $5].type;
	  insn[last_insn].imop.exh     = $5;
	  insn[last_insn].imop.mopdv   = id[ $7].type;
	  insn[last_insn].imop.mopdh   = $7;
	  insn[last_insn].imop.basev   = id[ $9].type;
	  insn[last_insn].imop.baseh   = $9;
	  insn[last_insn].imop.offsv   = id[$11].type;
	  insn[last_insn].imop.offsh   = $11;
	  if (insn[last_insn].imop.updt) { /* addr++ */
	    if (insn[last_insn].imop.offsv != T_IMMEDIATE || id[insn[last_insn].imop.offsh].val) { /* != zero */
	      fprintf(stderr, "in %s: incremental base=%s requires offset=0 (specified type=%d val=%d)\n",
		      id[current_prefix].name, id[insn[last_insn].imop.baseh].name, insn[last_insn].imop.offsv, id[insn[last_insn].imop.offsh].val);
	      exit(1);
	    }
	    else {
	      Ull size;
	      switch (insn[last_insn].imop.op) {
	      case OP_LDR:  case OP_STR:                 size =  8LL; break;
	      case OP_LDWR: case OP_LDUWR: case OP_STWR: size =  4LL; break;
#if 0
	      case OP_LDHR: case OP_LDUHR: case OP_STHR: size =  2LL; break;
#endif
	      case OP_LDBR: case OP_LDUBR: case OP_STBR: size =  1LL; break;
	      default:
		fprintf(stderr, "in %s: incremental base=%s is available with OP_LD*R and OP_ST*R\n",
			id[current_prefix].name, id[insn[last_insn].imop.baseh].name);
		exit(1);
	      }
	      /* one_shotを使用し,アドレス計算の初回は,immediateを０として扱う */
	      insn[last_insn].imop.offsv   = T_IMMEDIATE;
	      insn[last_insn].imop.offsh   = hash_reg_immediate(size);
	    }
	  }
	  insn[last_insn].imop.offsm   = id[$13].val;
	  insn[last_insn].imop.topv    = id[$15].type;
	  insn[last_insn].imop.toph    = $15;
	  insn[last_insn].imop.lenv    = id[$17].type;
	  insn[last_insn].imop.lenh    = $17;
	  insn[last_insn].imop.blk     = id[$19].val;
	  insn[last_insn].imop.forcev  = id[$21].type; /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.forceh  = $21;          /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.ptopv   = id[$23].type;
	  insn[last_insn].imop.ptoph   = $23;
	  insn[last_insn].imop.plenv   = id[$25].type;
	  insn[last_insn].imop.plenh   = $25;
          last_insn++;
        }
        | '}' {
        }
	| {
        }
        ;

cex_src : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	; 

cex_dst : '&' EXRNO {
          $$ = $2;
        }
	;

ex4_src : expr {
          $$ = $1;
        }
        | XVARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $2;
	}
        | ALRNO { /* AR[r] ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | BDRNO { /* BR[r][c] ([UNIT_WIDTH]) */
          $$ = $1;
	}
	;

ex4_dstd : XVARIABLE { /* var ([UNIT_WIDTH]) */
          $$ = $1;
	}
        | ALRNO { /* AR[r] ([UNIT_WIDTH]) */
          $$ = $1;
	}
	;

exe_src1 : expr {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].iexe.src1s = -1;
          $$ = $2;
	}
        | ALRNO '[' expr ']' { /* AR[r][s] */
	  insn[last_insn].iexe.src1s = id[$3].val;
          $$ = $1;
	}
        | BDRNO '[' expr ']' { /* BR[r][c][s] */
	  insn[last_insn].iexe.src1s = id[$3].val;
          $$ = $1;
	}
	;

exe_src2 : expr {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].iexe.src2s = -1;
          $$ = $2;
	}
        | ALRNO '[' expr ']' { /* AR[r][s] */
	  insn[last_insn].iexe.src2s = id[$3].val;
          $$ = $1;
	}
        | BDRNO '[' expr ']' { /* BR[r][c][s] */
	  insn[last_insn].iexe.src2s = id[$3].val;
          $$ = $1;
	}
	;

exe_src3 : expr {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].iexe.src3s = -1;
          $$ = $2;
	}
        | ALRNO '[' expr ']' { /* AR[r][s] */
	  insn[last_insn].iexe.src3s = id[$3].val;
          $$ = $1;
	}
        | BDRNO '[' expr ']' { /* BR[r][c][s] */
	  insn[last_insn].iexe.src3s = id[$3].val;
          $$ = $1;
	}
	;

exe_src4 : expr {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].iexe.src4s = -1;
          $$ = $2;
	}
        | ALRNO '[' expr ']' { /* AR[r][s] */
	  insn[last_insn].iexe.src4s = id[$3].val;
          $$ = $1;
	}
        | BDRNO '[' expr ']' { /* BR[r][c][s] */
	  insn[last_insn].iexe.src4s = id[$3].val;
          $$ = $1;
	}
	;

exe_src5 : expr {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].iexe.src5s = -1;
          $$ = $2;
	}
        | ALRNO '[' expr ']' { /* AR[r][s] */
	  insn[last_insn].iexe.src5s = id[$3].val;
          $$ = $1;
	}
        | BDRNO '[' expr ']' { /* BR[r][c][s] */
	  insn[last_insn].iexe.src5s = id[$3].val;
          $$ = $1;
	}
	;

exe_dstd : '&' XVARIABLE { /* &var */
	  insn[last_insn].iexe.exeds = -1;
          $$ = $2;
        }
        | '&' ALRNO '[' expr ']' { /* &AR[r][s] */
	  insn[last_insn].iexe.exeds = id[$4].val;
          $$ = $2;
	}
	;

mop_ex : expr {
          $$ = $1;
        }
        | EXRNO { /* exx */
          $$ = $1;
	}
	;

mo4_srcdst : XVARIABLE { /* for load/store */
          $$ = $1;
	}
        | ALRNO { /* for store */
          $$ = $1;
	}
        | BDRNO { /* for load */
          $$ = $1;
        }
	;

mop_srcdst : '&' XVARIABLE { /* for load/store */
	  insn[last_insn].imop.mopds = -1;
          $$ = $2;
	}
        | '&' ALRNO '[' expr ']' { /* for store */
	  insn[last_insn].imop.mopds = id[$4].val;
          $$ = $2;
	}
        | '&' BDRNO '[' expr ']' { /* for load */
	  insn[last_insn].imop.mopds = id[$4].val;
          $$ = $2;
        }
	;

mop_base : expr {
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].imop.bases = -1;
          $$ = $2;
	}
        | XVARIABLE CGRA_INCR {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          $$ = $1;
	}
        | CGRA_ULL '(' XVARIABLE CGRA_INCR ')' {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          $$ = $3;
	}
        | BDRNO '[' expr ']' {
	  insn[last_insn].imop.bases = id[$3].val;
          $$ = $1;
	}
	;

mop_offset : expr {
	  insn[last_insn].imop.offss = -1;
          $$ = $1;
        }
        | XVARIABLE {
	  insn[last_insn].imop.offss = -1;
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
	  insn[last_insn].imop.offss = -1;
          $$ = $2;
	}
        | BDRNO '[' expr ']' {
	  insn[last_insn].imop.offss = id[$3].val;
          $$ = $1;
	}
	;

mop_top : expr {
          $$ = $1;
        }
        | XVARIABLE {
          $$ = $1;
	}
        | CGRA_ULL XVARIABLE {
          $$ = $2;
	}
	;

mop_len : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	;

force : expr {
          $$ = $1;
        }
        | VARIABLE {
          $$ = $1;
	}
        | CGRA_ULL VARIABLE {
          $$ = $2;
	}
	;

XVARIABLE : CHIP {
          /*id[$1].chip = 1;*/
          $$ = $1;
        }
        | VARIABLE '[' CHIP ']' {
	  id[$1].cidx = 1;
          $$ = $1;
	}
        | VARIABLE {
          $$ = $1;
	}

expr : term {
          $$ = $1;
        }
        | expr '+' term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")+(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val + id[$3].val;
	  }
          $$ = hashval;
        }
        | expr '-' term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")-(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val - id[$3].val;
	  }
          $$ = hashval;
        }
        | expr CGRA_SLL term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")<<(",      BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val << id[$3].val;
	  }
          $$ = hashval;
        }
        | expr CGRA_SRL term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")>>(",      BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val >> id[$3].val;
	  }
          $$ = hashval;
        }
        | expr '&' term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")&(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val & id[$3].val;
	  }
          $$ = hashval;
        }
        | expr '^' term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")^(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val ^ id[$3].val;
	  }
          $$ = hashval;
        }
        | expr '|' term {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")|(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val | id[$3].val;
	  }
          $$ = hashval;
        }
        ;

term : factor {
          $$ = $1;
        }
        | '~' factor {
          int hashval;
	  strncpy(buf, "~(",        BUF_MAXLEN-1);
	  strncat(buf, id[$2].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = ~ id[$2].val;
	  }
          $$ = hashval;
        }
        | '-' factor {
          int hashval;
	  strncpy(buf, "-(",        BUF_MAXLEN-1);
	  strncat(buf, id[$2].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = - id[$2].val;
	  }
          $$ = hashval;
        }
        | term '*' factor {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")*(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val * id[$3].val;
	  }
          $$ = hashval;
        }
        | term '/' factor {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[$1].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")/(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[$3].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[$1].val / id[$3].val;
	  }
          $$ = hashval;
        }
        ;

factor : '(' expr ')' {
          $$ = $2;
        }
        | number {
          $$ = $1;
        }
        ;

number : IMMEDIATE {
          $$ = $1;
        }
        | CGRA_ULL IMMEDIATE {
          $$ = $2;
        }
        | CGRA_UINT IMMEDIATE {
          $$ = $2;
        }
        ;

EMAX6TBODY : TRAN_READ {
          trans[trans_pc].rw = 0; /* READ */
	}
        | TRAN_WRITE {
          trans[trans_pc].rw = 1; /* WRITE */
        }
        ;

%%


