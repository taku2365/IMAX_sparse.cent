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
#define YYLAST   1277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  449

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,     2,    46,     2,
      36,    37,    54,    49,    42,    50,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    40,
      41,    39,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    52,    45,    53,     2,     2,     2,
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
      35
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
  "CGRA_MO4", "CGRA_MOP", "CGRA_DECR", "CGRA_INCR", "TRAN_READ",
  "TRAN_WRITE", "IMMEDIATE", "EXRNO", "ALRNO", "BDRNO", "CHIP", "INITNO",
  "LOOPNO", "VARIABLE", "ASIS", "'('", "')'", "'{'", "'='", "';'", "'<'",
  "','", "'?'", "':'", "'}'", "'&'", "'['", "']'", "'+'", "'-'", "'^'",
  "'|'", "'~'", "'*'", "'/'", "$accept", "program", "line", "EMAX6ABODY",
  "EMAX6AUNIT", "cex_src", "cex_dst", "ex4_src", "ex4_dstd", "exe_src1",
  "exe_src2", "exe_src3", "exe_src4", "exe_src5", "exe_dstd", "mop_ex",
  "mo4_srcdst", "mop_srcdst", "mop_base", "mop_offset", "mop_top",
  "mop_len", "force", "XVARIABLE", "expr", "term", "factor", "number",
  "EMAX6TBODY", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,    40,    41,   123,    61,
      59,    60,    44,    63,    58,   125,    38,    91,    93,    43,
      45,    94,   124,   126,    42,    47
};
# endif

#define YYPACT_NINF (-392)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     667,  -392,  -392,    24,    -8,  -392,  -392,    45,    62,  -392,
     189,  -392,   251,    58,    82,    87,    93,    95,    99,   102,
    -392,    -8,  -392,  -392,  -392,  -392,  -392,  -392,  -392,   115,
     125,  -392,   251,    59,    59,   722,   -39,  -392,  -392,   123,
      -5,   251,   251,   251,   251,   251,  -392,  -392,  -392,    76,
    -392,  -392,   251,   251,   251,   251,   251,   251,   251,    59,
      59,   137,   134,   139,     4,   220,   398,   551,   569,  -392,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,  -392,  -392,   129,
     251,   251,   130,    86,   141,    53,    53,   145,   301,   584,
     156,   159,  -392,  -392,   155,    90,   161,   171,  -392,   174,
    -392,   180,   722,   195,  -392,   208,   207,  -392,   127,   210,
     196,  -392,   138,     9,   215,   245,   213,   212,   209,   -10,
    -392,   214,   722,   219,   251,    36,  -392,  -392,   231,  -392,
     722,    36,   230,   233,   238,   249,  -392,   722,   254,   256,
    -392,  -392,   258,  -392,   265,   261,   251,   267,  -392,   127,
    -392,   383,  -392,   251,  -392,   251,   251,   365,   251,   365,
     251,    80,   259,   262,  -392,    80,   592,   263,   269,  -392,
     610,   599,   654,   274,   665,   279,   676,   128,   281,   288,
     309,   722,   251,   251,   297,   311,    -6,   127,   138,  -392,
    -392,   365,   138,   365,   295,    -6,  -392,   251,   537,  -392,
     694,   705,   537,   316,   305,   304,   307,   312,   314,   320,
      36,   319,   322,   327,   329,  -392,   722,   348,   715,    36,
     332,   334,  -392,   722,  -392,  -392,   338,   347,   354,   127,
     251,   251,   251,   251,  -392,   251,   251,   430,   251,   353,
    -392,  -392,   251,   251,   251,   355,   360,   368,   733,   744,
     755,   766,   773,   784,   358,   795,  -392,   812,   824,   835,
    -392,   374,   251,   138,   138,   138,   430,  -392,  -392,   251,
     455,  -392,   202,   202,   388,   842,   372,   378,   380,   382,
     853,    36,   369,   381,   394,  -392,   722,    36,   396,  -392,
     722,   397,   390,   401,   251,   251,   251,   251,   251,  -392,
     251,   251,   251,  -392,   475,   475,   413,  -392,   868,   882,
     893,   907,   922,   932,   940,   951,    30,  -392,   410,   722,
     414,   424,   251,   138,   251,   455,   455,  -392,  -392,   251,
    -392,   251,   251,   251,   962,   423,   980,   427,   429,   991,
    1002,  1013,  1020,   138,   251,   138,   251,   251,   465,   542,
     542,   434,   431,  1031,   432,  1046,  1060,    36,   428,   443,
     439,  -392,   722,    48,  -392,   451,   722,   456,  -392,   251,
     251,   251,   251,   251,  -392,   251,   251,   251,  -392,   202,
     202,  1071,  1085,  1100,  1111,  1124,  1133,  1140,  1153,   458,
     461,   138,   138,   508,   465,   465,  -392,  -392,   508,   475,
     475,   467,   464,    36,   460,   463,   476,  -392,   722,   470,
     472,   479,   480,   482,   436,   251,  -392,   251,   251,   483,
     251,   251,   484,   487,   489,  -392,  1179,  1163,  1186,  -392,
    1202,  1225,  -392,  -392,  -392,   508,  -392,  -392,   508,   508,
     485,   494,   497,   496,   500,   503,  -392,  -392,  -392
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
    -392,  -392,   535,  -392,   525,  -145,  -392,  -187,  -392,  -108,
    -214,  -226,  -290,  -391,   468,   462,  -392,  -392,   386,   351,
    -271,  -302,   206,   260,   -12,   154,     1,  -392,  -392
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
      35,   206,   291,   320,   168,   208,   139,   411,    13,    14,
      15,    16,    17,    18,    19,    59,    60,    47,    52,    53,
      49,   131,    30,   254,   148,    93,    62,    63,    94,    64,
      65,    66,    67,    68,    50,    51,    31,    20,   132,   133,
      93,   134,   205,    94,   440,    32,    82,   441,   442,   173,
      54,   175,   279,    55,    56,    57,    58,    47,    12,    33,
      77,    78,    34,    47,   330,    29,    30,    93,    88,    89,
      94,    29,    30,   102,   102,    47,   276,   277,   278,    23,
      31,   100,   378,   207,   247,   209,    31,    24,    25,    32,
      52,    53,   177,    30,    39,    32,   122,   412,   413,   337,
     338,   137,   137,    33,   409,   410,    34,    31,   389,   390,
     178,    93,   151,    69,    94,    92,    32,    93,    40,   110,
      94,    93,    54,    41,    94,    55,    56,    57,    58,    42,
      33,    43,    95,    34,   166,    44,   335,   122,    45,   119,
      30,   170,    47,   171,   172,   137,   174,   137,   176,   181,
     125,    30,    48,   181,    31,    47,   352,    61,   354,    93,
      79,   120,    94,    32,   195,    31,    87,   126,   127,    93,
     200,   201,    94,    80,    32,   122,    90,    33,    81,   137,
      34,   137,   216,   104,   107,   218,   223,    95,    33,    27,
     223,    34,     1,     2,     3,     4,     5,     6,     7,     8,
       9,   108,   109,   112,   401,   402,    70,    71,    72,    73,
      74,    75,    76,   113,   287,    30,   114,   122,   248,   249,
     250,   251,   115,   252,   253,   216,   255,   131,    30,    31,
     257,   258,   259,    93,    52,    53,    94,   116,    32,   117,
     118,   123,    31,   124,   132,   133,    93,   138,   147,    94,
     275,    32,    33,   146,   216,    34,   149,   280,   286,   144,
     290,   290,    83,    29,    30,    33,    54,   150,    34,    55,
      56,    57,    58,   153,   140,   141,    93,   155,    31,    94,
     156,   157,   308,   309,   310,   311,   312,    32,   313,   314,
     315,   158,   319,   319,   162,   163,    93,   159,   160,    94,
     161,    33,   167,   165,    34,   186,   182,   210,    30,   183,
     334,   187,   336,   286,   286,    52,    53,   339,   191,   340,
     341,   342,    31,   193,   211,   212,    93,   213,   197,    94,
     198,    32,   353,   199,   355,   356,   362,   366,   366,   202,
     227,   105,   203,    98,   228,    33,   229,    54,    34,   230,
      55,    56,    57,    58,   231,   111,   232,   381,   382,   383,
     384,   385,   233,   386,   387,   388,   235,   290,   290,   236,
     237,   238,   239,   136,   136,   143,   243,   131,    30,   242,
     244,   408,   362,   362,   245,   152,   408,   319,   319,   246,
     256,   154,    31,   260,   132,   133,    93,    52,    53,    94,
     261,    32,   269,   426,   164,   427,   428,   274,   430,   431,
     262,   292,    52,    53,   294,    33,   300,   136,    34,   136,
     295,   180,   296,   408,   297,   180,   408,   408,   301,    54,
     306,   169,    55,    56,    57,    58,   302,   196,   304,   305,
      84,   307,   210,    30,    54,   321,   204,    55,    56,    57,
      58,   136,   331,   136,   215,   217,   332,    31,   222,   211,
     212,    93,   222,   333,    94,   344,    32,   281,    30,   346,
     234,   347,   368,   369,   371,   375,   425,   357,    30,   241,
      33,   377,    31,    34,   282,   283,    93,   316,    30,    94,
     376,    32,    31,   379,   358,   359,    93,   215,   380,    94,
     399,    32,    31,   400,   414,    33,   415,   417,    34,   317,
     418,    32,   420,   419,   421,    33,   422,   423,    34,   424,
     403,    30,   443,   429,   432,    33,   215,   433,    34,   434,
     285,   444,   289,   289,   445,    31,   446,   404,   405,    93,
     447,   299,    94,   448,    32,    28,    46,   303,   103,   219,
      30,   184,    99,   226,   363,    30,   367,     0,    33,     0,
       0,    34,     0,     0,    31,    52,    53,   220,    93,    31,
       0,    94,     0,    32,     0,     0,   364,     0,    32,     0,
       0,     0,     0,    52,    53,   285,   285,    33,     0,     0,
      34,     0,    33,    85,     0,    34,     0,    54,    52,    53,
      55,    56,    57,    58,     0,     0,    52,    53,   361,     0,
       0,    86,     0,    52,    53,    54,     0,   374,    55,    56,
      57,    58,     0,     0,    52,    53,   106,     0,     0,     0,
      54,     0,   185,    55,    56,    57,    58,     0,    54,   289,
     289,    55,    56,    57,    58,    54,     0,   189,    55,    56,
      57,    58,   188,   407,   361,   361,    54,     0,   407,    55,
      56,    57,    58,   416,     0,     0,     0,     0,    52,    53,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,     0,     0,     0,   407,     0,     0,   407,   407,
      54,     0,   190,    55,    56,    57,    58,   192,    52,    53,
       0,    54,     0,     0,    55,    56,    57,    58,   194,    52,
      53,     0,    54,     0,     0,    55,    56,    57,    58,    52,
      53,     0,     0,     0,     0,     0,    52,    53,     0,     0,
      54,     0,   224,    55,    56,    57,    58,    52,    53,     0,
       0,    54,     0,   225,    55,    56,    57,    58,    52,    53,
       0,    54,     0,   240,    55,    56,    57,    58,    54,    52,
      53,    55,    56,    57,    58,   263,     0,     0,     0,    54,
      52,    53,    55,    56,    57,    58,   264,    52,    53,     0,
      54,     0,     0,    55,    56,    57,    58,   265,    52,    53,
       0,    54,     0,     0,    55,    56,    57,    58,   266,    52,
      53,     0,    54,     0,     0,    55,    56,    57,    58,    54,
       0,   267,    55,    56,    57,    58,    52,    53,     0,     0,
      54,     0,   268,    55,    56,    57,    58,   270,    52,    53,
       0,    54,     0,     0,    55,    56,    57,    58,     0,    52,
      53,     0,     0,     0,     0,     0,    52,    53,    54,     0,
     271,    55,    56,    57,    58,     0,   272,    52,    53,     0,
      54,     0,     0,    55,    56,    57,    58,   273,     0,   293,
       0,    54,    52,    53,    55,    56,    57,    58,    54,     0,
       0,    55,    56,    57,    58,   298,    52,    53,     0,    54,
       0,     0,    55,    56,    57,    58,     0,    52,    53,     0,
     322,     0,     0,     0,    54,     0,     0,    55,    56,    57,
      58,    52,    53,     0,   323,     0,     0,     0,    54,     0,
       0,    55,    56,    57,    58,   324,    52,    53,     0,    54,
       0,     0,    55,    56,    57,    58,    52,    53,     0,   325,
       0,     0,     0,    54,    52,    53,    55,    56,    57,    58,
       0,     0,     0,     0,   326,    52,    53,     0,    54,     0,
       0,    55,    56,    57,    58,     0,    52,    53,    54,     0,
     327,    55,    56,    57,    58,     0,    54,     0,   328,    55,
      56,    57,    58,   329,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,   343,    52,    53,     0,    54,     0,
       0,    55,    56,    57,    58,     0,    52,    53,     0,     0,
       0,     0,   345,     0,     0,     0,    54,    52,    53,    55,
      56,    57,    58,   348,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,   349,    52,    53,     0,    54,     0,
       0,    55,    56,    57,    58,   350,     0,   351,     0,    54,
      52,    53,    55,    56,    57,    58,    54,     0,     0,    55,
      56,    57,    58,   370,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,     0,    52,    53,     0,   372,     0,
       0,     0,    54,     0,     0,    55,    56,    57,    58,    52,
      53,     0,   373,     0,     0,     0,    54,     0,     0,    55,
      56,    57,    58,   391,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,     0,    52,    53,   392,     0,     0,
       0,    54,     0,     0,    55,    56,    57,    58,    52,    53,
       0,     0,   393,     0,     0,     0,    54,    52,    53,    55,
      56,    57,    58,   394,    52,    53,     0,    54,     0,     0,
      55,    56,    57,    58,     0,     0,   395,    52,    53,     0,
      54,     0,     0,    55,    56,    57,    58,    52,    53,    54,
       0,   396,    55,    56,    57,    58,    54,     0,   397,    55,
      56,    57,    58,    52,    53,   398,     0,     0,     0,    54,
      52,    53,    55,    56,    57,    58,     0,     0,     0,    54,
       0,   436,    55,    56,    57,    58,    52,    53,     0,     0,
       0,   435,     0,     0,     0,    54,     0,     0,    55,    56,
      57,    58,    54,     0,   437,    55,    56,    57,    58,    52,
      53,     0,     0,     0,   438,     0,     0,     0,    54,     0,
       0,    55,    56,    57,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,     0,     0,
       0,    54,     0,     0,    55,    56,    57,    58
};

static const yytype_int16 yycheck[] =
{
      12,   188,   273,   305,   149,   192,   114,   398,    16,    17,
      18,    19,    20,    21,    22,    54,    55,    27,    14,    15,
      32,    12,    13,   237,    34,    31,    31,    32,    34,    41,
      42,    43,    44,    45,    33,    34,    27,    45,    29,    30,
      31,    32,   187,    34,   435,    36,    42,   438,   439,   157,
      46,   159,   266,    49,    50,    51,    52,    27,    34,    50,
      59,    60,    53,    27,    34,    12,    13,    31,    80,    81,
      34,    12,    13,    85,    86,    27,   263,   264,   265,    34,
      27,    28,    34,   191,   229,   193,    27,    25,    26,    36,
      14,    15,    12,    13,    36,    36,   108,   399,   400,   325,
     326,   113,   114,    50,   394,   395,    53,    27,   379,   380,
      30,    31,   124,    37,    34,    29,    36,    31,    36,    29,
      34,    31,    46,    36,    34,    49,    50,    51,    52,    36,
      50,    36,    46,    53,   146,    36,   323,   149,    36,    12,
      13,   153,    27,   155,   156,   157,   158,   159,   160,   161,
      12,    13,    27,   165,    27,    27,   343,    34,   345,    31,
      23,    34,    34,    36,    36,    27,    37,    29,    30,    31,
     182,   183,    34,    39,    36,   187,    46,    50,    39,   191,
      53,   193,   194,    38,    28,   197,   198,    46,    50,     0,
     202,    53,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    42,    47,    42,   391,   392,    52,    53,    54,    55,
      56,    57,    58,    42,    12,    13,    42,   229,   230,   231,
     232,   233,    42,   235,   236,   237,   238,    12,    13,    27,
     242,   243,   244,    31,    14,    15,    34,    42,    36,    31,
      33,    31,    27,    47,    29,    30,    31,    32,    39,    34,
     262,    36,    50,    41,   266,    53,    42,   269,   270,    46,
     272,   273,    42,    12,    13,    50,    46,    48,    53,    49,
      50,    51,    52,    42,    29,    30,    31,    47,    27,    34,
      47,    43,   294,   295,   296,   297,   298,    36,   300,   301,
     302,    42,   304,   305,    29,    30,    31,    43,    42,    34,
      42,    50,    35,    42,    53,    42,    47,    12,    13,    47,
     322,    42,   324,   325,   326,    14,    15,   329,    44,   331,
     332,   333,    27,    44,    29,    30,    31,    32,    47,    34,
      42,    36,   344,    24,   346,   347,   348,   349,   350,    42,
      24,    40,    31,    83,    39,    50,    42,    46,    53,    42,
      49,    50,    51,    52,    42,    95,    42,   369,   370,   371,
     372,   373,    42,   375,   376,   377,    47,   379,   380,    47,
      43,    42,    24,   113,   114,   115,    42,    12,    13,    47,
      42,   393,   394,   395,    37,   125,   398,   399,   400,    35,
      37,   131,    27,    38,    29,    30,    31,    14,    15,    34,
      40,    36,    44,   415,   144,   417,   418,    33,   420,   421,
      42,    23,    14,    15,    42,    50,    47,   157,    53,   159,
      42,   161,    42,   435,    42,   165,   438,   439,    47,    46,
      40,    48,    49,    50,    51,    52,    42,   177,    42,    42,
      42,    40,    12,    13,    46,    32,   186,    49,    50,    51,
      52,   191,    42,   193,   194,   195,    42,    27,   198,    29,
      30,    31,   202,    39,    34,    42,    36,    12,    13,    42,
     210,    42,    38,    42,    42,    47,    40,    12,    13,   219,
      50,    42,    27,    53,    29,    30,    31,    12,    13,    34,
      47,    36,    27,    42,    29,    30,    31,   237,    42,    34,
      42,    36,    27,    42,    37,    50,    42,    47,    53,    34,
      47,    36,    42,    37,    42,    50,    37,    37,    53,    37,
      12,    13,    37,    40,    40,    50,   266,    40,    53,    40,
     270,    37,   272,   273,    37,    27,    40,    29,    30,    31,
      40,   281,    34,    40,    36,    10,    21,   287,    86,    12,
      13,   165,    84,   202,    12,    13,   350,    -1,    50,    -1,
      -1,    53,    -1,    -1,    27,    14,    15,    30,    31,    27,
      -1,    34,    -1,    36,    -1,    -1,    34,    -1,    36,    -1,
      -1,    -1,    -1,    14,    15,   325,   326,    50,    -1,    -1,
      53,    -1,    50,    42,    -1,    53,    -1,    46,    14,    15,
      49,    50,    51,    52,    -1,    -1,    14,    15,   348,    -1,
      -1,    42,    -1,    14,    15,    46,    -1,   357,    49,    50,
      51,    52,    -1,    -1,    14,    15,    42,    -1,    -1,    -1,
      46,    -1,    40,    49,    50,    51,    52,    -1,    46,   379,
     380,    49,    50,    51,    52,    46,    -1,    48,    49,    50,
      51,    52,    42,   393,   394,   395,    46,    -1,   398,    49,
      50,    51,    52,   403,    -1,    -1,    -1,    -1,    14,    15,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,   435,    -1,    -1,   438,   439,
      46,    -1,    48,    49,    50,    51,    52,    42,    14,    15,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    42,    14,
      15,    -1,    46,    -1,    -1,    49,    50,    51,    52,    14,
      15,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    14,    15,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    14,    15,
      -1,    46,    -1,    48,    49,    50,    51,    52,    46,    14,
      15,    49,    50,    51,    52,    42,    -1,    -1,    -1,    46,
      14,    15,    49,    50,    51,    52,    42,    14,    15,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    42,    14,    15,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    42,    14,
      15,    -1,    46,    -1,    -1,    49,    50,    51,    52,    46,
      -1,    48,    49,    50,    51,    52,    14,    15,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    42,    14,    15,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    14,    15,    46,    -1,
      48,    49,    50,    51,    52,    -1,    42,    14,    15,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    42,    -1,    37,
      -1,    46,    14,    15,    49,    50,    51,    52,    46,    -1,
      -1,    49,    50,    51,    52,    42,    14,    15,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    -1,    14,    15,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    14,    15,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    42,    14,    15,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    14,    15,    -1,    42,
      -1,    -1,    -1,    46,    14,    15,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    42,    14,    15,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    -1,    14,    15,    46,    -1,
      48,    49,    50,    51,    52,    -1,    46,    -1,    48,    49,
      50,    51,    52,    42,    14,    15,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    42,    14,    15,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    -1,    14,    15,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    14,    15,    49,
      50,    51,    52,    42,    14,    15,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    42,    14,    15,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    42,    -1,    37,    -1,    46,
      14,    15,    49,    50,    51,    52,    46,    -1,    -1,    49,
      50,    51,    52,    42,    14,    15,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    -1,    14,    15,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    14,
      15,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    42,    14,    15,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    -1,    14,    15,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    14,    15,
      -1,    -1,    42,    -1,    -1,    -1,    46,    14,    15,    49,
      50,    51,    52,    42,    14,    15,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    42,    14,    15,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    14,    15,    46,
      -1,    48,    49,    50,    51,    52,    46,    -1,    48,    49,
      50,    51,    52,    14,    15,    42,    -1,    -1,    -1,    46,
      14,    15,    49,    50,    51,    52,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    14,    15,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    46,    -1,    48,    49,    50,    51,    52,    14,
      15,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      57,    58,    34,    16,    17,    18,    19,    20,    21,    22,
      45,    59,    60,    34,    25,    26,    84,     0,    58,    12,
      13,    27,    36,    50,    53,    80,    81,    82,    83,    36,
      36,    36,    36,    36,    36,    36,    60,    27,    27,    80,
      82,    82,    14,    15,    46,    49,    50,    51,    52,    54,
      55,    34,    31,    32,    80,    80,    80,    80,    80,    37,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    23,
      39,    39,    42,    42,    42,    42,    42,    37,    80,    80,
      46,    62,    29,    31,    34,    46,    64,    70,    79,    70,
      28,    71,    80,    71,    38,    40,    42,    28,    42,    47,
      29,    79,    42,    42,    42,    42,    42,    31,    33,    12,
      34,    61,    80,    31,    47,    12,    29,    30,    63,    79,
      80,    12,    29,    30,    32,    65,    79,    80,    32,    65,
      29,    30,    72,    79,    46,    73,    41,    39,    34,    42,
      48,    80,    79,    42,    79,    47,    47,    43,    42,    43,
      42,    42,    29,    30,    79,    42,    80,    35,    61,    48,
      80,    80,    80,    65,    80,    65,    80,    12,    30,    74,
      79,    80,    47,    47,    74,    40,    42,    42,    42,    48,
      48,    44,    42,    44,    42,    36,    79,    47,    42,    24,
      80,    80,    42,    31,    79,    61,    63,    65,    63,    65,
      12,    29,    30,    32,    66,    79,    80,    79,    80,    12,
      30,    75,    79,    80,    48,    48,    75,    24,    39,    42,
      42,    42,    42,    42,    79,    47,    47,    43,    42,    24,
      48,    79,    47,    42,    42,    37,    35,    61,    80,    80,
      80,    80,    80,    80,    66,    80,    37,    80,    80,    80,
      38,    40,    42,    42,    42,    42,    42,    48,    48,    44,
      42,    48,    42,    42,    33,    80,    63,    63,    63,    66,
      80,    12,    29,    30,    67,    79,    80,    12,    76,    79,
      80,    76,    23,    37,    42,    42,    42,    42,    42,    79,
      47,    47,    42,    79,    42,    42,    40,    40,    80,    80,
      80,    80,    80,    80,    80,    80,    12,    34,    77,    80,
      77,    32,    42,    42,    42,    42,    42,    48,    48,    42,
      34,    42,    42,    39,    80,    63,    80,    67,    67,    80,
      80,    80,    80,    42,    42,    42,    42,    42,    42,    42,
      42,    37,    63,    80,    63,    80,    80,    12,    29,    30,
      68,    79,    80,    12,    34,    78,    80,    78,    38,    42,
      42,    42,    42,    42,    79,    47,    47,    42,    34,    42,
      42,    80,    80,    80,    80,    80,    80,    80,    80,    76,
      76,    42,    42,    42,    42,    42,    48,    48,    42,    42,
      42,    63,    63,    12,    29,    30,    69,    79,    80,    68,
      68,    69,    77,    77,    37,    42,    79,    47,    47,    37,
      42,    42,    37,    37,    37,    40,    80,    80,    80,    40,
      80,    80,    40,    40,    40,    42,    48,    48,    42,    42,
      69,    69,    69,    37,    37,    37,    40,    40,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    62,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    84,    84
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
#line 1812 "y.tab.c"
    break;

  case 5:
#line 60 "conv-c2c.y"
                {
          fprintf(ofile, "%s\n", yytext);
        }
#line 1820 "y.tab.c"
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
#line 1847 "y.tab.c"
    break;

  case 7:
#line 85 "conv-c2c.y"
                                  {
        }
#line 1854 "y.tab.c"
    break;

  case 8:
#line 87 "conv-c2c.y"
                    {
	  emit_emax6a(0);
	  hash_clear();
        }
#line 1863 "y.tab.c"
    break;

  case 9:
#line 91 "conv-c2c.y"
                      {
	  emit_emax6a(1);
	  hash_clear();
        }
#line 1872 "y.tab.c"
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
#line 1884 "y.tab.c"
    break;

  case 11:
#line 102 "conv-c2c.y"
                                  {
	}
#line 1891 "y.tab.c"
    break;

  case 12:
#line 104 "conv-c2c.y"
                    {
	  emit_emax6t(0);
	  hash_clear();
	}
#line 1900 "y.tab.c"
    break;

  case 13:
#line 110 "conv-c2c.y"
                        {
        }
#line 1907 "y.tab.c"
    break;

  case 14:
#line 112 "conv-c2c.y"
                                {
        }
#line 1914 "y.tab.c"
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
#line 1943 "y.tab.c"
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
#line 1960 "y.tab.c"
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
#line 2025 "y.tab.c"
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
	  insn[last_insn].icex.bit1v   = id[ yyvsp[-6]].type;
	  insn[last_insn].icex.bit1h   = yyvsp[-6];
	  insn[last_insn].icex.bit2v   = id[ yyvsp[-8]].type;
	  insn[last_insn].icex.bit2h   = yyvsp[-8];
	  insn[last_insn].icex.bit3v   = id[ yyvsp[-10]].type;
	  insn[last_insn].icex.bit3h   = yyvsp[-10];
	  insn[last_insn].icex.table   = id[yyvsp[-2]].val;
	  insn[last_insn].icex.cexdv   = id[yyvsp[-12]].type;
	  insn[last_insn].icex.cexdh   = yyvsp[-12];
          last_insn++;
        }
#line 2052 "y.tab.c"
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
	  insn[last_insn].iheader.row  = id[yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-22]].type==T_ALRNO?(        -1):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
	  insn[last_insn].iexe.src1s   = 4; /* all suffix */
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
	  insn[last_insn].iexe.src5s   = 4; /* all suffix */
	  insn[last_insn].iexe.exedv   = id[yyvsp[-22]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-22];
	  insn[last_insn].iexe.exeds   = 4; /* all suffix */
          last_insn++;
        }
#line 2095 "y.tab.c"
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
	  insn[last_insn].iheader.row  = id[yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val)                :id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-22]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
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
	  insn[last_insn].iexe.exedv   = id[yyvsp[-22]].type;
	  insn[last_insn].iexe.exedh   = yyvsp[-22];
          last_insn++;
        }
#line 2134 "y.tab.c"
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
	    fprintf(stderr, "in %s: exe(INIT0?src1:src1) should be specified\n", id[current_prefix].name);
            exit(1);
	  }
	  insn[last_insn].iheader.type = 4; /* EX4 */
	  insn[last_insn].iheader.row  = id[yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
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
#line 2182 "y.tab.c"
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
	  insn[last_insn].iheader.row  = id[yyvsp[-22]].type==T_ALRNO?(id[yyvsp[-22]].val)                :id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-22]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-22]].type==T_BDRNO?(id[yyvsp[-22]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-24]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-22] == yyvsp[-20])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 0;
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-20]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-20];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-18]].val;
	  insn[last_insn].iexe.src2v   = id[ yyvsp[-16]].type;
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
#line 2219 "y.tab.c"
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
	  insn[last_insn].iheader.row  = id[yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
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
#line 2265 "y.tab.c"
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
	  insn[last_insn].iheader.row  = id[yyvsp[-26]].type==T_ALRNO?(id[yyvsp[-26]].val)                :id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val/EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iheader.col  = id[yyvsp[-26]].type==T_ALRNO?(insn[last_insn].iexe.exeds):id[yyvsp[-26]].type==T_BDRNO?(id[yyvsp[-26]].val%EMAX_WIDTH):-1; /* adr/bdr */
	  insn[last_insn].iexe.op1     = id[ yyvsp[-28]].val;
	  insn[last_insn].iexe.op2     = id[yyvsp[-8]].val;
	  insn[last_insn].iexe.op3     = id[yyvsp[-4]].val;
	  insn[last_insn].iexe.updt    = (yyvsp[-26] == yyvsp[-24])?1:0; /* if (src1 == dstd) self_update=1 */
	  insn[last_insn].iexe.init    = 2; /* activate s2+INIT0 */
	  insn[last_insn].iexe.src1v   = id[ yyvsp[-24]].type;
	  insn[last_insn].iexe.src1h   = yyvsp[-24];
	  insn[last_insn].iexe.src1e   = id[ yyvsp[-22]].val;
	  insn[last_insn].iexe.src2v   = id[ yyvsp[-18]].type;
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
#line 2311 "y.tab.c"
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
#line 2385 "y.tab.c"
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
#line 2449 "y.tab.c"
    break;

  case 27:
#line 591 "conv-c2c.y"
              {
        }
#line 2456 "y.tab.c"
    break;

  case 28:
#line 593 "conv-c2c.y"
          {
        }
#line 2463 "y.tab.c"
    break;

  case 29:
#line 597 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2471 "y.tab.c"
    break;

  case 30:
#line 600 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 2479 "y.tab.c"
    break;

  case 31:
#line 603 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 2487 "y.tab.c"
    break;

  case 32:
#line 608 "conv-c2c.y"
                    {
          yyval = yyvsp[0];
        }
#line 2495 "y.tab.c"
    break;

  case 33:
#line 613 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2503 "y.tab.c"
    break;

  case 34:
#line 616 "conv-c2c.y"
                    { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2511 "y.tab.c"
    break;

  case 35:
#line 619 "conv-c2c.y"
                             { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2519 "y.tab.c"
    break;

  case 36:
#line 622 "conv-c2c.y"
                { /* AR[r] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2527 "y.tab.c"
    break;

  case 37:
#line 625 "conv-c2c.y"
                { /* BR[r][c] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2535 "y.tab.c"
    break;

  case 38:
#line 630 "conv-c2c.y"
                     { /* var ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2543 "y.tab.c"
    break;

  case 39:
#line 633 "conv-c2c.y"
                { /* AR[r] ([UNIT_WIDTH]) */
          yyval = yyvsp[0];
	}
#line 2551 "y.tab.c"
    break;

  case 40:
#line 638 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
        }
#line 2560 "y.tab.c"
    break;

  case 41:
#line 642 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
	}
#line 2569 "y.tab.c"
    break;

  case 42:
#line 646 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src1s = -1;
          yyval = yyvsp[0];
	}
#line 2578 "y.tab.c"
    break;

  case 43:
#line 650 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src1s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2587 "y.tab.c"
    break;

  case 44:
#line 654 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src1s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2596 "y.tab.c"
    break;

  case 45:
#line 660 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
        }
#line 2605 "y.tab.c"
    break;

  case 46:
#line 664 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
	}
#line 2614 "y.tab.c"
    break;

  case 47:
#line 668 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src2s = -1;
          yyval = yyvsp[0];
	}
#line 2623 "y.tab.c"
    break;

  case 48:
#line 672 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src2s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2632 "y.tab.c"
    break;

  case 49:
#line 676 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src2s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2641 "y.tab.c"
    break;

  case 50:
#line 682 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
        }
#line 2650 "y.tab.c"
    break;

  case 51:
#line 686 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
	}
#line 2659 "y.tab.c"
    break;

  case 52:
#line 690 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src3s = -1;
          yyval = yyvsp[0];
	}
#line 2668 "y.tab.c"
    break;

  case 53:
#line 694 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src3s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2677 "y.tab.c"
    break;

  case 54:
#line 698 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src3s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2686 "y.tab.c"
    break;

  case 55:
#line 704 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
        }
#line 2695 "y.tab.c"
    break;

  case 56:
#line 708 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
	}
#line 2704 "y.tab.c"
    break;

  case 57:
#line 712 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src4s = -1;
          yyval = yyvsp[0];
	}
#line 2713 "y.tab.c"
    break;

  case 58:
#line 716 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src4s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2722 "y.tab.c"
    break;

  case 59:
#line 720 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src4s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2731 "y.tab.c"
    break;

  case 60:
#line 726 "conv-c2c.y"
                {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
        }
#line 2740 "y.tab.c"
    break;

  case 61:
#line 730 "conv-c2c.y"
                    {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
	}
#line 2749 "y.tab.c"
    break;

  case 62:
#line 734 "conv-c2c.y"
                             {
	  insn[last_insn].iexe.src5s = -1;
          yyval = yyvsp[0];
	}
#line 2758 "y.tab.c"
    break;

  case 63:
#line 738 "conv-c2c.y"
                             { /* AR[r][s] */
	  insn[last_insn].iexe.src5s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2767 "y.tab.c"
    break;

  case 64:
#line 742 "conv-c2c.y"
                             { /* BR[r][c][s] */
	  insn[last_insn].iexe.src5s = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2776 "y.tab.c"
    break;

  case 65:
#line 748 "conv-c2c.y"
                         { /* &var */
	  insn[last_insn].iexe.exeds = -1;
          yyval = yyvsp[0];
        }
#line 2785 "y.tab.c"
    break;

  case 66:
#line 752 "conv-c2c.y"
                                 { /* &AR[r][s] */
	  insn[last_insn].iexe.exeds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2794 "y.tab.c"
    break;

  case 67:
#line 758 "conv-c2c.y"
              {
          yyval = yyvsp[0];
        }
#line 2802 "y.tab.c"
    break;

  case 68:
#line 761 "conv-c2c.y"
                { /* exx */
          yyval = yyvsp[0];
	}
#line 2810 "y.tab.c"
    break;

  case 69:
#line 766 "conv-c2c.y"
                       { /* for load/store */
          yyval = yyvsp[0];
	}
#line 2818 "y.tab.c"
    break;

  case 70:
#line 769 "conv-c2c.y"
                { /* for store */
          yyval = yyvsp[0];
	}
#line 2826 "y.tab.c"
    break;

  case 71:
#line 772 "conv-c2c.y"
                { /* for load */
          yyval = yyvsp[0];
        }
#line 2834 "y.tab.c"
    break;

  case 72:
#line 777 "conv-c2c.y"
                           { /* for load/store */
	  insn[last_insn].imop.mopds = -1;
          yyval = yyvsp[0];
	}
#line 2843 "y.tab.c"
    break;

  case 73:
#line 781 "conv-c2c.y"
                                 { /* for store */
	  insn[last_insn].imop.mopds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2852 "y.tab.c"
    break;

  case 74:
#line 785 "conv-c2c.y"
                                 { /* for load */
	  insn[last_insn].imop.mopds = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
        }
#line 2861 "y.tab.c"
    break;

  case 75:
#line 791 "conv-c2c.y"
                {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
        }
#line 2870 "y.tab.c"
    break;

  case 76:
#line 795 "conv-c2c.y"
                    {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
	}
#line 2879 "y.tab.c"
    break;

  case 77:
#line 799 "conv-c2c.y"
                             {
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[0];
	}
#line 2888 "y.tab.c"
    break;

  case 78:
#line 803 "conv-c2c.y"
                              {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[-1];
	}
#line 2898 "y.tab.c"
    break;

  case 79:
#line 808 "conv-c2c.y"
                                               {
	  insn[last_insn].imop.updt = 1;
	  insn[last_insn].imop.bases = -1;
          yyval = yyvsp[-2];
	}
#line 2908 "y.tab.c"
    break;

  case 80:
#line 813 "conv-c2c.y"
                             {
	  insn[last_insn].imop.bases = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2917 "y.tab.c"
    break;

  case 81:
#line 819 "conv-c2c.y"
                  {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
        }
#line 2926 "y.tab.c"
    break;

  case 82:
#line 823 "conv-c2c.y"
                    {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
	}
#line 2935 "y.tab.c"
    break;

  case 83:
#line 827 "conv-c2c.y"
                             {
	  insn[last_insn].imop.offss = -1;
          yyval = yyvsp[0];
	}
#line 2944 "y.tab.c"
    break;

  case 84:
#line 831 "conv-c2c.y"
                             {
	  insn[last_insn].imop.offss = id[yyvsp[-1]].val;
          yyval = yyvsp[-3];
	}
#line 2953 "y.tab.c"
    break;

  case 85:
#line 837 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2961 "y.tab.c"
    break;

  case 86:
#line 840 "conv-c2c.y"
                    {
          yyval = yyvsp[0];
	}
#line 2969 "y.tab.c"
    break;

  case 87:
#line 843 "conv-c2c.y"
                             {
          yyval = yyvsp[0];
	}
#line 2977 "y.tab.c"
    break;

  case 88:
#line 848 "conv-c2c.y"
               {
          yyval = yyvsp[0];
        }
#line 2985 "y.tab.c"
    break;

  case 89:
#line 851 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 2993 "y.tab.c"
    break;

  case 90:
#line 854 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 3001 "y.tab.c"
    break;

  case 91:
#line 859 "conv-c2c.y"
             {
          yyval = yyvsp[0];
        }
#line 3009 "y.tab.c"
    break;

  case 92:
#line 862 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 3017 "y.tab.c"
    break;

  case 93:
#line 865 "conv-c2c.y"
                            {
          yyval = yyvsp[0];
	}
#line 3025 "y.tab.c"
    break;

  case 94:
#line 870 "conv-c2c.y"
                 {
          /*id[$1].chip = 1;*/
          yyval = yyvsp[0];
        }
#line 3034 "y.tab.c"
    break;

  case 95:
#line 874 "conv-c2c.y"
                                {
	  id[yyvsp[-3]].cidx = 1;
          yyval = yyvsp[-3];
	}
#line 3043 "y.tab.c"
    break;

  case 96:
#line 878 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
	}
#line 3051 "y.tab.c"
    break;

  case 97:
#line 882 "conv-c2c.y"
            {
          yyval = yyvsp[0];
        }
#line 3059 "y.tab.c"
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
#line 3077 "y.tab.c"
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
#line 3095 "y.tab.c"
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
#line 3113 "y.tab.c"
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
#line 3131 "y.tab.c"
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
#line 3149 "y.tab.c"
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
#line 3167 "y.tab.c"
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
#line 3185 "y.tab.c"
    break;

  case 105:
#line 978 "conv-c2c.y"
              {
          yyval = yyvsp[0];
        }
#line 3193 "y.tab.c"
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
#line 3209 "y.tab.c"
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
#line 3225 "y.tab.c"
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
#line 3243 "y.tab.c"
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
#line 3261 "y.tab.c"
    break;

  case 110:
#line 1031 "conv-c2c.y"
                      {
          yyval = yyvsp[-1];
        }
#line 3269 "y.tab.c"
    break;

  case 111:
#line 1034 "conv-c2c.y"
                 {
          yyval = yyvsp[0];
        }
#line 3277 "y.tab.c"
    break;

  case 112:
#line 1039 "conv-c2c.y"
                   {
          yyval = yyvsp[0];
        }
#line 3285 "y.tab.c"
    break;

  case 113:
#line 1042 "conv-c2c.y"
                             {
          yyval = yyvsp[0];
        }
#line 3293 "y.tab.c"
    break;

  case 114:
#line 1045 "conv-c2c.y"
                              {
          yyval = yyvsp[0];
        }
#line 3301 "y.tab.c"
    break;

  case 115:
#line 1050 "conv-c2c.y"
                       {
          trans[trans_pc].rw = 0; /* READ */
	}
#line 3309 "y.tab.c"
    break;

  case 116:
#line 1053 "conv-c2c.y"
                     {
          trans[trans_pc].rw = 1; /* WRITE */
        }
#line 3317 "y.tab.c"
    break;


#line 3321 "y.tab.c"

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



