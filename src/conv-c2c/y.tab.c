/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "conv-c2c.y"


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


#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  449

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,     2,
      37,    38,    55,    50,    43,    51,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    41,
      42,    40,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    53,    46,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    57,    60,    63,    85,    87,    91,
      95,   102,   104,   110,   112,   116,   140,   152,   212,   234,
     272,   306,   349,   381,   422,   463,   532,   591,   593,   597,
     600,   603,   608,   613,   616,   619,   622,   625,   630,   633,
     638,   642,   646,   650,   654,   660,   664,   668,   672,   676,
     682,   686,   690,   694,   698,   704,   708,   712,   716,   720,
     726,   730,   734,   738,   742,   748,   752,   758,   761,   766,
     769,   772,   777,   781,   785,   791,   795,   799,   803,   808,
     813,   819,   823,   827,   831,   837,   840,   843,   848,   851,
     854,   859,   862,   865,   870,   874,   878,   882,   885,   898,
     911,   924,   937,   950,   963,   978,   981,   992,  1003,  1016,
    1031,  1034,  1039,  1042,  1045,  1050,  1053
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "ARMV8", "EMAX6ABEGIN",
  "EMAX6ASTATEM", "EMAX6AEND", "EMAX6ADRAIN", "EMAX6TBEGIN",
  "EMAX6TSTATEM", "EMAX6TEND", "CGRA_ULL", "CGRA_UINT", "CGRA_SLL",
  "CGRA_SRL", "CGRA_WHILE", "CGRA_FOR", "CGRA_CEX", "CGRA_EX4", "CGRA_EXE",
  "CGRA_MO4", "CGRA_MO2", "CGRA_MOP", "CGRA_DECR", "CGRA_INCR",
  "TRAN_READ", "TRAN_WRITE", "IMMEDIATE", "EXRNO", "ALRNO", "BDRNO",
  "CHIP", "INITNO", "LOOPNO", "VARIABLE", "ASIS", "'('", "')'", "'{'",
  "'='", "';'", "'<'", "','", "'?'", "':'", "'}'", "'&'", "'['", "']'",
  "'+'", "'-'", "'^'", "'|'", "'~'", "'*'", "'/'", "$accept", "program",
  "line", "EMAX6ABODY", "EMAX6AUNIT", "cex_src", "cex_dst", "ex4_src",
  "ex4_dstd", "exe_src1", "exe_src2", "exe_src3", "exe_src4", "exe_src5",
  "exe_dstd", "mop_ex", "mo4_srcdst", "mop_srcdst", "mop_base",
  "mop_offset", "mop_top", "mop_len", "force", "XVARIABLE", "expr", "term",
  "factor", "number", "EMAX6TBODY", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    40,    41,   123,
      61,    59,    60,    44,    63,    58,   125,    38,    91,    93,
      43,    45,    94,   124,   126,    42,    47
};
# endif

#define YYPACT_NINF (-386)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     559,  -386,  -386,   -19,   333,  -386,  -386,     9,     0,  -386,
    1278,  -386,    67,   -14,    -2,    21,    25,    34,    53,    66,
    -386,   333,  -386,  -386,  -386,  -386,  -386,  -386,  -386,    18,
      47,  -386,    67,   171,   171,  1224,    38,  -386,  -386,    78,
      99,    67,    67,    67,    67,    67,  -386,  -386,  -386,   114,
    -386,  -386,    67,    67,    67,    67,    67,    67,    67,   171,
     171,    91,    77,    87,   248,   502,   546,   560,   573,  -386,
      38,    38,    38,    38,    38,    38,    38,  -386,  -386,    81,
      67,    67,    88,   -23,    93,   126,   126,   103,   186,   591,
     121,   108,  -386,  -386,   109,    29,   116,   117,  -386,   119,
    -386,   125,  1224,   129,  -386,   137,   142,  -386,   385,   146,
     139,  -386,    35,     6,   161,   210,   141,   153,   157,   -20,
    -386,   160,  1224,   158,    67,   -18,  -386,  -386,   167,  -386,
    1224,   -18,   165,   166,   172,   179,  -386,  1224,   190,   192,
    -386,  -386,   200,  -386,   234,   209,    67,   223,  -386,   385,
    -386,    73,  -386,    67,  -386,    67,    67,   243,    67,   243,
      67,    79,   220,   224,  -386,    79,   580,   233,   236,  -386,
     614,   621,   631,   232,   661,   242,   672,   174,   254,   238,
     271,  1224,    67,    67,   261,   273,   -10,   385,    35,  -386,
    -386,   243,    35,   243,   216,   -10,  -386,    67,   464,  -386,
     679,   686,   464,   278,   268,   266,   272,   275,   280,   284,
     -18,   263,   282,   289,   285,  -386,  1224,   291,   695,   -18,
     292,   296,  -386,  1224,  -386,  -386,   298,   304,   308,   385,
      67,    67,    67,    67,  -386,    67,    67,   294,    67,   309,
    -386,  -386,    67,    67,    67,   307,   321,   323,   706,   726,
     737,   748,   756,   767,   324,   778,  -386,   796,   808,   819,
    -386,   336,    67,    35,    35,    35,   294,  -386,  -386,    67,
     364,  -386,   474,   474,   347,   826,   329,   335,   337,   341,
     838,   -18,   342,   345,   346,  -386,  1224,   -18,   357,  -386,
    1224,   359,   366,   369,    67,    67,    67,    67,    67,  -386,
      67,    67,    67,  -386,   492,   492,   378,  -386,   853,   868,
     879,   893,   909,   919,   927,   939,    -7,  -386,   371,  1224,
     373,   372,    67,    35,    67,   364,   364,  -386,  -386,    67,
    -386,    67,    67,    67,   950,   381,   969,   392,   395,   980,
     991,  1003,  1010,    35,    67,    35,    67,    67,   429,   522,
     522,   401,   400,  1021,   402,  1037,  1051,   -18,   396,   399,
     405,  -386,  1224,    17,  -386,   409,  1224,   413,  -386,    67,
      67,    67,    67,    67,  -386,    67,    67,    67,  -386,   474,
     474,  1062,  1077,  1092,  1103,  1117,  1126,  1133,  1144,   420,
     428,    35,    35,   437,   429,   429,  -386,  -386,   437,   492,
     492,   435,   432,   -18,   430,   433,   444,  -386,  1224,   441,
     442,   451,   452,   455,   453,    67,  -386,    67,    67,   457,
      67,    67,   459,   462,   466,  -386,  1157,  1174,  1184,  -386,
    1197,  1214,  -386,  -386,  -386,   437,  -386,  -386,   437,   437,
     470,   472,   475,   471,   473,   478,  -386,  -386,  -386
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     5,     0,    28,     8,     9,     0,     0,    12,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     7,    13,    10,   115,   116,    11,     1,     2,     0,
       0,   112,     0,     0,     0,     6,    97,   105,   111,     0,
       0,     0,     0,     0,     0,     0,    14,   113,   114,     0,
     107,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     100,   101,   102,    98,    99,   103,   104,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    94,    96,     0,     0,     0,    38,     0,
      68,     0,    67,     0,    15,     0,     0,    32,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    29,     0,     0,     0,    36,    37,     0,    34,
      33,     0,     0,     0,     0,     0,    41,    40,     0,     0,
      70,    71,     0,    69,     0,     0,     0,     0,    31,     0,
      95,     0,    35,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    75,     0,     0,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    45,     0,     0,     0,
       0,     0,    82,    81,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      80,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    50,     0,     0,    86,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,    87,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,    88,
       0,     0,     0,     0,     0,     0,     0,    53,    54,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    55,     0,    92,     0,    91,     0,    17,     0,
       0,     0,     0,     0,    57,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    60,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,    20,
       0,     0,    22,    25,    26,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    23,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -386,  -386,   511,  -386,   501,  -145,  -386,  -187,  -386,  -108,
    -226,  -220,  -295,  -385,   439,   438,  -386,  -386,   374,   334,
    -271,  -302,   181,   260,   -12,   376,    22,  -386,  -386
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    21,    22,   121,    91,   128,    96,   135,
     214,   284,   360,   406,    97,   101,   142,   145,   179,   221,
     288,   318,   365,   129,   130,    36,    37,    38,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   206,   291,   320,   168,   208,   139,    92,    47,    93,
      47,   254,    94,   411,    93,   148,    12,    94,   131,    30,
      49,    47,    93,    39,    95,    94,    24,    25,   330,    64,
      65,    66,    67,    68,    31,    40,   132,   133,    93,   134,
     279,    94,   205,    32,    23,    47,    47,   125,    30,   173,
     440,   175,   378,   441,   442,    50,    51,    33,    41,   110,
      34,    93,    42,    31,    94,   126,   127,    93,    88,    89,
      94,    43,    32,   102,   102,    48,   276,   277,   278,    29,
      30,    77,    78,   207,   247,   209,    33,    52,    53,    34,
      44,   177,    30,    59,    60,    31,   122,   412,   413,   409,
     410,   137,   137,    45,    32,   337,   338,    31,   389,   390,
     178,    93,   151,    61,    94,    79,    32,    80,    33,    87,
      54,    34,   169,    55,    56,    57,    58,    81,    52,    53,
      33,    62,    63,    34,   166,    90,   335,   122,    29,    30,
      95,   170,   104,   171,   172,   137,   174,   137,   176,   181,
     107,   108,    69,   181,    31,   100,   352,   109,   354,   112,
     113,    54,   114,    32,    55,    56,    57,    58,   115,   117,
     200,   201,   116,   131,    30,   122,   118,    33,   123,   137,
      34,   137,   216,    29,    30,   218,   223,   124,   144,    31,
     223,   132,   133,    93,   138,   146,    94,   147,    32,    31,
      52,    53,    47,   149,   401,   402,    93,   150,    32,    94,
     153,   195,    33,   155,   156,    34,   157,   122,   248,   249,
     250,   251,   158,   252,   253,   216,   255,   105,   210,    30,
     257,   258,   259,    54,   159,   160,    55,    56,    57,    58,
     140,   141,    93,   161,    31,    94,   211,   212,    93,   213,
     275,    94,   165,    32,   216,   131,    30,   280,   286,   167,
     290,   290,    52,    53,   162,   163,    93,    33,   182,    94,
      34,    31,   183,   132,   133,    93,   186,   191,    94,   187,
      32,   198,   308,   309,   310,   311,   312,   193,   313,   314,
     315,    82,   319,   319,    33,    54,   199,    34,    55,    56,
      57,    58,   197,   227,   202,   203,   210,    30,   228,   229,
     334,   235,   336,   286,   286,   230,   239,   339,   231,   340,
     341,   342,    31,   232,   211,   212,    93,   233,   238,    94,
     236,    32,   353,   237,   355,   356,   362,   366,   366,   243,
     242,   244,   245,    98,   246,    33,   260,   256,    34,    13,
      14,    15,    16,    17,    18,   111,    19,   381,   382,   383,
     384,   385,   261,   386,   387,   388,   262,   290,   290,   269,
     274,   292,   294,   136,   136,   143,   281,    30,   295,    20,
     296,   408,   362,   362,   297,   152,   408,   319,   319,   302,
     300,   154,    31,   301,   282,   283,    93,   119,    30,    94,
     304,    32,   305,   426,   164,   427,   428,   306,   430,   431,
     307,   321,   333,    31,   331,    33,   332,   136,    34,   136,
     120,   180,    32,   408,   344,   180,   408,   408,    70,    71,
      72,    73,    74,    75,    76,   346,    33,   196,   347,    34,
     368,   357,    30,   369,   375,   371,   204,   376,   377,   403,
      30,   136,   379,   136,   215,   217,   380,    31,   222,   358,
     359,    93,   222,   399,    94,    31,    32,   404,   405,    93,
     234,   400,    94,   414,    32,   415,   219,    30,   417,   241,
      33,   418,   419,    34,   420,   421,   287,    30,    33,   422,
     423,    34,    31,   424,   425,   220,    93,   215,   429,    94,
     432,    32,    31,   433,   316,    30,    93,   434,   443,    94,
     444,    32,   446,   445,   447,    33,    52,    53,    34,   448,
      31,    28,    46,    99,   103,    33,   215,   317,    34,    32,
     285,   367,   289,   289,   363,    30,   226,     0,     0,   184,
       0,   299,     0,    33,     0,    83,    34,   303,     0,    54,
      31,     0,    55,    56,    57,    58,     0,   364,     0,    32,
      52,    53,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,    33,    52,    53,    34,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   285,    52,    53,    84,
       0,     0,     0,    54,    52,    53,    55,    56,    57,    58,
       0,     0,     0,    85,     0,    52,    53,    54,   361,     0,
      55,    56,    57,    58,     0,     0,    86,   374,     0,     0,
      54,   185,     0,    55,    56,    57,    58,    54,    52,    53,
      55,    56,    57,    58,   106,    52,    53,     0,    54,   289,
     289,    55,    56,    57,    58,    52,    53,     0,     0,     0,
       0,     0,     0,   407,   361,   361,     0,   188,   407,     0,
       0,    54,     0,   416,    55,    56,    57,    58,    54,     0,
     189,    55,    56,    57,    58,    52,    53,     0,    54,     0,
     190,    55,    56,    57,    58,     0,    52,    53,     0,     0,
       0,     0,     0,    52,    53,   407,     0,     0,   407,   407,
      52,    53,     0,     0,   192,     0,     0,     0,    54,    52,
      53,    55,    56,    57,    58,   194,     0,     0,     0,    54,
      52,    53,    55,    56,    57,    58,    54,     0,   224,    55,
      56,    57,    58,    54,     0,   225,    55,    56,    57,    58,
      52,    53,    54,     0,   240,    55,    56,    57,    58,   263,
       0,    52,    53,    54,     0,     0,    55,    56,    57,    58,
       0,     0,    52,    53,     0,     0,     0,     0,     0,   264,
      52,    53,     0,    54,     0,     0,    55,    56,    57,    58,
     265,    52,    53,     0,    54,     0,     0,    55,    56,    57,
      58,   266,    52,    53,     0,    54,     0,     0,    55,    56,
      57,    58,     0,    54,     0,   267,    55,    56,    57,    58,
      52,    53,     0,     0,    54,     0,   268,    55,    56,    57,
      58,   270,    52,    53,     0,    54,     0,     0,    55,    56,
      57,    58,     0,    52,    53,     0,     0,     0,     0,     0,
      52,    53,     0,    54,     0,   271,    55,    56,    57,    58,
       0,   272,    52,    53,     0,    54,     0,     0,    55,    56,
      57,    58,   273,     0,   293,     0,    54,    52,    53,    55,
      56,    57,    58,    54,     0,     0,    55,    56,    57,    58,
       0,   298,    52,    53,     0,    54,     0,     0,    55,    56,
      57,    58,     0,    52,    53,     0,   322,     0,     0,     0,
      54,     0,     0,    55,    56,    57,    58,    52,    53,     0,
       0,   323,     0,     0,     0,    54,     0,     0,    55,    56,
      57,    58,   324,    52,    53,     0,    54,     0,     0,    55,
      56,    57,    58,    52,    53,     0,   325,     0,     0,     0,
      54,    52,    53,    55,    56,    57,    58,     0,     0,     0,
       0,     0,   326,    52,    53,     0,    54,     0,     0,    55,
      56,    57,    58,     0,    52,    53,    54,     0,   327,    55,
      56,    57,    58,     0,    54,     0,   328,    55,    56,    57,
      58,     0,   329,    52,    53,     0,    54,     0,     0,    55,
      56,    57,    58,   343,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,     0,    52,    53,     0,     0,     0,
       0,     0,   345,     0,     0,     0,    54,    52,    53,    55,
      56,    57,    58,   348,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,   349,    52,    53,     0,    54,     0,
       0,    55,    56,    57,    58,     0,   350,     0,   351,     0,
      54,    52,    53,    55,    56,    57,    58,    54,     0,     0,
      55,    56,    57,    58,   370,    52,    53,     0,    54,     0,
       0,    55,    56,    57,    58,     0,    52,    53,     0,     0,
     372,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,    52,    53,     0,   373,     0,     0,     0,    54,     0,
       0,    55,    56,    57,    58,   391,    52,    53,     0,    54,
       0,     0,    55,    56,    57,    58,     0,    52,    53,     0,
     392,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,    52,    53,     0,     0,   393,     0,     0,     0,    54,
      52,    53,    55,    56,    57,    58,   394,    52,    53,     0,
      54,     0,     0,    55,    56,    57,    58,     0,    52,    53,
     395,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,    52,    53,    54,     0,   396,    55,    56,    57,    58,
      54,     0,   397,    55,    56,    57,    58,   398,    52,    53,
       0,    54,     0,     0,    55,    56,    57,    58,    52,    53,
     435,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,   436,    55,    56,    57,    58,    52,    53,
       0,    54,     0,   437,    55,    56,    57,    58,    52,    53,
     438,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,     0,     0,     0,     0,     0,     0,   439,     0,     0,
       0,    54,     0,     0,    55,    56,    57,    58,     0,     0,
       0,    54,     0,     0,    55,    56,    57,    58,    27,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9
};

static const yytype_int16 yycheck[] =
{
      12,   188,   273,   305,   149,   192,   114,    30,    28,    32,
      28,   237,    35,   398,    32,    35,    35,    35,    12,    13,
      32,    28,    32,    37,    47,    35,    26,    27,    35,    41,
      42,    43,    44,    45,    28,    37,    30,    31,    32,    33,
     266,    35,   187,    37,    35,    28,    28,    12,    13,   157,
     435,   159,    35,   438,   439,    33,    34,    51,    37,    30,
      54,    32,    37,    28,    35,    30,    31,    32,    80,    81,
      35,    37,    37,    85,    86,    28,   263,   264,   265,    12,
      13,    59,    60,   191,   229,   193,    51,    14,    15,    54,
      37,    12,    13,    55,    56,    28,   108,   399,   400,   394,
     395,   113,   114,    37,    37,   325,   326,    28,   379,   380,
      31,    32,   124,    35,    35,    24,    37,    40,    51,    38,
      47,    54,    49,    50,    51,    52,    53,    40,    14,    15,
      51,    32,    33,    54,   146,    47,   323,   149,    12,    13,
      47,   153,    39,   155,   156,   157,   158,   159,   160,   161,
      29,    43,    38,   165,    28,    29,   343,    48,   345,    43,
      43,    47,    43,    37,    50,    51,    52,    53,    43,    32,
     182,   183,    43,    12,    13,   187,    34,    51,    32,   191,
      54,   193,   194,    12,    13,   197,   198,    48,    47,    28,
     202,    30,    31,    32,    33,    42,    35,    40,    37,    28,
      14,    15,    28,    43,   391,   392,    32,    49,    37,    35,
      43,    37,    51,    48,    48,    54,    44,   229,   230,   231,
     232,   233,    43,   235,   236,   237,   238,    41,    12,    13,
     242,   243,   244,    47,    44,    43,    50,    51,    52,    53,
      30,    31,    32,    43,    28,    35,    30,    31,    32,    33,
     262,    35,    43,    37,   266,    12,    13,   269,   270,    36,
     272,   273,    14,    15,    30,    31,    32,    51,    48,    35,
      54,    28,    48,    30,    31,    32,    43,    45,    35,    43,
      37,    43,   294,   295,   296,   297,   298,    45,   300,   301,
     302,    43,   304,   305,    51,    47,    25,    54,    50,    51,
      52,    53,    48,    25,    43,    32,    12,    13,    40,    43,
     322,    48,   324,   325,   326,    43,    25,   329,    43,   331,
     332,   333,    28,    43,    30,    31,    32,    43,    43,    35,
      48,    37,   344,    44,   346,   347,   348,   349,   350,    43,
      48,    43,    38,    83,    36,    51,    39,    38,    54,    16,
      17,    18,    19,    20,    21,    95,    23,   369,   370,   371,
     372,   373,    41,   375,   376,   377,    43,   379,   380,    45,
      34,    24,    43,   113,   114,   115,    12,    13,    43,    46,
      43,   393,   394,   395,    43,   125,   398,   399,   400,    43,
      48,   131,    28,    48,    30,    31,    32,    12,    13,    35,
      43,    37,    43,   415,   144,   417,   418,    41,   420,   421,
      41,    33,    40,    28,    43,    51,    43,   157,    54,   159,
      35,   161,    37,   435,    43,   165,   438,   439,    52,    53,
      54,    55,    56,    57,    58,    43,    51,   177,    43,    54,
      39,    12,    13,    43,    48,    43,   186,    48,    43,    12,
      13,   191,    43,   193,   194,   195,    43,    28,   198,    30,
      31,    32,   202,    43,    35,    28,    37,    30,    31,    32,
     210,    43,    35,    38,    37,    43,    12,    13,    48,   219,
      51,    48,    38,    54,    43,    43,    12,    13,    51,    38,
      38,    54,    28,    38,    41,    31,    32,   237,    41,    35,
      41,    37,    28,    41,    12,    13,    32,    41,    38,    35,
      38,    37,    41,    38,    41,    51,    14,    15,    54,    41,
      28,    10,    21,    84,    86,    51,   266,    35,    54,    37,
     270,   350,   272,   273,    12,    13,   202,    -1,    -1,   165,
      -1,   281,    -1,    51,    -1,    43,    54,   287,    -1,    47,
      28,    -1,    50,    51,    52,    53,    -1,    35,    -1,    37,
      14,    15,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    51,    14,    15,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   325,   326,    14,    15,    43,
      -1,    -1,    -1,    47,    14,    15,    50,    51,    52,    53,
      -1,    -1,    -1,    43,    -1,    14,    15,    47,   348,    -1,
      50,    51,    52,    53,    -1,    -1,    43,   357,    -1,    -1,
      47,    41,    -1,    50,    51,    52,    53,    47,    14,    15,
      50,    51,    52,    53,    43,    14,    15,    -1,    47,   379,
     380,    50,    51,    52,    53,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,   393,   394,   395,    -1,    43,   398,    -1,
      -1,    47,    -1,   403,    50,    51,    52,    53,    47,    -1,
      49,    50,    51,    52,    53,    14,    15,    -1,    47,    -1,
      49,    50,    51,    52,    53,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    14,    15,   435,    -1,    -1,   438,   439,
      14,    15,    -1,    -1,    43,    -1,    -1,    -1,    47,    14,
      15,    50,    51,    52,    53,    43,    -1,    -1,    -1,    47,
      14,    15,    50,    51,    52,    53,    47,    -1,    49,    50,
      51,    52,    53,    47,    -1,    49,    50,    51,    52,    53,
      14,    15,    47,    -1,    49,    50,    51,    52,    53,    43,
      -1,    14,    15,    47,    -1,    -1,    50,    51,    52,    53,
      -1,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      14,    15,    -1,    47,    -1,    -1,    50,    51,    52,    53,
      43,    14,    15,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    43,    14,    15,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    -1,    47,    -1,    49,    50,    51,    52,    53,
      14,    15,    -1,    -1,    47,    -1,    49,    50,    51,    52,
      53,    43,    14,    15,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    47,    -1,    49,    50,    51,    52,    53,
      -1,    43,    14,    15,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    43,    -1,    38,    -1,    47,    14,    15,    50,
      51,    52,    53,    47,    -1,    -1,    50,    51,    52,    53,
      -1,    43,    14,    15,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    -1,    14,    15,    -1,    43,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    14,    15,    -1,
      -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    43,    14,    15,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    14,    15,    -1,    43,    -1,    -1,    -1,
      47,    14,    15,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    43,    14,    15,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    -1,    14,    15,    47,    -1,    49,    50,
      51,    52,    53,    -1,    47,    -1,    49,    50,    51,    52,
      53,    -1,    43,    14,    15,    -1,    47,    -1,    -1,    50,
      51,    52,    53,    43,    14,    15,    -1,    47,    -1,    -1,
      50,    51,    52,    53,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    14,    15,    50,
      51,    52,    53,    43,    14,    15,    -1,    47,    -1,    -1,
      50,    51,    52,    53,    43,    14,    15,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    -1,    43,    -1,    38,    -1,
      47,    14,    15,    50,    51,    52,    53,    47,    -1,    -1,
      50,    51,    52,    53,    43,    14,    15,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    -1,    14,    15,    -1,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    14,    15,    -1,    43,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    43,    14,    15,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    -1,    14,    15,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    14,    15,    -1,    -1,    43,    -1,    -1,    -1,    47,
      14,    15,    50,    51,    52,    53,    43,    14,    15,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    -1,    14,    15,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    14,    15,    47,    -1,    49,    50,    51,    52,    53,
      47,    -1,    49,    50,    51,    52,    53,    43,    14,    15,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    14,    15,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    51,    52,    53,    14,    15,
      -1,    47,    -1,    49,    50,    51,    52,    53,    14,    15,
      43,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    53,     0,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      58,    59,    35,    16,    17,    18,    19,    20,    21,    23,
      46,    60,    61,    35,    26,    27,    85,     0,    59,    12,
      13,    28,    37,    51,    54,    81,    82,    83,    84,    37,
      37,    37,    37,    37,    37,    37,    61,    28,    28,    81,
      83,    83,    14,    15,    47,    50,    51,    52,    53,    55,
      56,    35,    32,    33,    81,    81,    81,    81,    81,    38,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    24,
      40,    40,    43,    43,    43,    43,    43,    38,    81,    81,
      47,    63,    30,    32,    35,    47,    65,    71,    80,    71,
      29,    72,    81,    72,    39,    41,    43,    29,    43,    48,
      30,    80,    43,    43,    43,    43,    43,    32,    34,    12,
      35,    62,    81,    32,    48,    12,    30,    31,    64,    80,
      81,    12,    30,    31,    33,    66,    80,    81,    33,    66,
      30,    31,    73,    80,    47,    74,    42,    40,    35,    43,
      49,    81,    80,    43,    80,    48,    48,    44,    43,    44,
      43,    43,    30,    31,    80,    43,    81,    36,    62,    49,
      81,    81,    81,    66,    81,    66,    81,    12,    31,    75,
      80,    81,    48,    48,    75,    41,    43,    43,    43,    49,
      49,    45,    43,    45,    43,    37,    80,    48,    43,    25,
      81,    81,    43,    32,    80,    62,    64,    66,    64,    66,
      12,    30,    31,    33,    67,    80,    81,    80,    81,    12,
      31,    76,    80,    81,    49,    49,    76,    25,    40,    43,
      43,    43,    43,    43,    80,    48,    48,    44,    43,    25,
      49,    80,    48,    43,    43,    38,    36,    62,    81,    81,
      81,    81,    81,    81,    67,    81,    38,    81,    81,    81,
      39,    41,    43,    43,    43,    43,    43,    49,    49,    45,
      43,    49,    43,    43,    34,    81,    64,    64,    64,    67,
      81,    12,    30,    31,    68,    80,    81,    12,    77,    80,
      81,    77,    24,    38,    43,    43,    43,    43,    43,    80,
      48,    48,    43,    80,    43,    43,    41,    41,    81,    81,
      81,    81,    81,    81,    81,    81,    12,    35,    78,    81,
      78,    33,    43,    43,    43,    43,    43,    49,    49,    43,
      35,    43,    43,    40,    81,    64,    81,    68,    68,    81,
      81,    81,    81,    43,    43,    43,    43,    43,    43,    43,
      43,    38,    64,    81,    64,    81,    81,    12,    30,    31,
      69,    80,    81,    12,    35,    79,    81,    79,    39,    43,
      43,    43,    43,    43,    80,    48,    48,    43,    35,    43,
      43,    81,    81,    81,    81,    81,    81,    81,    81,    77,
      77,    43,    43,    43,    43,    43,    49,    49,    43,    43,
      43,    64,    64,    12,    30,    31,    70,    80,    81,    69,
      69,    70,    78,    78,    38,    43,    80,    48,    48,    38,
      43,    43,    38,    38,    38,    41,    81,    81,    81,    41,
      81,    81,    41,    41,    41,    43,    49,    49,    43,    43,
      70,    70,    70,    38,    38,    38,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     2,     1,     1,     2,     6,    14,    22,    17,    27,
      27,    31,    27,    31,    31,    27,    27,     1,     0,     1,
       1,     2,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     1,     1,     2,     4,     4,
       1,     1,     2,     4,     4,     1,     1,     2,     4,     4,
       1,     1,     2,     4,     4,     2,     5,     1,     1,     1,
       1,     1,     2,     5,     5,     1,     1,     2,     2,     5,
       4,     1,     1,     2,     4,     1,     1,     2,     1,     1,
       2,     1,     1,     2,     1,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     3,     3,
       3,     1,     1,     2,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4:
#line 57 "conv-c2c.y"
            {
		printf("reading line %d\n",y_lineno);
        }
#line 1816 "y.tab.c"
    break;

  case 5:
#line 60 "conv-c2c.y"
                {
          fprintf(ofile, "%s\n", yytext);
        }
#line 1824 "y.tab.c"
    break;

  case 6:
#line 63 "conv-c2c.y"
                                    { /* reset conf[][] */
          printf("==EMAX6AB reading line=%d name=%s\n", y_lineno, id[yyvsp[-1]].name);
          current_prefix  = yyvsp[-1];
          current_mapdist = id[yyvsp[0]].val;
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
#line 1851 "y.tab.c"
    break;

  case 7:
#line 85 "conv-c2c.y"
                                  {
        }
#line 1858 "y.tab.c"
    break;

  case 8:
#line 87 "conv-c2c.y"
                    {
	  emit_emax6a(0);
	  hash_clear();
        }
#line 1867 "y.tab.c"
    break;

  case 9:
#line 91 "conv-c2c.y"
                      {
	  emit_emax6a(1);
	  hash_clear();
        }
#line 1876 "y.tab.c"
    break;

  case 10:
#line 95 "conv-c2c.y"
                               { /* reset tconf[][] */
          printf("==EMAX6TB reading line=%d name=%s\n", y_lineno, id[yyvsp[0]].name);
          current_prefix = yyvsp[0];
          trans_pc = 0;
	  bzero(&trans, sizeof(trans));
	  bzero(&tconf, sizeof(tconf));
	}
#line 1888 "y.tab.c"
    break;

  case 11:
#line 102 "conv-c2c.y"
                                  {
	}
#line 1895 "y.tab.c"
    break;

  case 12:
#line 104 "conv-c2c.y"
                    {
	  emit_emax6t(0);
	  hash_clear();
	}
#line 1904 "y.tab.c"
    break;

  case 13:
#line 110 "conv-c2c.y"
                        {
        }
#line 1911 "y.tab.c"
    break;

  case 14:
#line 112 "conv-c2c.y"
                                {
        }
#line 1918 "y.tab.c"
    break;

  case 15:
#line 116 "conv-c2c.y"
                                                       {
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
	  insn[last_insn].iexe.src1h   = yyvsp[-3];
	  insn[last_insn].iexe.src1s   = -1; /* no suffix */
	  insn[last_insn].iexe.src1e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.src2v   = T_IMMEDIATE; /* variable */
	  insn[last_insn].iexe.src2h   = yyvsp[-2]; /* -1 */
	  insn[last_insn].iexe.src2s   = -1; /* no suffix */
	  insn[last_insn].iexe.src2e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.exedv   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.exedh   = yyvsp[-3];
	  insn[last_insn].iexe.exeds   = -1; /* no suffix */
          last_insn++;
	}
#line 1947 "y.tab.c"
    break;

  case 16:
#line 140 "conv-c2c.y"
                                                                                  {
	  if (id[yyvsp[-9]].val != 0) {
	    fprintf(stderr, "in %s: for(CHIP=0;;) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
          current_nchip = id[yyvsp[-5]].val; /* should be <= EMAX_NCHIP */
	  if (current_nchip > EMAX_NCHIP) {
	    fprintf(stderr, "in %s: for(;CHIP<NCHIP;) NCHIP(%d) should be <= EMAX_NCHIP(%d)\n", id[current_prefix].name, current_nchip, EMAX_NCHIP);
            exit(1);
	  }
	  fprintf(ofile, "\t  ((struct reg_ctrl*)emax6.reg_ctrl)->i[0].mcid = %d; // NCHIP-1\n", current_nchip-1);
	}
#line 1964 "y.tab.c"
    break;

  case 17:
#line 152 "conv-c2c.y"
                                                                                                                                   {
	  int loop_no = id[yyvsp[-19]].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no > 1) {
	    fprintf(stderr, "in %s: for() is limited to INIT0 or INIT1\n", id[current_prefix].name);
            exit(1);
	  }
	  if (loop_no != id[ yyvsp[-15]].val || loop_no != id[yyvsp[-7]].val || loop_no != id[yyvsp[-4]].val || loop_no != id[yyvsp[-15]].val) {
	    fprintf(stderr, "in %s: for() includes INIT#/LOOP# mismatch\n", id[current_prefix].name);
            exit(1);
	  }
	  if (id[yyvsp[-17]].val != 1 || id[yyvsp[-2]].val != 0) {
	    fprintf(stderr, "in %s: for(INIT#=1,...; LOOP#--; INIT#=0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  fprintf(ofile, "\t%s = %s;\n", id[ yyvsp[-15]].name, id[ yyvsp[-13]].name);
	  if (id[yyvsp[-11]].cidx) {
	    int c, len, i; char *buf;
	    len = strlen(id[yyvsp[-9]].name);
	    buf = malloc(len+1);
	    buf[len] = 0;
	    for (c=0; c<current_nchip; c++) {
	      strncpy(buf, id[yyvsp[-9]].name, len);
	      for (i=0; i<len; i++) {
		if (!strncmp(id[yyvsp[-9]].name+i, "CHIP", 4)) {
		  *(buf+i+0) = ' ';
		  *(buf+i+1) = ' ';
		  *(buf+i+2) = ' ';
		  *(buf+i+3) = '0'+c;
		  i += 4;
		}
	      }
	      fprintf(ofile, "\t%s[%d] = %s;\n", id[yyvsp[-11]].name, c, buf);
	    }
	    free(buf);
	  }
	  else
	    fprintf(ofile, "\t%s = %s;\n", id[yyvsp[-11]].name, id[yyvsp[-9]].name);
	  insn[last_insn].iheader.type = 2; /* FOR */
	  insn[last_insn].iheader.row  = 0; /* top */
	  insn[last_insn].iheader.col  = loop_no;
	  insn[last_insn].iexe.op1     = OP_FOR;
	  insn[last_insn].iexe.updt    = 1;
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.src1h   = yyvsp[-7];
	  insn[last_insn].iexe.src1s   = -1; /* no suffix */
	  insn[last_insn].iexe.src1e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.src2v   = T_IMMEDIATE; /* variable */
	  insn[last_insn].iexe.src2h   = yyvsp[-6]; /* -1 */
	  insn[last_insn].iexe.src2s   = -1; /* no suffix */
	  insn[last_insn].iexe.src2e   = EXP_H3210; /* full */
	  insn[last_insn].iexe.exedv   = T_VARIABLE; /* variable */
	  insn[last_insn].iexe.exedh   = yyvsp[-7];
	  insn[last_insn].iexe.exeds   = -1; /* no suffix */
          last_insn++;
	}
#line 2029 "y.tab.c"
    break;

  case 18:
#line 212 "conv-c2c.y"
                                                                                                         {
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 3; /* CEX */
	  insn[last_insn].iheader.row  = -1;
	  insn[last_insn].iheader.col  = -1;
	  insn[last_insn].icex.op      = id[ yyvsp[-14]].val;
	  insn[last_insn].icex.bit0v   = id[yyvsp[-4]].type;
	  insn[last_insn].icex.bit0h   = yyvsp[-4];
	  insn[last_insn].icex.bit1v   = id[yyvsp[-6]].type;
	  insn[last_insn].icex.bit1h   = yyvsp[-6];
	  insn[last_insn].icex.bit2v   = id[ yyvsp[-8]].type;
	  insn[last_insn].icex.bit2h   = yyvsp[-8];
	  insn[last_insn].icex.bit3v   = id[ yyvsp[-10]].type;
	  insn[last_insn].icex.bit3h   = yyvsp[-10];
	  insn[last_insn].icex.table   = id[yyvsp[-2]].val;
	  insn[last_insn].icex.cexdv   = id[ yyvsp[-12]].type;
	  insn[last_insn].icex.cexdh   = yyvsp[-12];
          last_insn++;
        }
#line 2056 "y.tab.c"
    break;

  case 19:
#line 234 "conv-c2c.y"
                                                                                                                                                          {
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &BR[r][c], NULL); followed by next ex */
	  /* ex4(op1, &BR[r-1][c1], &BR[r-1][c2], &BR[r-1][c3], op2, IMM, op3, IMM, &AR[r],    NULL); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[ yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-22]].type==T_ALRNO?(        -1):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
	  insn[last_insn].iexe.src1s   = 4; /* all suffix */
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[yyvsp[-16]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-16];
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.src5s   = 4; /* all suffix */
	  insn[last_insn].iexe.exedv   = id[yyvsp[-22]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-22];
	  insn[last_insn].iexe.exeds   = 4; /* all suffix */
          last_insn++;
        }
#line 2099 "y.tab.c"
    break;

  case 20:
#line 272 "conv-c2c.y"
                                                                                                                                                            {
	  /* ex4(OP_SFMA, &b00, b00, EXP_H3210, BR[r][1], EXP_H3210, BR[r][2], EXP_H3210, OP_NOP, 0LL, OP_NOP, 32LL) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[ yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val)                :id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-22]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[yyvsp[-16]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-16];
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.exedv   = id[yyvsp[-22]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-22];
          last_insn++;
        }
#line 2138 "y.tab.c"
    break;

  case 21:
#line 306 "conv-c2c.y"
                                                                                                                                                                                    {
	  /* ex4(OP_SFMA, &b00, INIT0?b00:b00, EXP_H3210, BR[r][1], EXP_H3210, BR[r][2], EXP_H3210, OP_NOP, 0LL, OP_NOP, 32LL) */
	  int loop_no0 = id[yyvsp[-24]].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if (yyvsp[-22] != yyvsp[-20]) {
	    fprintf(stderr, "in %s: exe(INIT0?src1:src1) src1 should be the same\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[ yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-28]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-26] == yyvsp[-22])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 1; /* activate INIT0?src1 */
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-22]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-22];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[ yyvsp[-16]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-16];
	  insn[last_insn].iexe.src2s   = 4; /* all suffix */
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3s   = 4; /* all suffix */
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src4s   = 4; /* all suffix */
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.exedv   = id[yyvsp[-26]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-26];
          last_insn++;
        }
#line 2186 "y.tab.c"
    break;

  case 22:
#line 349 "conv-c2c.y"
                                                                                                                                                               {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[ yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val)                :id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-22]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[yyvsp[-16]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-16];
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.exedv   = id[yyvsp[-22]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-22];
          last_insn++;
        }
#line 2223 "y.tab.c"
    break;

  case 23:
#line 381 "conv-c2c.y"
                                                                                                                                                                                       {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
	  int loop_no0 = id[yyvsp[-24]].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if (yyvsp[-22] != yyvsp[-20]) {
	    fprintf(stderr, "in %s: exe(INIT0?src1:src1) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[ yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-28]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-26] == yyvsp[-22])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 1; /* activate INIT0?src1 */
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-22]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-22];
	  insn[last_insn].iexe.src1e   = id[yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[yyvsp[-16]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-16];
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.exedv   = id[yyvsp[-26]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-26];
          last_insn++;
        }
#line 2269 "y.tab.c"
    break;

  case 24:
#line 422 "conv-c2c.y"
                                                                                                                                                                                   {
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &BR[r][c][s]); followed by next ex */
	  /* exe(op1, BR[r-1][c1][s], BR[r-1][c2][s], BR[r-1][c3][s], op2, IMM, op3, IMM, &AR[r][c]   ); followed by store(automatic allocating) */
	  int loop_no0 = id[yyvsp[-20]].val;
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  if (loop_no0 != 0) {
	    fprintf(stderr, "in %s: exe(INIT0) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  if (id[yyvsp[-16]].val != 0) {
	    fprintf(stderr, "in %s: exe(INIT0?src2:expr) expr should be zero\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 5; /* EXE */
	  insn[last_insn].iheader.row  = id[ yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[ yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-28]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-26] == yyvsp[-24])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 2; /* activate s2+INIT0 */
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-24]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-24];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-22]].val;
	  insn[last_insn].iexe.src2v   = id[yyvsp[-18]].type;
	  insn[last_insn].iexe.src2h   = yyvsp[-18];
	  insn[last_insn].iexe.src2e   = id[yyvsp[-14]].val;
	  insn[last_insn].iexe.src3v   = id[yyvsp[-12]].type;
	  insn[last_insn].iexe.src3h   = yyvsp[-12];
	  insn[last_insn].iexe.src3e   = id[yyvsp[-10]].val;
	  insn[last_insn].iexe.src4v   = id[yyvsp[-6]].type;
	  insn[last_insn].iexe.src4h   = yyvsp[-6];
	  insn[last_insn].iexe.src5v   = id[yyvsp[-2]].type;
	  insn[last_insn].iexe.src5h   = yyvsp[-2];
	  insn[last_insn].iexe.exedv   = id[yyvsp[-26]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-26];
          last_insn++;
        }
#line 2315 "y.tab.c"
    break;

  case 25:
#line 463 "conv-c2c.y"
                                                                                                                                                                      {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 6; /* MO4 */
	  insn[last_insn].iheader.row  = id[yyvsp[-20]].type==T_ALRNO?(id[yyvsp[-20]].val):id[yyvsp[-20]].type==T_BDRNO?(id[yyvsp[-20]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-20]].type==T_ALRNO?(        -1):id[yyvsp[-20]].type==T_BDRNO?(id[yyvsp[-20]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ yyvsp[-24]].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ yyvsp[-24]].val);
	  insn[last_insn].imop.exv     = id[ yyvsp[-22]].type;
	  insn[last_insn].imop.exh     = yyvsp[-22];
	  insn[last_insn].imop.mopdv   = id[ yyvsp[-20]].type;
	  insn[last_insn].imop.mopdh   = yyvsp[-20];
	  insn[last_insn].imop.mopds   = 4; /* all suffix */
	  insn[last_insn].imop.basev   = id[ yyvsp[-18]].type;
	  insn[last_insn].imop.baseh   = yyvsp[-18];
	  insn[last_insn].imop.offsv   = id[yyvsp[-16]].type;
	  insn[last_insn].imop.offsh   = yyvsp[-16];
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
	  insn[last_insn].imop.offsm   = id[yyvsp[-14]].val;
	  insn[last_insn].imop.topv    = id[yyvsp[-12]].type;
	  insn[last_insn].imop.toph    = yyvsp[-12];
	  insn[last_insn].imop.lenv    = id[yyvsp[-10]].type;
	  insn[last_insn].imop.lenh    = yyvsp[-10];
	  insn[last_insn].imop.blk     = id[yyvsp[-8]].val;
	  insn[last_insn].imop.forcev  = id[yyvsp[-6]].type; /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.forceh  = yyvsp[-6];          /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.ptopv   = id[yyvsp[-4]].type;
	  insn[last_insn].imop.ptoph   = yyvsp[-4];
	  insn[last_insn].imop.plenv   = id[yyvsp[-2]].type;
	  insn[last_insn].imop.plenh   = yyvsp[-2];
          last_insn++;
        }
#line 2389 "y.tab.c"
    break;

  case 26:
#line 532 "conv-c2c.y"
                                                                                                                                                                      {
	  /* mop(load,  ex, BR[r][c][s], single_reg, offset, offset_mask, stream_top, length, block, force, ptop, plen); load requires target regs */
	  /* mop(store, ex, AR[r][c][s], single_reg, offset, offset_mask, stream_top, length, , blockforce, ptop, plen); store requires current ex */
          if (last_insn >= INSN_DEPTH) {
	    fprintf(stderr, "in %s: last_insn exceeds INSN_DEPTH=%d\n", id[current_prefix].name, INSN_DEPTH);
            exit(1);
          }
	  insn[last_insn].iheader.type = 7; /* MOP */
	  insn[last_insn].iheader.row  = id[yyvsp[-20]].type==T_ALRNO?(id[yyvsp[-20]].val)                :id[yyvsp[-20]].type==T_BDRNO?(id[yyvsp[-20]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-20]].type==T_ALRNO?(insn[last_insn].imop.mopds):id[yyvsp[-20]].type==T_BDRNO?(id[yyvsp[-20]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].imop.op      = id[ yyvsp[-24]].val;
	  insn[last_insn].imop.mtype   = get_mop_type(id[ yyvsp[-24]].val);
	  insn[last_insn].imop.exv     = id[ yyvsp[-22]].type;
	  insn[last_insn].imop.exh     = yyvsp[-22];
	  insn[last_insn].imop.mopdv   = id[ yyvsp[-20]].type;
	  insn[last_insn].imop.mopdh   = yyvsp[-20];
	  insn[last_insn].imop.basev   = id[ yyvsp[-18]].type;
	  insn[last_insn].imop.baseh   = yyvsp[-18];
	  insn[last_insn].imop.offsv   = id[yyvsp[-16]].type;
	  insn[last_insn].imop.offsh   = yyvsp[-16];
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
	  insn[last_insn].imop.offsm   = id[yyvsp[-14]].val;
	  insn[last_insn].imop.topv    = id[yyvsp[-12]].type;
	  insn[last_insn].imop.toph    = yyvsp[-12];
	  insn[last_insn].imop.lenv    = id[yyvsp[-10]].type;
	  insn[last_insn].imop.lenh    = yyvsp[-10];
	  insn[last_insn].imop.blk     = id[yyvsp[-8]].val;
	  insn[last_insn].imop.forcev  = id[yyvsp[-6]].type; /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.forceh  = yyvsp[-6];          /* OP_LDは変数OK(lmr/lmp動的切替えOK), OP_STは定数のみ(lmw/lmxの動的切替えNG) */
	  insn[last_insn].imop.ptopv   = id[yyvsp[-4]].type;
	  insn[last_insn].imop.ptoph   = yyvsp[-4];
	  insn[last_insn].imop.plenv   = id[yyvsp[-2]].type;
	  insn[last_insn].imop.plenh   = yyvsp[-2];
          last_insn++;
        }
#line 2453 "y.tab.c"
    break;

  case 27:
#line 591 "conv-c2c.y"
              {
        }
#line 2460 "y.tab.c"
    break;

  case 28:
#line 593 "conv-c2c.y"
          {
        }
#line 2467 "y.tab.c"
    break;

  case 29:
#line 597 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2475 "y.tab.c"
    break;

  case 30:
#line 600 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 2483 "y.tab.c"
    break;

  case 31:
#line 603 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 2491 "y.tab.c"
    break;

  case 32:
#line 608 "conv-c2c.y"
                    {
          yyval = yyvsp[0];
        }
#line 2499 "y.tab.c"
    break;

  case 33:
#line 613 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2507 "y.tab.c"
    break;

  case 34:
#line 616 "conv-c2c.y"
                    { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2515 "y.tab.c"
    break;

  case 35:
#line 619 "conv-c2c.y"
                             { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2523 "y.tab.c"
    break;

  case 36:
#line 622 "conv-c2c.y"
                { /* AR[r] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2531 "y.tab.c"
    break;

  case 37:
#line 625 "conv-c2c.y"
                { /* BR[r][c] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2539 "y.tab.c"
    break;

  case 38:
#line 630 "conv-c2c.y"
                     { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2547 "y.tab.c"
    break;

  case 39:
#line 633 "conv-c2c.y"
                { /* AR[r] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2555 "y.tab.c"
    break;

  case 40:
#line 638 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
        }
#line 2564 "y.tab.c"
    break;

  case 41:
#line 642 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
	}
#line 2573 "y.tab.c"
    break;

  case 42:
#line 646 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
	}
#line 2582 "y.tab.c"
    break;

  case 43:
#line 650 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src1s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2591 "y.tab.c"
    break;

  case 44:
#line 654 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src1s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2600 "y.tab.c"
    break;

  case 45:
#line 660 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
        }
#line 2609 "y.tab.c"
    break;

  case 46:
#line 664 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
	}
#line 2618 "y.tab.c"
    break;

  case 47:
#line 668 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
	}
#line 2627 "y.tab.c"
    break;

  case 48:
#line 672 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src2s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2636 "y.tab.c"
    break;

  case 49:
#line 676 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src2s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2645 "y.tab.c"
    break;

  case 50:
#line 682 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
        }
#line 2654 "y.tab.c"
    break;

  case 51:
#line 686 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
	}
#line 2663 "y.tab.c"
    break;

  case 52:
#line 690 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
	}
#line 2672 "y.tab.c"
    break;

  case 53:
#line 694 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src3s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2681 "y.tab.c"
    break;

  case 54:
#line 698 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src3s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2690 "y.tab.c"
    break;

  case 55:
#line 704 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
        }
#line 2699 "y.tab.c"
    break;

  case 56:
#line 708 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
	}
#line 2708 "y.tab.c"
    break;

  case 57:
#line 712 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
	}
#line 2717 "y.tab.c"
    break;

  case 58:
#line 716 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src4s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2726 "y.tab.c"
    break;

  case 59:
#line 720 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src4s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2735 "y.tab.c"
    break;

  case 60:
#line 726 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
        }
#line 2744 "y.tab.c"
    break;

  case 61:
#line 730 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
	}
#line 2753 "y.tab.c"
    break;

  case 62:
#line 734 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
	}
#line 2762 "y.tab.c"
    break;

  case 63:
#line 738 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src5s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2771 "y.tab.c"
    break;

  case 64:
#line 742 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src5s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2780 "y.tab.c"
    break;

  case 65:
#line 748 "conv-c2c.y"
                         { /* &var */
	  insn[last_insn].iexe.exeds = -1;
          yyval = yyvsp[0];
        }
#line 2789 "y.tab.c"
    break;

  case 66:
#line 752 "conv-c2c.y"
                                 { /* &AR[r][s] */
	  insn[last_insn].iexe.exeds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2798 "y.tab.c"
    break;

  case 67:
#line 758 "conv-c2c.y"
              {
          yyval = yyvsp[0];
        }
#line 2806 "y.tab.c"
    break;

  case 68:
#line 761 "conv-c2c.y"
                { /* exx */
          yyval = yyvsp[0];
	}
#line 2814 "y.tab.c"
    break;

  case 69:
#line 766 "conv-c2c.y"
                       { /* for load/store */
          yyval = yyvsp[0];
	}
#line 2822 "y.tab.c"
    break;

  case 70:
#line 769 "conv-c2c.y"
                { /* for store */
          yyval = yyvsp[0];
	}
#line 2830 "y.tab.c"
    break;

  case 71:
#line 772 "conv-c2c.y"
                { /* for load */
          yyval = yyvsp[0];
        }
#line 2838 "y.tab.c"
    break;

  case 72:
#line 777 "conv-c2c.y"
                           { /* for load/store */
	  insn[last_insn].imop.mopds = -1;
          yyval = yyvsp[0];
	}
#line 2847 "y.tab.c"
    break;

  case 73:
#line 781 "conv-c2c.y"
                                 { /* for store */
	  insn[last_insn].imop.mopds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2856 "y.tab.c"
    break;

  case 74:
#line 785 "conv-c2c.y"
                                 { /* for load */
	  insn[last_insn].imop.mopds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
        }
#line 2865 "y.tab.c"
    break;

  case 75:
#line 791 "conv-c2c.y"
                {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
        }
#line 2874 "y.tab.c"
    break;

  case 76:
#line 795 "conv-c2c.y"
                    {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
	}
#line 2883 "y.tab.c"
    break;

  case 77:
#line 799 "conv-c2c.y"
                             {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
	}
#line 2892 "y.tab.c"
    break;

  case 78:
#line 803 "conv-c2c.y"
                              {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[-1];
	}
#line 2902 "y.tab.c"
    break;

  case 79:
#line 808 "conv-c2c.y"
                                               {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[-2];
	}
#line 2912 "y.tab.c"
    break;

  case 80:
#line 813 "conv-c2c.y"
                             {
	  insn[last_insn].imop.bases = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2921 "y.tab.c"
    break;

  case 81:
#line 819 "conv-c2c.y"
                  {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
        }
#line 2930 "y.tab.c"
    break;

  case 82:
#line 823 "conv-c2c.y"
                    {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
	}
#line 2939 "y.tab.c"
    break;

  case 83:
#line 827 "conv-c2c.y"
                             {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
	}
#line 2948 "y.tab.c"
    break;

  case 84:
#line 831 "conv-c2c.y"
                             {
	  insn[last_insn].imop.offss = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2957 "y.tab.c"
    break;

  case 85:
#line 837 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2965 "y.tab.c"
    break;

  case 86:
#line 840 "conv-c2c.y"
                    {
          yyval = yyvsp[0];
	}
#line 2973 "y.tab.c"
    break;

  case 87:
#line 843 "conv-c2c.y"
                             {
          yyval = yyvsp[0];
	}
#line 2981 "y.tab.c"
    break;

  case 88:
#line 848 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2989 "y.tab.c"
    break;

  case 89:
#line 851 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 2997 "y.tab.c"
    break;

  case 90:
#line 854 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 3005 "y.tab.c"
    break;

  case 91:
#line 859 "conv-c2c.y"
             {
          yyval = yyvsp[0];
        }
#line 3013 "y.tab.c"
    break;

  case 92:
#line 862 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 3021 "y.tab.c"
    break;

  case 93:
#line 865 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 3029 "y.tab.c"
    break;

  case 94:
#line 870 "conv-c2c.y"
                 {
          /*id[$1].chip = 1;*/
          yyval = yyvsp[0];
        }
#line 3038 "y.tab.c"
    break;

  case 95:
#line 874 "conv-c2c.y"
                                {
	  id[yyvsp[-3]].cidx = 1;
          yyval = yyvsp[-3];
	}
#line 3047 "y.tab.c"
    break;

  case 96:
#line 878 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 3055 "y.tab.c"
    break;

  case 97:
#line 882 "conv-c2c.y"
            {
          yyval = yyvsp[0];
        }
#line 3063 "y.tab.c"
    break;

  case 98:
#line 885 "conv-c2c.y"
                        {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")+(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val + id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3081 "y.tab.c"
    break;

  case 99:
#line 898 "conv-c2c.y"
                        {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")-(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val - id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3099 "y.tab.c"
    break;

  case 100:
#line 911 "conv-c2c.y"
                             {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")<<(",      BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val << id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3117 "y.tab.c"
    break;

  case 101:
#line 924 "conv-c2c.y"
                             {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")>>(",      BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val >> id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3135 "y.tab.c"
    break;

  case 102:
#line 937 "conv-c2c.y"
                        {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")&(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val & id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3153 "y.tab.c"
    break;

  case 103:
#line 950 "conv-c2c.y"
                        {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")^(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val ^ id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3171 "y.tab.c"
    break;

  case 104:
#line 963 "conv-c2c.y"
                        {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")|(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val | id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3189 "y.tab.c"
    break;

  case 105:
#line 978 "conv-c2c.y"
              {
          yyval = yyvsp[0];
        }
#line 3197 "y.tab.c"
    break;

  case 106:
#line 981 "conv-c2c.y"
                     {
          int hashval;
	  strncpy(buf, "~(",        BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = ~ id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3213 "y.tab.c"
    break;

  case 107:
#line 992 "conv-c2c.y"
                     {
          int hashval;
	  strncpy(buf, "-(",        BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = - id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3229 "y.tab.c"
    break;

  case 108:
#line 1003 "conv-c2c.y"
                          {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")*(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val * id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3247 "y.tab.c"
    break;

  case 109:
#line 1016 "conv-c2c.y"
                          {
          int hashval;
	  strncpy(buf, "(",         BUF_MAXLEN-1);
	  strncat(buf, id[yyvsp[-2]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")/(",       BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, id[yyvsp[0]].name, BUF_MAXLEN-strlen(buf)-1);
	  strncat(buf, ")",         BUF_MAXLEN-strlen(buf)-1);
	  if (!hash_search(buf, &hashval)) { /* not found */
	    id[hashval].type = T_IMMEDIATE;
	    id[hashval].val = id[yyvsp[-2]].val / id[yyvsp[0]].val;
	  }
          yyval = hashval;
        }
#line 3265 "y.tab.c"
    break;

  case 110:
#line 1031 "conv-c2c.y"
                      {
          yyval = yyvsp[-1];
        }
#line 3273 "y.tab.c"
    break;

  case 111:
#line 1034 "conv-c2c.y"
                 {
          yyval = yyvsp[0];
        }
#line 3281 "y.tab.c"
    break;

  case 112:
#line 1039 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
        }
#line 3289 "y.tab.c"
    break;

  case 113:
#line 1042 "conv-c2c.y"
                             {
          yyval = yyvsp[0];
        }
#line 3297 "y.tab.c"
    break;

  case 114:
#line 1045 "conv-c2c.y"
                              {
          yyval = yyvsp[0];
        }
#line 3305 "y.tab.c"
    break;

  case 115:
#line 1050 "conv-c2c.y"
                       {
          trans[trans_pc].rw = 0; /* READ */
	}
#line 3313 "y.tab.c"
    break;

  case 116:
#line 1053 "conv-c2c.y"
                     {
          trans[trans_pc].rw = 1; /* WRITE */
        }
#line 3321 "y.tab.c"
    break;


#line 3325 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1058 "conv-c2c.y"



