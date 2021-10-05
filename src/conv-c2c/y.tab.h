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
    CGRA_MO2 = 277,
    CGRA_MOP = 278,
    CGRA_DECR = 279,
    CGRA_INCR = 280,
    TRAN_READ = 281,
    TRAN_WRITE = 282,
    IMMEDIATE = 283,
    EXRNO = 284,
    ALRNO = 285,
    BDRNO = 286,
    CHIP = 287,
    INITNO = 288,
    LOOPNO = 289,
    VARIABLE = 290,
    ASIS = 291
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
#define CGRA_MO2 277
#define CGRA_MOP 278
#define CGRA_DECR 279
#define CGRA_INCR 280
#define TRAN_READ 281
#define TRAN_WRITE 282
#define IMMEDIATE 283
#define EXRNO 284
#define ALRNO 285
#define BDRNO 286
#define CHIP 287
#define INITNO 288
#define LOOPNO 289
#define VARIABLE 290
#define ASIS 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
