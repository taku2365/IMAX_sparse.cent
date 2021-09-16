
static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/src/conv-c2c/RCS/main.c,v 1.5 2021/06/06 06:24:28 nakashim Exp nakashim $";

/* EMAX6 Compiler                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* main.c: emin assembler 2012/3/16 */ 

#include "yacc_lex_util.h"


extern FILE *yyin;

main(argc, argv) int argc; char **argv;
{
  char *version();
  struct stat stbuf;
  int i, j, offset;

  /* ���ץ������� */
  for (argc--, argv++; argc; argc--, argv++) {
    if (**argv == '-') { /* regard as a command */
      switch (*(*argv+1)) {
      case 'v':
	printf("Conv-c2c Version %s\n", version());
	break;
      default:
	printf("usage: conv-c2c [-v] src_prog\n");
	printf("       -v: vervose\n");
	exit(1);
      }
    }
    else { /* regard as a filename */
      strncpy(srcprog = (char*)malloc(strlen(*argv)+1), *argv, strlen(*argv)+1);
    }
  }

  /* �ե����륪���ץ� */
  if ((yyin = fopen(srcprog, "r")) == NULL) {
    fprintf(stderr, "can't open source:\"%s\"\n", srcprog);
    exit(1);
  }
  strncpy(objprog = (char*)malloc(strlen(srcprog)+strlen(OBJSUFX)+1), srcprog, strlen(srcprog)+1); /* xxx.x -> xxx-emax6.c */
  for (i=0; i<strlen(srcprog); i++) {
    if (objprog[i] == '.' || objprog[i] == '\0' ) {
      strncpy(objprog+i, OBJSUFX, strlen(OBJSUFX)+1);
      break;
    }
  }

  if ((ofile = fopen(objprog, "w")) == NULL) {
    fprintf(stderr, "can't open object:\"%s\"\n", objprog);
    exit(1);
  }

  /* ASM�ɤ߹��� */
  y_lineno = 1;
  y_errornum = 0;
  yydebug = 1;
  while (yyparse());
  fclose(yyin);
  fclose(ofile);

  if (y_errornum) exit(1);

  exit(0);
}

char *
version()
{
  char *i;

  for (i=RcsHeader; *i && *i!=' '; i++);
  for (           ; *i && *i==' '; i++);
  for (           ; *i && *i!=' '; i++);
  for (           ; *i && *i==' '; i++);
  return (i);
}
