
static char RcsHeader[] = "$Header: /usr/home/nakashim/proj-arm64/src/conv-c2c/RCS/main.c,v 1.6 2021/12/21 04:00:00 nakashim Exp nakashim $";

/* EMAX6 Compiler                      */
/*        Copyright (C) 2012 by NAIST. */
/*         Primary writer: Y.Nakashima */
/*                nakashim@is.naist.jp */

/* main.c: emin assembler 2012/3/16 */ 

#include "conv-c2c.h"

extern FILE *yyin;

main(argc, argv) int argc; char **argv;
{
  char *version();
  struct stat stbuf;
  int i, j, offset;

  /* オプション解析 */
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

  /* ファイルオープン */
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
    fprintf(stderr, "can't open output:\"%s\"\n", objprog);
    exit(1);
  }
  strncpy(pthprog = (char*)malloc(strlen(srcprog)+strlen(PTHSUFX)+1), srcprog, strlen(srcprog)+1); /* xxx.x -> xxx-emax6pt.c */
  for (i=0; i<strlen(srcprog); i++) {
    if (pthprog[i] == '.' || pthprog[i] == '\0' ) {
      strncpy(pthprog+i, PTHSUFX, strlen(PTHSUFX)+1);
      break;
    }
  }
  if ((pfile = fopen(pthprog, "w")) == NULL) {
    fprintf(stderr, "can't open output:\"%s\"\n", pthprog);
    exit(1);
  }

  /* ASM読み込み */
  y_lineno = 1;
  y_errornum = 0;
  while (yyparse());
  fclose(yyin);
  fclose(ofile);
  fclose(pfile);

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
