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
#line 1 "parse.yy"


    #include<iostream>
    using namespace std;
    
    extern int yylex();
    extern int yyparse();
    extern int yylineno;
    extern FILE* yyin;

    void yyerror(const char *s) {
        cout << "[Line no: " << yylineno << "] " << "error: " << "parse error: " << s << endl;
        exit(-1);
    }



#line 88 "parse.tab.cc"

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
#ifndef YY_YY_PARSE_TAB_HH_INCLUDED
# define YY_YY_PARSE_TAB_HH_INCLUDED
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
    KEY_PRIVATE = 286,
    KEY_PUBLIC = 287,
    KEY_STATIC = 288,
    KEY_CLASS = 289,
    ASSIGN_OP = 290,
    INCREMENT = 291,
    DECREMENT = 292,
    LOG_OR = 293,
    LOG_AND = 294,
    EQUAL = 295,
    NOT_EQUAL = 296,
    GTR_EQUAL = 297,
    LESS_EQUAL = 298,
    LEFT_SHIFT = 299,
    RIGHT_SHIFT = 300,
    SIGN_SHIFT = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parse.yy"

    int num;
    char chr;
    char* str;

#line 193 "parse.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_HH_INCLUDED  */



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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  376

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
       2,     2,     2,    70,     2,     2,     2,    68,    62,     2,
      53,    54,    49,    65,    55,    66,    48,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    47,
      63,    56,    64,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    60,    51,    69,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,    98,   101,   102,   105,   106,   109,   110,
     113,   114,   117,   118,   121,   122,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   136,   137,   140,   141,   142,
     143,   144,   147,   148,   149,   150,   153,   155,   157,   159,
     162,   163,   166,   167,   168,   171,   172,   175,   177,   179,
     183,   186,   187,   188,   189,   192,   193,   194,   195,   198,
     199,   200,   201,   204,   206,   207,   210,   212,   213,   216,
     218,   219,   222,   223,   224,   225,   226,   227,   230,   233,
     236,   237,   240,   243,   244,   247,   248,   250,   251,   254,
     255,   256,   260,   261,   264,   265,   268,   269,   272,   273,
     276,   277,   280,   281,   284,   285,   286,   289,   290,   291,
     292,   293,   296,   297,   298,   299,   302,   303,   304,   307,
     308,   309,   310,   313,   314,   315,   316,   317,   320,   323,
     326,   327,   328,   331,   332,   333,   334,   337,   338,   342,
     343,   347,   348,   349,   350,   351,   352,   353,   356,   357,
     360,   361,   364,   365,   368,   371,   376,   376,   379,   379,
     382,   383,   386,   387,   388,   389,   390,   391,   392,   396,
     397,   401,   402,   403,   404,   405,   406,   407,   411,   414,
     415,   418,   419,   422,   423,   424,   425,   426,   429,   431,
     434,   435,   438,   439,   442,   445,   446,   447,   448,   451,
     452,   455,   456,   459,   462,   463,   466,   467,   470,   471,
     472,   475,   476
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
  "KEY_IMPORT", "KEY_PRIVATE", "KEY_PUBLIC", "KEY_STATIC", "KEY_CLASS",
  "ASSIGN_OP", "INCREMENT", "DECREMENT", "LOG_OR", "LOG_AND", "EQUAL",
  "NOT_EQUAL", "GTR_EQUAL", "LESS_EQUAL", "LEFT_SHIFT", "RIGHT_SHIFT",
  "SIGN_SHIFT", "';'", "'.'", "'*'", "'{'", "'}'", "':'", "'('", "')'",
  "','", "'='", "'['", "']'", "'?'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'/'", "'%'", "'~'", "'!'", "$accept", "START",
  "ClassDeclaration_list", "ImportDecl_list", "ImportDecl", "Imp_list",
  "BODY", "BLCK", "STMNT_without_sub", "Assert_stmnt", "STMNT",
  "STMNT_noshortif", "WHILE_STMNT", "WHILE_STMNT_noshortif", "BASIC_FOR",
  "BASIC_FOR_noshortif", "FOR_UPDATE", "FOR_INIT", "STMNT_EXPR_list",
  "IF_THEN", "IF_THEN_ELSE", "IF_THEN_ELSE_noshortif", "DEF_VAR",
  "VAR_LIST", "VARA", "VAR", "L3D", "CONT3D", "L2D", "CONT2D", "L1D",
  "CONT1D", "STMNT_EXPR", "Meth_invoc", "Expr", "AssignmentExpression",
  "Assignment", "AssignmentOperator", "ExpressionName", "AmbiguousName",
  "LeftHandSide", "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "InclusiveOrExpression",
  "ExclusiveOrExpression", "AndExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PreIncrementExpression",
  "PreDecrementExpression", "UnaryExpressionNotPlusMinus",
  "PostfixExpression", "FieldAccess", "Primary", "PrimaryNoNewArray",
  "ArrayCreationExpr", "DimExpr", "ArrayAccess", "PostIncrementExpression",
  "PostDecrementExpression", "EMP_EXPR", "ARG_LIST", "ARG_LISTp", "LIT",
  "STAT", "DTYPE", "ClassDeclaration", "Class_body", "Class_body_dec_list",
  "Class_body_dec", "Class_DEF_VAR", "MethodDeclaration", "Meth_Body",
  "DIMS_list", "DIMS", "Meth_Head", "Meth_decl", "Param_list", "Param",
  "MOD_EMPTY_LIST", "MOD_LIST", "MOD", "ConstructorDeclaration", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,    59,    46,    42,
     123,   125,    58,    40,    41,    44,    61,    91,    93,    63,
     124,    94,    38,    60,    62,    43,    45,    47,    37,   126,
      33
};
# endif

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-206)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     284,     5,  -329,  -329,  -329,    31,   287,   284,  -329,  -329,
       6,   185,  -329,  -329,    62,  -329,  -329,   287,  -329,    98,
    -329,  -329,   166,    53,  -329,    18,   245,  -329,  -329,    66,
      93,  -329,   106,  -329,   249,  -329,  -329,  -329,   116,  -329,
    -329,   366,  -329,  -329,  -329,   118,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,     2,    14,    68,   100,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,   295,   144,   181,   183,   208,   217,
     541,   541,   541,   225,   541,   541,  -329,  -329,   541,   541,
     541,   541,   541,   419,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,   228,  -329,   236,  -329,  -329,   189,   253,   -15,
    -329,    -1,   246,   262,   244,   288,   207,    82,   176,   195,
      71,  -329,  -329,  -329,  -329,   267,    29,   350,   332,  -329,
      58,  -329,  -329,  -329,   276,    32,   355,   351,   353,   408,
    -329,   101,   -22,  -329,  -329,   408,  -329,  -329,  -329,  -329,
      42,   357,   576,   541,   541,  -329,  -329,  -329,   365,    16,
     368,   415,   109,  -329,  -329,  -329,  -329,   367,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,   541,   541,   417,  -329,
    -329,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,  -329,  -329,   427,   541,   430,   106,   431,   293,
    -329,    95,  -329,   384,  -329,   541,   541,  -329,   430,  -329,
     541,   541,   392,   392,   403,   396,  -329,  -329,    97,  -329,
    -329,  -329,   267,   341,   343,   399,   400,  -329,  -329,   541,
    -329,  -329,  -329,  -329,   404,   402,   401,   412,  -329,   246,
     409,   262,   244,   288,   207,    82,    82,   176,   176,   176,
     176,   195,   195,   195,    71,    71,  -329,  -329,  -329,  -329,
     406,   325,   407,  -329,   410,  -329,   106,   276,  -329,   329,
    -329,  -329,   413,  -329,  -329,   411,   424,   541,   541,    47,
     471,   506,   421,  -329,   541,  -329,   541,  -329,   541,  -329,
    -329,  -329,   340,    53,  -329,   425,   426,  -329,  -329,   433,
     434,   441,   478,  -329,   479,  -329,  -329,  -329,  -329,  -329,
    -329,   445,   455,   541,  -329,  -329,    47,   576,   541,   541,
     471,   449,   541,  -329,   459,   465,   396,   473,   468,   469,
    -329,   541,   113,  -329,   344,   471,   541,   506,   506,   480,
    -329,   541,   502,   541,  -329,   482,  -329,   531,   498,  -329,
     455,  -329,   499,    47,   506,   541,   155,  -329,   505,   504,
    -329,   507,  -329,   455,   512,   506,  -329,  -329,   502,  -329,
    -329,   156,  -329,  -329,   502,  -329
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     205,   170,   208,   209,   210,     0,     3,   205,     7,     5,
       0,   204,   207,   169,     0,     1,     4,     2,     6,     0,
     206,    11,     0,     0,     8,     0,   205,   178,    10,     0,
     210,   180,     0,   185,   205,   182,   183,   184,     0,   187,
       9,   170,   186,   179,   181,     0,   171,   174,   175,   173,
     172,   176,   177,     0,     0,     0,    86,   162,   163,   168,
     164,   165,   166,   167,     0,     0,     0,     0,     0,     0,
     157,     0,     0,     0,     0,     0,    24,    15,     0,     0,
       0,     0,     0,   170,    16,    27,    23,    13,    30,    31,
      28,    29,     0,   144,     0,    79,    81,   134,     0,     0,
      80,    92,    94,    96,    98,   100,   102,   104,   107,   112,
     116,   119,   123,   124,   127,   130,   145,   133,   139,   140,
     143,   135,   136,   141,     0,     0,     0,     0,   194,     0,
     198,    59,     0,    54,    53,     0,   197,   191,   190,   189,
       0,     0,   170,     0,     0,    20,    21,   156,     0,     0,
       0,     0,   134,   128,   145,   143,   129,     0,   125,   126,
     131,   132,    14,    12,    18,    17,   159,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,     0,     0,     0,     0,     0,     0,
     202,     0,   193,     0,   196,     0,   157,   188,     0,   195,
     159,     0,   149,   148,     0,    43,    42,    46,   144,    72,
      73,    74,     0,    76,    75,     0,     0,    19,    25,     0,
      22,   138,   142,   161,     0,   158,     0,    85,    82,    95,
       0,    97,    99,   101,   103,   105,   106,   110,   111,   108,
     109,   113,   114,   115,   117,   118,   120,   121,   122,   137,
       0,    59,    50,   212,    59,   203,     0,     0,   200,     0,
     192,    55,     0,    52,    51,     0,     0,     0,   157,     0,
     170,   170,     0,    78,     0,   152,     0,   153,   157,   211,
     201,   199,    60,   147,   150,     0,     0,    45,    36,     0,
       0,     0,    27,    47,     0,    34,    35,    33,    26,   160,
      93,     0,     0,   157,   146,   151,    41,   170,     0,     0,
     170,    60,     0,    56,     0,     0,    40,     0,     0,     0,
      48,   157,     0,    71,    61,   170,   157,   170,   170,     0,
      69,     0,     0,   157,    38,     0,    37,     0,    61,    70,
       0,    57,     0,    41,   170,   157,     0,    68,    62,     0,
      49,     0,    66,     0,     0,   170,    62,    67,     0,    58,
      39,     0,    65,    63,     0,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,   556,  -329,   557,  -329,  -329,   -28,  -249,  -329,
     -41,  -142,  -329,  -329,  -329,  -329,   213,   250,  -293,  -329,
    -329,  -329,  -123,   372,   361,  -169,  -329,  -329,  -287,  -329,
    -328,  -329,   294,  -126,   -69,  -329,  -124,  -329,    -2,  -329,
    -329,   301,  -329,   416,   418,   414,   398,   420,   226,   163,
      84,   219,   -68,  -118,  -116,  -329,  -114,   151,  -329,  -329,
    -329,   450,   177,  -112,   -51,  -196,   380,  -329,  -329,    35,
     -30,   237,   300,  -329,   562,  -329,  -329,  -329,  -329,   544,
    -329,   -39,   423,   333,    36,  -329,   588,  -329
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    22,    83,    84,    85,    86,
     298,   304,    88,   305,    89,   306,   325,   214,   215,    90,
      91,   307,    92,   132,   133,   134,   369,   371,   351,   356,
     323,   332,   217,    93,    94,    95,    96,   171,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   212,   120,   121,   122,   148,   234,   235,   123,   124,
     198,     9,    27,    34,    35,    36,    37,   139,   128,   129,
      55,   130,   199,   200,    10,    11,    12,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   147,   149,   150,    42,   126,   153,   156,    54,   157,
     272,   158,   159,   160,   161,   136,   218,   131,   219,   216,
     169,    28,   357,   326,   220,   207,   221,   138,   222,   265,
     223,    15,   302,   208,   141,   367,    14,   172,    13,   274,
      19,   170,   163,    46,    47,    48,    49,    50,    51,    52,
      56,    57,    58,    59,    60,    61,    62,    63,   173,   127,
     326,    32,    38,   228,   -90,    21,    64,    29,   229,    32,
      38,   127,   152,   152,   225,   226,    73,   152,   152,   152,
     152,   372,   296,    74,    75,   -90,   197,   375,   302,   302,
     204,   224,   311,   -91,   196,   210,   209,   233,   236,   211,
      78,    23,   238,    26,   240,   302,    46,    47,    48,    49,
      50,    51,    52,    40,   -91,   137,   302,   324,    41,    45,
     189,   256,   257,   258,   180,   181,   260,    46,    47,    48,
      49,    50,    51,    52,    53,   339,   271,   147,   190,   191,
     345,   233,   276,  -169,   -77,   182,   183,   352,   -87,   268,
      19,   -77,   -77,   218,   201,   219,    41,   205,   206,   361,
     282,   220,   166,   221,   340,   222,   167,   223,   341,   263,
     152,   125,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     218,   218,   219,   219,   216,   346,   347,   142,   220,   220,
     221,   221,   222,   222,   223,   223,   362,   373,   295,   147,
     363,   374,   360,    24,    25,   309,     2,     3,     4,   147,
     184,   185,   186,   370,   -89,   154,   154,   218,   224,   219,
     154,   154,   154,   154,   143,   220,   144,   221,   289,   222,
     303,   223,   166,    16,   147,   -89,   167,   178,   179,   328,
     329,   155,   155,   333,    16,   145,   155,   155,   155,   155,
     187,   188,   147,    33,   146,   224,   224,   147,   251,   252,
     253,    33,   349,   151,   147,   164,     2,     3,    30,   330,
       2,     3,    30,   165,   152,   174,   147,    46,    47,    48,
      49,    50,    51,    52,   344,  -170,    31,   303,   140,  -170,
      43,   168,   224,   192,   193,   176,    46,    47,    48,    49,
      50,    51,    52,   330,     1,     2,     3,     4,     2,     3,
       4,  -205,   175,   154,   344,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   247,   248,   249,   250,   266,   267,   155,
     177,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,    56,
      57,    58,    59,    60,    61,    62,    63,  -135,  -135,  -136,
    -136,   205,   206,   291,   267,    64,    65,    66,    67,   195,
      68,    69,    70,    71,    72,    73,   312,   313,   194,    13,
     342,   343,    74,    75,   245,   246,   254,   255,   201,   202,
     203,   126,   227,    76,   211,   230,    41,    77,   231,    78,
     237,   232,    56,    57,    58,    59,    60,    61,    62,    63,
     259,    79,    80,   261,   264,    81,    82,   154,    64,    65,
      66,    67,   270,    68,    69,    70,    71,    72,    73,   277,
     278,   279,    13,   280,   281,    74,    75,   284,   283,   285,
     -88,   286,   208,   155,   287,   293,    76,   288,   308,    41,
     162,   292,    78,   316,    56,    57,    58,    59,    60,    61,
      62,    63,   294,   315,    79,    80,   317,   318,    81,    82,
      64,    65,    66,    67,   319,    68,    69,    70,    71,    72,
      73,   -32,   320,   321,    13,   322,   331,    74,    75,    56,
      57,    58,    59,    60,    61,    62,    63,   334,    76,   335,
     336,    41,   337,   338,    78,    64,   299,   300,   301,   353,
      68,    69,    70,    71,    72,    73,    79,    80,   348,    13,
      81,    82,    74,    75,    56,    57,    58,    59,    60,    61,
      62,    63,   350,    76,   354,   355,    41,   358,   365,    78,
      64,   364,   368,    17,    18,   366,   359,   327,   262,   273,
      73,    79,    80,   297,   243,    81,    82,    74,    75,    56,
      57,    58,    59,    60,    61,    62,    63,   310,   239,   242,
     275,   213,   241,   314,    78,    64,    44,   244,   135,    20,
     290,     0,     0,     0,     0,    73,    79,    80,     0,    13,
      81,    82,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -44,   269,     0,     0,     0,     0,    78
};

static const yytype_int16 yycheck[] =
{
      41,    70,    71,    72,    32,     3,    74,    75,    38,    78,
     206,    79,    80,    81,    82,    54,   142,     3,   142,   142,
      35,     3,   350,   316,   142,    47,   142,    55,   142,   198,
     142,     0,   281,    55,    64,   363,     1,    38,    33,   208,
      34,    56,    83,    11,    12,    13,    14,    15,    16,    17,
       3,     4,     5,     6,     7,     8,     9,    10,    59,    57,
     353,    26,    26,    47,    35,     3,    19,    49,    52,    34,
      34,    57,    74,    75,   143,   144,    29,    79,    80,    81,
      82,   368,   278,    36,    37,    56,    54,   374,   337,   338,
     129,   142,   288,    35,   124,    53,   135,   166,   167,    57,
      53,     3,   171,    50,   173,   354,    11,    12,    13,    14,
      15,    16,    17,    47,    56,    47,   365,   313,    50,     3,
      49,   189,   190,   191,    42,    43,   195,    11,    12,    13,
      14,    15,    16,    17,    18,   331,   205,   206,    67,    68,
     336,   210,   211,    50,    47,    63,    64,   343,    48,    54,
      34,    54,    55,   279,    53,   279,    50,    56,    57,   355,
     229,   279,    53,   279,    51,   279,    57,   279,    55,   197,
     172,    53,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     316,   317,   316,   317,   317,   337,   338,    53,   316,   317,
     316,   317,   316,   317,   316,   317,    51,    51,   277,   278,
      55,    55,   354,    47,    48,   284,    31,    32,    33,   288,
      44,    45,    46,   365,    35,    74,    75,   353,   279,   353,
      79,    80,    81,    82,    53,   353,    53,   353,   266,   353,
     281,   353,    53,     6,   313,    56,    57,    40,    41,   318,
     319,    74,    75,   322,    17,    47,    79,    80,    81,    82,
      65,    66,   331,    26,    47,   316,   317,   336,   184,   185,
     186,    34,   341,    48,   343,    47,    31,    32,    33,   320,
      31,    32,    33,    47,   286,    39,   355,    11,    12,    13,
      14,    15,    16,    17,   335,    50,    51,   338,     3,    50,
      51,    48,   353,    36,    37,    61,    11,    12,    13,    14,
      15,    16,    17,   354,    30,    31,    32,    33,    31,    32,
      33,    34,    60,   172,   365,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   180,   181,   182,   183,    54,    55,   172,
      62,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     3,
       4,     5,     6,     7,     8,     9,    10,    36,    37,    36,
      37,    56,    57,    54,    55,    19,    20,    21,    22,    57,
      24,    25,    26,    27,    28,    29,    56,    57,    48,    33,
      56,    57,    36,    37,   178,   179,   187,   188,    53,    58,
      57,     3,    47,    47,    57,    47,    50,    51,     3,    53,
       3,    54,     3,     4,     5,     6,     7,     8,     9,    10,
       3,    65,    66,     3,     3,    69,    70,   286,    19,    20,
      21,    22,    58,    24,    25,    26,    27,    28,    29,    57,
      47,    55,    33,    54,    54,    36,    37,    55,    54,    58,
      48,    52,    55,   286,    58,    54,    47,    57,    47,    50,
      51,    58,    53,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    58,    58,    65,    66,    53,    53,    69,    70,
      19,    20,    21,    22,    53,    24,    25,    26,    27,    28,
      29,    23,    23,    58,    33,    50,    57,    36,    37,     3,
       4,     5,     6,     7,     8,     9,    10,    58,    47,    54,
      47,    50,    54,    54,    53,    19,    20,    21,    22,    47,
      24,    25,    26,    27,    28,    29,    65,    66,    58,    33,
      69,    70,    36,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    50,    47,    23,    57,    50,    58,    54,    53,
      19,    56,    50,     7,     7,    58,   353,   317,   196,   208,
      29,    65,    66,   279,   176,    69,    70,    36,    37,     3,
       4,     5,     6,     7,     8,     9,    10,   286,   172,   175,
     210,   141,   174,   293,    53,    19,    34,   177,    54,    11,
     267,    -1,    -1,    -1,    -1,    29,    65,    66,    -1,    33,
      69,    70,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,   201,    -1,    -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    32,    33,    72,    73,    74,    75,   142,
     155,   156,   157,    33,   140,     0,   142,    73,    75,    34,
     157,     3,    76,     3,    47,    48,    50,   143,     3,    49,
      33,    51,   140,   142,   144,   145,   146,   147,   155,   158,
      47,    50,    78,    51,   145,     3,    11,    12,    13,    14,
      15,    16,    17,    18,   141,   151,     3,     4,     5,     6,
       7,     8,     9,    10,    19,    20,    21,    22,    24,    25,
      26,    27,    28,    29,    36,    37,    47,    51,    53,    65,
      66,    69,    70,    77,    78,    79,    80,    81,    83,    85,
      90,    91,    93,   104,   105,   106,   107,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     133,   134,   135,   139,   140,    53,     3,    57,   149,   150,
     152,     3,    94,    95,    96,   150,   152,    47,    78,   148,
       3,   141,    53,    53,    53,    47,    47,   105,   136,   105,
     105,    48,   109,   123,   128,   133,   123,   105,   123,   123,
     123,   123,    51,    81,    47,    47,    53,    57,    48,    35,
      56,   108,    38,    59,    39,    60,    61,    62,    40,    41,
      42,    43,    63,    64,    44,    45,    46,    65,    66,    49,
      67,    68,    36,    37,    48,    57,   141,    54,   141,   153,
     154,    53,    58,    57,   152,    56,    57,    47,    55,   152,
      53,    57,   132,   132,    88,    89,    93,   103,   104,   107,
     124,   125,   127,   134,   135,   105,   105,    47,    47,    52,
      47,     3,    54,   105,   137,   138,   105,     3,   105,   114,
     105,   115,   116,   117,   118,   119,   119,   120,   120,   120,
     120,   121,   121,   121,   122,   122,   123,   123,   123,     3,
     105,     3,    94,    78,     3,    96,    54,    55,    54,   153,
      58,   105,   136,    95,    96,   137,   105,    57,    47,    55,
      54,    54,   105,    54,    55,    58,    52,    58,    57,    78,
     154,    54,    58,    54,    58,   105,   136,   103,    81,    20,
      21,    22,    79,    81,    82,    84,    86,    92,    47,   105,
     112,   136,    56,    57,   143,    58,    47,    53,    53,    53,
      23,    58,    50,   101,   136,    87,    89,    88,   105,   105,
      81,    57,   102,   105,    58,    54,    47,    54,    54,   136,
      51,    55,    56,    57,    81,   136,    82,    82,    58,   105,
      50,    99,   136,    47,    23,    57,   100,   101,    58,    87,
      82,   136,    51,    55,    56,    54,    58,   101,    50,    97,
      82,    98,    99,    51,    55,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    83,    84,    85,    86,
      87,    87,    88,    88,    88,    89,    89,    90,    91,    92,
      93,    94,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    98,    98,    99,   100,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   105,
     106,   106,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   121,   121,   121,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   124,   125,
     126,   126,   126,   127,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   140,
     140,   141,   141,   141,   141,   141,   141,   141,   142,   143,
     143,   144,   144,   145,   145,   145,   145,   145,   146,   147,
     148,   148,   149,   149,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   155,   155,   156,   156,   157,   157,
     157,   158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     4,     6,
       3,     1,     2,     1,     3,     2,     1,     2,     2,     3,
       2,     2,     3,     1,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     9,     9,
       1,     0,     1,     1,     0,     3,     1,     5,     7,     7,
       3,     3,     3,     1,     1,     3,     6,     9,    12,     1,
       4,     7,    10,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     2,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     3,     1,     1,     1,     6,     5,     3,     3,
       3,     4,     4,     4,     2,     2,     1,     0,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     2,     1,     1,     1,     1,     2,     1,     4,     3,
       1,     1,     3,     2,     1,     3,     3,     2,     2,     4,
       3,     3,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     6,     5
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

#line 1709 "parse.tab.cc"

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
#line 479 "parse.yy"



int main(int argc, char** argv) {

    FILE *myfile = fopen("test.java", "r");
    if (!myfile) {
        cout <<"ERROR: "  << "Could not open file: "<< argv[1] << endl;
        return -1;
    }
    yyin = myfile;
    
    do {
        yyparse();
    } while (!feof(yyin));
  
}
