/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EOL = 258,
    ARMV8 = 259,
    EMAX6ABEGIN = 260,
    EMAX6ASTATEM = 261,
    EMAX6AEND = 262,
    EMAX6ADRAIN = 263,
    EMAX6TBEGIN = 264,
    EMAX6TSTATEM = 265,
    EMAX6TEND = 266,
    CGRA_ULL = 267,
    CGRA_UINT = 268,
    CGRA_SLL = 269,
    CGRA_SRL = 270,
    CGRA_WHILE = 271,
    CGRA_FOR = 272,
    CGRA_CEX = 273,
    CGRA_EX4 = 274,
    CGRA_EXE = 275,
    CGRA_MO4 = 276,
    CGRA_MOP = 277,
    CGRA_DECR = 278,
    CGRA_INCR = 279,
    TRAN_READ = 280,
    TRAN_WRITE = 281,
    IMMEDIATE = 282,
    EXRNO = 283,
    ALRNO = 284,
    BDRNO = 285,
    CHIP = 286,
    INITNO = 287,
    LOOPNO = 288,
    VARIABLE = 289,
    ASIS = 290
  };
#endif
/* Tokens.  */
#define EOL 258
#define ARMV8 259
#define EMAX6ABEGIN 260
#define EMAX6ASTATEM 261
#define EMAX6AEND 262
#define EMAX6ADRAIN 263
#define EMAX6TBEGIN 264
#define EMAX6TSTATEM 265
#define EMAX6TEND 266
#define CGRA_ULL 267
#define CGRA_UINT 268
#define CGRA_SLL 269
#define CGRA_SRL 270
#define CGRA_WHILE 271
#define CGRA_FOR 272
#define CGRA_CEX 273
#define CGRA_EX4 274
#define CGRA_EXE 275
#define CGRA_MO4 276
#define CGRA_MOP 277
#define CGRA_DECR 278
#define CGRA_INCR 279
#define TRAN_READ 280
#define TRAN_WRITE 281
#define IMMEDIATE 282
#define EXRNO 283
#define ALRNO 284
#define BDRNO 285
#define CHIP 286
#define INITNO 287
#define LOOPNO 288
#define VARIABLE 289
#define ASIS 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
