#ifndef YACC_DEF
#define YACC_DEF
#include "conv-c2c.h"
#include "emax6.h"
#include "y.tab.h"
int hash(register char *s);
int hash_reg_immediate(Ull imm);
int hash_search(char *buf, int *reth);
void hash_clear();
int hash(register char *s);
#endif
