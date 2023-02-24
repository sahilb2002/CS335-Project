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
#line 1 "parse_oracle.yy"


    #include<iostream>
    using namespace std;   

#line 76 "parse_oracle.tab.cc"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCREMENT = 258,
    DECREMENT = 259,
    DOUBLE_COLON = 260,
    LOG_OR = 261,
    LOG_AND = 262,
    EQUAL = 263,
    NOT_EQUAL = 264,
    GTR_EQUAL = 265,
    LESS_EQUAL = 266,
    LEFT_SHIFT = 267,
    RIGHT_SHIFT = 268,
    SIGN_SHIFT = 269,
    ASSIGN_OP = 270,
    TRIPLE_DOT = 271,
    Identifier = 272,
    INT = 273,
    FLOAT = 274,
    CHAR = 275,
    STRING = 276,
    BOOL = 277,
    TEXTBLOCK = 278,
    TypeIdentifier = 279,
    KEY_STATIC = 280,
    KEY_RETURN = 281,
    KEY_NEW = 282,
    KEY_THIS = 283,
    KEY_SUPER = 284,
    KEY_THROWS = 285,
    KEY_INSTANCEOF = 286,
    KEY_INT = 287,
    KEY_BYTE = 288,
    KEY_SHORT = 289,
    KEY_FLOAT = 290,
    KEY_LONG = 291,
    KEY_DOUBLE = 292,
    KEY_BOOL = 293,
    KEY_CHAR = 294,
    KEY_VOID = 295,
    KEY_VAR = 296,
    KEY_FOR = 297,
    KEY_WHILE = 298,
    KEY_IF = 299,
    KEY_ELSE = 300,
    KEY_FINAL = 301,
    KEY_PRIVATE = 302,
    KEY_PUBLIC = 303,
    KEY_CLASS = 304,
    KEY_NULL = 305,
    KEY_BREAK = 306,
    KEY_CONTINUE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 7 "parse_oracle.yy"

    int num;
    char chr;
    char* str;

#line 184 "parse_oracle.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  148
/* YYNRULES -- Number of rules.  */
#define YYNRULES  324
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  522

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


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
       2,     2,     2,    76,     2,     2,     2,    57,    74,     2,
      66,    67,    55,    53,    68,    54,    60,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    65,
      58,    69,    59,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    73,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    72,    64,    75,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    96,    97,    98,    99,   100,   103,   104,
     107,   108,   112,   113,   116,   117,   118,   123,   124,   131,
     134,   135,   136,   139,   140,   141,   142,   145,   153,   154,
     155,   158,   161,   162,   165,   166,   167,   168,   171,   172,
     173,   174,   177,   178,   181,   182,   185,   186,   187,   190,
     191,   194,   195,   198,   199,   200,   203,   204,   205,   208,
     211,   212,   215,   218,   219,   220,   223,   224,   227,   228,
     231,   232,   233,   236,   239,   240,   243,   247,   248,   251,
     254,   255,   258,   259,   262,   265,   266,   269,   270,   273,
     274,   277,   278,   281,   284,   287,   288,   291,   292,   295,
     296,   298,   301,   304,   305,   308,   309,   312,   313,   316,
     319,   322,   325,   326,   329,   330,   331,   332,   335,   336,
     339,   342,   343,   346,   347,   357,   358,   360,   361,   363,
     364,   365,   368,   371,   374,   375,   377,   378,   380,   383,
     384,   387,   388,   391,   392,   394,   395,   397,   398,   401,
     403,   404,   405,   406,   407,   409,   410,   411,   412,   415,
     416,   417,   418,   419,   420,   423,   426,   429,   432,   434,
     436,   437,   438,   439,   440,   441,   442,   445,   447,   450,
     452,   455,   457,   457,   458,   458,   459,   459,   461,   463,
     464,   466,   468,   469,   471,   472,   474,   475,   477,   478,
     481,   482,   483,   484,   485,   485,   489,   490,   491,   493,
     495,   496,   503,   504,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   519,   520,   521,   522,   523,   524,
     525,   528,   529,   530,   531,   534,   535,   536,   539,   542,
     543,   546,   547,   550,   551,   554,   555,   558,   559,   560,
     561,   562,   565,   566,   567,   568,   569,   570,   571,   574,
     575,   578,   579,   583,   586,   589,   590,   593,   596,   597,
     600,   601,   602,   605,   606,   609,   610,   613,   614,   617,
     618,   621,   622,   625,   626,   629,   630,   631,   634,   635,
     636,   637,   638,   639,   642,   643,   646,   649,   652,   653,
     654,   655,   658,   659,   660,   663,   664,   665,   666,   669,
     670,   671,   672,   673,   676,   679,   682,   683,   684,   687,
     688,   689,   690,   693,   696
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCREMENT", "DECREMENT", "DOUBLE_COLON",
  "LOG_OR", "LOG_AND", "EQUAL", "NOT_EQUAL", "GTR_EQUAL", "LESS_EQUAL",
  "LEFT_SHIFT", "RIGHT_SHIFT", "SIGN_SHIFT", "ASSIGN_OP", "TRIPLE_DOT",
  "Identifier", "INT", "FLOAT", "CHAR", "STRING", "BOOL", "TEXTBLOCK",
  "TypeIdentifier", "KEY_STATIC", "KEY_RETURN", "KEY_NEW", "KEY_THIS",
  "KEY_SUPER", "KEY_THROWS", "KEY_INSTANCEOF", "KEY_INT", "KEY_BYTE",
  "KEY_SHORT", "KEY_FLOAT", "KEY_LONG", "KEY_DOUBLE", "KEY_BOOL",
  "KEY_CHAR", "KEY_VOID", "KEY_VAR", "KEY_FOR", "KEY_WHILE", "KEY_IF",
  "KEY_ELSE", "KEY_FINAL", "KEY_PRIVATE", "KEY_PUBLIC", "KEY_CLASS",
  "KEY_NULL", "KEY_BREAK", "KEY_CONTINUE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'<'", "'>'", "'.'", "'['", "']'", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'='", "'?'", "':'", "'|'", "'^'", "'&'", "'~'", "'!'",
  "$accept", "START", "IntegralType", "FloatingPointType", "NumericType",
  "PrimitiveType", "ReferenceType", "ClassType", "TypeVariable",
  "ArrayType", "Dims", "Dim", "ClassModifier", "ClassBody",
  "ClassBodyDeclaration_c", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "FieldModifier_c",
  "FieldModifier", "UnannType", "UnannPrimitiveType", "UnannReferenceType",
  "UnannClassOrInterfaceType", "UnannClassType", "UnannInterfaceType",
  "UnannTypeVariable", "UnannArrayType", "MethodDeclaration",
  "MethodModifier_c", "MethodModifier", "MethodHeader", "Result",
  "MethodDeclarator", "ReceiverParameter_b", "ReceiverParameter",
  "Identifier_b", "FormalParameterList_b", "FormalParameterList",
  "FormalParameter_c", "FormalParameter", "VariableArityParameter",
  "Throws_b", "Throws", "ExceptionTypeList", "ExceptionType_c",
  "ExceptionType", "MethodBody", "StaticInitializer",
  "InstanceInitializer", "ConstructorDeclaration", "ConstructorModifier_c",
  "ConstructorModifier", "ConstructorDeclarator", "SimpleTypeName",
  "ConstructorBody", "ExplicitConstructorInvocation_b",
  "ExplicitConstructorInvocation", "ArgumentList_b", "ArgumentList",
  "Expression_c", "BlockStatements_b", "Block", "BlockStatements",
  "BlockStatement", "LocalClassOrInterfaceDeclaration", "ClassDeclaration",
  "NormalClassDeclaration", "ClassModifier_b", "LocalVariableDeclaration",
  "LocalVariableType", "VariableDeclaratorList", "VariableDeclarator",
  "VariableDeclaratorId", "VariableInitializer",
  "LocalVariableDeclarationStatement", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "IfThenStatement",
  "IfThenElseStatement", "IfThenElseStatementNoShortIf", "EmptyStatement",
  "ExpressionStatement", "StatementExpression", "WhileStatement",
  "WhileStatementNoShortIf", "ForStatement", "ForStatementNoShortIf",
  "BasicForStatement", "Expression_s", "ForInit_s", "ForUpdate_s",
  "BasicForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ArrayInitializer", "VariableInitializerList_s",
  "comma_s", "TypeName", "ExpressionName", "MethodName", "AmbiguousName",
  "Primary", "PrimaryNoNewArray", "Literal", "ClassLiteral",
  "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ArgumentList_s",
  "ClassBody_s", "FieldAccess", "ArrayAccess", "MethodInvocation",
  "MethodReference", "ArrayCreationExpression", "DimExprs", "DimExpr",
  "Expression", "AssignmentExpression", "Assignment", "AssignmentOperator",
  "LeftHandSide", "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "InclusiveOrExpression",
  "ExclusiveOrExpression", "AndExpression", "EqualityExpression",
  "RelationalExpression", "InstanceofExpression", "Pattern", "TypePattern",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    43,    45,    42,    47,    37,    60,    62,
      46,    91,    93,   123,   125,    59,    40,    41,    44,    61,
      63,    58,   124,    94,    38,   126,    33
};
# endif

#define YYPACT_NINF (-430)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-323)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,  -430,  -430,  -430,    22,    79,  -430,  -430,  -430,   237,
      52,  -430,    84,  -430,  1578,  -430,    52,    53,   130,  -430,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,   181,   201,
    1244,  -430,  -430,  -430,  -430,   274,  -430,  -430,  -430,   703,
    -430,   124,   114,  -430,   150,  -430,  -430,   212,  -430,  -430,
     199,  -430,   104,   202,  -430,  -430,  -430,    33,  -430,   162,
     132,  -430,  -430,  -430,  -430,  1184,  1184,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,   205,  1003,   148,  -430,    35,    45,
     143,  -430,   159,   192,   194,  -430,    24,    26,  -430,  -430,
    1184,    50,   114,   239,    37,   114,   258,  -430,  -430,  1294,
    -430,  -430,  -430,   209,   124,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,   216,  -430,  -430,  -430,  -430,  -430,  -430,   217,
     809,   204,   231,    43,  1184,  -430,  -430,   175,  -430,  -430,
    -430,   186,  -430,  -430,  -430,    13,  -430,  -430,   276,   284,
     286,  -430,  -430,  -430,  -430,  -430,  -430,  -430,   124,   114,
      64,  -430,   224,   233,  -430,   114,   273,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,   104,  -430,  -430,  -430,   263,   162,
    -430,  -430,  -430,  -430,   162,   281,   261,  -430,   341,  -430,
     241,  1184,  1184,  1184,  1184,   241,   809,  -430,  -430,  -430,
    -430,  -430,  -430,  -430,  -430,   276,  -430,  -430,  -430,  -430,
     267,  -430,  -430,  -430,    32,   321,   268,   260,   279,   295,
      55,  -430,    40,   262,    16,  -430,  -430,  1184,  -430,   879,
     318,   343,   303,   315,  1494,  1184,  1184,   302,  -430,   304,
    -430,   299,   308,  -430,   353,   344,   361,  -430,  -430,   365,
    -430,  -430,  -430,   325,  -430,   180,   334,   379,    51,  -430,
    -430,  1184,   380,   382,    58,  -430,  -430,  -430,  1184,  -430,
    -430,    97,  -430,  -430,   124,  1063,  -430,   114,  -430,  -430,
     341,  -430,   261,  -430,   340,  -430,  -430,  -430,  1558,  -430,
     384,   310,   339,  -430,  -430,  -430,  -430,  -430,  1184,  1184,
    1184,  1184,  1184,  1184,  1184,  1184,  1184,  1184,   391,  1184,
    1184,  1184,  1184,  1184,  1184,  1184,  1184,  1184,  1184,  -430,
     335,  -430,   348,  -430,  1124,  -430,  -430,   346,   364,  -430,
    -430,  -430,   349,  -430,   350,   352,   366,  -430,  -430,  -430,
     367,  -430,  -430,  -430,  -430,   351,  -430,   415,   385,  -430,
     369,   371,  -430,   375,  -430,  -430,   372,  -430,  -430,  -430,
    -430,  1063,  -430,  -430,  -430,  -430,   310,  -430,   376,   377,
      30,  1344,  -430,   943,    44,   388,   417,   341,   301,   386,
    -430,  -430,  -430,  -430,   321,   378,   268,   260,   279,   295,
      55,    55,  -430,  -430,  -430,  -430,  -430,  -430,   259,  -430,
    -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
    -430,  -430,  -430,    52,   389,  -430,  -430,  -430,  1184,  -430,
    1184,  1534,  1394,  1444,  -430,  1184,   437,  -430,  1184,  -430,
    1184,  -430,   393,   395,   281,  1184,  1184,   399,  1344,   111,
     178,  -430,  -430,   449,   451,  -430,  -430,   404,  1184,  -430,
    -430,  1184,   411,   420,  -430,  -430,   414,   422,   427,  -430,
     453,   456,  -430,  -430,  -430,  -430,   429,  -430,   435,   436,
    1063,   430,   114,  -430,   439,  -430,   440,  -430,   445,   446,
     500,  -430,   310,  -430,  -430,  -430,  1534,  1494,  1184,  1184,
    1394,  -430,  -430,  -430,  -430,  -430,  -430,   454,   455,  1184,
    1184,  -430,  -430,   458,  -430,   350,   457,   459,   461,  -430,
    -430,  -430,   462,   463,  1394,  1184,  1444,  1444,   468,   473,
    -430,   477,  -430,   498,  -430,  -430,  1534,  1444,   479,  -430,
    1444,  -430
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    30,    29,    28,     0,     0,   137,     2,   133,     0,
       0,     1,     0,   136,     0,   135,     0,    62,    48,     3,
       4,     5,     8,     6,     9,    52,     7,    75,    47,    46,
       0,    41,    10,    11,    51,     0,    33,    34,    38,     0,
      45,     0,    23,    50,    23,    56,    57,    23,    54,    39,
       0,    69,     0,     0,    35,    37,    36,     0,   106,    92,
       0,   102,    40,   134,   101,     0,     0,   207,   224,   225,
     227,   228,   226,   229,    17,     0,     0,   216,     0,    13,
       0,   140,     0,     0,     0,   230,     0,     0,   126,   168,
       0,    12,    23,     0,     0,    16,     0,   139,   159,     0,
     128,   129,   132,     0,     0,   130,   131,   150,   151,   152,
     160,   161,     0,   153,   154,   179,   162,   163,   164,     0,
     183,     0,     0,   319,   183,   214,   215,   219,   235,   220,
     221,   222,   223,   213,   170,     0,   171,   172,     0,   173,
     174,    31,    32,    62,    48,    47,    46,    44,     0,    23,
       0,   142,   144,     0,    63,    26,     0,    64,    65,    72,
      71,    70,    74,    68,     0,   100,    67,    99,     0,    92,
     110,   108,   107,   105,    92,     0,     0,    91,    78,    17,
      13,     0,     0,     0,     0,    12,   183,   219,   220,   221,
     222,   314,   309,   310,   313,   316,   321,   322,   315,   199,
       0,   264,   266,   265,   273,   275,   277,   279,   281,   283,
     285,   293,   288,   298,   304,   308,    13,   239,    12,   183,
       0,     0,     0,     0,   185,     0,     0,     0,   195,     0,
     197,     0,     0,    20,     0,     0,     0,    21,    22,     0,
     125,   127,   149,   138,   169,     0,     0,     0,     0,   245,
     182,   239,     0,     0,     0,   246,   268,   269,     0,   323,
     324,     0,   146,    43,     0,     0,    27,    24,    59,    66,
      78,    73,     0,    17,    97,    98,    93,    96,   113,   104,
      81,    83,     0,   311,   312,   317,   318,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,   122,     0,   263,    23,   262,   255,   244,     0,   234,
     190,   193,     0,   184,   189,     0,     0,   194,   196,   218,
       0,   254,   257,    18,   258,     0,   217,     0,     0,   252,
       0,     0,   236,     0,   208,   253,   243,   237,   267,    42,
     141,   203,   143,   148,   147,    25,    83,   103,    94,   216,
       0,   124,   112,     0,     0,     0,     0,     0,     0,     0,
      82,    86,    88,    77,   276,     0,   278,   280,   282,   284,
     286,   287,   291,   292,    17,    13,    12,   294,    14,    15,
     297,   295,   296,   289,   290,   299,   300,   301,   302,   303,
     305,   306,   307,   241,   120,   260,   259,   261,   239,   233,
     183,     0,     0,     0,   232,   239,     0,   231,   239,   247,
     239,   201,   205,     0,     0,   119,   119,     0,   123,     0,
       0,    80,    79,     0,     0,    87,   109,    84,     0,   242,
     238,     0,     0,     0,   192,   177,     0,     0,     0,   165,
       0,   150,   156,   157,   158,   180,     0,   256,     0,     0,
     204,     0,    23,    95,     0,   118,     0,   111,     0,     0,
       0,    89,     0,   274,   121,   251,   187,   185,     0,     0,
       0,   248,   249,   250,   202,   200,    76,     0,     0,   119,
     119,    90,    85,     0,   186,   191,     0,     0,     0,   166,
     114,   115,     0,     0,     0,   183,     0,     0,     0,     0,
     181,     0,   178,     0,   117,   116,   187,     0,     0,   167,
       0,   188
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -430,  -430,  -430,  -430,    -6,   442,   249,  -163,  -158,   251,
     -31,  -145,   541,   -13,  -430,   517,  -430,  -430,  -430,   516,
      -5,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,  -430,
     507,   508,  -430,  -430,   289,  -430,  -430,   206,  -430,  -430,
      88,  -430,   -62,  -430,  -430,  -430,   137,   401,  -430,  -430,
    -430,  -430,   509,   513,  -430,   305,  -430,  -430,  -406,  -389,
    -430,  -430,     4,   213,   -98,  -430,   116,  -430,  -430,  -222,
    -430,   -54,   311,   208,  -336,  -430,  -381,  -386,  -354,  -430,
    -430,  -430,  -430,  -430,  -220,  -430,  -430,  -430,  -430,  -430,
    -110,   101,    65,  -430,  -430,  -430,  -429,  -430,  -430,  -430,
     270,  -430,  -430,  -430,   418,  -430,  -430,   306,  -430,  -430,
    -430,   -30,  -229,  -244,  -430,   471,   503,   -25,  -430,  -430,
    -430,   271,   -69,  -430,    -7,  -430,  -430,   149,  -430,   298,
     300,   307,   297,   313,    31,  -430,  -430,  -430,   -84,  -154,
      54,   -39,    28,    47,  -430,   103,   128,   160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    32,    33,   185,    92,    93,    94,    95,    96,
     222,   155,     6,    15,    35,    36,    37,    38,    39,    40,
      97,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   169,   281,   282,   366,   369,   370,   437,
     371,   372,   176,   177,   276,   358,   277,   166,    54,    55,
      56,    57,    58,    59,    60,   279,   361,   362,   464,   309,
     404,   427,    98,    99,   100,   101,   102,     8,     9,   103,
     104,   150,   151,   152,   352,   105,   106,   450,   107,   108,
     109,   452,   110,   111,   112,   113,   453,   114,   454,   115,
     249,   322,   493,   455,   323,   494,   324,   116,   117,   118,
     353,   422,   461,   119,   120,   121,   122,   123,   124,   125,
     126,   187,   128,   310,   440,   129,   130,   190,   132,   133,
     314,   315,   311,   201,   202,   258,   135,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   391,   392,   212,   213,
     214,   215,   192,   193,   194,   195,   196,   197
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     127,   241,   320,    63,   321,   131,   200,   343,    34,    41,
     267,   154,   274,   157,   255,   421,   158,   275,    61,   342,
     466,   231,    64,   134,    91,   347,   191,   198,   256,    34,
      41,   445,   449,    34,   148,   220,   465,   465,   288,    61,
     220,   227,   235,   229,    34,   162,    10,   495,   253,   253,
     243,   250,   301,   302,   303,   250,   167,   170,   136,   451,
     232,   233,   -52,   237,   238,   296,   297,   -51,   340,   127,
     218,   306,   307,   308,   131,   346,   390,   137,   341,    11,
     171,   172,   257,   502,   503,   341,   298,   495,   246,   228,
     221,   230,   134,    91,   261,   221,   426,   236,   153,   499,
     465,   465,   289,   254,   430,   -23,   153,   271,    16,   313,
     -23,   153,   272,   299,   300,    14,     7,   250,   262,  -110,
     512,   513,   355,   510,   484,   445,   449,   136,   340,   263,
      62,   519,   264,   138,   521,   388,   499,     1,   341,   510,
     468,   149,   283,   284,   285,   286,   137,   395,   396,   397,
     250,    62,   451,   451,   232,   -30,   325,   326,   139,     2,
       3,     4,   349,   451,   442,   264,   451,    30,   167,   165,
     -72,   456,    34,   280,   458,   153,   459,   -30,   -30,   -30,
      19,    20,    21,    22,    23,    24,   216,    26,   312,   348,
     140,   444,   175,    30,   127,   346,   354,   335,   178,   131,
     342,   347,   138,   223,   313,   341,   -29,   469,   336,   337,
     156,   153,   382,   383,   217,   393,   394,   134,    91,   168,
     375,   -71,   -62,   143,   159,   224,   -28,   139,   -29,   -29,
     -29,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    -176,   -70,  -176,  -176,   234,   250,   160,   161,   -28,   -28,
     -28,  -175,   136,  -175,  -175,   320,   321,   321,   225,   140,
     226,   274,     1,   239,    34,   280,   275,   400,   401,   402,
     251,   137,   -58,   153,   242,    34,   368,   245,   153,   259,
     260,   244,   354,   406,     2,     3,    12,  -321,  -321,  -322,
    -322,   252,   386,   265,   250,   266,   321,   268,    17,    18,
     443,   -23,   153,   294,   295,   273,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   304,   305,   434,   149,   236,
     153,    28,    29,     4,   278,   380,   381,   138,   290,   270,
     241,   127,   287,   292,   143,   316,   131,    30,   141,    31,
     291,   250,    19,    20,    21,    22,    23,    24,    25,    26,
      34,   368,   139,   293,   134,    91,   367,   237,   398,   399,
     317,    34,   433,   318,   319,   143,   329,   327,   330,   328,
     331,   332,   474,    19,    20,    21,    22,    23,    24,    25,
      26,   127,   127,   127,   140,   333,   131,   131,   131,   136,
     439,   354,   334,   264,   338,   511,   339,   344,   127,   345,
     236,   365,   403,   131,   134,   134,   134,   373,   137,   497,
     498,   351,   408,   409,   410,   384,   414,   415,   411,   412,
     416,   134,    91,    19,    20,    21,    22,    23,    24,   385,
      26,   486,    81,   413,   417,   418,   250,   217,   420,   136,
     136,   136,   419,   425,   424,   432,   127,   127,   431,   438,
     127,   131,   131,   436,   457,   131,   136,   441,   137,   137,
     137,   460,   462,   467,   138,   470,    34,   368,   471,   134,
     134,    91,   472,   134,   127,   137,   127,   127,   475,   131,
     477,   131,   131,   186,   186,   476,   127,   127,   478,   139,
     127,   131,   131,   479,   485,   131,   481,   134,   480,   134,
     134,  -155,   482,   483,   136,   136,   487,   488,   136,   134,
     134,   489,   490,   134,   138,   138,   138,   491,   219,   500,
     501,   140,   505,   137,   137,   504,   506,   137,   507,   508,
     509,   138,   136,   514,   136,   136,   188,   188,   515,   139,
     139,   139,   516,   517,   136,   136,   520,   387,   136,   389,
      13,   137,   142,   137,   137,   147,   139,   163,   164,   356,
     492,   463,   423,   137,   137,   269,   173,   137,   189,   189,
     174,   140,   140,   140,   428,   350,   435,   357,   496,   138,
     138,   518,   405,   138,   364,   407,   374,   473,   140,   378,
     376,     0,     0,     0,     0,     0,     0,     0,   377,   186,
     186,   186,   186,     0,   139,   139,   379,   138,   139,   138,
     138,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     138,     0,     0,   138,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,   139,   139,   140,   140,     0,     0,
     140,     0,     0,     0,   139,   139,     0,     0,   139,     0,
       0,     0,   188,   188,   188,   188,     0,     0,     0,     0,
       0,     0,     0,     0,   140,     0,   140,   140,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   140,     0,     0,
     140,     0,     0,     0,   189,   189,   189,   189,     0,     0,
       0,     0,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,   186,   186,
     186,   186,   186,   186,   186,   186,     0,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   143,   144,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,   188,
     145,   146,     0,     0,     0,     0,     0,     0,     0,   188,
       0,   188,   188,   188,   188,   188,   188,   188,   188,     0,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,   189,   189,   189,   189,   189,   189,   189,
     189,     0,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,    65,    66,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    73,   179,     0,     0,    76,    77,    78,     0,
       0,    19,    20,    21,    22,    23,    24,   180,    26,    80,
       0,     0,     0,     0,     0,     0,   186,     0,     0,    85,
       0,     0,   181,   182,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,    65,    66,   183,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    73,   179,     0,     0,    76,    77,    78,   188,
       0,    19,    20,    21,    22,    23,    24,   180,    26,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,   181,   182,     0,     0,     0,     0,     0,     0,
     153,   189,   -23,     0,     0,    90,    65,    66,   247,     0,
       0,     0,     0,     0,   183,   184,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,   179,     0,     0,
      76,    77,    78,     0,     0,    19,    20,    21,    22,    23,
      24,   180,    26,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,   181,   182,     0,     0,
       0,     0,     0,   429,     0,     0,    65,    66,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
      67,    68,    69,    70,    71,    72,    73,   179,     0,     0,
      76,    77,    78,     0,     0,    19,    20,    21,    22,    23,
      24,   180,    26,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,   199,    90,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
      67,    68,    69,    70,    71,    72,    73,   179,     0,     0,
      76,    77,    78,     0,     0,    19,    20,    21,    22,    23,
      24,   180,    26,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,   181,   182,     0,     0,
       0,     0,     0,     0,     0,     0,   351,    65,    66,    90,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,    67,    68,    69,    70,    71,    72,    73,   179,     0,
       0,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,   180,    26,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   153,     0,    65,    66,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,    67,    68,    69,    70,    71,    72,    73,   179,     0,
       0,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,   180,    26,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,    67,    68,    69,    70,    71,    72,    73,    74,     1,
      75,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,    79,    26,    80,    81,    82,    83,    84,     0,
       0,     2,     3,     4,    85,    86,    87,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    88,    89,
      90,    67,    68,    69,    70,    71,    72,    73,    74,     1,
      75,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,    79,    26,    80,    81,    82,    83,    84,     0,
       0,     2,     3,     4,    85,    86,    87,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    30,   240,    89,
      90,    67,    68,    69,    70,    71,    72,    73,    74,     1,
      75,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,    79,    26,    80,    81,    82,    83,    84,     0,
       0,     2,     3,     4,    85,    86,    87,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    89,
      90,    67,    68,    69,    70,    71,    72,    73,   179,     0,
      75,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,   180,    26,    80,     0,    82,    83,    84,     0,
       0,     0,     0,     0,    85,    86,    87,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    89,
      90,    67,    68,    69,    70,    71,    72,    73,   179,     0,
      75,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,   180,    26,    80,     0,   446,   447,   448,     0,
       0,     0,     0,     0,    85,    86,    87,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    89,
      90,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,    79,    26,    80,    81,     0,    65,    66,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,    72,    73,   179,     0,
      90,    76,    77,    78,     0,     0,    19,    20,    21,    22,
      23,    24,   180,    26,    80,    67,    68,    69,    70,    71,
      72,    73,   179,     0,    85,    76,   359,   360,     0,     0,
      19,    20,    21,    22,    23,    24,   180,    26,    80,     0,
      90,     0,    17,    18,     0,     0,     0,     0,    85,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,    90,    28,    29,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    31
};

static const yytype_int16 yycheck[] =
{
      30,    99,   224,    16,   224,    30,    75,   251,    14,    14,
     155,    42,   175,    44,   124,   351,    47,   175,    14,   248,
     426,    90,    18,    30,    30,   254,    65,    66,    15,    35,
      35,   412,   413,    39,    39,     5,   425,   426,     6,    35,
       5,    17,     5,    17,    50,    50,    24,   476,     5,     5,
     104,   120,    12,    13,    14,   124,    52,    24,    30,   413,
      91,    92,    17,    94,    95,    10,    11,    17,    17,    99,
      76,    55,    56,    57,    99,    17,   298,    30,    27,     0,
      47,    48,    69,   489,   490,    27,    31,   516,   119,    65,
      60,    65,    99,    99,   148,    60,    66,    60,    61,   480,
     489,   490,    70,    60,    60,    60,    61,   169,    24,   219,
      60,    61,   174,    58,    59,    63,     0,   186,   149,    66,
     506,   507,   267,   504,   460,   506,   507,    99,    17,    65,
      14,   517,    68,    30,   520,   298,   517,    25,    27,   520,
      29,    17,   181,   182,   183,   184,    99,   301,   302,   303,
     219,    35,   506,   507,   185,    25,   225,   226,    30,    47,
      48,    49,    65,   517,   408,    68,   520,    63,   164,    65,
      40,   415,   178,   178,   418,    61,   420,    47,    48,    49,
      32,    33,    34,    35,    36,    37,    38,    39,   219,   258,
      30,   411,    30,    63,   224,    17,   265,    17,    66,   224,
     429,   430,    99,    60,   314,    27,    25,    29,    28,    29,
      60,    61,   296,   297,    66,   299,   300,   224,   224,    17,
     289,    40,    17,    24,    25,    66,    25,    99,    47,    48,
      49,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      65,    40,    67,    68,     5,   314,    47,    48,    47,    48,
      49,    65,   224,    67,    68,   477,   476,   477,    66,    99,
      66,   424,    25,     5,   270,   270,   424,   306,   307,   308,
      66,   224,    60,    61,    65,   281,   281,    60,    61,     3,
       4,    65,   351,   314,    47,    48,    49,     3,     4,     3,
       4,    60,   298,    69,   363,    62,   516,    24,    24,    25,
     410,    60,    61,     8,     9,    24,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    53,    54,    16,    17,    60,
      61,    47,    48,    49,    63,   294,   295,   224,     7,    66,
     428,   361,    65,    73,    24,    17,   361,    63,    64,    65,
      72,   410,    32,    33,    34,    35,    36,    37,    38,    39,
     356,   356,   224,    74,   361,   361,    46,   388,   304,   305,
      17,   367,   367,    60,    49,    24,    67,    65,    60,    65,
      17,    27,   441,    32,    33,    34,    35,    36,    37,    38,
      39,   411,   412,   413,   224,    24,   411,   412,   413,   361,
     403,   460,    27,    68,    60,   505,    17,    17,   428,    17,
      60,    17,    67,   428,   411,   412,   413,    68,   361,   478,
     479,    63,    66,    49,    65,    24,    49,    66,    68,    67,
       5,   428,   428,    32,    33,    34,    35,    36,    37,    38,
      39,   462,    41,    67,    49,    66,   505,    66,    66,   411,
     412,   413,    67,    66,    68,    28,   476,   477,    60,    71,
     480,   476,   477,    67,    17,   480,   428,    68,   411,   412,
     413,    68,    67,    64,   361,    16,   472,   472,    17,   476,
     477,   477,    68,   480,   504,   428,   506,   507,    67,   504,
      66,   506,   507,    65,    66,    65,   516,   517,    66,   361,
     520,   516,   517,    66,    64,   520,    67,   504,    45,   506,
     507,    45,    67,    67,   476,   477,    67,    67,   480,   516,
     517,    66,    66,   520,   411,   412,   413,    17,    76,    65,
      65,   361,    65,   476,   477,    67,    67,   480,    67,    67,
      67,   428,   504,    65,   506,   507,    65,    66,    65,   411,
     412,   413,    65,    45,   516,   517,    67,   298,   520,   298,
       9,   504,    35,   506,   507,    39,   428,    50,    50,   270,
     472,   424,   356,   516,   517,   164,    57,   520,    65,    66,
      57,   411,   412,   413,   361,   264,   368,   272,   477,   476,
     477,   516,   312,   480,   278,   314,   288,   438,   428,   292,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   181,
     182,   183,   184,    -1,   476,   477,   293,   504,   480,   506,
     507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,
     517,    -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   504,    -1,   506,   507,   476,   477,    -1,    -1,
     480,    -1,    -1,    -1,   516,   517,    -1,    -1,   520,    -1,
      -1,    -1,   181,   182,   183,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   504,    -1,   506,   507,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   516,   517,    -1,    -1,
     520,    -1,    -1,    -1,   181,   182,   183,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,   290,   291,
     292,   293,   294,   295,   296,   297,    -1,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,
      -1,   290,   291,   292,   293,   294,   295,   296,   297,    -1,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,    -1,   290,   291,   292,   293,   294,   295,   296,
     297,    -1,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,   438,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      61,   438,    63,    -1,    -1,    66,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,     3,     4,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,     3,     4,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,     3,     4,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      66,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    50,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      66,    -1,    24,    25,    -1,    -1,    -1,    -1,    50,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    66,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    47,    48,    49,    78,    89,   143,   144,   145,
      24,     0,    49,    89,    63,    90,    24,    24,    25,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    47,    48,
      63,    65,    79,    80,    81,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   125,   126,   127,   128,   129,   130,
     131,   139,   143,    90,   139,     3,     4,    17,    18,    19,
      20,    21,    22,    23,    24,    26,    27,    28,    29,    38,
      40,    41,    42,    43,    44,    50,    51,    52,    64,    65,
      66,    81,    82,    83,    84,    85,    86,    97,   139,   140,
     141,   142,   143,   146,   147,   152,   153,   155,   156,   157,
     159,   160,   161,   162,   164,   166,   174,   175,   176,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   192,
     193,   194,   195,   196,   201,   203,   219,   220,   222,   223,
     224,    64,    92,    24,    25,    47,    48,    96,    97,    17,
     148,   149,   150,    61,    87,    88,    60,    87,    87,    25,
      47,    48,    97,   107,   108,    65,   124,   139,    17,   110,
      24,    47,    48,   129,   130,    30,   119,   120,    66,    24,
      38,    53,    54,    75,    76,    81,   181,   188,   192,   193,
     194,   218,   219,   220,   221,   222,   223,   224,   218,    65,
     199,   200,   201,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   215,   216,   217,   218,    38,    66,    81,    82,
       5,    60,    87,    60,    66,    66,    66,    17,    65,    17,
      65,   199,    87,    87,     5,     5,    60,    87,    87,     5,
      64,   141,    65,   148,    65,    60,    87,     5,    60,   167,
     199,    66,    60,     5,    60,   167,    15,    69,   202,     3,
       4,   148,    87,    65,    68,    69,    62,    88,    24,   124,
      66,   119,   119,    24,    84,    85,   121,   123,    63,   132,
      97,   111,   112,   218,   218,   218,   218,    65,     6,    70,
       7,    72,    73,    74,     8,     9,    10,    11,    31,    58,
      59,    12,    13,    14,    53,    54,    55,    56,    57,   136,
     190,   199,    87,   167,   197,   198,    17,    17,    60,    49,
     146,   161,   168,   171,   173,   199,   199,    65,    65,    67,
      60,    17,    27,    24,    27,    17,    28,    29,    60,    17,
      17,    27,   189,   190,    17,    17,    17,   189,   199,    65,
     149,    63,   151,   177,   199,    88,   111,   132,   122,    28,
      29,   133,   134,   181,   184,    17,   113,    46,    97,   114,
     115,   117,   118,    68,   206,   199,   207,   208,   209,   210,
     211,   211,   215,   215,    24,    38,    81,    83,    84,    86,
     146,   213,   214,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   218,    67,   137,   177,    87,   198,    66,    49,
      65,    68,    67,    67,    49,    66,     5,    49,    66,    67,
      66,   151,   178,   114,    68,    66,    66,   138,   140,    60,
      60,    60,    28,    97,    16,   150,    67,   116,    71,    90,
     191,    68,   190,   167,   161,   153,    42,    43,    44,   153,
     154,   155,   158,   163,   165,   170,   190,    17,   190,   190,
      68,   179,    67,   123,   135,   136,   135,    64,    29,    29,
      16,    17,    68,   204,   199,    67,    65,    66,    66,    66,
      45,    67,    67,    67,   151,    64,    87,    67,    67,    66,
      66,    17,   117,   169,   172,   173,   168,   199,   199,   153,
      65,    65,   135,   135,    67,    65,    67,    67,    67,    67,
     153,   167,   154,   154,    65,    65,    65,    45,   169,   154,
      67,   154
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
      86,    86,    86,    87,    87,    87,    87,    88,    89,    89,
      89,    90,    91,    91,    92,    92,    92,    92,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     102,   102,   103,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   108,   109,   109,   110,   111,   111,   112,
     113,   113,   114,   114,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   121,   122,   122,   123,   123,   124,
     124,   125,   126,   127,   127,   128,   128,   129,   129,   130,
     131,   132,   133,   133,   134,   134,   134,   134,   135,   135,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   141,   142,   143,   144,   144,   145,   145,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   156,   157,   158,   159,   160,
     161,   161,   161,   161,   161,   161,   161,   162,   163,   164,
     165,   166,   167,   167,   168,   168,   169,   169,   170,   171,
     171,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   178,   178,   178,   179,   179,   180,   181,   181,   182,
     183,   183,   184,   184,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   187,   188,   188,   188,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   194,
     194,   194,   195,   195,   195,   195,   195,   195,   195,   196,
     196,   197,   197,   198,   199,   200,   200,   201,   202,   202,
     203,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   208,   208,   209,   209,   210,   210,   210,   211,   211,
     211,   211,   211,   211,   212,   212,   213,   214,   215,   215,
     215,   215,   216,   216,   216,   217,   217,   217,   217,   218,
     218,   218,   218,   218,   219,   220,   221,   221,   221,   222,
     222,   222,   222,   223,   224
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     2,     0,     2,     3,     1,     2,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     2,     2,     3,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     6,     2,     0,     3,
       2,     0,     1,     0,     2,     3,     0,     2,     1,     3,
       4,     1,     0,     2,     2,     3,     0,     1,     1,     1,
       1,     2,     1,     4,     3,     2,     1,     1,     1,     5,
       1,     4,     1,     0,     5,     5,     7,     7,     1,     0,
       2,     3,     0,     1,     0,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     4,     3,     2,     1,     2,     1,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     1,
       1,     9,     1,     0,     1,     0,     1,     0,     9,     1,
       1,     1,     3,     1,     3,     2,     3,     2,     3,     2,
       4,     1,     3,     0,     1,     0,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     3,     1,     3,     3,     5,     0,
       1,     0,     1,     3,     3,     2,     2,     4,     6,     6,
       6,     6,     3,     3,     3,     3,     5,     3,     3,     4,
       4,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     2,     2
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

#line 2021 "parse_oracle.tab.cc"

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
#line 710 "parse_oracle.yy"

