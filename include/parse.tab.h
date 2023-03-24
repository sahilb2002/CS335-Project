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


#line 117 "include/parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSE_TAB_H_INCLUDED  */
