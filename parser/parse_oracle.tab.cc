/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#line 77 "parse_oracle.tab.cc"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INCREMENT = 258,               /* INCREMENT  */
    DECREMENT = 259,               /* DECREMENT  */
    DOUBLE_COLON = 260,            /* DOUBLE_COLON  */
    LOG_OR = 261,                  /* LOG_OR  */
    LOG_AND = 262,                 /* LOG_AND  */
    EQUAL = 263,                   /* EQUAL  */
    NOT_EQUAL = 264,               /* NOT_EQUAL  */
    GTR_EQUAL = 265,               /* GTR_EQUAL  */
    LESS_EQUAL = 266,              /* LESS_EQUAL  */
    LEFT_SHIFT = 267,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 268,             /* RIGHT_SHIFT  */
    SIGN_SHIFT = 269,              /* SIGN_SHIFT  */
    ASSIGN_OP = 270,               /* ASSIGN_OP  */
    TRIPLE_DOT = 271,              /* TRIPLE_DOT  */
    Identifier = 272,              /* Identifier  */
    INT = 273,                     /* INT  */
    FLOAT = 274,                   /* FLOAT  */
    CHAR = 275,                    /* CHAR  */
    STRING = 276,                  /* STRING  */
    BOOL = 277,                    /* BOOL  */
    TEXTBLOCK = 278,               /* TEXTBLOCK  */
    TypeIdentifier = 279,          /* TypeIdentifier  */
    KEY_STATIC = 280,              /* KEY_STATIC  */
    KEY_RETURN = 281,              /* KEY_RETURN  */
    KEY_NEW = 282,                 /* KEY_NEW  */
    KEY_THIS = 283,                /* KEY_THIS  */
    KEY_SUPER = 284,               /* KEY_SUPER  */
    KEY_THROWS = 285,              /* KEY_THROWS  */
    KEY_INSTANCEOF = 286,          /* KEY_INSTANCEOF  */
    KEY_INT = 287,                 /* KEY_INT  */
    KEY_BYTE = 288,                /* KEY_BYTE  */
    KEY_SHORT = 289,               /* KEY_SHORT  */
    KEY_FLOAT = 290,               /* KEY_FLOAT  */
    KEY_LONG = 291,                /* KEY_LONG  */
    KEY_DOUBLE = 292,              /* KEY_DOUBLE  */
    KEY_BOOL = 293,                /* KEY_BOOL  */
    KEY_CHAR = 294,                /* KEY_CHAR  */
    KEY_VOID = 295,                /* KEY_VOID  */
    KEY_VAR = 296,                 /* KEY_VAR  */
    KEY_FOR = 297,                 /* KEY_FOR  */
    KEY_WHILE = 298,               /* KEY_WHILE  */
    KEY_IF = 299,                  /* KEY_IF  */
    KEY_ELSE = 300,                /* KEY_ELSE  */
    KEY_FINAL = 301,               /* KEY_FINAL  */
    KEY_PRIVATE = 302,             /* KEY_PRIVATE  */
    KEY_PUBLIC = 303,              /* KEY_PUBLIC  */
    KEY_CLASS = 304,               /* KEY_CLASS  */
    KEY_NULL = 305,                /* KEY_NULL  */
    KEY_BREAK = 306,               /* KEY_BREAK  */
    KEY_CONTINUE = 307             /* KEY_CONTINUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 7 "parse_oracle.yy"

    int num;
    char chr;
    char* str;

#line 182 "parse_oracle.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INCREMENT = 3,                  /* INCREMENT  */
  YYSYMBOL_DECREMENT = 4,                  /* DECREMENT  */
  YYSYMBOL_DOUBLE_COLON = 5,               /* DOUBLE_COLON  */
  YYSYMBOL_LOG_OR = 6,                     /* LOG_OR  */
  YYSYMBOL_LOG_AND = 7,                    /* LOG_AND  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 9,                  /* NOT_EQUAL  */
  YYSYMBOL_GTR_EQUAL = 10,                 /* GTR_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 11,                /* LESS_EQUAL  */
  YYSYMBOL_LEFT_SHIFT = 12,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 13,               /* RIGHT_SHIFT  */
  YYSYMBOL_SIGN_SHIFT = 14,                /* SIGN_SHIFT  */
  YYSYMBOL_ASSIGN_OP = 15,                 /* ASSIGN_OP  */
  YYSYMBOL_TRIPLE_DOT = 16,                /* TRIPLE_DOT  */
  YYSYMBOL_Identifier = 17,                /* Identifier  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_TEXTBLOCK = 23,                 /* TEXTBLOCK  */
  YYSYMBOL_TypeIdentifier = 24,            /* TypeIdentifier  */
  YYSYMBOL_KEY_STATIC = 25,                /* KEY_STATIC  */
  YYSYMBOL_KEY_RETURN = 26,                /* KEY_RETURN  */
  YYSYMBOL_KEY_NEW = 27,                   /* KEY_NEW  */
  YYSYMBOL_KEY_THIS = 28,                  /* KEY_THIS  */
  YYSYMBOL_KEY_SUPER = 29,                 /* KEY_SUPER  */
  YYSYMBOL_KEY_THROWS = 30,                /* KEY_THROWS  */
  YYSYMBOL_KEY_INSTANCEOF = 31,            /* KEY_INSTANCEOF  */
  YYSYMBOL_KEY_INT = 32,                   /* KEY_INT  */
  YYSYMBOL_KEY_BYTE = 33,                  /* KEY_BYTE  */
  YYSYMBOL_KEY_SHORT = 34,                 /* KEY_SHORT  */
  YYSYMBOL_KEY_FLOAT = 35,                 /* KEY_FLOAT  */
  YYSYMBOL_KEY_LONG = 36,                  /* KEY_LONG  */
  YYSYMBOL_KEY_DOUBLE = 37,                /* KEY_DOUBLE  */
  YYSYMBOL_KEY_BOOL = 38,                  /* KEY_BOOL  */
  YYSYMBOL_KEY_CHAR = 39,                  /* KEY_CHAR  */
  YYSYMBOL_KEY_VOID = 40,                  /* KEY_VOID  */
  YYSYMBOL_KEY_VAR = 41,                   /* KEY_VAR  */
  YYSYMBOL_KEY_FOR = 42,                   /* KEY_FOR  */
  YYSYMBOL_KEY_WHILE = 43,                 /* KEY_WHILE  */
  YYSYMBOL_KEY_IF = 44,                    /* KEY_IF  */
  YYSYMBOL_KEY_ELSE = 45,                  /* KEY_ELSE  */
  YYSYMBOL_KEY_FINAL = 46,                 /* KEY_FINAL  */
  YYSYMBOL_KEY_PRIVATE = 47,               /* KEY_PRIVATE  */
  YYSYMBOL_KEY_PUBLIC = 48,                /* KEY_PUBLIC  */
  YYSYMBOL_KEY_CLASS = 49,                 /* KEY_CLASS  */
  YYSYMBOL_KEY_NULL = 50,                  /* KEY_NULL  */
  YYSYMBOL_KEY_BREAK = 51,                 /* KEY_BREAK  */
  YYSYMBOL_KEY_CONTINUE = 52,              /* KEY_CONTINUE  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '='  */
  YYSYMBOL_63_ = 63,                       /* '?'  */
  YYSYMBOL_64_ = 64,                       /* ':'  */
  YYSYMBOL_65_ = 65,                       /* '|'  */
  YYSYMBOL_66_ = 66,                       /* '^'  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '<'  */
  YYSYMBOL_69_ = 69,                       /* '>'  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '%'  */
  YYSYMBOL_75_ = 75,                       /* '~'  */
  YYSYMBOL_76_ = 76,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_START = 78,                     /* START  */
  YYSYMBOL_IntegralType = 79,              /* IntegralType  */
  YYSYMBOL_FloatingPointType = 80,         /* FloatingPointType  */
  YYSYMBOL_NumericType = 81,               /* NumericType  */
  YYSYMBOL_PrimitiveType = 82,             /* PrimitiveType  */
  YYSYMBOL_ReferenceType = 83,             /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 84,      /* ClassOrInterfaceType  */
  YYSYMBOL_ClassType = 85,                 /* ClassType  */
  YYSYMBOL_InterfaceType = 86,             /* InterfaceType  */
  YYSYMBOL_TypeVariable = 87,              /* TypeVariable  */
  YYSYMBOL_ArrayType = 88,                 /* ArrayType  */
  YYSYMBOL_Dims = 89,                      /* Dims  */
  YYSYMBOL_ClassModifier = 90,             /* ClassModifier  */
  YYSYMBOL_ClassBody = 91,                 /* ClassBody  */
  YYSYMBOL_ClassBodyDeclaration_c = 92,    /* ClassBodyDeclaration_c  */
  YYSYMBOL_ClassBodyDeclaration = 93,      /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 94,    /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 95,          /* FieldDeclaration  */
  YYSYMBOL_FieldModifier_c = 96,           /* FieldModifier_c  */
  YYSYMBOL_FieldModifier = 97,             /* FieldModifier  */
  YYSYMBOL_UnannType = 98,                 /* UnannType  */
  YYSYMBOL_UnannPrimitiveType = 99,        /* UnannPrimitiveType  */
  YYSYMBOL_UnannReferenceType = 100,       /* UnannReferenceType  */
  YYSYMBOL_UnannClassOrInterfaceType = 101, /* UnannClassOrInterfaceType  */
  YYSYMBOL_UnannClassType = 102,           /* UnannClassType  */
  YYSYMBOL_UnannInterfaceType = 103,       /* UnannInterfaceType  */
  YYSYMBOL_UnannTypeVariable = 104,        /* UnannTypeVariable  */
  YYSYMBOL_UnannArrayType = 105,           /* UnannArrayType  */
  YYSYMBOL_MethodDeclaration = 106,        /* MethodDeclaration  */
  YYSYMBOL_MethodModifier_c = 107,         /* MethodModifier_c  */
  YYSYMBOL_MethodModifier = 108,           /* MethodModifier  */
  YYSYMBOL_MethodHeader = 109,             /* MethodHeader  */
  YYSYMBOL_Result = 110,                   /* Result  */
  YYSYMBOL_MethodDeclarator = 111,         /* MethodDeclarator  */
  YYSYMBOL_Dims_b = 112,                   /* Dims_b  */
  YYSYMBOL_ReceiverParameter_b = 113,      /* ReceiverParameter_b  */
  YYSYMBOL_ReceiverParameter = 114,        /* ReceiverParameter  */
  YYSYMBOL_Identifier_b = 115,             /* Identifier_b  */
  YYSYMBOL_FormalParameterList_b = 116,    /* FormalParameterList_b  */
  YYSYMBOL_FormalParameterList = 117,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter_c = 118,        /* FormalParameter_c  */
  YYSYMBOL_FormalParameter = 119,          /* FormalParameter  */
  YYSYMBOL_VariableArityParameter = 120,   /* VariableArityParameter  */
  YYSYMBOL_Throws_b = 121,                 /* Throws_b  */
  YYSYMBOL_Throws = 122,                   /* Throws  */
  YYSYMBOL_ExceptionTypeList = 123,        /* ExceptionTypeList  */
  YYSYMBOL_ExceptionType_c = 124,          /* ExceptionType_c  */
  YYSYMBOL_ExceptionType = 125,            /* ExceptionType  */
  YYSYMBOL_MethodBody = 126,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 127,        /* StaticInitializer  */
  YYSYMBOL_InstanceInitializer = 128,      /* InstanceInitializer  */
  YYSYMBOL_ConstructorDeclaration = 129,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorModifier_c = 130,    /* ConstructorModifier_c  */
  YYSYMBOL_ConstructorModifier = 131,      /* ConstructorModifier  */
  YYSYMBOL_ConstructorDeclarator = 132,    /* ConstructorDeclarator  */
  YYSYMBOL_SimpleTypeName = 133,           /* SimpleTypeName  */
  YYSYMBOL_ConstructorBody = 134,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation_b = 135, /* ExplicitConstructorInvocation_b  */
  YYSYMBOL_ExplicitConstructorInvocation = 136, /* ExplicitConstructorInvocation  */
  YYSYMBOL_ArgumentList_b = 137,           /* ArgumentList_b  */
  YYSYMBOL_ArgumentList = 138,             /* ArgumentList  */
  YYSYMBOL_Expression_c = 139,             /* Expression_c  */
  YYSYMBOL_BlockStatements_b = 140,        /* BlockStatements_b  */
  YYSYMBOL_Block = 141,                    /* Block  */
  YYSYMBOL_BlockStatements = 142,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 143,           /* BlockStatement  */
  YYSYMBOL_LocalClassOrInterfaceDeclaration = 144, /* LocalClassOrInterfaceDeclaration  */
  YYSYMBOL_ClassDeclaration = 145,         /* ClassDeclaration  */
  YYSYMBOL_NormalClassDeclaration = 146,   /* NormalClassDeclaration  */
  YYSYMBOL_ClassModifier_b = 147,          /* ClassModifier_b  */
  YYSYMBOL_LocalVariableDeclaration = 148, /* LocalVariableDeclaration  */
  YYSYMBOL_LocalVariableType = 149,        /* LocalVariableType  */
  YYSYMBOL_VariableDeclaratorList = 150,   /* VariableDeclaratorList  */
  YYSYMBOL_VariableDeclarator = 151,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 152,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 153,      /* VariableInitializer  */
  YYSYMBOL_LocalVariableDeclarationStatement = 154, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_Statement = 155,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 156,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 157, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_IfThenStatement = 158,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 159,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 160, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_EmptyStatement = 161,           /* EmptyStatement  */
  YYSYMBOL_ExpressionStatement = 162,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 163,      /* StatementExpression  */
  YYSYMBOL_WhileStatement = 164,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 165,  /* WhileStatementNoShortIf  */
  YYSYMBOL_ForStatement = 166,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 167,    /* ForStatementNoShortIf  */
  YYSYMBOL_BasicForStatement = 168,        /* BasicForStatement  */
  YYSYMBOL_Expression_s = 169,             /* Expression_s  */
  YYSYMBOL_ForInit_s = 170,                /* ForInit_s  */
  YYSYMBOL_ForUpdate_s = 171,              /* ForUpdate_s  */
  YYSYMBOL_BasicForStatementNoShortIf = 172, /* BasicForStatementNoShortIf  */
  YYSYMBOL_ForInit = 173,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 174,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 175,  /* StatementExpressionList  */
  YYSYMBOL_BreakStatement = 176,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 177,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 178,          /* ReturnStatement  */
  YYSYMBOL_ArrayInitializer = 179,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializerList_s = 180, /* VariableInitializerList_s  */
  YYSYMBOL_comma_s = 181,                  /* comma_s  */
  YYSYMBOL_VariableInitializerList = 182,  /* VariableInitializerList  */
  YYSYMBOL_TypeName = 183,                 /* TypeName  */
  YYSYMBOL_ExpressionName = 184,           /* ExpressionName  */
  YYSYMBOL_MethodName = 185,               /* MethodName  */
  YYSYMBOL_AmbiguousName = 186,            /* AmbiguousName  */
  YYSYMBOL_Primary = 187,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 188,        /* PrimaryNoNewArray  */
  YYSYMBOL_Literal = 189,                  /* Literal  */
  YYSYMBOL_ClassLiteral = 190,             /* ClassLiteral  */
  YYSYMBOL_ClassInstanceCreationExpression = 191, /* ClassInstanceCreationExpression  */
  YYSYMBOL_UnqualifiedClassInstanceCreationExpression = 192, /* UnqualifiedClassInstanceCreationExpression  */
  YYSYMBOL_ArgumentList_s = 193,           /* ArgumentList_s  */
  YYSYMBOL_ClassBody_s = 194,              /* ClassBody_s  */
  YYSYMBOL_FieldAccess = 195,              /* FieldAccess  */
  YYSYMBOL_ArrayAccess = 196,              /* ArrayAccess  */
  YYSYMBOL_MethodInvocation = 197,         /* MethodInvocation  */
  YYSYMBOL_MethodReference = 198,          /* MethodReference  */
  YYSYMBOL_ArrayCreationExpression = 199,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 200,                 /* DimExprs  */
  YYSYMBOL_DimExprs_b = 201,               /* DimExprs_b  */
  YYSYMBOL_DimExpr = 202,                  /* DimExpr  */
  YYSYMBOL_Expression = 203,               /* Expression  */
  YYSYMBOL_AssignmentExpression = 204,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 205,               /* Assignment  */
  YYSYMBOL_AssignmentOperator = 206,       /* AssignmentOperator  */
  YYSYMBOL_LeftHandSide = 207,             /* LeftHandSide  */
  YYSYMBOL_ConditionalExpression = 208,    /* ConditionalExpression  */
  YYSYMBOL_ConditionalOrExpression = 209,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 210, /* ConditionalAndExpression  */
  YYSYMBOL_InclusiveOrExpression = 211,    /* InclusiveOrExpression  */
  YYSYMBOL_ExclusiveOrExpression = 212,    /* ExclusiveOrExpression  */
  YYSYMBOL_AndExpression = 213,            /* AndExpression  */
  YYSYMBOL_EqualityExpression = 214,       /* EqualityExpression  */
  YYSYMBOL_RelationalExpression = 215,     /* RelationalExpression  */
  YYSYMBOL_InstanceofExpression = 216,     /* InstanceofExpression  */
  YYSYMBOL_Pattern = 217,                  /* Pattern  */
  YYSYMBOL_TypePattern = 218,              /* TypePattern  */
  YYSYMBOL_ShiftExpression = 219,          /* ShiftExpression  */
  YYSYMBOL_AdditiveExpression = 220,       /* AdditiveExpression  */
  YYSYMBOL_MultiplicativeExpression = 221, /* MultiplicativeExpression  */
  YYSYMBOL_UnaryExpression = 222,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 223,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 224,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 225, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_PostfixExpression = 226,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 227,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 228   /* PostDecrementExpression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   1515

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  152
/* YYNRULES -- Number of rules.  */
#define YYNRULES  336
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  542

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    74,    67,     2,
      59,    60,    72,    70,    61,    71,    53,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    58,
      68,    62,    69,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    65,    57,    75,     2,     2,     2,
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
       0,    89,    89,    91,    92,    93,    94,    95,    98,    99,
     102,   103,   107,   108,   111,   112,   113,   116,   117,   120,
     121,   125,   128,   131,   132,   133,   136,   137,   138,   139,
     148,   149,   150,   153,   156,   157,   160,   161,   162,   163,
     166,   167,   168,   169,   172,   173,   176,   177,   180,   181,
     182,   185,   186,   189,   190,   193,   194,   195,   198,   199,
     200,   203,   206,   207,   210,   213,   214,   215,   218,   219,
     222,   223,   226,   227,   228,   231,   232,   235,   236,   239,
     242,   243,   245,   246,   249,   252,   253,   256,   257,   260,
     263,   264,   267,   268,   271,   272,   275,   276,   279,   282,
     285,   286,   289,   290,   293,   294,   296,   299,   302,   303,
     306,   307,   310,   311,   314,   317,   320,   323,   324,   327,
     328,   329,   330,   333,   334,   337,   340,   341,   344,   345,
     355,   356,   358,   359,   361,   362,   363,   366,   369,   372,
     373,   375,   376,   378,   381,   382,   385,   386,   389,   390,
     392,   393,   395,   396,   399,   401,   402,   403,   404,   405,
     407,   408,   409,   410,   413,   414,   415,   416,   417,   418,
     421,   424,   427,   430,   432,   434,   435,   436,   437,   438,
     439,   440,   443,   445,   448,   450,   453,   455,   455,   456,
     456,   457,   457,   459,   461,   462,   464,   466,   467,   469,
     470,   472,   473,   475,   476,   479,   480,   480,   481,   481,
     483,   484,   487,   488,   489,   491,   493,   494,   510,   511,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     526,   527,   528,   529,   530,   531,   532,   535,   536,   537,
     538,   541,   542,   543,   546,   549,   550,   553,   554,   557,
     558,   559,   562,   563,   566,   567,   568,   569,   570,   571,
     574,   575,   576,   577,   578,   579,   580,   583,   584,   585,
     586,   589,   592,   593,   594,   597,   600,   603,   604,   607,
     610,   611,   614,   615,   616,   619,   620,   623,   624,   627,
     628,   631,   632,   635,   636,   639,   640,   643,   644,   645,
     648,   649,   650,   651,   652,   653,   656,   657,   660,   663,
     666,   667,   668,   669,   672,   673,   674,   677,   678,   679,
     680,   683,   684,   685,   686,   687,   690,   693,   696,   697,
     698,   701,   702,   703,   704,   707,   710
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INCREMENT",
  "DECREMENT", "DOUBLE_COLON", "LOG_OR", "LOG_AND", "EQUAL", "NOT_EQUAL",
  "GTR_EQUAL", "LESS_EQUAL", "LEFT_SHIFT", "RIGHT_SHIFT", "SIGN_SHIFT",
  "ASSIGN_OP", "TRIPLE_DOT", "Identifier", "INT", "FLOAT", "CHAR",
  "STRING", "BOOL", "TEXTBLOCK", "TypeIdentifier", "KEY_STATIC",
  "KEY_RETURN", "KEY_NEW", "KEY_THIS", "KEY_SUPER", "KEY_THROWS",
  "KEY_INSTANCEOF", "KEY_INT", "KEY_BYTE", "KEY_SHORT", "KEY_FLOAT",
  "KEY_LONG", "KEY_DOUBLE", "KEY_BOOL", "KEY_CHAR", "KEY_VOID", "KEY_VAR",
  "KEY_FOR", "KEY_WHILE", "KEY_IF", "KEY_ELSE", "KEY_FINAL", "KEY_PRIVATE",
  "KEY_PUBLIC", "KEY_CLASS", "KEY_NULL", "KEY_BREAK", "KEY_CONTINUE",
  "'.'", "'['", "']'", "'{'", "'}'", "';'", "'('", "')'", "','", "'='",
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'~'", "'!'", "$accept", "START", "IntegralType",
  "FloatingPointType", "NumericType", "PrimitiveType", "ReferenceType",
  "ClassOrInterfaceType", "ClassType", "InterfaceType", "TypeVariable",
  "ArrayType", "Dims", "ClassModifier", "ClassBody",
  "ClassBodyDeclaration_c", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "FieldModifier_c",
  "FieldModifier", "UnannType", "UnannPrimitiveType", "UnannReferenceType",
  "UnannClassOrInterfaceType", "UnannClassType", "UnannInterfaceType",
  "UnannTypeVariable", "UnannArrayType", "MethodDeclaration",
  "MethodModifier_c", "MethodModifier", "MethodHeader", "Result",
  "MethodDeclarator", "Dims_b", "ReceiverParameter_b", "ReceiverParameter",
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
  "comma_s", "VariableInitializerList", "TypeName", "ExpressionName",
  "MethodName", "AmbiguousName", "Primary", "PrimaryNoNewArray", "Literal",
  "ClassLiteral", "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ArgumentList_s",
  "ClassBody_s", "FieldAccess", "ArrayAccess", "MethodInvocation",
  "MethodReference", "ArrayCreationExpression", "DimExprs", "DimExprs_b",
  "DimExpr", "Expression", "AssignmentExpression", "Assignment",
  "AssignmentOperator", "LeftHandSide", "ConditionalExpression",
  "ConditionalOrExpression", "ConditionalAndExpression",
  "InclusiveOrExpression", "ExclusiveOrExpression", "AndExpression",
  "EqualityExpression", "RelationalExpression", "InstanceofExpression",
  "Pattern", "TypePattern", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PreIncrementExpression",
  "PreDecrementExpression", "UnaryExpressionNotPlusMinus",
  "PostfixExpression", "PostIncrementExpression",
  "PostDecrementExpression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-446)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-335)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,  -446,  -446,  -446,    50,   104,  -446,  -446,  -446,   169,
      10,  -446,    96,  -446,   296,  -446,    10,    53,   123,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   119,   164,
     665,  -446,  -446,  -446,  -446,   269,  -446,  -446,  -446,   218,
    -446,   113,    83,  -446,   111,  -446,  -446,   137,  -446,  -446,
    1467,  -446,   255,   128,  -446,  -446,  -446,   197,  -446,   121,
     101,  -446,  -446,  -446,  -446,  1116,  1116,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,   156,  1026,   199,  -446,    40,    69,
     124,  -446,   155,   161,   171,  -446,    48,    52,  -446,  -446,
    1116,    71,    83,   191,   173,   236,  -446,    83,   264,  -446,
    -446,  1176,  -446,  -446,  -446,   219,   113,  -446,  -446,  -446,
    -446,  -446,  -446,  -446,   223,  -446,  -446,  -446,  -446,  -446,
    -446,   194,   876,   241,   266,    56,  1116,  -446,  -446,    68,
    -446,  -446,  -446,   231,  -446,  -446,  -446,    22,  -446,  -446,
     282,   311,   335,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
     113,    83,    88,  -446,   261,   291,  -446,   329,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,   255,  -446,  -446,  -446,   298,
     121,  -446,  -446,  -446,  -446,   121,   344,   313,  -446,   348,
    -446,   287,  1116,  1116,  1116,  1116,   287,   876,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,  -446,   282,  -446,  -446,  -446,
    -446,   315,  -446,  -446,  -446,    42,   369,   312,   322,   325,
     340,    31,  -446,   196,   280,     8,  -446,  -446,  -446,  1116,
    -446,   921,   798,  -446,   362,   380,   345,   350,  1362,  1116,
    1116,   342,  -446,   349,  -446,   343,   353,  -446,   385,   384,
    -446,   386,  -446,   391,  -446,  -446,  -446,   358,  -446,   211,
     370,   407,    32,  -446,  -446,  1116,   408,   409,    94,  -446,
    -446,  -446,  1116,  -446,  -446,    97,  -446,  -446,   113,  1071,
     375,  -446,  -446,   348,  -446,   313,  -446,   378,   379,  -446,
    -446,  -446,  1439,  -446,   416,   826,   373,  -446,  -446,  -446,
    -446,  -446,  1116,  1116,  1116,  1116,  1116,  1116,  1116,  1116,
    1116,  1116,   607,  1116,  1116,  1116,  1116,  1116,  1116,  1116,
    1116,  1116,  1116,  -446,   377,  -446,   382,  -446,    83,  1116,
     382,    83,  -446,   381,   390,  -446,  -446,  -446,   383,  -446,
     387,   389,   392,  -446,  -446,  -446,   393,  -446,  -446,  -446,
    -446,   397,  -446,    63,   395,  -446,   398,   399,  -446,   400,
    -446,  -446,   404,  -446,  -446,  -446,  -446,  1071,  -446,  -446,
    -446,   413,   826,  -446,   403,   410,    30,  1226,  -446,   981,
      65,   406,   417,   348,   339,   411,  -446,  -446,  -446,  -446,
     369,   414,   312,   322,   325,   340,    31,    31,   196,   196,
    -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,   196,   196,
     280,   280,   280,     8,     8,  -446,  -446,  -446,    10,   424,
    -446,  -446,  1116,  -446,  -446,  -446,  1116,  -446,  1116,  1405,
    1276,  1319,  -446,  1116,   433,   455,  -446,  1116,  -446,  1116,
    -446,   429,   436,   448,   453,   344,  1116,  1116,   461,  1226,
     246,   247,  -446,  -446,   504,   507,  -446,  -446,   469,  1116,
    -446,  -446,  1116,  -446,   474,   477,  -446,  -446,   482,   483,
     484,  -446,   499,   500,  -446,  -446,  -446,  -446,   489,  -446,
     497,   498,   501,  -446,   491,  1071,   508,    83,  -446,   502,
    -446,   505,  -446,   509,   510,   547,  -446,   826,  -446,  -446,
    -446,  1405,  1362,  1116,  1116,  1276,  -446,  1116,  -446,  -446,
    -446,  -446,  -446,  -446,  -446,   514,   515,  1116,  1116,  -446,
    -446,   506,  -446,   387,   519,   522,   524,  -446,   527,  -446,
    -446,   528,   529,  1276,  1116,  1319,  1319,  -446,   532,   535,
    -446,   536,  -446,   553,  -446,  -446,  1405,  1319,   539,  -446,
    1319,  -446
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    32,    31,    30,     0,     0,   142,     2,   138,     0,
       0,     1,     0,   141,     0,   140,     0,    64,    50,     3,
       4,     5,     8,     6,     9,    54,     7,    78,    49,    48,
       0,    43,    10,    11,    53,     0,    35,    36,    40,     0,
      47,     0,    26,    52,    26,    58,    59,    26,    56,    41,
       0,    71,     0,     0,    37,    39,    38,     0,   111,    97,
       0,   107,    42,   139,   106,     0,     0,   213,   230,   231,
     233,   234,   232,   235,    19,     0,     0,   222,     0,    13,
       0,   145,     0,     0,     0,   236,     0,     0,   131,   173,
       0,    12,    26,     0,    14,    17,    18,    16,     0,   144,
     164,     0,   133,   134,   137,     0,     0,   135,   136,   155,
     156,   157,   165,   166,     0,   158,   159,   184,   167,   168,
     169,     0,   188,     0,     0,   331,   188,   220,   221,   225,
     241,   226,   227,   228,   229,   219,   175,     0,   176,   177,
       0,   178,   179,    33,    34,    64,    50,    49,    48,    46,
       0,    26,     0,   147,   149,     0,    65,     0,    66,    67,
      74,    73,    72,    77,    70,     0,   105,    69,   104,     0,
      76,   115,   113,   112,   110,    97,     0,     0,    96,    83,
      19,    13,     0,     0,     0,     0,    12,   188,   225,   226,
     227,   228,   326,   321,   322,   325,   328,   333,   334,   327,
     204,     0,   276,   278,   277,   285,   287,   289,   291,   293,
     295,   297,   305,   300,   310,   314,   317,    19,    13,   245,
      12,   188,   188,    17,     0,     0,     0,     0,   190,     0,
       0,     0,   200,     0,   202,     0,     0,    23,     0,     0,
      24,     0,    25,     0,   130,   132,   154,   143,   174,     0,
       0,     0,     0,   252,   187,   245,     0,     0,     0,   253,
     280,   281,     0,   335,   336,     0,   151,    45,     0,     0,
      27,    61,    68,    83,    75,     0,    19,     0,   102,   103,
      98,   101,   118,   109,    86,    88,     0,   323,   324,   329,
     330,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,   127,     0,   275,    26,   188,
       0,    26,   263,   250,     0,   240,   195,   198,     0,   189,
     194,     0,     0,   199,   201,   224,     0,   262,    20,   265,
     266,     0,   223,     0,     0,   260,     0,     0,   242,     0,
     214,   261,   249,   243,   279,    44,   146,   207,   148,   153,
     152,     0,    88,   108,    99,   222,     0,   129,   117,     0,
       0,     0,     0,     0,     0,     0,    87,    91,    93,    82,
     288,     0,   290,   292,   294,   296,   298,   299,   303,   304,
      19,    13,    12,   306,    15,   309,   307,   308,   301,   302,
     311,   312,   313,   315,   316,   318,   319,   320,   247,   125,
     269,   267,   188,   273,   270,   268,   245,   239,   188,     0,
       0,     0,   238,   245,     0,     0,   237,   245,   254,   245,
     211,   209,   206,    28,     0,     0,   124,   124,     0,   128,
       0,     0,    85,    84,     0,     0,    92,   114,    89,     0,
     248,   244,     0,   274,     0,     0,   197,   182,     0,     0,
       0,   170,     0,   155,   161,   162,   163,   185,     0,   264,
     251,     0,     0,   208,     0,     0,     0,    26,   100,     0,
     123,     0,   116,     0,     0,     0,    94,     0,   286,   126,
     258,   192,   190,     0,     0,     0,   255,   245,   256,   257,
     205,   210,    29,    81,    79,     0,     0,   124,   124,    95,
      90,     0,   191,   196,     0,     0,     0,   171,     0,   119,
     120,     0,     0,     0,   188,     0,     0,   259,     0,     0,
     186,     0,   183,     0,   122,   121,   192,     0,     0,   172,
       0,   193
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -446,  -446,  -446,  -446,    -3,   525,   265,   -69,   -73,  -446,
    -164,   300,   -34,   594,   -15,  -446,   569,  -446,  -446,  -446,
     566,     5,  -446,  -446,  -446,  -446,  -446,  -446,  -446,  -446,
    -446,   556,   558,  -446,  -446,  -446,   338,  -446,  -446,   250,
    -446,  -446,   126,  -446,   -98,  -446,  -446,  -446,   179,   450,
    -446,  -446,  -446,  -446,   559,   560,  -446,   347,  -446,  -446,
    -413,  -406,  -446,  -446,     4,   251,   -92,  -446,   127,  -446,
    -446,  -224,  -446,   -54,   351,   249,  -328,  -446,  -387,  -345,
    -383,  -446,  -446,  -446,  -446,  -446,  -212,  -446,  -446,  -446,
    -446,  -446,  -120,   138,    93,  -446,  -446,  -446,  -445,  -446,
    -446,  -446,  -201,  -446,  -446,  -446,  -446,   355,  -446,  -446,
     352,  -446,  -446,  -446,   -30,  -235,  -230,  -446,   443,   488,
     -25,  -446,  -446,   435,  -446,  -299,   -47,  -446,    -9,  -446,
    -446,   183,  -446,   341,   401,   415,   422,   423,    62,  -446,
    -446,  -446,  -250,   -10,    66,   -51,    -4,    34,  -446,    55,
      60,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,    32,    33,   186,    92,    93,    94,    95,    96,
      97,    98,   226,     6,    15,    35,    36,    37,    38,    39,
      40,    99,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   170,   504,   285,   286,   372,   375,
     376,   448,   377,   378,   177,   178,   280,   364,   281,   167,
      54,    55,    56,    57,    58,    59,    60,   283,   367,   368,
     479,   313,   409,   438,   100,   101,   102,   103,   104,     8,
       9,   105,   106,   152,   153,   154,   358,   107,   108,   462,
     109,   110,   111,   464,   112,   113,   114,   115,   465,   116,
     466,   117,   317,   328,   511,   467,   329,   512,   330,   118,
     119,   120,   359,   431,   474,   432,   121,   122,   123,   124,
     125,   126,   127,   128,   188,   130,   314,   451,   131,   132,
     191,   134,   135,   318,   412,   319,   315,   202,   203,   262,
     137,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     396,   397,   213,   214,   215,   216,   193,   194,   195,   196,
     197,   198
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     129,    63,   253,   223,   326,   133,   259,   222,   156,   245,
     158,    34,   279,   159,   192,   199,   327,   348,    61,    41,
     413,   136,    64,   353,   481,   349,   138,    91,   201,   430,
     480,   480,    34,   457,   461,   224,    34,   260,   463,    61,
      41,   300,   301,   235,   150,   224,   513,    34,   292,   346,
     388,   389,   247,   398,   399,   163,   168,   236,   237,   347,
     240,   257,   302,   242,   139,   231,    14,   253,   424,   233,
     257,   129,   274,   220,    10,   254,   133,   275,   395,   254,
     310,   311,   312,   225,   261,   140,   -54,   250,   -53,   437,
     141,   513,   136,   225,   521,   522,   265,   138,    91,   303,
     304,   480,   480,   278,    11,   293,   232,   277,   517,   258,
     234,   352,  -115,   453,   142,   410,   425,   266,   441,   414,
      16,   347,   -26,   155,   -26,   155,  -181,     7,  -181,  -181,
     151,   287,   288,   289,   290,   139,   530,   155,   457,   461,
     254,    62,   463,   463,   -31,   169,   267,   501,   -32,   268,
     517,   176,   236,   530,   463,   355,   140,   463,   268,   -73,
     179,   141,    62,   -74,   157,   155,   -31,   -31,   -31,   168,
     -32,   -32,   -32,   -64,   254,   254,    34,   227,     1,    30,
     532,   533,   331,   332,   284,   142,   454,   316,   320,   -30,
     -60,   155,   539,   468,     1,   541,   238,   471,   129,   472,
       2,     3,     4,   133,   -72,   348,   353,   456,   305,   306,
     307,   -30,   -30,   -30,   228,   354,     2,     3,    12,   136,
     229,   171,   360,   217,   138,    91,   239,   155,   341,   223,
     230,    19,    20,    21,    22,    23,    24,   218,    26,   342,
     343,   241,   145,   146,   172,   173,   381,   249,   155,   253,
      19,    20,    21,    22,    23,    24,    25,    26,   219,   405,
     406,   407,   139,   346,   352,   147,   148,   518,   326,   243,
      34,   279,   254,   347,   347,   483,   484,   246,   284,   327,
     327,   248,    34,   140,   411,   263,   264,   415,   141,  -180,
     374,  -180,  -180,    17,    18,   400,   401,   402,   455,   392,
     255,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     360,    30,   142,   166,  -333,  -333,    28,    29,     4,   256,
      17,    18,   254,   269,   327,    30,   143,    31,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   129,  -334,  -334,
     -26,   155,   133,    28,    29,     4,   270,   245,   298,   299,
     308,   309,    30,   271,    31,   445,   151,   273,   136,    34,
     386,   387,   278,   138,    91,   254,   277,   374,   276,   282,
      34,   254,   145,   291,   403,   404,   294,   295,   444,   322,
      19,    20,    21,    22,    23,    24,    25,    26,   296,   129,
     129,   129,   297,   450,   133,   133,   133,   323,   324,   325,
     333,   139,   337,   335,   531,   489,   336,   334,   338,   129,
     136,   136,   136,   339,   133,   138,   138,   138,   340,   268,
     187,   187,   140,   344,   345,   350,   351,   141,   360,   361,
     136,   239,   -17,   371,   379,   138,    91,   408,   357,   417,
     416,   418,   422,   503,   426,   443,   515,   516,   419,   420,
     469,   142,   421,   139,   139,   139,   423,   427,   219,   442,
     428,   129,   129,   429,   435,   129,   133,   133,   433,   436,
     133,   447,   470,   139,   140,   140,   140,   254,   449,   141,
     141,   141,   136,   136,    34,   452,   136,   138,   138,    91,
     473,   138,   374,   129,   140,   129,   129,   475,   133,   141,
     133,   133,   476,   142,   142,   142,   129,   129,   189,   189,
     129,   133,   133,   477,   136,   133,   136,   136,   482,   138,
     485,   138,   138,   142,   486,   139,   139,   136,   136,   139,
     487,   136,   138,   138,   490,   491,   138,   187,   187,   187,
     187,   492,   493,   494,   495,  -160,   140,   140,   500,   496,
     140,   141,   141,   190,   190,   141,   497,   139,   498,   139,
     139,   499,   505,   502,   509,   506,   523,   393,   507,   508,
     139,   139,   519,   520,   139,   142,   142,   524,   140,   142,
     140,   140,   525,   141,   526,   141,   141,   527,   528,   529,
     534,   140,   140,   535,   536,   140,   141,   141,   537,   540,
     141,   221,   394,    13,   144,   149,   164,   142,   165,   142,
     142,   362,   434,   510,   478,   272,   174,   175,   439,   356,
     142,   142,   363,   446,   142,   189,   189,   189,   189,   538,
     514,   390,   488,   380,   370,     0,     0,   369,     0,    19,
      20,    21,    22,    23,    24,   391,    26,   187,    81,   187,
     187,   187,   187,   187,   187,   187,   187,   321,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,    65,    66,
     190,   190,   190,   190,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,    72,    73,    74,
       1,    75,    76,    77,    78,   382,     0,    19,    20,    21,
      22,    23,    24,    79,    26,    80,    81,    82,    83,    84,
     383,     0,     2,     3,     4,    85,    86,    87,   384,     0,
     385,    30,    88,    89,    90,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,   189,   189,   189,
     189,   189,   189,   189,   189,     0,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,   190,   190,   190,   190,   190,   190,   190,   190,
       0,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,    65,    66,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    73,   180,     0,     0,    76,    77,    78,     0,     0,
      19,    20,    21,    22,    23,    24,   181,    26,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
     145,   239,   155,     0,   -26,     0,     0,    90,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,   182,   183,
       0,     0,   373,   184,   185,     0,     0,     0,     0,    65,
      66,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,    67,    68,    69,    70,    71,    72,    73,
     180,     0,     0,    76,    77,    78,     0,     0,    19,    20,
      21,    22,    23,    24,   181,    26,    80,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    85,     0,     0,   252,
       0,     0,     0,     0,     0,    90,     0,   190,    67,    68,
      69,    70,    71,    72,    73,   180,   182,   183,    76,    77,
      78,   184,   185,    19,    20,    21,    22,    23,    24,   181,
      26,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,   155,     0,   -26,     0,     0,
      90,     0,     0,     0,    65,    66,   251,     0,     0,     0,
       0,   182,   183,     0,     0,     0,   184,   185,    67,    68,
      69,    70,    71,    72,    73,   180,     0,     0,    76,    77,
      78,     0,     0,    19,    20,    21,    22,    23,    24,   181,
      26,    80,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    85,     0,     0,   440,     0,     0,     0,     0,     0,
      90,     0,     0,    67,    68,    69,    70,    71,    72,    73,
     180,   182,   183,    76,    77,    78,   184,   185,    19,    20,
      21,    22,    23,    24,   181,    26,    80,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    85,     0,     0,     0,
       0,     0,     0,     0,   200,    90,     0,     0,    67,    68,
      69,    70,    71,    72,    73,   180,   182,   183,    76,    77,
      78,   184,   185,    19,    20,    21,    22,    23,    24,   181,
      26,    80,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    85,     0,     0,     0,     0,     0,   357,     0,     0,
      90,     0,     0,    67,    68,    69,    70,    71,    72,    73,
     180,   182,   183,    76,    77,    78,   184,   185,    19,    20,
      21,    22,    23,    24,   181,    26,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,   182,   183,     0,     0,
       0,   184,   185,    67,    68,    69,    70,    71,    72,    73,
      74,     1,    75,    76,    77,    78,     0,     0,    19,    20,
      21,    22,    23,    24,    79,    26,    80,    81,    82,    83,
      84,     0,     0,     2,     3,     4,    85,    86,    87,    65,
      66,     0,    30,   244,    89,    90,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     1,    75,    76,    77,    78,     0,     0,    19,    20,
      21,    22,    23,    24,    79,    26,    80,    81,    82,    83,
      84,     0,     0,     2,     3,     4,    85,    86,    87,    65,
      66,     0,    30,     0,    89,    90,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,    72,    73,
     180,     0,    75,    76,    77,    78,     0,     0,    19,    20,
      21,    22,    23,    24,   181,    26,    80,     0,    82,    83,
      84,     0,    65,    66,     0,     0,    85,    86,    87,     0,
       0,     0,    30,     0,    89,    90,    67,    68,    69,    70,
      71,    72,    73,   180,     0,    75,    76,    77,    78,     0,
       0,    19,    20,    21,    22,    23,    24,   181,    26,    80,
       0,   458,   459,   460,     0,    65,    66,     0,     0,    85,
      86,    87,     0,     0,     0,    30,     0,    89,    90,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    76,
      77,    78,     0,     0,    19,    20,    21,    22,    23,    24,
      79,    26,    80,    81,     0,     0,     0,     0,    65,    66,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    67,    68,    69,    70,    71,    72,    73,   180,
       0,     0,    76,    77,    78,     0,     0,    19,    20,    21,
      22,    23,    24,   181,    26,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    67,    68,    69,    70,
      71,    72,    73,   180,    90,     0,    76,   365,   366,     0,
       0,    19,    20,    21,    22,    23,    24,   181,    26,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,   145,   160,     0,     0,     0,     0,     0,    90,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,   161,   162
};

static const yytype_int16 yycheck[] =
{
      30,    16,   122,    76,   228,    30,   126,    76,    42,   101,
      44,    14,   176,    47,    65,    66,   228,   252,    14,    14,
     319,    30,    18,   258,   437,   255,    30,    30,    75,   357,
     436,   437,    35,   420,   421,     5,    39,    15,   421,    35,
      35,    10,    11,    90,    39,     5,   491,    50,     6,    17,
     300,   301,   106,   303,   304,    50,    52,    91,    92,    27,
      94,     5,    31,    97,    30,    17,    56,   187,     5,    17,
       5,   101,   170,    76,    24,   122,   101,   175,   302,   126,
      72,    73,    74,    53,    62,    30,    17,   121,    17,    59,
      30,   536,   101,    53,   507,   508,   150,   101,   101,    68,
      69,   507,   508,   176,     0,    63,    58,   176,   495,    53,
      58,    17,    59,   412,    30,   316,    53,   151,    53,   320,
      24,    27,    53,    54,    53,    54,    58,     0,    60,    61,
      17,   182,   183,   184,   185,   101,   523,    54,   525,   526,
     187,    14,   525,   526,    25,    17,    58,   475,    25,    61,
     537,    30,   186,   540,   537,    58,   101,   540,    61,    40,
      59,   101,    35,    40,    53,    54,    47,    48,    49,   165,
      47,    48,    49,    17,   221,   222,   179,    53,    25,    56,
     525,   526,   229,   230,   179,   101,   416,   221,   222,    25,
      53,    54,   537,   423,    25,   540,     5,   427,   228,   429,
      47,    48,    49,   228,    40,   440,   441,   419,    12,    13,
      14,    47,    48,    49,    59,   262,    47,    48,    49,   228,
      59,    24,   269,    24,   228,   228,    53,    54,    17,   302,
      59,    32,    33,    34,    35,    36,    37,    38,    39,    28,
      29,     5,    24,    25,    47,    48,   293,    53,    54,   369,
      32,    33,    34,    35,    36,    37,    38,    39,    59,   310,
     311,   312,   228,    17,    17,    47,    48,   497,   492,     5,
     273,   435,   319,    27,    27,    29,    29,    58,   273,   491,
     492,    58,   285,   228,   318,     3,     4,   321,   228,    58,
     285,    60,    61,    24,    25,   305,   306,   307,   418,   302,
      59,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     357,    56,   228,    58,     3,     4,    47,    48,    49,    53,
      24,    25,   369,    62,   536,    56,    57,    58,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   367,     3,     4,
      53,    54,   367,    47,    48,    49,    55,   439,     8,     9,
      70,    71,    56,    24,    58,    16,    17,    59,   367,   362,
     298,   299,   435,   367,   367,   412,   435,   362,    24,    56,
     373,   418,    24,    58,   308,   309,     7,    65,   373,    17,
      32,    33,    34,    35,    36,    37,    38,    39,    66,   419,
     420,   421,    67,   408,   419,   420,   421,    17,    53,    49,
      58,   367,    17,    60,   524,   452,    53,    58,    24,   439,
     419,   420,   421,    27,   439,   419,   420,   421,    27,    61,
      65,    66,   367,    53,    17,    17,    17,   367,   475,    54,
     439,    53,    53,    17,    61,   439,   439,    60,    56,    49,
      59,    58,    49,   477,    49,    28,   493,   494,    61,    60,
      17,   367,    60,   419,   420,   421,    59,    59,    59,    53,
      60,   491,   492,    59,    61,   495,   491,   492,    55,    59,
     495,    60,    17,   439,   419,   420,   421,   524,    64,   419,
     420,   421,   491,   492,   487,    61,   495,   491,   492,   492,
      61,   495,   487,   523,   439,   525,   526,    61,   523,   439,
     525,   526,    54,   419,   420,   421,   536,   537,    65,    66,
     540,   536,   537,    60,   523,   540,   525,   526,    57,   523,
      16,   525,   526,   439,    17,   491,   492,   536,   537,   495,
      61,   540,   536,   537,    60,    58,   540,   182,   183,   184,
     185,    59,    59,    59,    45,    45,   491,   492,    57,    60,
     495,   491,   492,    65,    66,   495,    59,   523,    60,   525,
     526,    60,    60,    55,    17,    60,    60,   302,    59,    59,
     536,   537,    58,    58,   540,   491,   492,    58,   523,   495,
     525,   526,    60,   523,    60,   525,   526,    60,    60,    60,
      58,   536,   537,    58,    58,   540,   536,   537,    45,    60,
     540,    76,   302,     9,    35,    39,    50,   523,    50,   525,
     526,   273,   362,   487,   435,   165,    57,    57,   367,   268,
     536,   537,   275,   374,   540,   182,   183,   184,   185,   536,
     492,    24,   449,   292,   282,    -1,    -1,   282,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,   292,    41,   294,
     295,   296,   297,   298,   299,   300,   301,   222,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,     3,     4,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,   294,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
     295,    -1,    47,    48,    49,    50,    51,    52,   296,    -1,
     297,    56,    57,    58,    59,   282,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,    -1,   294,   295,   296,
     297,   298,   299,   300,   301,    -1,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292,    -1,   294,   295,   296,   297,   298,   299,   300,   301,
      -1,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,     3,     4,    -1,   449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      24,    53,    54,    -1,    56,    -1,    -1,    59,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    70,    71,
      -1,    -1,    46,    75,    76,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    50,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    -1,   449,    17,    18,
      19,    20,    21,    22,    23,    24,    70,    71,    27,    28,
      29,    75,    76,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,    -1,
      59,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    75,    76,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    70,    71,    27,    28,    29,    75,    76,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    70,    71,    27,    28,
      29,    75,    76,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    70,    71,    27,    28,    29,    75,    76,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      -1,    75,    76,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,     3,
       4,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,     3,
       4,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    -1,     3,     4,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    56,    -1,    58,    59,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    -1,     3,     4,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    58,    59,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    17,    18,    19,    20,
      21,    22,    23,    24,    59,    -1,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    59,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    47,    48,    49,    78,    90,   145,   146,   147,
      24,     0,    49,    90,    56,    91,    24,    24,    25,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    47,    48,
      56,    58,    79,    80,    81,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   127,   128,   129,   130,   131,   132,
     133,   141,   145,    91,   141,     3,     4,    17,    18,    19,
      20,    21,    22,    23,    24,    26,    27,    28,    29,    38,
      40,    41,    42,    43,    44,    50,    51,    52,    57,    58,
      59,    81,    82,    83,    84,    85,    86,    87,    88,    98,
     141,   142,   143,   144,   145,   148,   149,   154,   155,   157,
     158,   159,   161,   162,   163,   164,   166,   168,   176,   177,
     178,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   195,   196,   197,   198,   199,   205,   207,   223,   224,
     226,   227,   228,    57,    93,    24,    25,    47,    48,    97,
      98,    17,   150,   151,   152,    54,    89,    53,    89,    89,
      25,    47,    48,    98,   108,   109,    58,   126,   141,    17,
     111,    24,    47,    48,   131,   132,    30,   121,   122,    59,
      24,    38,    70,    71,    75,    76,    81,   184,   191,   195,
     196,   197,   222,   223,   224,   225,   226,   227,   228,   222,
      58,   203,   204,   205,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   219,   220,   221,   222,    24,    38,    59,
      81,    82,    84,    85,     5,    53,    89,    53,    59,    59,
      59,    17,    58,    17,    58,   203,    89,    89,     5,    53,
      89,     5,    89,     5,    57,   143,    58,   150,    58,    53,
      89,     5,    53,   169,   203,    59,    53,     5,    53,   169,
      15,    62,   206,     3,     4,   150,    89,    58,    61,    62,
      55,    24,   126,    59,   121,   121,    24,    84,    85,    87,
     123,   125,    56,   134,    98,   113,   114,   222,   222,   222,
     222,    58,     6,    63,     7,    65,    66,    67,     8,     9,
      10,    11,    31,    68,    69,    12,    13,    14,    70,    71,
      72,    73,    74,   138,   193,   203,    89,   169,   200,   202,
      89,   200,    17,    17,    53,    49,   148,   163,   170,   173,
     175,   203,   203,    58,    58,    60,    53,    17,    24,    27,
      27,    17,    28,    29,    53,    17,    17,    27,   192,   193,
      17,    17,    17,   192,   203,    58,   151,    56,   153,   179,
     203,    54,   113,   134,   124,    28,    29,   135,   136,   184,
     187,    17,   115,    46,    98,   116,   117,   119,   120,    61,
     210,   203,   211,   212,   213,   214,   215,   215,   219,   219,
      24,    38,    81,    83,    88,   148,   217,   218,   219,   219,
     220,   220,   220,   221,   221,   222,   222,   222,    60,   139,
     179,    89,   201,   202,   179,    89,    59,    49,    58,    61,
      60,    60,    49,    59,     5,    53,    49,    59,    60,    59,
     153,   180,   182,    55,   116,    61,    59,    59,   140,   142,
      53,    53,    53,    28,    98,    16,   152,    60,   118,    64,
      91,   194,    61,   202,   193,   169,   163,   155,    42,    43,
      44,   155,   156,   157,   160,   165,   167,   172,   193,    17,
      17,   193,   193,    61,   181,    61,    54,    60,   125,   137,
     138,   137,    57,    29,    29,    16,    17,    61,   208,   203,
      60,    58,    59,    59,    59,    45,    60,    59,    60,    60,
      57,   153,    55,    89,   112,    60,    60,    59,    59,    17,
     119,   171,   174,   175,   170,   203,   203,   155,   193,    58,
      58,   137,   137,    60,    58,    60,    60,    60,    60,    60,
     155,   169,   156,   156,    58,    58,    58,    45,   171,   156,
      60,   156
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   100,   101,   101,
     101,   102,   103,   103,   104,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   109,   109,   110,   110,   111,
     112,   112,   113,   113,   114,   115,   115,   116,   116,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   123,
     124,   124,   125,   125,   126,   126,   127,   128,   129,   129,
     130,   130,   131,   131,   132,   133,   134,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   143,   144,   145,   146,
     146,   147,   147,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   155,   155,   155,   155,   155,
     156,   156,   156,   156,   157,   157,   157,   157,   157,   157,
     158,   159,   160,   161,   162,   163,   163,   163,   163,   163,
     163,   163,   164,   165,   166,   167,   168,   169,   169,   170,
     170,   171,   171,   172,   173,   173,   174,   175,   175,   176,
     176,   177,   177,   178,   178,   179,   180,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   186,   186,   187,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   190,   190,   190,
     190,   191,   191,   191,   192,   193,   193,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   197,   197,   197,   197,
     198,   198,   198,   198,   198,   198,   198,   199,   199,   199,
     199,   200,   201,   201,   201,   202,   203,   204,   204,   205,
     206,   206,   207,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   212,   213,   213,   214,   214,   214,
     215,   215,   215,   215,   215,   215,   216,   216,   217,   218,
     219,   219,   219,   219,   220,   220,   220,   221,   221,   221,
     221,   222,   222,   222,   222,   222,   223,   224,   225,   225,
     225,   226,   226,   226,   226,   227,   228
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     2,     2,     2,     0,     2,     4,     6,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     2,     2,     3,     2,
       2,     1,     1,     1,     1,     3,     2,     1,     1,     6,
       0,     1,     2,     0,     3,     2,     0,     1,     0,     2,
       3,     0,     2,     1,     3,     4,     1,     0,     2,     2,
       3,     0,     1,     1,     1,     1,     2,     1,     4,     3,
       2,     1,     1,     1,     5,     1,     4,     1,     0,     5,
       5,     7,     7,     1,     0,     2,     3,     0,     1,     0,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     2,     1,     2,     1,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     7,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     1,     1,     9,     1,     0,     1,
       0,     1,     0,     9,     1,     1,     1,     3,     1,     3,
       2,     3,     2,     3,     2,     4,     1,     0,     1,     0,
       3,     1,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       3,     1,     3,     3,     5,     0,     1,     0,     1,     3,
       3,     5,     2,     2,     4,     6,     6,     6,     6,     8,
       3,     3,     3,     3,     5,     3,     3,     4,     4,     4,
       4,     2,     0,     1,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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

#line 2030 "parse_oracle.tab.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 724 "parse_oracle.yy"

