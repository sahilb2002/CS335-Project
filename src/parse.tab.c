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
#line 1 "src/parse.y"


    #include<iostream>
    #include<fstream>
    #include<AST.h>
    #include<symbol_table.h>
    #include<typecheck.h>
    #include<TAC.h>
    #include<map>
    #include<cstring>
    using namespace std;

    
    extern int yylex();
    extern int yyparse();
    extern int yylineno;
    extern treeNode* root;
    extern FILE* yyin;
    extern SymbolTable* current;

    // 3AC
    int temp_addr = 0;
    int instr_addr = 0;

    string dType;
    string retType;
    int mod_flag;
    bool* ptr_func_def = NULL;
    extern vector<SymbTbl_entry*> methKeys;
    int flag = 0;
    int dims_count_1 = 0;
    int dims_count_2 = 0;
    int dims_count_3 = 0;
    int arr_d = 0;
    int flag_array = 0;

    map<char, int> Size ={
        {'I', 4},
        {'F', 4},
        {'D', 8},
        {'L', 8},
        {'C', 1}
    };
    
    FILE* dotfile;

    void yyerror(string s) {
        cout << "[Line no: " << yylineno << "] " << "error: " << s << endl;
        exit(-1);
    }


#line 123 "src/parse.tab.c"

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
#ifndef YY_YY_INCLUDE_PARSE_TAB_H_INCLUDED
# define YY_YY_INCLUDE_PARSE_TAB_H_INCLUDED
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
    ID = 258,
    INT = 259,
    FLOAT = 260,
    DOUBLE = 261,
    CHAR = 262,
    STRING = 263,
    BOOL = 264,
    LONG = 265,
    KEY_INT = 266,
    KEY_FLOAT = 267,
    KEY_LONG = 268,
    KEY_DOUBLE = 269,
    KEY_BOOL = 270,
    KEY_CHAR = 271,
    KEY_STRING = 272,
    KEY_VOID = 273,
    KEY_NEW = 274,
    KEY_FOR = 275,
    KEY_WHILE = 276,
    KEY_IF = 277,
    KEY_ELSE = 278,
    KEY_CONTINUE = 279,
    KEY_BREAK = 280,
    KEY_RETURN = 281,
    KEY_ASSERT = 282,
    KEY_YIELD = 283,
    KEY_SUPER = 284,
    KEY_IMPORT = 285,
    KEY_THROW = 286,
    KEY_CASE = 287,
    KEY_DEFAULT = 288,
    KEY_SWITCH = 289,
    KEY_DO = 290,
    KEY_PRIVATE = 291,
    KEY_PUBLIC = 292,
    KEY_STATIC = 293,
    KEY_PROTECTED = 294,
    KEY_CLASS = 295,
    ASSIGN_OP = 296,
    INCREMENT = 297,
    DECREMENT = 298,
    LOG_OR = 299,
    LOG_AND = 300,
    EQUAL = 301,
    NOT_EQUAL = 302,
    GTR_EQUAL = 303,
    LESS_EQUAL = 304,
    LEFT_SHIFT = 305,
    RIGHT_SHIFT = 306,
    SIGN_SHIFT = 307,
    ARROW = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "src/parse.y"

    string *str;
    treeNode* ptr;


#line 235 "src/parse.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSE_TAB_H_INCLUDED  */



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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1071

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  258
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  472

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
       2,     2,     2,    77,     2,     2,     2,    75,    69,     2,
      59,    60,    56,    72,    62,    73,    55,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    54,
      70,    63,    71,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    67,    58,    76,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   148,   155,   161,   168,   174,   181,   182,
     186,   189,   194,   200,   205,   208,   213,   213,   223,   231,
     234,   237,   247,   250,   253,   259,   262,   265,   268,   278,
     282,   282,   295,   303,   310,   314,   323,   332,   338,   342,
     348,   353,   360,   366,   371,   378,   385,   394,   400,   405,
     413,   418,   425,   431,   440,   443,   446,   449,   452,   457,
     460,   463,   466,   471,   481,   492,   496,   513,   529,   534,
     539,   544,   549,   554,   560,   567,   575,   585,   597,   604,
     604,   611,   611,   619,   638,   656,   672,   689,   704,   724,
     747,   775,   778,   791,   794,   812,   815,   838,   844,   857,
     873,   895,   907,   930,   940,   951,   973,   981,   988,  1005,
    1013,  1016,  1017,  1018,  1019,  1020,  1023,  1080,  1085,  1086,
    1089,  1105,  1108,  1113,  1148,  1162,  1172,  1204,  1213,  1214,
    1221,  1222,  1237,  1238,  1253,  1254,  1270,  1271,  1286,  1287,
    1302,  1303,  1318,  1319,  1332,  1347,  1348,  1361,  1374,  1387,
    1402,  1403,  1416,  1429,  1444,  1445,  1458,  1473,  1474,  1487,
    1500,  1515,  1516,  1517,  1529,  1541,  1544,  1565,  1586,  1589,
    1600,  1612,  1617,  1644,  1647,  1654,  1657,  1662,  1694,  1704,
    1719,  1725,  1728,  1739,  1742,  1743,  1744,  1787,  1797,  1817,
    1830,  1846,  1892,  1939,  1961,  1984,  1985,  1991,  1992,  1997,
    2007,  2017,  2025,  2033,  2044,  2055,  2061,  2067,  2076,  2079,
    2085,  2090,  2095,  2100,  2105,  2110,  2115,  2123,  2123,  2136,
    2143,  2151,  2157,  2160,  2161,  2162,  2163,  2169,  2172,  2180,
    2189,  2192,  2202,  2209,  2217,  2220,  2227,  2227,  2234,  2240,
    2240,  2249,  2249,  2274,  2274,  2295,  2307,  2320,  2330,  2333,
    2339,  2345,  2348,  2355,  2362,  2369,  2378,  2415,  2446
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT", "FLOAT", "DOUBLE", "CHAR",
  "STRING", "BOOL", "LONG", "KEY_INT", "KEY_FLOAT", "KEY_LONG",
  "KEY_DOUBLE", "KEY_BOOL", "KEY_CHAR", "KEY_STRING", "KEY_VOID",
  "KEY_NEW", "KEY_FOR", "KEY_WHILE", "KEY_IF", "KEY_ELSE", "KEY_CONTINUE",
  "KEY_BREAK", "KEY_RETURN", "KEY_ASSERT", "KEY_YIELD", "KEY_SUPER",
  "KEY_IMPORT", "KEY_THROW", "KEY_CASE", "KEY_DEFAULT", "KEY_SWITCH",
  "KEY_DO", "KEY_PRIVATE", "KEY_PUBLIC", "KEY_STATIC", "KEY_PROTECTED",
  "KEY_CLASS", "ASSIGN_OP", "INCREMENT", "DECREMENT", "LOG_OR", "LOG_AND",
  "EQUAL", "NOT_EQUAL", "GTR_EQUAL", "LESS_EQUAL", "LEFT_SHIFT",
  "RIGHT_SHIFT", "SIGN_SHIFT", "ARROW", "';'", "'.'", "'*'", "'{'", "'}'",
  "'('", "')'", "':'", "','", "'='", "'['", "']'", "'?'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'/'", "'%'", "'~'", "'!'", "$accept",
  "START", "ClassDeclaration_list", "ImportDecl_list", "ImportDecl",
  "Imp_list", "BODY", "BLCK_STMNT", "BLCK", "$@1", "STMNT_without_sub",
  "SwitchStatement", "$@2", "SwitchBlock",
  "SwitchBlockStatementGroup_list", "SwitchRule_list",
  "SwitchBlockStatementGroup", "SwitchLabel_list", "SwitchRule",
  "SwitchLabel", "CaseConstant_list", "ThrowStatement", "Assert_stmnt",
  "STMNT", "STMNT_noshortif", "WHILE_STMNT", "WHILE_STMNT_noshortif",
  "FOR", "BASIC_FOR", "BASIC_FOR_noshortif", "FOR_UPDATE", "FOR_INIT",
  "STMNT_EXPR_list", "IF_THEN", "IF_THEN_ELSE", "IF_THEN_ELSE_noshortif",
  "DEF_VAR", "$@3", "$@4", "VAR_LIST", "VARA", "Array_init_1D",
  "Array_init_2D", "Array_init_3D", "VAR", "L3D", "CONT3D", "L2D",
  "CONT2D", "L1D", "CONT1D", "STMNT_EXPR", "Meth_invoc", "Expr",
  "AssignmentExpression", "Assignment", "AssignmentOperator",
  "ExpressionName", "AmbiguousName", "LeftHandSide",
  "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "InclusiveOrExpression",
  "ExclusiveOrExpression", "AndExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PreIncrementExpression",
  "PreDecrementExpression", "UnaryExpressionNotPlusMinus",
  "CastExpression", "PostfixExpression", "FieldAccess", "Primary",
  "PrimaryNoNewArray", "ArrayCreationExpr", "DimExpr", "ArrayAccess",
  "PostIncrementExpression", "PostDecrementExpression", "EMP_EXPR",
  "ARG_LIST", "ARG_LISTp", "LIT", "STAT", "DTYPE", "ClassDeclaration",
  "$@5", "Class_body", "Class_body_dec_list", "Class_body_dec",
  "Class_DEF_VAR", "MethodDeclaration", "Meth_Body", "DIMS_list", "DIMS",
  "Meth_Head", "$@6", "$@7", "Meth_decl", "$@8", "$@9", "Param_list",
  "Param", "MOD_EMPTY_LIST", "MOD_LIST", "MOD", "ConstructorHead",
  "ConstructorDeclaration", YY_NULLPTR
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
     305,   306,   307,   308,    59,    46,    42,   123,   125,    40,
      41,    58,    44,    61,    91,    93,    63,   124,    94,    38,
      60,    62,    43,    45,    47,    37,   126,    33
};
# endif

#define YYPACT_NINF (-396)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-250)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     315,     3,  -396,  -396,  -396,  -396,    59,   423,   315,  -396,
    -396,    34,   238,  -396,  -396,    92,  -396,  -396,   423,  -396,
     127,  -396,  -396,   233,  -396,  -396,    23,   111,  -396,   119,
     224,  -396,  -396,   154,  -396,   158,  -396,   324,  -396,  -396,
    -396,   124,   158,  -396,   123,  -396,  -396,  -396,   164,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,   231,    14,   168,  -396,
    -396,   733,    21,   179,   250,   -19,   194,   -12,  -396,  -396,
     207,   250,  -396,  -396,  -396,  -396,    25,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,   380,   232,   241,   243,   229,   258,
     953,   953,   953,   242,   953,   259,   792,   323,   953,   953,
    -396,   926,   953,   953,   953,   953,   674,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,    48,  -396,  -396,  -396,   276,
    -396,   304,  -396,  -396,   102,   300,    -2,  -396,    84,   327,
     311,   316,   317,   261,   209,   271,   268,   210,  -396,  -396,
    -396,  -396,  -396,   301,   108,   351,   367,  -396,   165,  -396,
    -396,  -396,   481,  -396,   408,   159,  -396,   250,   391,  -396,
     404,   953,   953,  -396,  -396,   463,   406,  -396,   463,    54,
     414,  -396,   953,   953,  -396,  -396,   429,  -396,   435,    28,
     447,   500,   450,   953,   487,  -396,    98,  -396,  -396,  -396,
    -396,   449,   451,  -396,  -396,  -396,  -396,  -396,  -396,   953,
     456,   452,  -396,  -396,   156,  -396,  -396,  -396,   301,   306,
     347,  -396,  -396,   953,   953,   509,  -396,  -396,   953,   953,
     953,   953,   953,   953,   953,   953,   953,   953,   953,   953,
     953,   953,   953,   953,   953,   953,   953,   953,   953,  -396,
    -396,   510,   953,   463,   454,  -396,  -396,   481,  -396,   481,
     455,  -396,   457,   335,  -396,  -396,  -396,   461,   953,   953,
     470,   470,   459,   475,  -396,  -396,   953,  -396,  -396,  -396,
     476,   479,   463,  -396,   953,   953,  1012,  -396,   480,   477,
     488,   486,  -396,   327,   485,   311,   316,   317,   261,   209,
     209,   271,   271,   271,   271,   268,   268,   268,   210,   210,
    -396,  -396,  -396,  -396,   494,   461,   953,  -396,   205,  -396,
     339,   502,   495,   953,   792,   851,   462,  -396,   953,   461,
    -396,   514,  -396,  -396,   953,  -396,   953,  -396,   498,  -396,
      30,   953,  -396,  -396,   499,  -396,   511,   512,   546,  -396,
     549,  -396,    48,  -396,  -396,  -396,   516,   515,  1012,  -396,
    -396,   519,   481,   953,  -396,  -396,   513,  -396,   953,   953,
     792,   520,    76,  -396,   522,   524,   452,   953,   521,   101,
    -396,   345,   526,   528,  -396,   953,   953,  -396,  -396,   175,
     181,  -396,   448,  -396,    62,  -396,   792,   525,   953,  -396,
     953,    43,   953,   851,   851,   535,   517,  -396,  -396,  -396,
     523,   530,  -396,  -396,   539,  -396,   615,   532,   328,  -396,
    -396,   533,   529,  -396,   481,   541,  -396,  -396,   536,  -396,
     579,  1012,   953,  -396,  -396,  -396,  -396,   550,   953,  -396,
     542,   116,  -396,   540,   851,   545,  -396,  -396,   543,   953,
    -396,   541,    44,  -396,   851,  -396,   544,  -396,   481,   553,
    -396,  -396,  -396,   547,   548,   147,  -396,   953,   953,  -396,
     553,   551,   552,  -396,  -396,   562,   953,   563,   565,   953,
     566,  -396
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     249,   209,   252,   253,   254,   255,     0,     3,   249,     7,
       5,     0,   248,   251,   208,     0,     1,     4,     2,     6,
       0,   250,    11,     0,   217,     8,     0,     0,    10,     0,
     249,   218,     9,   254,   220,     0,   225,   249,   222,   223,
     224,     0,     0,   227,    16,   226,   219,   221,     0,   210,
     213,   214,   212,   211,   215,   216,   236,     0,     0,   258,
      18,   209,     0,     0,     0,    97,     0,     0,    86,    85,
     234,     0,   238,   231,   230,   229,   124,   201,   202,   207,
     203,   204,   205,   206,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,   208,     0,     0,
      29,     0,     0,     0,     0,     0,   209,    13,    19,    54,
      27,    26,    25,    14,    57,   209,    58,    55,    56,     0,
     184,     0,   117,   119,   174,     0,     0,   118,   130,   132,
     134,   136,   138,   140,   142,   145,   150,   154,   157,   161,
     162,   165,   171,   168,   185,   173,   179,   180,   183,   175,
     176,   181,     0,   257,     0,     0,   246,     0,     0,   240,
     241,     0,   196,   233,   228,     0,     0,   235,     0,     0,
       0,    65,     0,     0,    22,    23,   124,   195,     0,     0,
       0,     0,     0,     0,     0,    79,   174,   166,   185,   183,
     167,     0,     0,   163,   164,   169,   170,    17,    12,     0,
       0,    71,    70,    74,   184,   110,   111,   112,     0,   114,
     113,    15,    20,   198,     0,     0,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   193,
     194,     0,     0,     0,    97,   247,   256,     0,   237,     0,
       0,    87,     0,    97,    84,    83,   232,    82,   198,     0,
     188,   187,     0,     0,    21,    52,     0,    24,   178,    51,
       0,     0,     0,   182,     0,   196,     0,   200,     0,   197,
       0,   123,   120,   133,     0,   135,   137,   139,   141,   143,
     144,   148,   149,   146,   147,   151,   152,   153,   155,   156,
     158,   159,   160,   177,     0,    78,   196,   245,     0,   244,
      98,     0,     0,     0,     0,     0,     0,    30,     0,    80,
     172,     0,    73,   116,     0,   191,     0,   192,     0,   242,
       0,   196,   186,   189,     0,    63,     0,     0,    54,    75,
       0,    61,   209,    62,    60,    53,     0,     0,    69,   199,
     131,    98,     0,     0,    88,    91,     0,   190,     0,     0,
       0,     0,     0,    31,     0,     0,    68,   196,     0,     0,
     109,    99,     0,     0,    76,   196,     0,    48,    34,     0,
       0,    38,   209,    40,     0,    28,     0,     0,     0,   107,
       0,     0,   196,     0,     0,     0,    47,    50,    33,    37,
     209,     0,    32,    39,     0,    36,   209,     0,     0,    43,
      66,    99,     0,   108,     0,     0,    89,    93,     0,    64,
       0,    69,     0,    35,    42,    45,    46,     0,   196,    92,
       0,     0,   106,   100,     0,     0,    49,    44,     0,     0,
     104,     0,     0,    77,     0,   100,     0,   105,     0,     0,
      90,    95,    67,     0,     0,     0,   103,     0,     0,   101,
       0,     0,     0,   102,    94,     0,     0,     0,     0,     0,
       0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -396,  -396,   599,  -396,   606,  -396,   554,  -102,   -29,  -396,
    -290,  -396,  -396,  -396,  -396,  -396,   248,   251,   252,  -332,
    -396,   230,  -396,   -88,  -318,  -396,  -396,  -288,  -396,  -396,
     234,   303,  -333,  -396,  -396,  -396,  -106,  -396,  -396,  -158,
     489,  -396,  -396,  -396,   -33,  -396,  -396,  -302,  -396,  -395,
    -396,   375,  -104,   -89,  -396,  -101,  -396,   -34,  -396,  -396,
    -310,  -396,   433,   438,   434,   437,   439,   262,   137,   143,
     265,    -6,   -97,   -96,  -396,  -396,   -94,   191,  -396,  -396,
    -396,   491,   211,   -93,   -92,  -155,   407,  -396,  -396,   118,
     -41,   115,  -396,  -396,  -396,   625,  -396,  -396,  -396,  -396,
     601,  -396,  -396,  -396,   -40,  -396,  -396,   417,   420,   130,
    -396,   656,  -396,  -396
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    23,   406,   107,   108,    61,
     109,   110,   346,   363,   379,   380,   381,   382,   383,   407,
     396,   111,   112,   113,   340,   114,   341,   115,   116,   343,
     365,   200,   201,   117,   118,   344,   119,   272,   168,    67,
      68,   354,   416,   450,    69,   451,   455,   417,   431,   355,
     369,   203,   120,   121,   122,   123,   218,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   260,   148,   149,   150,   178,   278,   279,   151,   152,
     154,    10,    27,    31,    37,    38,    39,    40,    75,    70,
      71,    58,    63,    64,    72,   249,   250,   155,   156,    11,
      12,    13,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   177,   179,   180,   198,   182,    45,   252,   184,   202,
     257,   204,   191,    59,   205,   366,   350,    65,   206,   207,
     432,   208,   209,   210,   159,   338,    28,   342,   -81,    74,
     384,   167,    49,    50,    51,    52,    53,    54,    55,   216,
     160,    14,   164,   170,   161,   162,   447,   401,   404,   352,
     165,    76,    77,    78,    79,    80,    81,    82,    83,    16,
     192,   217,   414,   448,   186,   186,   397,    84,   186,   186,
     186,   186,   251,   177,    20,   419,   420,    93,    66,    29,
    -125,   153,   265,   262,   263,   305,    97,   353,   366,   266,
      98,    99,   187,   190,   270,    22,   193,   194,   195,   196,
     415,   449,   -72,   338,   338,   342,   342,   199,   376,   377,
     191,   243,   436,   258,   319,   408,   443,   248,   259,    15,
     321,   245,    17,   409,   277,   280,   452,    48,   219,   282,
      24,   284,   255,    17,   378,    49,    50,    51,    52,    53,
      54,    55,    56,  -127,   338,    36,   342,   456,    35,  -128,
     220,   328,    36,   304,   338,    35,   342,   213,   463,   389,
      41,   213,   214,   390,    20,  -127,   214,    41,    30,   277,
     312,  -128,   204,    32,   440,   205,   356,   316,   441,   206,
     207,    60,   208,   209,   210,   186,   177,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   459,  -129,   376,   377,   460,
    -115,  -208,   387,   376,   377,    44,  -115,   177,  -115,   246,
     395,   247,    73,    62,   334,    44,   335,   339,  -129,   347,
     300,   301,   302,   398,  -239,   349,   202,   418,   204,   402,
     186,   205,   177,    66,   204,   206,   207,   205,   208,   209,
     210,   206,   207,   158,   208,   209,   210,   227,   228,   163,
       2,     3,    33,     5,   370,   329,   236,   247,   320,   372,
     373,   166,   374,   438,     2,     3,     4,     5,   177,   229,
     230,  -209,    34,   174,   237,   238,   177,    25,    26,   188,
     188,   171,   186,   188,   188,   188,   188,   181,   410,   412,
     172,   413,   173,   177,   198,   335,   339,   225,   226,   189,
     189,   368,   175,   189,   189,   189,   189,   204,   183,   427,
     205,   231,   232,   233,   206,   207,   185,   208,   209,   210,
     211,   176,    77,    78,    79,    80,    81,    82,    83,   177,
     234,   235,   186,   239,   240,     1,   374,    84,  -175,  -175,
     446,     2,     3,     4,     5,   215,   410,    93,   212,    94,
       2,     3,    33,     5,   291,   292,   293,   294,   461,   462,
      98,    99,   221,   430,   295,   296,   297,   467,   222,   425,
     470,  -209,    46,   169,   223,    44,   224,   101,   186,  -176,
    -176,    49,    50,    51,    52,    53,    54,    55,   161,   162,
     102,   103,   330,   331,   104,   105,   241,   454,   391,   392,
     188,   244,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     189,   242,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     160,    76,    77,    78,    79,    80,    81,    82,    83,     2,
       3,     4,     5,  -249,  -243,   188,   253,    84,    85,    86,
      87,   256,    88,    89,    90,    91,    92,    93,   259,    94,
     376,   377,    95,    96,  -125,   189,    97,   289,   290,   264,
      98,    99,    49,    50,    51,    52,    53,    54,    55,   298,
     299,   267,   100,   268,   269,    44,   405,   101,   271,   273,
     275,   274,   281,   303,   276,   309,   345,   188,   306,   314,
     102,   103,   310,   165,   104,   105,    76,    77,    78,    79,
      80,    81,    82,    83,   313,   315,   317,   189,   318,   324,
     323,  -126,    84,    85,    86,    87,   326,    88,    89,    90,
      91,    92,    93,   325,    94,   376,   377,    95,    96,   327,
     333,    97,   332,   351,   357,    98,    99,   188,   348,   -59,
     358,   359,   360,   362,   375,   364,   385,   100,   371,   422,
      44,   423,   101,   367,   386,   388,   393,   189,   394,   421,
     411,   409,   408,   424,   429,   102,   103,   428,   353,   104,
     105,   433,   434,   442,   437,   444,   439,    18,   445,   453,
     415,   457,   458,   188,    19,   106,   464,   465,    76,    77,
      78,    79,    80,    81,    82,    83,   466,   399,   468,   469,
     400,   471,   403,   189,    84,    85,    86,    87,   426,    88,
      89,    90,    91,    92,    93,   361,    94,   -41,   -41,    95,
      96,   322,   283,    97,   254,   435,   286,    98,    99,   285,
     287,   261,    47,   288,   157,   311,   308,   307,    21,   100,
       0,     0,    44,   -41,   101,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,   102,   103,     0,
       0,   104,   105,    84,    85,    86,    87,     0,    88,    89,
      90,    91,    92,    93,     0,    94,     0,     0,    95,    96,
       0,     0,    97,     0,     0,     0,    98,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,    44,   197,   101,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,   102,   103,     0,     0,
     104,   105,    84,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,     0,    94,     0,     0,    95,    96,     0,
       0,    97,     0,     0,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,     0,     0,
      44,     0,   101,     0,     0,   176,    77,    78,    79,    80,
      81,    82,    83,     0,     0,   102,   103,     0,     0,   104,
     105,    84,    85,    86,    87,     0,    88,    89,    90,    91,
      92,    93,     0,    94,     0,     0,    95,    96,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,    44,
       0,   101,     0,     0,   176,    77,    78,    79,    80,    81,
      82,    83,     0,     0,   102,   103,     0,     0,   104,   105,
      84,    85,   336,   337,     0,    88,    89,    90,    91,    92,
      93,     0,    94,     0,     0,    95,    96,     0,     0,     0,
       0,     0,     0,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,    44,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,   104,   105,   176,
      77,    78,    79,    80,    81,    82,    83,    49,    50,    51,
      52,    53,    54,    55,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   176,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    98,    99,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   102,   103,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,   176,    77,    78,    79,    80,
      81,    82,    83,     0,     0,   102,   103,     0,     0,   104,
     105,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199
};

static const yytype_int16 yycheck[] =
{
      41,    90,    91,    92,   106,    94,    35,   162,    96,   115,
     168,   115,   101,    42,   115,   348,   326,     3,   115,   115,
     415,   115,   115,   115,    64,   315,     3,   315,     3,    58,
     362,    71,    11,    12,    13,    14,    15,    16,    17,    41,
      59,    38,    54,    84,    63,    64,   441,   379,   380,    19,
      62,     3,     4,     5,     6,     7,     8,     9,    10,     0,
     101,    63,    19,    19,    98,    99,   376,    19,   102,   103,
     104,   105,   161,   162,    40,   393,   394,    29,    64,    56,
      55,    60,    54,   172,   173,   243,    38,    57,   421,    61,
      42,    43,    98,    99,   183,     3,   102,   103,   104,   105,
      57,    57,    54,   393,   394,   393,   394,    59,    32,    33,
     199,   152,   422,    59,   272,    53,   434,   157,    64,     1,
     275,   154,     7,    61,   213,   214,   444,     3,    44,   218,
       3,   220,   165,    18,    58,    11,    12,    13,    14,    15,
      16,    17,    18,    41,   434,    30,   434,   449,    30,    41,
      66,   306,    37,   242,   444,    37,   444,    59,   460,    58,
      30,    59,    64,    62,    40,    63,    64,    37,    57,   258,
     259,    63,   276,    54,    58,   276,   331,   266,    62,   276,
     276,    58,   276,   276,   276,   219,   275,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    58,    41,    32,    33,    62,
      54,    57,   367,    32,    33,    57,    60,   306,    62,    60,
     375,    62,    54,    59,   313,    57,   314,   315,    63,   318,
     236,   237,   238,    58,     3,   324,   342,   392,   342,    58,
     274,   342,   331,    64,   348,   342,   342,   348,   342,   342,
     342,   348,   348,     3,   348,   348,   348,    48,    49,    65,
      36,    37,    38,    39,   353,    60,    56,    62,   274,   358,
     359,    64,   360,   428,    36,    37,    38,    39,   367,    70,
      71,    57,    58,    54,    74,    75,   375,    54,    55,    98,
      99,    59,   326,   102,   103,   104,   105,    55,   386,   388,
      59,   390,    59,   392,   406,   393,   394,    46,    47,    98,
      99,   352,    54,   102,   103,   104,   105,   421,    59,   408,
     421,    50,    51,    52,   421,   421,     3,   421,   421,   421,
      54,     3,     4,     5,     6,     7,     8,     9,    10,   428,
      72,    73,   376,    42,    43,    30,   434,    19,    42,    43,
     439,    36,    37,    38,    39,    55,   444,    29,    54,    31,
      36,    37,    38,    39,   227,   228,   229,   230,   457,   458,
      42,    43,    45,   414,   231,   232,   233,   466,    67,   408,
     469,    57,    58,     3,    68,    57,    69,    59,   422,    42,
      43,    11,    12,    13,    14,    15,    16,    17,    63,    64,
      72,    73,    63,    64,    76,    77,    55,   448,    63,    64,
     219,     3,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     219,    64,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      59,     3,     4,     5,     6,     7,     8,     9,    10,    36,
      37,    38,    39,    40,    60,   274,     3,    19,    20,    21,
      22,    65,    24,    25,    26,    27,    28,    29,    64,    31,
      32,    33,    34,    35,    55,   274,    38,   225,   226,    54,
      42,    43,    11,    12,    13,    14,    15,    16,    17,   234,
     235,    54,    54,     3,    54,    57,    58,    59,    21,    60,
      54,    60,     3,     3,    62,    60,    54,   326,    64,    60,
      72,    73,    65,    62,    76,    77,     3,     4,     5,     6,
       7,     8,     9,    10,    64,    60,    60,   326,    59,    62,
      60,    55,    19,    20,    21,    22,    61,    24,    25,    26,
      27,    28,    29,    65,    31,    32,    33,    34,    35,    65,
      65,    38,    60,    65,    65,    42,    43,   376,    54,    23,
      59,    59,    23,    57,    54,    60,    54,    54,    65,    62,
      57,    58,    59,    64,    60,    64,    60,   376,    60,    54,
      65,    61,    53,    61,    65,    72,    73,    64,    57,    76,
      77,    65,    23,    63,    54,    60,    64,     8,    65,    65,
      57,    64,    64,   422,     8,    61,    65,    65,     3,     4,
       5,     6,     7,     8,     9,    10,    64,   379,    65,    64,
     379,    65,   380,   422,    19,    20,    21,    22,   408,    24,
      25,    26,    27,    28,    29,   342,    31,    32,    33,    34,
      35,   276,   219,    38,   165,   421,   222,    42,    43,   221,
     223,   170,    37,   224,    63,   258,   249,   247,    12,    54,
      -1,    -1,    57,    58,    59,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    72,    73,    -1,    -1,    76,    77,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    72,    73,
      -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    36,    37,    38,    39,    79,    80,    81,    82,
     169,   187,   188,   189,    38,   167,     0,   169,    80,    82,
      40,   189,     3,    83,     3,    54,    55,   170,     3,    56,
      57,   171,    54,    38,    58,   167,   169,   172,   173,   174,
     175,   187,   190,   191,    57,    86,    58,   173,     3,    11,
      12,    13,    14,    15,    16,    17,    18,   168,   179,    86,
      58,    87,    59,   180,   181,     3,    64,   117,   118,   122,
     177,   178,   182,    54,    86,   176,     3,     4,     5,     6,
       7,     8,     9,    10,    19,    20,    21,    22,    24,    25,
      26,    27,    28,    29,    31,    34,    35,    38,    42,    43,
      54,    59,    72,    73,    76,    77,    84,    85,    86,    88,
      89,    99,   100,   101,   103,   105,   106,   111,   112,   114,
     130,   131,   132,   133,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   160,   161,
     162,   166,   167,    60,   168,   185,   186,   178,     3,   182,
      59,    63,    64,    65,    54,    62,    64,   182,   116,     3,
     168,    59,    59,    59,    54,    54,     3,   131,   163,   131,
     131,    55,   131,    59,   101,     3,   135,   149,   155,   160,
     149,   131,   168,   149,   149,   149,   149,    58,    85,    59,
     109,   110,   114,   129,   130,   133,   150,   151,   154,   161,
     162,    54,    54,    59,    64,    55,    41,    63,   134,    44,
      66,    45,    67,    68,    69,    46,    47,    48,    49,    70,
      71,    50,    51,    52,    72,    73,    56,    74,    75,    42,
      43,    55,    64,   168,     3,   122,    60,    62,   182,   183,
     184,   131,   163,     3,   118,   122,    65,   117,    59,    64,
     159,   159,   131,   131,    54,    54,    61,    54,     3,    54,
     131,    21,   115,    60,    60,    54,    62,   131,   164,   165,
     131,     3,   131,   140,   131,   141,   142,   143,   144,   145,
     145,   146,   146,   146,   146,   147,   147,   147,   148,   148,
     149,   149,   149,     3,   131,   117,    64,   186,   185,    60,
      65,   164,   131,    64,    60,    60,   131,    60,    59,   117,
     149,   163,   129,    60,    62,    65,    61,    65,   163,    60,
      63,    64,    60,    65,   131,   101,    21,    22,    88,   101,
     102,   104,   105,   107,   113,    54,    90,   131,    54,   131,
     138,    65,    19,    57,   119,   127,   163,    65,    59,    59,
      23,   109,    57,    91,    60,   108,   110,    64,   168,   128,
     131,    65,   131,   131,   101,    54,    32,    33,    58,    92,
      93,    94,    95,    96,    97,    54,    60,   163,    64,    58,
      62,    63,    64,    60,    60,   163,    98,   138,    58,    94,
      95,    97,    58,    96,    97,    58,    84,    97,    53,    61,
     101,    65,   131,   131,    19,    57,   120,   125,   163,   102,
     102,    54,    62,    58,    61,    86,    99,   131,    64,    65,
     168,   126,   127,    65,    23,   108,   138,    54,   163,    64,
      58,    62,    63,   102,    60,    65,   131,   127,    19,    57,
     121,   123,   102,    65,   168,   124,   125,    64,    64,    58,
      62,   131,   131,   125,    65,    65,    64,   131,    65,    64,
     131,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    87,    86,    86,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      90,    89,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    96,    97,    97,    98,
      98,    99,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   103,   104,   105,   106,   107,   108,   108,
     109,   109,   109,   110,   110,   111,   112,   113,   114,   115,
     114,   116,   114,   117,   117,   117,   117,   118,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     122,   123,   124,   124,   125,   126,   126,   127,   128,   128,
     129,   129,   129,   129,   129,   129,   130,   131,   132,   132,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   144,   145,   145,   145,   145,   145,
     146,   146,   146,   146,   147,   147,   147,   148,   148,   148,
     148,   149,   149,   149,   149,   149,   150,   151,   152,   152,
     152,   152,   153,   154,   154,   154,   154,   155,   155,   156,
     156,   157,   157,   157,   157,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   170,   169,   171,
     171,   172,   172,   173,   173,   173,   173,   173,   174,   175,
     176,   176,   177,   177,   178,   179,   180,   179,   179,   181,
     179,   183,   182,   184,   182,   185,   185,   186,   187,   187,
     188,   188,   189,   189,   189,   189,   190,   190,   191
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     4,     6,
       3,     1,     2,     1,     1,     2,     0,     4,     2,     1,
       2,     3,     2,     2,     3,     1,     1,     1,     7,     1,
       0,     6,     3,     3,     2,     4,     3,     2,     1,     2,
       1,     2,     3,     2,     4,     3,     3,     2,     1,     3,
       1,     3,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     2,     8,     8,     1,     0,
       1,     1,     0,     3,     1,     5,     7,     7,     3,     0,
       4,     0,     3,     3,     3,     1,     1,     3,     6,     9,
      12,     1,     5,     1,     8,     1,    11,     1,     4,     7,
      10,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     4,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     3,     1,     1,     1,     5,     3,     3,     3,
       4,     4,     4,     2,     2,     1,     0,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       2,     2,     1,     1,     1,     1,     2,     1,     4,     3,
       1,     1,     3,     2,     1,     3,     0,     4,     2,     0,
       3,     0,     5,     0,     4,     3,     1,     2,     1,     0,
       2,     1,     1,     1,     1,     1,     5,     4,     2
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
  case 2:
#line 140 "src/parse.y"
                                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "ImportList", 1);
    insertAttr(v, (yyvsp[0].ptr), "ClassList", 1);
    (yyval.ptr) = makenode("Program", v);
    root = (yyval.ptr);

}
#line 1907 "src/parse.tab.c"
    break;

  case 3:
#line 148 "src/parse.y"
                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "ClassList", 1);
    (yyval.ptr) = makenode("Program", v);
}
#line 1917 "src/parse.tab.c"
    break;

  case 4:
#line 155 "src/parse.y"
                                                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "ClassList", 1);
    insertAttr(v, (yyvsp[0].ptr), "Class", 1);
    (yyval.ptr) = makenode("Classes", v);
}
#line 1928 "src/parse.tab.c"
    break;

  case 5:
#line 161 "src/parse.y"
                                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "Class", 1);
    (yyval.ptr) = makenode("ClassList", v);
}
#line 1938 "src/parse.tab.c"
    break;

  case 6:
#line 168 "src/parse.y"
                                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "ImportList", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ImportList", v);
}
#line 1949 "src/parse.tab.c"
    break;

  case 7:
#line 174 "src/parse.y"
                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ImportList", v);
}
#line 1959 "src/parse.tab.c"
    break;

  case 8:
#line 181 "src/parse.y"
                                             {(yyval.ptr) = makeleaf("ID(" + *(yyvsp[-1].str) + ")");}
#line 1965 "src/parse.tab.c"
    break;

  case 9:
#line 182 "src/parse.y"
                                                     {(yyval.ptr) = makeleaf("ID(" + *(yyvsp[-3].str) + ")");}
#line 1971 "src/parse.tab.c"
    break;

  case 10:
#line 186 "src/parse.y"
                            {
    *(yyval.str) = *(yyvsp[-2].str) + "." + *(yyvsp[0].str);
}
#line 1979 "src/parse.tab.c"
    break;

  case 11:
#line 189 "src/parse.y"
              {
    *(yyval.str) = *(yyvsp[0].str);
}
#line 1987 "src/parse.tab.c"
    break;

  case 12:
#line 194 "src/parse.y"
                       {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "Body", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Body", v);
}
#line 1998 "src/parse.tab.c"
    break;

  case 13:
#line 200 "src/parse.y"
                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2006 "src/parse.tab.c"
    break;

  case 14:
#line 205 "src/parse.y"
                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2014 "src/parse.tab.c"
    break;

  case 15:
#line 208 "src/parse.y"
                        {
    (yyval.ptr) = (yyvsp[-1].ptr);
}
#line 2022 "src/parse.tab.c"
    break;

  case 16:
#line 213 "src/parse.y"
            {create_symtbl();}
#line 2028 "src/parse.tab.c"
    break;

  case 17:
#line 213 "src/parse.y"
                                       {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("Block", v);

    // semantics
    current = current->parent;
}
#line 2043 "src/parse.tab.c"
    break;

  case 18:
#line 223 "src/parse.y"
               {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("Block", v);
}
#line 2054 "src/parse.tab.c"
    break;

  case 19:
#line 231 "src/parse.y"
                        {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2062 "src/parse.tab.c"
    break;

  case 20:
#line 234 "src/parse.y"
                            {
    (yyval.ptr) = (yyvsp[-1].ptr);
}
#line 2070 "src/parse.tab.c"
    break;

  case 21:
#line 237 "src/parse.y"
                                           {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("return"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("STMNT_without_sub", v);

    // semantics
    if(!can_be_TypeCasted((yyvsp[-1].ptr)->type, retType))
        yyerror("Invalid Return Type, expected " + retType );
}
#line 2085 "src/parse.tab.c"
    break;

  case 22:
#line 247 "src/parse.y"
                                    {
    (yyval.ptr) = makeleaf("continue");
}
#line 2093 "src/parse.tab.c"
    break;

  case 23:
#line 250 "src/parse.y"
                                 {
    (yyval.ptr) = makeleaf("break");
}
#line 2101 "src/parse.tab.c"
    break;

  case 24:
#line 253 "src/parse.y"
                                      {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("yield"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("STMNT_without_sub", v);
}
#line 2112 "src/parse.tab.c"
    break;

  case 25:
#line 259 "src/parse.y"
                                {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2120 "src/parse.tab.c"
    break;

  case 26:
#line 262 "src/parse.y"
                                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2128 "src/parse.tab.c"
    break;

  case 27:
#line 265 "src/parse.y"
                                   {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2136 "src/parse.tab.c"
    break;

  case 28:
#line 268 "src/parse.y"
                                                           {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("do"), "", 1);
    insertAttr(v, (yyvsp[-5].ptr), "", 1);
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("STMNT_without_sub", v);
}
#line 2151 "src/parse.tab.c"
    break;

  case 29:
#line 278 "src/parse.y"
                        {(yyval.ptr) = NULL;}
#line 2157 "src/parse.tab.c"
    break;

  case 30:
#line 282 "src/parse.y"
                                            {create_symtbl();}
#line 2163 "src/parse.tab.c"
    break;

  case 31:
#line 282 "src/parse.y"
                                                                          {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("switch"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchStatement", v);
    
    //end of scope
    current = current->parent;
}
#line 2180 "src/parse.tab.c"
    break;

  case 32:
#line 295 "src/parse.y"
                                        {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("SwitchBlock", v);
}
#line 2192 "src/parse.tab.c"
    break;

  case 33:
#line 303 "src/parse.y"
                                           {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("SwitchBlock", v);
}
#line 2204 "src/parse.tab.c"
    break;

  case 34:
#line 310 "src/parse.y"
            {
    (yyval.ptr) = NULL;
}
#line 2212 "src/parse.tab.c"
    break;

  case 35:
#line 314 "src/parse.y"
                                                            {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("SwitchBlock", v);
}
#line 2225 "src/parse.tab.c"
    break;

  case 36:
#line 323 "src/parse.y"
                            {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "}", 0);
    (yyval.ptr) = makenode("SwitchBlock", v);
}
#line 2237 "src/parse.tab.c"
    break;

  case 37:
#line 332 "src/parse.y"
                                                                                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchBlockStatementGroupList", v);
}
#line 2248 "src/parse.tab.c"
    break;

  case 38:
#line 338 "src/parse.y"
                                              {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2256 "src/parse.tab.c"
    break;

  case 39:
#line 342 "src/parse.y"
                                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchRuleList", v);
}
#line 2267 "src/parse.tab.c"
    break;

  case 40:
#line 348 "src/parse.y"
                              {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2275 "src/parse.tab.c"
    break;

  case 41:
#line 353 "src/parse.y"
                                                 {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchBlockStatementGroup", v);
}
#line 2286 "src/parse.tab.c"
    break;

  case 42:
#line 360 "src/parse.y"
                                                    {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchLabelList", v);
}
#line 2297 "src/parse.tab.c"
    break;

  case 43:
#line 366 "src/parse.y"
                                 {
    (yyval.ptr) = (yyvsp[-1].ptr);
}
#line 2305 "src/parse.tab.c"
    break;

  case 44:
#line 371 "src/parse.y"
                                       {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchRule", v);
}
#line 2317 "src/parse.tab.c"
    break;

  case 45:
#line 378 "src/parse.y"
                                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchRule", v);
}
#line 2329 "src/parse.tab.c"
    break;

  case 46:
#line 385 "src/parse.y"
                                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchRule", v);
}
#line 2341 "src/parse.tab.c"
    break;

  case 47:
#line 394 "src/parse.y"
                                        {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("case"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("SwitchLabel", v);
}
#line 2352 "src/parse.tab.c"
    break;

  case 48:
#line 400 "src/parse.y"
              {
    (yyval.ptr) = makeleaf("default");
}
#line 2360 "src/parse.tab.c"
    break;

  case 49:
#line 405 "src/parse.y"
                                                               {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("CaseConstantList", v);
}
#line 2372 "src/parse.tab.c"
    break;

  case 50:
#line 413 "src/parse.y"
                      {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2380 "src/parse.tab.c"
    break;

  case 51:
#line 418 "src/parse.y"
                                   {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("throw"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("ThrowStatement", v);
}
#line 2391 "src/parse.tab.c"
    break;

  case 52:
#line 425 "src/parse.y"
                                    {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("Assert_stmnt", v);
}
#line 2402 "src/parse.tab.c"
    break;

  case 53:
#line 431 "src/parse.y"
                                            {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("Assert_stmnt", v);
}
#line 2414 "src/parse.tab.c"
    break;

  case 54:
#line 440 "src/parse.y"
                         {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2422 "src/parse.tab.c"
    break;

  case 55:
#line 443 "src/parse.y"
               {
    (yyval.ptr)  =(yyvsp[0].ptr);
}
#line 2430 "src/parse.tab.c"
    break;

  case 56:
#line 446 "src/parse.y"
                    {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2438 "src/parse.tab.c"
    break;

  case 57:
#line 449 "src/parse.y"
                   {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2446 "src/parse.tab.c"
    break;

  case 58:
#line 452 "src/parse.y"
                 {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2454 "src/parse.tab.c"
    break;

  case 59:
#line 457 "src/parse.y"
                                     {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2462 "src/parse.tab.c"
    break;

  case 60:
#line 460 "src/parse.y"
                                          {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2470 "src/parse.tab.c"
    break;

  case 61:
#line 463 "src/parse.y"
                                         {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2478 "src/parse.tab.c"
    break;

  case 62:
#line 466 "src/parse.y"
                                       {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2486 "src/parse.tab.c"
    break;

  case 63:
#line 471 "src/parse.y"
                                         {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("WHILE_STMNT", v);
}
#line 2500 "src/parse.tab.c"
    break;

  case 64:
#line 481 "src/parse.y"
                                                             {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("WHILE_STMNT_noshortif", v);
}
#line 2514 "src/parse.tab.c"
    break;

  case 65:
#line 492 "src/parse.y"
                {
    create_symtbl();
}
#line 2522 "src/parse.tab.c"
    break;

  case 66:
#line 496 "src/parse.y"
                                                              {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("for"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, (yyvsp[-6].ptr), "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("BASIC_FOR", v);

    // end of scope
    current = current->parent;
}
#line 2543 "src/parse.tab.c"
    break;

  case 67:
#line 513 "src/parse.y"
                                                                                    {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("FOR"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, (yyvsp[-6].ptr), "", 1);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("BASIC_FOR_noshortif", v);

    // end of scope
    current = current->parent;
}
#line 2562 "src/parse.tab.c"
    break;

  case 68:
#line 529 "src/parse.y"
                            {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("FOR_UPDATE", v);
}
#line 2572 "src/parse.tab.c"
    break;

  case 69:
#line 534 "src/parse.y"
        {
    (yyval.ptr) = NULL;
}
#line 2580 "src/parse.tab.c"
    break;

  case 70:
#line 539 "src/parse.y"
                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("FOR_INIT", v);
}
#line 2590 "src/parse.tab.c"
    break;

  case 71:
#line 544 "src/parse.y"
                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("FOR_INIT", v);
}
#line 2600 "src/parse.tab.c"
    break;

  case 72:
#line 549 "src/parse.y"
                  {
    (yyval.ptr) = NULL;
}
#line 2608 "src/parse.tab.c"
    break;

  case 73:
#line 554 "src/parse.y"
                                                  {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("STMNT_EXPR_list", v);
}
#line 2619 "src/parse.tab.c"
    break;

  case 74:
#line 560 "src/parse.y"
                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("STMNT_EXPR_list", v);
}
#line 2629 "src/parse.tab.c"
    break;

  case 75:
#line 567 "src/parse.y"
                                     {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("IF_THEN", v);
}
#line 2641 "src/parse.tab.c"
    break;

  case 76:
#line 575 "src/parse.y"
                                                                  {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("IF_THEN_ELSE", v);
}
#line 2655 "src/parse.tab.c"
    break;

  case 77:
#line 585 "src/parse.y"
                                                                                    {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("IF_THEN_ELSE_noshortif", v);
}
#line 2669 "src/parse.tab.c"
    break;

  case 78:
#line 597 "src/parse.y"
                            {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("DEF_VAR", v);
}
#line 2681 "src/parse.tab.c"
    break;

  case 79:
#line 604 "src/parse.y"
                     {CREATE_ST_KEY(temp, *(yyvsp[0].str)); temp->type.push_back(TYPE_CLASS); if(lookup(temp)){dType = *(yyvsp[0].str);} else {yyerror(*(yyvsp[0].str) + "doesn't name a type");} }
#line 2687 "src/parse.tab.c"
    break;

  case 80:
#line 604 "src/parse.y"
                                                                                                                                                                        {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("static"),"",1);
    insertAttr(v,makeleaf("ID(" + *(yyvsp[-2].str) + ")"), "", 1 );
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("DEF_VAR", v);
}
#line 2699 "src/parse.tab.c"
    break;

  case 81:
#line 611 "src/parse.y"
           {CREATE_ST_KEY(temp, *(yyvsp[0].str)); temp->type.push_back(TYPE_CLASS); if(lookup(temp)){dType = *(yyvsp[0].str);} else {yyerror(*(yyvsp[0].str) + "doesn't name a type");} }
#line 2705 "src/parse.tab.c"
    break;

  case 82:
#line 611 "src/parse.y"
                                                                                                                                                              {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-2].str) + ")"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("DEF_VAR", v);
}
#line 2716 "src/parse.tab.c"
    break;

  case 83:
#line 619 "src/parse.y"
                            {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("VAR_LIST", v);

    // sematics
    CREATE_ST_KEY(temp, (yyvsp[0].ptr)->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
    temp_entry->arr_dims = (yyvsp[0].ptr)->arr_dims;
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + (yyvsp[0].ptr)->lexeme);
    }
    free(temp);


}
#line 2740 "src/parse.tab.c"
    break;

  case 84:
#line 638 "src/parse.y"
                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("VAR_LIST", v);
    // sematics
    CREATE_ST_KEY(temp, (yyvsp[0].ptr)->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
    temp_entry->arr_dims = (yyvsp[0].ptr)->arr_dims;

    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + (yyvsp[0].ptr)->lexeme);
    }
    free(temp);
}
#line 2763 "src/parse.tab.c"
    break;

  case 85:
#line 656 "src/parse.y"
               {
    (yyval.ptr) = (yyvsp[0].ptr);

    // sematics
    CREATE_ST_KEY(temp, (yyvsp[0].ptr)->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
    temp_entry->arr_dims = (yyvsp[0].ptr)->arr_dims;

    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + (yyvsp[0].ptr)->lexeme);
    }
    free(temp);
}
#line 2784 "src/parse.tab.c"
    break;

  case 86:
#line 672 "src/parse.y"
                {
    (yyval.ptr) = (yyvsp[0].ptr);

    // sematics
    CREATE_ST_KEY(temp, (yyvsp[0].ptr)->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
    temp_entry->arr_dims = (yyvsp[0].ptr)->arr_dims;
    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + (yyvsp[0].ptr)->lexeme);
    }
    free(temp);
}
#line 2804 "src/parse.tab.c"
    break;

  case 87:
#line 689 "src/parse.y"
                   {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-2].str) + ")"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("=", v);

    (yyval.ptr)->lexeme = *(yyvsp[-2].str);
    (yyval.ptr)->dim = 0;

    // sematics
    if(!can_be_TypeCasted((yyvsp[0].ptr)->type, dType)){
        yyerror("Type Mismatch " + (yyvsp[0].ptr)->type + " cannot be typecasted to " + dType);
    }

}
#line 2824 "src/parse.tab.c"
    break;

  case 88:
#line 704 "src/parse.y"
                                             {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-5].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("=", v);

    (yyval.ptr)->lexeme = *(yyvsp[-5].str);
    (yyval.ptr)->dim = 1;
    // sematics
    if(!can_be_TypeCasted((yyvsp[0].ptr)->type, dType + TYPE_ARRAY)){
        yyerror("Type Mismatch " + (yyvsp[0].ptr)->type + " cannot be typecasted to " + dType + TYPE_ARRAY);
    }
    (yyval.ptr)->arr_dims = (yyvsp[0].ptr)->arr_dims;
}
#line 2849 "src/parse.tab.c"
    break;

  case 89:
#line 724 "src/parse.y"
                                                              {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-8].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-6].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("=", v);

    (yyval.ptr)->lexeme = *(yyvsp[-8].str);
    (yyval.ptr)->dim = 2;
    // sematics
    if(!can_be_TypeCasted((yyvsp[0].ptr)->type, dType + TYPE_ARRAY + TYPE_ARRAY)){
        yyerror("Type Mismatch " + (yyvsp[0].ptr)->type + " cannot be typecasted to " + dType + TYPE_ARRAY + TYPE_ARRAY);
    }
    (yyval.ptr)->arr_dims = (yyvsp[0].ptr)->arr_dims;
}
#line 2877 "src/parse.tab.c"
    break;

  case 90:
#line 747 "src/parse.y"
                                                                               {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-11].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-9].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-6].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("=", v);

    (yyval.ptr)->lexeme = *(yyvsp[-11].str);
    (yyval.ptr)->dim = 3;
    // sematics
    if(!can_be_TypeCasted((yyvsp[0].ptr)->type, dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY)){
        yyerror("Type Mismatch " + (yyvsp[0].ptr)->type + " cannot be typecasted to " + dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY);
    }
    (yyval.ptr)->arr_dims = (yyvsp[0].ptr)->arr_dims;
}
#line 2908 "src/parse.tab.c"
    break;

  case 91:
#line 775 "src/parse.y"
                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2916 "src/parse.tab.c"
    break;

  case 92:
#line 778 "src/parse.y"
                                          {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("Array-1D", v);
    (yyval.ptr)->type = dType + TYPE_ARRAY;

    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->addr);
}
#line 2933 "src/parse.tab.c"
    break;

  case 93:
#line 791 "src/parse.y"
                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2941 "src/parse.tab.c"
    break;

  case 94:
#line 794 "src/parse.y"
                                                       {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, (yyvsp[-6].ptr), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("Array-2D", v);

    (yyval.ptr)->type = dType + TYPE_ARRAY + TYPE_ARRAY;

    (yyval.ptr)->arr_dims.push_back((yyvsp[-4].ptr)->addr);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->addr);
}
#line 2963 "src/parse.tab.c"
    break;

  case 95:
#line 812 "src/parse.y"
                  {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 2971 "src/parse.tab.c"
    break;

  case 96:
#line 815 "src/parse.y"
                                                                    {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, (yyvsp[-9].ptr), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-7].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("Array-3D", v);

    (yyval.ptr)->type = dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY;

    (yyval.ptr)->arr_dims.push_back((yyvsp[-7].ptr)->addr);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-4].ptr)->addr);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->addr);
}
#line 2997 "src/parse.tab.c"
    break;

  case 97:
#line 838 "src/parse.y"
          {
    (yyval.ptr) = makeleaf("ID(" + *(yyvsp[0].str) + ")");

    (yyval.ptr)->lexeme = *(yyvsp[0].str);
    (yyval.ptr)->dim = 0;
}
#line 3008 "src/parse.tab.c"
    break;

  case 98:
#line 844 "src/parse.y"
                           {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-3].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("1D Array",v);

    (yyval.ptr)->lexeme = *(yyvsp[-3].str);
    (yyval.ptr)->dim = 1;
    
    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->lexeme);
}
#line 3026 "src/parse.tab.c"
    break;

  case 99:
#line 857 "src/parse.y"
                                            {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-6].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("2D Array",v);

    (yyval.ptr)->lexeme = *(yyvsp[-6].str);
    (yyval.ptr)->dim = 2;
    (yyval.ptr)->arr_dims.push_back((yyvsp[-4].ptr)->lexeme);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->lexeme);
}
#line 3047 "src/parse.tab.c"
    break;

  case 100:
#line 873 "src/parse.y"
                                                             {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-9].str) + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-7].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, "]", 0);
    (yyval.ptr) = makenode("3D Array",v);

    (yyval.ptr)->lexeme = *(yyvsp[-9].str);
    (yyval.ptr)->dim = 3;
    (yyval.ptr)->arr_dims.push_back((yyvsp[-7].ptr)->lexeme);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-4].ptr)->lexeme);
    (yyval.ptr)->arr_dims.push_back((yyvsp[-1].ptr)->lexeme);
}
#line 3072 "src/parse.tab.c"
    break;

  case 101:
#line 895 "src/parse.y"
                      {
    (yyval.ptr) = (yyvsp[-1].ptr);
    (yyval.ptr)->type = (yyvsp[-1].ptr)->type + TYPE_ARRAY;

    (yyval.ptr)->dims_count_1 = dims_count_1;
    (yyval.ptr)->dims_count_2 = dims_count_2;
    (yyval.ptr)->dims_count_3 = dims_count_3;
    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_1));
    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_2));
    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_3));
}
#line 3088 "src/parse.tab.c"
    break;

  case 102:
#line 907 "src/parse.y"
                      {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Array-3D", v);
    if((yyvsp[-2].ptr)->type == (yyvsp[0].ptr)->type){
        (yyval.ptr)->type = (yyvsp[-2].ptr)->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }

    dims_count_3 += 1;
    (yyval.ptr)->dims_count_3 = dims_count_3;
    (yyval.ptr)->dims_count_2 = dims_count_2;
    (yyval.ptr)->dims_count_1 = dims_count_1;

    //cout<<"3d dims_count_2: "<<dims_count_2<<endl;
    if(dims_count_2 != (yyvsp[-2].ptr)->dims_count_2){
        yyerror("Array dimensions mismatch");
    }
}
#line 3116 "src/parse.tab.c"
    break;

  case 103:
#line 930 "src/parse.y"
           {
    (yyval.ptr) = (yyvsp[0].ptr);
    dims_count_3 = 1;

    (yyval.ptr)->dims_count_3 = dims_count_3;
    (yyval.ptr)->dims_count_2 = dims_count_2;
    (yyval.ptr)->dims_count_1 = dims_count_1;
}
#line 3129 "src/parse.tab.c"
    break;

  case 104:
#line 940 "src/parse.y"
                      {
    (yyval.ptr) = (yyvsp[-1].ptr);
    (yyval.ptr)->type = (yyvsp[-1].ptr)->type + TYPE_ARRAY;

    (yyval.ptr)->dims_count_1 = dims_count_1;
    (yyval.ptr)->dims_count_2 = dims_count_2;

    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_1));
    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_2));
}
#line 3144 "src/parse.tab.c"
    break;

  case 105:
#line 951 "src/parse.y"
                      {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Array-2D", v);
    if((yyvsp[-2].ptr)->type == (yyvsp[0].ptr)->type){
        (yyval.ptr)->type = (yyvsp[-2].ptr)->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }
    dims_count_2 += 1;
    (yyval.ptr)->dims_count_2 = dims_count_2;
    (yyval.ptr)->dims_count_1 = dims_count_1;

    //cout<<dims_count_1<<" "<<$1->dims_count_1<<endl;
    
    if(dims_count_1 != (yyvsp[-2].ptr)->dims_count_1){
        yyerror("Array dimensions mismatch");
    }   
}
#line 3171 "src/parse.tab.c"
    break;

  case 106:
#line 973 "src/parse.y"
           {
    (yyval.ptr) = (yyvsp[0].ptr);
    dims_count_2 = 1;
    (yyval.ptr)->dims_count_2 = dims_count_2;
    (yyval.ptr)->dims_count_1 = dims_count_1;
}
#line 3182 "src/parse.tab.c"
    break;

  case 107:
#line 981 "src/parse.y"
                    {
    (yyval.ptr) = (yyvsp[-1].ptr);
    (yyval.ptr)->type = (yyvsp[-1].ptr)->type + TYPE_ARRAY;
    (yyval.ptr)->dims_count_1 = dims_count_1;
    (yyval.ptr)->arr_dims.push_back(to_string(dims_count_1));
}
#line 3193 "src/parse.tab.c"
    break;

  case 108:
#line 988 "src/parse.y"
                       {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Array-1D", v);

    if((yyvsp[-2].ptr)->type == (yyvsp[0].ptr)->type){
        (yyval.ptr)->type = (yyvsp[-2].ptr)->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }

    dims_count_1 += 1;
    (yyval.ptr)->dims_count_1 = dims_count_1;
}
#line 3215 "src/parse.tab.c"
    break;

  case 109:
#line 1005 "src/parse.y"
            {
    (yyval.ptr) = (yyvsp[0].ptr);

    dims_count_1 = 1;
    (yyval.ptr)->dims_count_1 = dims_count_1;
}
#line 3226 "src/parse.tab.c"
    break;

  case 110:
#line 1013 "src/parse.y"
                      {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 3234 "src/parse.tab.c"
    break;

  case 111:
#line 1016 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3240 "src/parse.tab.c"
    break;

  case 112:
#line 1017 "src/parse.y"
                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3246 "src/parse.tab.c"
    break;

  case 113:
#line 1018 "src/parse.y"
                                   {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3252 "src/parse.tab.c"
    break;

  case 114:
#line 1019 "src/parse.y"
                                   {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3258 "src/parse.tab.c"
    break;

  case 115:
#line 1020 "src/parse.y"
                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3264 "src/parse.tab.c"
    break;

  case 116:
#line 1023 "src/parse.y"
                                           {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + (yyvsp[-3].ptr)->lexeme + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("Meth_invoc", v);

    /*type checking*/
    if((yyvsp[-3].ptr)->typevec.size()==0){
        // ExpressionName is just ID.
        CREATE_ST_KEY(temp, (yyvsp[-3].ptr)->lexeme);
        // if($3){
        //    temp->type = $3->typevec;
        // }

        SymbTbl_entry* entry = lookup(temp);
        if(entry){
            if(compareMethTypes(entry->type, (yyvsp[-1].ptr)->typevec))(yyval.ptr)->type = *(entry->type.rbegin());
            else{
                yyerror("Invalid Argument Types for Method " + (yyvsp[-3].ptr)->lexeme);
            }
        }
        else{
            yyerror("method " + (yyvsp[-3].ptr)->lexeme + " not found");
        }
    }
    else{
        // ExpressionName is ID.ID.ID...
        CREATE_ST_KEY(temp, (yyvsp[-3].ptr)->typevec[0]);
        temp->type.push_back(TYPE_CLASS);
        SymbTbl_entry* entry = lookup(temp);
        if(entry){
            SymbolTable* classTable = entry->table;
            CREATE_ST_KEY(classTemp, (yyvsp[-3].ptr)->typevec[1]);
            auto it = classTable->table.find(*classTemp);
            if(it != classTable->table.end()){
                SymbTbl_entry* entry = it->second;
                if(entry->mod_flag == PUBLIC_FLAG){
                    (yyval.ptr)->type = *(entry->type.rbegin());
                }
                else{
                    yyerror("Non-Public member " + (yyvsp[-3].ptr)->typevec[1] + " of class " + (yyvsp[-3].ptr)->typevec[0] + " cannot be accessed");
                }
            }
            else {
                yyerror("No method " + (yyvsp[-3].ptr)->typevec[1] + " found in class " + (yyvsp[-3].ptr)->typevec[0]);

            }
        }
        else{
            yyerror("No class " + (yyvsp[-3].ptr)->type + " found");
        }
    }
}
#line 3324 "src/parse.tab.c"
    break;

  case 117:
#line 1080 "src/parse.y"
                          {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 3332 "src/parse.tab.c"
    break;

  case 118:
#line 1085 "src/parse.y"
                                           {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3338 "src/parse.tab.c"
    break;

  case 119:
#line 1086 "src/parse.y"
                                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3344 "src/parse.tab.c"
    break;

  case 120:
#line 1089 "src/parse.y"
                                                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode(*(yyvsp[-1].str), v);

    // type checking
    if(can_be_TypeCasted((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type))(yyval.ptr)->type = (yyvsp[-2].ptr)->type;
    else{
        yyerror("Type Mismatched cannot cast " + (yyvsp[0].ptr)->type + " to " + (yyvsp[-2].ptr)->type);
    }

    emit("", (yyvsp[0].ptr)->addr, "", (yyvsp[-2].ptr)->addr);   
}
#line 3363 "src/parse.tab.c"
    break;

  case 121:
#line 1105 "src/parse.y"
                             {
    *(yyval.str) = *(yyvsp[0].str);
}
#line 3371 "src/parse.tab.c"
    break;

  case 122:
#line 1108 "src/parse.y"
                      {
    *(yyval.str) = "=";
}
#line 3379 "src/parse.tab.c"
    break;

  case 123:
#line 1113 "src/parse.y"
                                     {
    (yyval.ptr) = new treeNode;
    (yyval.ptr)->lexeme = (yyvsp[-2].ptr)->lexeme + "." + *(yyvsp[0].str);

    // semantics
    CREATE_ST_KEY(temp, (yyvsp[-2].ptr)->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *(yyvsp[0].str));
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end() && !it->second->is_func){
            SymbTbl_entry* entry = it->second;
            if(entry->mod_flag == PUBLIC_FLAG){
                (yyval.ptr)->type = entry->type[0];
                (yyval.ptr)->addr = (yyval.ptr)->lexeme;
            }
            else{
                yyerror("Non-Public member " + *(yyvsp[0].str) + " of class " + (yyvsp[-2].ptr)->type + " cannot be accessed");
            }
        }
        else {
            (yyval.ptr)->typevec.push_back((yyvsp[-2].ptr)->type);
            (yyval.ptr)->typevec.push_back(*(yyvsp[0].str));
            (yyval.ptr)->type = TYPE_ERROR;

        }
    }
    else{
        yyerror("No class " + (yyvsp[-2].ptr)->type + " found");
    } 


}
#line 3419 "src/parse.tab.c"
    break;

  case 124:
#line 1148 "src/parse.y"
                    {
    (yyval.ptr) = new treeNode;
    (yyval.ptr)->lexeme = *(yyvsp[0].str);
    CREATE_ST_KEY(temp, *(yyvsp[0].str));
    SymbTbl_entry* entry = lookup(temp);
    if(entry && !entry->is_func){
        (yyval.ptr)->type = entry->type[0];
        (yyval.ptr)->addr = *(yyvsp[0].str);
    }
    else{
        (yyval.ptr)->type = TYPE_ERROR;
    }
}
#line 3437 "src/parse.tab.c"
    break;

  case 125:
#line 1162 "src/parse.y"
                    {
    (yyval.ptr) = new treeNode;
    (yyval.ptr)->lexeme = *(yyvsp[0].str);
    CREATE_ST_KEY(temp, *(yyvsp[0].str));
    SymbTbl_entry* entry = lookup(temp);
    if(entry)(yyval.ptr)->type = entry->type[0];
    else{
        yyerror("undeclared variable " + *(yyvsp[0].str) );
    } 
}
#line 3452 "src/parse.tab.c"
    break;

  case 126:
#line 1172 "src/parse.y"
                                    {
    (yyval.ptr) = new treeNode;
    (yyval.ptr)->lexeme = (yyvsp[-2].ptr)->lexeme + "." + *(yyvsp[0].str);

    // semantics
    CREATE_ST_KEY(temp, (yyvsp[-2].ptr)->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *(yyvsp[0].str));
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            // SymbTbl_entry* entry;
            if(entry->mod_flag == PUBLIC_FLAG){
                (yyval.ptr)->type = entry->type[0];
            }
            else{
                yyerror("Non-Public member " + *(yyvsp[0].str) + " of class " + (yyvsp[-2].ptr)->type + " cannot be accessed");
            }
        }
        else {
            yyerror("No member " + *(yyvsp[0].str) + " in class " + (yyvsp[-2].ptr)->type);
        }
    }
    else{
        yyerror("No class " + (yyvsp[-2].ptr)->type + " found");
    } 
}
#line 3487 "src/parse.tab.c"
    break;

  case 127:
#line 1204 "src/parse.y"
                              {
    (yyval.ptr) = makeleaf("ID(" + (yyvsp[0].ptr)->lexeme + ")");
    (yyval.ptr)->lexeme = (yyvsp[0].ptr)->lexeme;
    (yyval.ptr)->type = (yyvsp[0].ptr)->type;
    if((yyvsp[0].ptr)->type == TYPE_ERROR){
        yyerror("Unidentified Symbol "+ (yyval.ptr)->lexeme);
    }
    (yyval.ptr)->addr = (yyvsp[0].ptr)->addr;
}
#line 3501 "src/parse.tab.c"
    break;

  case 128:
#line 1213 "src/parse.y"
                           {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3507 "src/parse.tab.c"
    break;

  case 129:
#line 1214 "src/parse.y"
                           {
                                (yyval.ptr) = (yyvsp[0].ptr);
                                (yyval.ptr)->addr = (yyvsp[0].ptr)->lexeme + "[" + (yyvsp[0].ptr)->addr + "]";

}
#line 3517 "src/parse.tab.c"
    break;

  case 130:
#line 1221 "src/parse.y"
                                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3523 "src/parse.tab.c"
    break;

  case 131:
#line 1222 "src/parse.y"
                                                                                  {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("?:", v);

    //type checking
    if((yyvsp[-4].ptr)->type == TYPE_BOOL)(yyval.ptr)->type = maxType((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);
    else{
        yyerror("TypeError: Conditional Expression: Type Mismatch");
    }
}
#line 3541 "src/parse.tab.c"
    break;

  case 132:
#line 1237 "src/parse.y"
                                                    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3547 "src/parse.tab.c"
    break;

  case 133:
#line 1238 "src/parse.y"
                                                                                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("||", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("||", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3565 "src/parse.tab.c"
    break;

  case 134:
#line 1253 "src/parse.y"
                                                 {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3571 "src/parse.tab.c"
    break;

  case 135:
#line 1254 "src/parse.y"
                                                                                  {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("&&", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    // 3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("&&", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);

}
#line 3590 "src/parse.tab.c"
    break;

  case 136:
#line 1270 "src/parse.y"
                                                 {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3596 "src/parse.tab.c"
    break;

  case 137:
#line 1271 "src/parse.y"
                                                                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("|", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, "|");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("|", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3614 "src/parse.tab.c"
    break;

  case 138:
#line 1286 "src/parse.y"
                                         {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3620 "src/parse.tab.c"
    break;

  case 139:
#line 1287 "src/parse.y"
                                                                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("^", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, "^");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("^", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3638 "src/parse.tab.c"
    break;

  case 140:
#line 1302 "src/parse.y"
                                              {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3644 "src/parse.tab.c"
    break;

  case 141:
#line 1303 "src/parse.y"
                                                                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("&", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type,"&" );
    
    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("&", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3662 "src/parse.tab.c"
    break;

  case 142:
#line 1318 "src/parse.y"
                                                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3668 "src/parse.tab.c"
    break;

  case 143:
#line 1319 "src/parse.y"
                                                                         {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("==", v);
    
    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("==", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3686 "src/parse.tab.c"
    break;

  case 144:
#line 1332 "src/parse.y"
                                                                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("!=", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("!=", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);    
}
#line 3704 "src/parse.tab.c"
    break;

  case 145:
#line 1347 "src/parse.y"
                                           {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3710 "src/parse.tab.c"
    break;

  case 146:
#line 1348 "src/parse.y"
                                                                    {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("<", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("<", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3728 "src/parse.tab.c"
    break;

  case 147:
#line 1361 "src/parse.y"
                                                                    {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode(">", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit(">", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3746 "src/parse.tab.c"
    break;

  case 148:
#line 1374 "src/parse.y"
                                                                          {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode(">=", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit(">=", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3764 "src/parse.tab.c"
    break;

  case 149:
#line 1387 "src/parse.y"
                                                                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("<=", v);

    //type checking
    (yyval.ptr)->type = relCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type);

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("<=", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3782 "src/parse.tab.c"
    break;

  case 150:
#line 1402 "src/parse.y"
                                              {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3788 "src/parse.tab.c"
    break;

  case 151:
#line 1403 "src/parse.y"
                                                                         {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("<<", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, "<<");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("<<", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3806 "src/parse.tab.c"
    break;

  case 152:
#line 1416 "src/parse.y"
                                                                          {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode(">>", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, ">>");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit(">>", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3824 "src/parse.tab.c"
    break;

  case 153:
#line 1429 "src/parse.y"
                                                                         {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode(">>>", v);

    //type checking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, ">>>");
    
    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit(">>>", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3842 "src/parse.tab.c"
    break;

  case 154:
#line 1444 "src/parse.y"
                                                    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3848 "src/parse.tab.c"
    break;

  case 155:
#line 1445 "src/parse.y"
                                                                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("+", v);

    //typeChecking
    (yyval.ptr)->type = addCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type,"+");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("+", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3866 "src/parse.tab.c"
    break;

  case 156:
#line 1458 "src/parse.y"
                                                                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("-", v);

    //typeChecking
    (yyval.ptr)->type = addCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type,"-");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("-", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3884 "src/parse.tab.c"
    break;

  case 157:
#line 1473 "src/parse.y"
                                           {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3890 "src/parse.tab.c"
    break;

  case 158:
#line 1474 "src/parse.y"
                                                                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("*", v);

    //typeChecking
    (yyval.ptr)->type = multCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type,"*");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("*", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3908 "src/parse.tab.c"
    break;

  case 159:
#line 1487 "src/parse.y"
                                                                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("/", v);

    //typeChecking
    (yyval.ptr)->type = multCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type,"/");

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("/", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3926 "src/parse.tab.c"
    break;

  case 160:
#line 1500 "src/parse.y"
                                                                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("%", v);

    //typeChecking
    (yyval.ptr)->type = onlyIntCheck((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type, "%");
    
    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("%", (yyvsp[-2].ptr)->addr, (yyvsp[0].ptr)->addr, (yyval.ptr)->addr);
}
#line 3944 "src/parse.tab.c"
    break;

  case 161:
#line 1515 "src/parse.y"
                                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3950 "src/parse.tab.c"
    break;

  case 162:
#line 1516 "src/parse.y"
                                                  {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3956 "src/parse.tab.c"
    break;

  case 163:
#line 1517 "src/parse.y"
                                               {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("+", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[0].ptr)->type;

    //3ac
    (yyval.ptr)->addr = (yyvsp[0].ptr)->addr;
    emit("+", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 3973 "src/parse.tab.c"
    break;

  case 164:
#line 1529 "src/parse.y"
                                               {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("-", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[0].ptr)->type;

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("-", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 3990 "src/parse.tab.c"
    break;

  case 165:
#line 1541 "src/parse.y"
                                                       {(yyval.ptr) = (yyvsp[0].ptr);}
#line 3996 "src/parse.tab.c"
    break;

  case 166:
#line 1544 "src/parse.y"
                                                     {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("++", v);

    //type checking
    if(isNum((yyvsp[0].ptr)->type)){
        (yyval.ptr)->type = (yyvsp[0].ptr)->type;

    }
    else{
        yyerror("Cannot increment non-numeric type");
    }

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("+", (yyvsp[0].ptr)->addr, "1", (yyvsp[0].ptr)->addr);
    emit("", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 4020 "src/parse.tab.c"
    break;

  case 167:
#line 1565 "src/parse.y"
                                                     {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("--", v);

    //type checking
    if(isNum((yyvsp[0].ptr)->type)){
        (yyval.ptr)->type = (yyvsp[0].ptr)->type;

    }
    else{
        yyerror("Cannot decrement non-numeric type");
    }

    //3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("-", (yyvsp[0].ptr)->addr, "1", (yyvsp[0].ptr)->addr);
    emit("", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 4044 "src/parse.tab.c"
    break;

  case 168:
#line 1586 "src/parse.y"
                                                 {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4052 "src/parse.tab.c"
    break;

  case 169:
#line 1589 "src/parse.y"
                                                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("~", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[0].ptr)->type;

    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("~", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 4068 "src/parse.tab.c"
    break;

  case 170:
#line 1600 "src/parse.y"
                                                   {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("!", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[0].ptr)->type;
    
    // 3ac
    (yyval.ptr)->addr = get_temp((yyval.ptr)->type);
    emit("!", (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
}
#line 4085 "src/parse.tab.c"
    break;

  case 171:
#line 1612 "src/parse.y"
                   {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4093 "src/parse.tab.c"
    break;

  case 172:
#line 1617 "src/parse.y"
                                                         {
    vector<treeNode*> v;
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("CastExpression", v);

    //type checking
    if(can_be_TypeCasted((yyvsp[-2].ptr)->type, (yyvsp[0].ptr)->type)){
        (yyval.ptr)->type = (yyvsp[-2].ptr)->type;
    }
    else{
        (yyval.ptr)->type = TYPE_ERROR;
        yyerror("Cannot cast " + (yyvsp[0].ptr)->type + " to " + (yyvsp[-2].ptr)->type);
    }

    //3ac
    if((yyvsp[-2].ptr)->type!= (yyvsp[0].ptr)->type){
        (yyval.ptr)->addr = get_temp((yyvsp[-2].ptr)->type);
        emit((yyvsp[0].ptr)->type + "TO" + (yyvsp[-2].ptr)->type , (yyvsp[0].ptr)->addr, "", (yyval.ptr)->addr);
    }
    else{
        (yyval.ptr)->addr = (yyvsp[0].ptr)->addr;
    }
}
#line 4124 "src/parse.tab.c"
    break;

  case 173:
#line 1644 "src/parse.y"
                                       {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4132 "src/parse.tab.c"
    break;

  case 174:
#line 1647 "src/parse.y"
                                              {
    (yyval.ptr) = makeleaf("ID(" + (yyvsp[0].ptr)->lexeme + ")");
    if((yyvsp[0].ptr)->type == TYPE_ERROR){
        yyerror("Undeclared variable " + (yyvsp[0].ptr)->lexeme);
    }
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4144 "src/parse.tab.c"
    break;

  case 175:
#line 1654 "src/parse.y"
                                                       {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4152 "src/parse.tab.c"
    break;

  case 176:
#line 1657 "src/parse.y"
                                                       {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4160 "src/parse.tab.c"
    break;

  case 177:
#line 1662 "src/parse.y"
                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[0].str) + ")"), "", 1);
    (yyval.ptr) = makenode("FieldAccess", v);

    /*type checking*/
    CREATE_ST_KEY(temp, (yyvsp[-2].ptr)->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *(yyvsp[0].str));
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            if(entry->mod_flag == PUBLIC_FLAG){
                (yyval.ptr)->type = entry->type[0];
            }
            else{
                yyerror("Non-Public member " + *(yyvsp[0].str) + " of class " + (yyvsp[-2].ptr)->type + " cannot be accessed");
            }
        }
        else {
            yyerror("No member " + *(yyvsp[0].str) + " in class " + (yyvsp[-2].ptr)->type);
        }
    }
    else{
        yyerror("No class " + (yyvsp[-2].ptr)->type + " found");
    } 
}
#line 4197 "src/parse.tab.c"
    break;

  case 178:
#line 1694 "src/parse.y"
                                {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("super"), "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[0].str) + ")"), "", 1);
    (yyval.ptr) = makenode("FieldAccess", v);
}
#line 4209 "src/parse.tab.c"
    break;

  case 179:
#line 1704 "src/parse.y"
                             {
    (yyval.ptr) = (yyvsp[0].ptr);
    // $$ = new treeNode;
    // flag_array=0;
    // $$->addr = $1->lexeme + "[" + $1->addr + "]";
    if(flag_array){
        string id = (yyvsp[0].ptr)->addr;
        (yyval.ptr)->addr = get_temp((yyvsp[0].ptr)->type);
        emit("", (yyvsp[0].ptr)->lexeme + "["+ id + "]", "", (yyval.ptr)->addr);
        flag_array = 0;
    }
    // $$->type= $1->type;

    
}
#line 4229 "src/parse.tab.c"
    break;

  case 180:
#line 1719 "src/parse.y"
                             {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4237 "src/parse.tab.c"
    break;

  case 181:
#line 1725 "src/parse.y"
                       {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4245 "src/parse.tab.c"
    break;

  case 182:
#line 1728 "src/parse.y"
                                {
    vector<treeNode*> v;
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("PrimaryNoNewArray", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[-1].ptr)->type;
    (yyval.ptr)->addr = (yyvsp[-1].ptr)->addr;
}
#line 4261 "src/parse.tab.c"
    break;

  case 183:
#line 1739 "src/parse.y"
                               {
                        (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4269 "src/parse.tab.c"
    break;

  case 184:
#line 1742 "src/parse.y"
                              {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4275 "src/parse.tab.c"
    break;

  case 185:
#line 1743 "src/parse.y"
                               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4281 "src/parse.tab.c"
    break;

  case 186:
#line 1744 "src/parse.y"
                                               {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-3].str) + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("PrimaryNoNewArray", v);

    // semantics
    CREATE_ST_KEY(temp, *(yyvsp[-3].str));
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *(yyvsp[-3].str));
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            if(compareMethTypes(entry->type, (yyvsp[-1].ptr)->typevec))
                (yyval.ptr)->type = *(yyvsp[-3].str);
            else{
                yyerror("Invalid argument list to contructor of class " + entry->lexeme);
            }
        }
        else {
            if((yyvsp[-1].ptr)->typevec.size()==0){
                // give a default constructor
                (yyval.ptr)->type = *(yyvsp[-3].str);
            }
            else{
                yyerror("No constructor found for class " + *(yyvsp[-3].str));
            }
        }
        free(classTemp);
    }
    else{
        yyerror("No class " + *(yyvsp[-3].str) + " found");
    } 
    free(temp);
}
#line 4327 "src/parse.tab.c"
    break;

  case 187:
#line 1787 "src/parse.y"
                                         {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ArrayCreationExpr", v);

    //type checking
    (yyval.ptr)->type = (yyvsp[-1].ptr)->type + (yyvsp[0].ptr)->type;
}
#line 4342 "src/parse.tab.c"
    break;

  case 188:
#line 1797 "src/parse.y"
                                      {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-1].str) + ")"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ArrayCreationExpr", v);

    //type checking
    CREATE_ST_KEY(temp, *(yyvsp[-1].str));
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        (yyval.ptr)->type = *(yyvsp[-1].str) + (yyvsp[0].ptr)->type;
    }
    else{
        yyerror("No class " + *(yyvsp[-1].str) + " found");
    }
}
#line 4365 "src/parse.tab.c"
    break;

  case 189:
#line 1817 "src/parse.y"
                        {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("Dimensional Expression", v);

    //type checking
    if(onlyIntCheck((yyvsp[-1].ptr)->type) == TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    (yyval.ptr)->type = TYPE_ARRAY;
}
#line 4383 "src/parse.tab.c"
    break;

  case 190:
#line 1830 "src/parse.y"
                                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("Dimensional Expression", v);

    //type checking
    if(onlyIntCheck((yyvsp[-1].ptr)->type) == TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    (yyval.ptr)->type = (yyvsp[-3].ptr)->type + TYPE_ARRAY;
}
#line 4402 "src/parse.tab.c"
    break;

  case 191:
#line 1846 "src/parse.y"
                                           {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + (yyvsp[-3].ptr)->lexeme + ")"), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("ArrayAccess", v);

    /* type checking */
    if(onlyIntCheck((yyvsp[-1].ptr)->type)==TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    if((yyvsp[-3].ptr)->type.compare((yyvsp[-3].ptr)->type.size()-2, 2, TYPE_ARRAY)==0){
        (yyval.ptr)->type = (yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2);
        arr_d = 1;
        int width = 1;
        CREATE_ST_KEY(temp, (yyvsp[-3].ptr)->lexeme);
        SymbTbl_entry* entry = lookup(temp);
        string s, w;
        w=get_temp((yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2));
        if(arr_d<entry->arr_dims.size()){
            s = entry->arr_dims[arr_d];
        }
    
        for(int i=arr_d+1; i<entry->arr_dims.size(); i++){
            emit("*", entry->arr_dims[i], s, w);

        }
        
        if(s!="") emit("*", to_string(Size[(yyvsp[-3].ptr)->type[0]]), w, w);
        else emit("*", to_string(Size[(yyvsp[-3].ptr)->type[0]]), "1", w);

        (yyval.ptr)->addr = get_temp((yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2));
        (yyval.ptr)->lexeme = (yyvsp[-3].ptr)->lexeme;
        
        emit("*", (yyvsp[-1].ptr)->addr, w, (yyval.ptr)->addr);
        
        if(arr_d==entry->arr_dims.size()){
            flag_array = 1;
        }
    }
    else{
        yyerror("Cannot access array of type " + (yyval.ptr)->type);
    }
    // flag_array = 1;
}
#line 4453 "src/parse.tab.c"
    break;

  case 192:
#line 1892 "src/parse.y"
                                              {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("ArrayAccess", v);

    /* type checking */
    if(onlyIntCheck((yyvsp[-1].ptr)->type)==TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    if((yyvsp[-3].ptr)->type.compare((yyvsp[-3].ptr)->type.size()-2, 2, TYPE_ARRAY)==0){
        arr_d++;
        int width = 1;
        CREATE_ST_KEY(temp, (yyvsp[-3].ptr)->lexeme);
        SymbTbl_entry* entry = lookup(temp);
        string s;
        if(arr_d<entry->arr_dims.size()) s = entry->arr_dims[arr_d];
        // for(int i=arr_d+1; i<entry->arr_dims.size(); i++){
        //     s = s + " x " + entry->arr_dims[i];
        //     // width *= stoi(entry->arr_dims[i]);
        // }
        (yyval.ptr)->type = (yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2);
        (yyval.ptr)->addr = get_temp((yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2));
        (yyval.ptr)->lexeme = (yyvsp[-3].ptr)->lexeme;
        string w = get_temp((yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2));
        
        if(s!="") emit("*", to_string(Size[(yyvsp[-3].ptr)->type[0]]), s, w);
        else emit("*", to_string(Size[(yyvsp[-3].ptr)->type[0]]), "1", w);

        string t = get_temp((yyvsp[-3].ptr)->type.substr(0, (yyvsp[-3].ptr)->type.size()-2));
        emit("*", (yyvsp[-1].ptr)->addr, w, t);
        emit("+", (yyvsp[-3].ptr)->addr, t, (yyval.ptr)->addr);
        
        if(arr_d==entry->arr_dims.size()){
            flag_array = 1;
        }
        
    }
    else{
        yyerror("Cannot access array of type " + (yyval.ptr)->type);
    }

}
#line 4503 "src/parse.tab.c"
    break;

  case 193:
#line 1939 "src/parse.y"
                                                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("++", v);
    
    //type checking
    if(isNum((yyvsp[-1].ptr)->type)){
        (yyval.ptr)->type = (yyvsp[-1].ptr)->type;

    }
    else{
        yyerror("Cannot increment non-numeric type");
    }

    //3ac
    (yyval.ptr)->addr = get_temp((yyvsp[-1].ptr)->type);
    emit("", (yyvsp[-1].ptr)->addr, "", (yyval.ptr)->addr);
    emit("+", (yyvsp[-1].ptr)->addr, "1", (yyvsp[-1].ptr)->addr);

}
#line 4528 "src/parse.tab.c"
    break;

  case 194:
#line 1961 "src/parse.y"
                                                            {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("--", v);
    
    //type checking
    if(isNum((yyvsp[-1].ptr)->type)){
        (yyval.ptr)->type = (yyvsp[-1].ptr)->type;

    }
    else{
        yyerror("Cannot decrement non-numeric type");
    }

    //3ac
    (yyval.ptr)->addr = get_temp((yyvsp[-1].ptr)->type);
    emit("", (yyvsp[-1].ptr)->addr, "", (yyval.ptr)->addr);
    emit("-", (yyvsp[-1].ptr)->addr, "1", (yyvsp[-1].ptr)->addr);
}
#line 4552 "src/parse.tab.c"
    break;

  case 195:
#line 1984 "src/parse.y"
                {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4558 "src/parse.tab.c"
    break;

  case 196:
#line 1985 "src/parse.y"
        {
    (yyval.ptr) = new treeNode;
    (yyval.ptr)->type = TYPE_VOID;
}
#line 4567 "src/parse.tab.c"
    break;

  case 197:
#line 1991 "src/parse.y"
                    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4573 "src/parse.tab.c"
    break;

  case 198:
#line 1992 "src/parse.y"
        {
    (yyval.ptr) = new treeNode;
}
#line 4581 "src/parse.tab.c"
    break;

  case 199:
#line 1997 "src/parse.y"
                               {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Argument List", v);
    free((yyval.ptr));
    // type checking
    (yyval.ptr) = (yyvsp[-2].ptr);
    (yyval.ptr)->typevec.push_back((yyvsp[0].ptr)->type);
}
#line 4596 "src/parse.tab.c"
    break;

  case 200:
#line 2007 "src/parse.y"
                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Argument List", v);

    // type checking
    (yyval.ptr)->typevec.push_back((yyvsp[0].ptr)->type);
}
#line 4609 "src/parse.tab.c"
    break;

  case 201:
#line 2017 "src/parse.y"
           {
    string s = "INT(" + *(yyvsp[0].str) + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_INT;

    //3ac
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4622 "src/parse.tab.c"
    break;

  case 202:
#line 2025 "src/parse.y"
             {
    string s = "FLOAT(" + *(yyvsp[0].str) + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_FLOAT;

    //3ac
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4635 "src/parse.tab.c"
    break;

  case 203:
#line 2033 "src/parse.y"
            {
    string temp = *(yyvsp[0].str);
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "CHAR(" + temp + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_CHAR;

    //3ac
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4651 "src/parse.tab.c"
    break;

  case 204:
#line 2044 "src/parse.y"
              {
    string temp = *(yyvsp[0].str);
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "STRING(" + temp + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_STRING;

    //3ac
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4667 "src/parse.tab.c"
    break;

  case 205:
#line 2055 "src/parse.y"
            {
    string s = "BOOL(" + *(yyvsp[0].str) + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_BOOL;
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4678 "src/parse.tab.c"
    break;

  case 206:
#line 2061 "src/parse.y"
            {
    string s = "LONG(" + *(yyvsp[0].str) + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_LONG;
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4689 "src/parse.tab.c"
    break;

  case 207:
#line 2067 "src/parse.y"
              {
    string s = "DOUBLE(" + *(yyvsp[0].str) + ")";
    (yyval.ptr) = makeleaf(s);
    (yyval.ptr)->type = TYPE_DOUBLE;
    (yyval.ptr)->addr = *(yyvsp[0].str);
}
#line 4700 "src/parse.tab.c"
    break;

  case 208:
#line 2076 "src/parse.y"
                  {
    (yyval.ptr) = makeleaf("static");
}
#line 4708 "src/parse.tab.c"
    break;

  case 209:
#line 2079 "src/parse.y"
              {
    (yyval.ptr) = NULL;
}
#line 4716 "src/parse.tab.c"
    break;

  case 210:
#line 2085 "src/parse.y"
               {
    (yyval.ptr) = makeleaf("int");
    dType = TYPE_INT;
    (yyval.ptr)->type = dType;
}
#line 4726 "src/parse.tab.c"
    break;

  case 211:
#line 2090 "src/parse.y"
                {
    (yyval.ptr) = makeleaf("bool");
    dType = TYPE_BOOL;
    (yyval.ptr)->type = dType;
}
#line 4736 "src/parse.tab.c"
    break;

  case 212:
#line 2095 "src/parse.y"
                  {
    (yyval.ptr) = makeleaf("double");
    dType = TYPE_DOUBLE;
    (yyval.ptr)->type = dType;
}
#line 4746 "src/parse.tab.c"
    break;

  case 213:
#line 2100 "src/parse.y"
                 {
    (yyval.ptr) = makeleaf("float");
    dType = TYPE_FLOAT;
    (yyval.ptr)->type = dType;
}
#line 4756 "src/parse.tab.c"
    break;

  case 214:
#line 2105 "src/parse.y"
                {
    (yyval.ptr) = makeleaf("long");
    dType = TYPE_LONG;
    (yyval.ptr)->type = dType;
}
#line 4766 "src/parse.tab.c"
    break;

  case 215:
#line 2110 "src/parse.y"
                {
    (yyval.ptr) = makeleaf("char");
    dType = TYPE_CHAR;
    (yyval.ptr)->type = dType;
}
#line 4776 "src/parse.tab.c"
    break;

  case 216:
#line 2115 "src/parse.y"
                  {
    (yyval.ptr) = makeleaf("string");
    dType = TYPE_STRING;
    (yyval.ptr)->type = dType;
}
#line 4786 "src/parse.tab.c"
    break;

  case 217:
#line 2123 "src/parse.y"
                                             {CREATE_ST_KEY(temp,*(yyvsp[0].str));temp->type.push_back(TYPE_CLASS); CREATE_ST_ENTRY(temp_entry, "ID", *(yyvsp[0].str), yylineno, 0); temp_entry->type.push_back(TYPE_CLASS); if(insert_symtbl(temp,temp_entry ) == ALREADY_EXIST) yyerror("Class " + *(yyvsp[0].str) + " Already Exist!") ;create_symtbl(); temp_entry->table = current; free(temp);}
#line 4792 "src/parse.tab.c"
    break;

  case 218:
#line 2123 "src/parse.y"
                                                                                                                                                                                                                                                                                                                                                                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, makeleaf("class"), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-2].str) + ")"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ClassDeclaration", v);

    //end scope
    current = current->parent;
}
#line 4808 "src/parse.tab.c"
    break;

  case 219:
#line 2136 "src/parse.y"
                                       {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    (yyval.ptr) = makenode("ClassBody", v);
}
#line 4820 "src/parse.tab.c"
    break;

  case 220:
#line 2143 "src/parse.y"
                       {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    (yyval.ptr) = makenode("ClassBody", v);
}
#line 4831 "src/parse.tab.c"
    break;

  case 221:
#line 2151 "src/parse.y"
                                                          {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ClassBody Declaration", v);
}
#line 4842 "src/parse.tab.c"
    break;

  case 222:
#line 2157 "src/parse.y"
                                      {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4848 "src/parse.tab.c"
    break;

  case 223:
#line 2160 "src/parse.y"
                                 {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4854 "src/parse.tab.c"
    break;

  case 224:
#line 2161 "src/parse.y"
                                     {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4860 "src/parse.tab.c"
    break;

  case 225:
#line 2162 "src/parse.y"
                                    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4866 "src/parse.tab.c"
    break;

  case 226:
#line 2163 "src/parse.y"
                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("ClassBody Declaration", v);
}
#line 4877 "src/parse.tab.c"
    break;

  case 227:
#line 2169 "src/parse.y"
                                          {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4883 "src/parse.tab.c"
    break;

  case 228:
#line 2172 "src/parse.y"
                                                 {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    (yyval.ptr) = makenode("ClassVariableDeclaration", v);
}
#line 4895 "src/parse.tab.c"
    break;

  case 229:
#line 2180 "src/parse.y"
                                                     {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("MethodDeclaration", v);
}
#line 4907 "src/parse.tab.c"
    break;

  case 230:
#line 2189 "src/parse.y"
                 {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 4915 "src/parse.tab.c"
    break;

  case 231:
#line 2192 "src/parse.y"
               {
    (yyval.ptr) = NULL;
    *ptr_func_def = false;
    ptr_func_def = NULL;

    //sematics
    methKeys.clear();
}
#line 4928 "src/parse.tab.c"
    break;

  case 232:
#line 2202 "src/parse.y"
                            {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("Dimensions", v);
}
#line 4940 "src/parse.tab.c"
    break;

  case 233:
#line 2209 "src/parse.y"
             {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    (yyval.ptr) = makenode("Dimensions", v);
}
#line 4951 "src/parse.tab.c"
    break;

  case 234:
#line 2217 "src/parse.y"
               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 4957 "src/parse.tab.c"
    break;

  case 235:
#line 2220 "src/parse.y"
                                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Method Header", v);
}
#line 4969 "src/parse.tab.c"
    break;

  case 236:
#line 2227 "src/parse.y"
                    {dType = TYPE_VOID;}
#line 4975 "src/parse.tab.c"
    break;

  case 237:
#line 2227 "src/parse.y"
                                                       {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Method Header", v);
}
#line 4987 "src/parse.tab.c"
    break;

  case 238:
#line 2234 "src/parse.y"
                           {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Method Header", v);
}
#line 4998 "src/parse.tab.c"
    break;

  case 239:
#line 2240 "src/parse.y"
                    {dType = TYPE_VOID;}
#line 5004 "src/parse.tab.c"
    break;

  case 240:
#line 2240 "src/parse.y"
                                                  {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("Method Header", v);
}
#line 5015 "src/parse.tab.c"
    break;

  case 241:
#line 2249 "src/parse.y"
                  {retType = dType;}
#line 5021 "src/parse.tab.c"
    break;

  case 242:
#line 2249 "src/parse.y"
                                                   {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-4].str) + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("Method Declaration", v);

    //sematics
    CREATE_ST_KEY(temp, *(yyvsp[-4].str));
    CREATE_ST_ENTRY(temp_entry, "ID", *(yyvsp[-4].str), yylineno, mod_flag);
    for(auto p:methKeys){
        temp_entry->type.push_back(p->type[0]);
    }
    temp_entry->type.push_back(retType);
    temp_entry->is_func = true;
    ptr_func_def = &(temp_entry->func_is_defined);
    if(insert_symtbl(temp, temp_entry) == ALREADY_EXIST){
        SymbTbl_entry* __temp = lookup(temp);
        if(__temp->func_is_defined){
            yyerror("Redeclaration of function " + *(yyvsp[-4].str));
        }
        ptr_func_def = &(__temp->func_is_defined);
    }
}
#line 5051 "src/parse.tab.c"
    break;

  case 243:
#line 2274 "src/parse.y"
                  {retType = dType;}
#line 5057 "src/parse.tab.c"
    break;

  case 244:
#line 2274 "src/parse.y"
                                        {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-3].str) + ")"), "", 1);
    insertAttr(v, NULL, "( )", 0);
    (yyval.ptr) = makenode("Method Declaration", v);

    //sematics
    CREATE_ST_KEY(temp, *(yyvsp[-3].str));
    CREATE_ST_ENTRY(temp_entry, "ID", *(yyvsp[-3].str), yylineno, mod_flag);
    temp_entry->type.push_back(dType);
    ptr_func_def = &(temp_entry->func_is_defined);
    if(insert_symtbl(temp, temp_entry) == ALREADY_EXIST){
        SymbTbl_entry* __temp = lookup(temp);
        if(__temp->func_is_defined){
            yyerror("Redeclaration of function " + *(yyvsp[-3].str));
        }
        ptr_func_def = &(__temp->func_is_defined);
    }
}
#line 5081 "src/parse.tab.c"
    break;

  case 245:
#line 2295 "src/parse.y"
                                {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-2].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("parameter list", v);

    // sematics
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
    
    methKeys.push_back(temp_entry);
}
#line 5098 "src/parse.tab.c"
    break;

  case 246:
#line 2307 "src/parse.y"
                 {
    (yyval.ptr) = (yyvsp[0].ptr);

    // sematics
    CREATE_ST_ENTRY(temp_entry,"ID", (yyvsp[0].ptr)->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, (yyvsp[0].ptr)->dim));
        
    methKeys.push_back(temp_entry);

    
}
#line 5114 "src/parse.tab.c"
    break;

  case 247:
#line 2320 "src/parse.y"
                 {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("parameter", v);
    (yyval.ptr)->lexeme = (yyvsp[0].ptr)->lexeme;
    (yyval.ptr)->dim = (yyvsp[0].ptr)->dim;
}
#line 5127 "src/parse.tab.c"
    break;

  case 248:
#line 2330 "src/parse.y"
                        {
    (yyval.ptr) = (yyvsp[0].ptr);
}
#line 5135 "src/parse.tab.c"
    break;

  case 249:
#line 2333 "src/parse.y"
                      {
    (yyval.ptr) = NULL;
    mod_flag = 0;
}
#line 5144 "src/parse.tab.c"
    break;

  case 250:
#line 2339 "src/parse.y"
                        {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("modifier list", v);
}
#line 5155 "src/parse.tab.c"
    break;

  case 251:
#line 2345 "src/parse.y"
               {(yyval.ptr) = (yyvsp[0].ptr);}
#line 5161 "src/parse.tab.c"
    break;

  case 252:
#line 2348 "src/parse.y"
                   {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("private"), "", 1);
    (yyval.ptr) = makenode("modifier", v);

    mod_flag = PRIVATE_FLAG;
}
#line 5173 "src/parse.tab.c"
    break;

  case 253:
#line 2355 "src/parse.y"
                  {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("public"), "", 1);
    (yyval.ptr) = makenode("modifier", v);

    mod_flag = PUBLIC_FLAG;
}
#line 5185 "src/parse.tab.c"
    break;

  case 254:
#line 2362 "src/parse.y"
                  {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("static"), "", 1);
    (yyval.ptr) = makenode("modifier", v);

    mod_flag = 0;
}
#line 5197 "src/parse.tab.c"
    break;

  case 255:
#line 2369 "src/parse.y"
                    {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("protected"), "", 1);
    (yyval.ptr) = makenode("modifier", v);

    mod_flag = PROTECTED_FLAG;
}
#line 5209 "src/parse.tab.c"
    break;

  case 256:
#line 2378 "src/parse.y"
                                                         {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-4].ptr), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-3].str) + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, NULL, ")", 0);
    (yyval.ptr) = makenode("construtorhead", v);

    //sematics
    CREATE_ST_KEY(temp, *(yyvsp[-3].str));
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* temp_entry;
    temp_entry = lookup(temp);
    if(temp_entry->table == current && *(yyvsp[-3].str) == temp_entry->lexeme){
        // correct constructor declaration.
        // create a new entry in the symbol table for class.
        CREATE_ST_KEY(temp_construct, *(yyvsp[-3].str));
        CREATE_ST_ENTRY(temp_centry, "ID", *(yyvsp[-3].str), yylineno, PUBLIC_FLAG);
        temp_centry->is_func = true;
        for(auto p:methKeys){
            temp->type.push_back(p->type[0]);
        }
        temp->type.push_back(TYPE_NORET);
        if(insert_symtbl(temp_construct, temp_centry)==ALREADY_EXIST){
            yyerror("Constructor already declared in class " + *(yyvsp[-3].str));
        }
        free(temp_construct);
        
    }
    else{
        yyerror("No return type for the function " + *(yyvsp[-3].str) );
    }
    free(temp);
    
    
}
#line 5251 "src/parse.tab.c"
    break;

  case 257:
#line 2415 "src/parse.y"
                                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-3].ptr), "", 1);
    insertAttr(v, makeleaf("ID(" + *(yyvsp[-2].str) + ")"), "", 1);
    (yyval.ptr) = makenode("construtorhead", v);

    //sematics
    CREATE_ST_KEY(temp, *(yyvsp[-2].str));
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* temp_entry;
    temp_entry = lookup(temp);
    if(temp_entry->table == current && *(yyvsp[-2].str) == temp_entry->lexeme){
        // correct constructor declaration.
        // create a new entry in the symbol table for class.
        CREATE_ST_KEY(temp_construct, *(yyvsp[-2].str));
        CREATE_ST_ENTRY(temp_centry, "ID", *(yyvsp[-2].str), yylineno, PUBLIC_FLAG);
        temp_centry->is_func = true;
        temp->type.push_back(TYPE_NORET);
        if(insert_symtbl(temp_construct, temp_centry)==ALREADY_EXIST){
            yyerror("Constructor already declared in class " + *(yyvsp[-2].str));
        }
        free(temp_construct);
    }
    else{
        yyerror("No return type for the function " + *(yyvsp[-2].str) );
    }
    free(temp);
    retType = TYPE_NORET;
}
#line 5285 "src/parse.tab.c"
    break;

  case 258:
#line 2446 "src/parse.y"
                                             {
    vector<treeNode*> v;
    insertAttr(v, (yyvsp[-1].ptr), "", 1);
    insertAttr(v, (yyvsp[0].ptr), "", 1);
    (yyval.ptr) = makenode("construtor", v);

}
#line 5297 "src/parse.tab.c"
    break;


#line 5301 "src/parse.tab.c"

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
#line 2455 "src/parse.y"



int main(int argc, char** argv) {
    if(argc < 2){
        cout << "Usage: " << argv[0] << " <input file> [--input=<input file>] [--output=<output file>] [--verbose] [--help]" << endl;
        return 0;
    }
    char* infile = argv[1];
    char* outfile = strdup(argv[0]);
    outfile = strcat(outfile, ".dot");
    bool verbose = false;
    for(int i=1;i<argc;i++){
        
        /* cout<<i<<endl; */
        /* if argv contains --input= take it as input file */
        if(strncmp(argv[i], "--input=", 8) == 0){
            infile = argv[i] + 8;
        }
        /* if argv contains --output= take it as output file */
        else if(strncmp(argv[i], "--output=", 9) == 0){
            outfile = argv[i] + 9;
        }
        /* if argv is --verbose */
        else if(strcmp(argv[i], "--verbose") == 0){
            verbose = true;
        }
        /* if argv is --help print help message and exit.  */
        else if(strcmp(argv[i], "--help") == 0){
            cout << "Usage: " << argv[0] << " path/to/input.java [other options]" << endl;
            cout << "Other options:" << endl;
            cout << "  --input=FILE\t\tRead input from FILE" << endl;
            cout << "  --output=FILE\t\tWrite output to FILE" << endl;
            cout << "  --verbose\t\tPrint verbose output" << endl;
            cout << "  --help\t\tPrint this help message" << endl;
            return 0;
        }
        /* else print error */
        else if(i>1) {
            cout << "Invalid format! use" << argv[0] <<" --help for more info."<<endl;
            return -1; 
        }
    }

    /* Open input file... */
    if(verbose){
        cout<<"Opening input file..."<<endl;

    }
    FILE *myfile = fopen(infile, "r");
    if (!myfile) {
        cout <<"ERROR: "  << "Could not open file: "<< infile << endl;
        return -1;
    }
    yyin = myfile;

    /* Open output file... */
    if(verbose){
        cout<<"Opening output file..."<<endl;
    }
    dotfile = fopen(outfile, "w");
    if(!dotfile){
        cout <<"ERROR: "  << "Could not open file: "<< outfile << endl;
        return -1;
    }

    /* start parsing */
    if(verbose){
        cout<<"Started Parsing"<<endl;
    }
    beginAST();
    do {
        yyparse();
    } while (!feof(yyin));
    endAST();
    printSymbolTable(current);
    print_code();
    if(verbose){
        cout<<"Parsing Complete"<<endl;
        cout<<"Output written to "<<outfile<<endl;
    }
  
}
