#include "yacc_lex_util.h"

int hash(register char *s)
{
  register int    hashval;

  for (hashval=0; *s!=0;)
    hashval += *s++;
  return(hashval % ID_NUM+1);
}

void hash_clear()
{
  register int    i;

  for (i=0; i<ID_NUM; i++) {
    id[i].name  = NULL;
    id[i].type  = 0;
    id[i].itype = 0;
    id[i].row   = 0;
    id[i].col   = 0;
  }
}

int hash_search(char *buf, int *reth)
{
  /* return 0 ... new id[reth] is assigned */
  /* return 1 ... old id[reth] is found */
  char *bufptr;
  int  hashval, hashsave, buflen;

  /* hash */
  hashval = hashsave = hash(buf);
  while (id[hashval].name != NULL) {
    if (!strncmp(buf, id[hashval].name, BUF_MAXLEN)) {
      *reth = hashval;
      return (1);
    }
    hashval = rehash(hashval);
    if (hashval == hashsave)
      break;
  }
  if (id[hashval].name != NULL) {
    yyerror("too many IDs");
    fprintf(stderr, "current ID_NUM is %d\n", ID_NUM);
    exit(1);
  }

  /* new number */
  buflen = strlen(buf)+1;
  id[hashval].name = bufptr = malloc(buflen);
  id[hashval].row = -1; /* init */
  id[hashval].col = -1; /* init */
  strncpy(bufptr, buf, buflen);
  *reth = hashval;
  return(0);
}

int hash_reg_immediate(Ull imm)
{
  int hashval;
  /* return hashval */
  snprintf(buf, BUF_MAXLEN, "%lldLL", imm);
  if (!hash_search(buf, &hashval)) { /* not found */
    id[hashval].type = T_IMMEDIATE;
    id[hashval].val = imm;
  }
  return (hashval);
}




