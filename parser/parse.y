%{

    #include<iostream>
    using namespace std;   
%}

%union{
    int num;
    char chr;
    char* str;
}

%token<chr> UNR_OP              // unary operator (+,-,~)
%token<chr> BIN_OP              // BInary operators
%token<chr> ASSIGN_OP           // Assignment operators except '='
%token<str> INC_DEC             // ++, --
%token<str> ID
%token<str> INT
%token<str> FLOAT
%token<str> DOUBLE
%token<str> CHAR
%token<str> STRING
%token<str> BOOL
%token<str> LONG

%token<str> KEY_STATIC
%token<str> KEY_RETURN
%token<str> KEY_NEW

%token<str> KEY_INT
%token<str> KEY_FLOAT
%token<str> KEY_LONG
%token<str> KEY_DOUBLE
%token<str> KEY_BOOL
%token<str> KEY_CHAR
%token<str> KEY_STRING
%token<str> KEY_VOID

%token<str> KEY_FOR
%token<str> KEY_WHILE
%token<str> KEY_IF
%token<str> KEY_ELSE

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_CLASS

%token<str> KEY_CONST
%token<str> KEY_NULL




%right UNR_OP
%right ASSIGN_OP
%right '='
%left BIN_OP
%left '?'
%left ':'
%left INC_DEC
%right KEY_ELSE

%%


STMNT:  STMNT_without_sub
|       IF_THEN
|       IF_THEN_ELSE
|       WHILE_STMNT
|       BASIC_FOR
;
STMNT_noshortif:    STMNT_without_sub
|                   IF_THEN_ELSE_noshortif
|                   WHILE_STMNT_noshortif
|                   BASIC_FOR_noshortif
;

WHILE_STMNT: KEY_WHILE '(' Expr ')' STMNT;
WHILE_STMNT_noshortif: KEY_WHILE '(' Expr ')' STMNT_noshortif

BASIC_FOR:  KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT
BASIC_FOR_noshortif:    KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT_noshortif

FOR_UPDATE: STMNT_EXPR_list | %empty;

FOR_INIT:   DEF_VAR
|           STMNT_EXPR_list
|           %empty
;
STMNT_EXPR_list:    STMNT_EXPR_list ',' STMNT_EXPR
|                   STMNT_EXPR


IF_THEN:    KEY_IF '(' Expr ')' STMNT;
IF_THEN_ELSE:   KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT;
IF_THEN_ELSE_noshortif: KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT_noshortif;



BODY:   BODY STMNT
|       STMNT
;

BLCK:   '{' BODY '}'
|       '{' '}'

STMNT_without_sub:  BLCK 
|                   Expr ';'
|                   DEF_VAR ';'
|                   KEY_RETURN Expr ';'
|                   ';'

DEF_VAR: STAT DTYPE VAR_LIST


VAR_LIST:   VAR_LIST ',' VAR
|           VAR_LIST ',' VARA
|           VAR
|           VARA
;

VARA:   ID '=' Expr
|       ID '[' Expr ']' '=' L1D
|       ID '[' Expr ']' '[' Expr ']' '=' L2D
|       ID '[' Expr ']' '[' Expr ']' '[' Expr ']' '=' L3D
;

VAR:    ID
|       ID '[' Expr ']'
|       ID '[' Expr ']' '[' Expr ']'
|       ID '[' Expr ']' '[' Expr ']' '[' Expr ']'
;

L3D:    '{' CONT3D '}' ;
CONT3D: CONT3D ',' L2D
|       L2D
;

L2D:    '{' CONT2D '}' ;
CONT2D: CONT2D ',' L1D
|       L1D
;

L1D: '{' CONT1D '}' ;
CONT1D: CONT1D ',' Expr
|       Expr
;

STMNT_EXPR: ID ASSIGN_OP Expr
|           ID '=' Expr
|           ID INC_DEC
|           INC_DEC ID  
|           ID '(' ARG_LIST ')'

Expr:   Expr BIN_OP Expr
|       '(' Expr ')'
|       UNR_OP Expr
|       Expr '?' Expr ':' Expr
|       STMNT_EXPR
|       LIT
|       ID
;

EMP_EXPR:   Expr | %empty

ARG_LIST: ARG_LISTp | %empty;

ARG_LISTp:   ARG_LISTp ',' Expr
|           Expr
;

LIT:    INT
|       FLOAT
|       CHAR
|       STRING
|       BOOL
|       LONG
|       DOUBLE
;


STAT:   KEY_STATIC
|       %empty
;


DTYPE:  KEY_INT
|       KEY_BOOL
|       KEY_DOUBLE
|       KEY_FLOAT
|       KEY_LONG
|       KEY_CHAR
|       KEY_STRING
;


%%
/* CONST:  KEY_CONST
|       %empty
;
NULL:   KEY_NULL;
NEW:    KEY_NEW;
FTYPE:  KEY_VOID
|       DTYPE
;

MOD :   KEY_PRIVATE
|       KEY_PUBLIC
;

IN_LIST:    IN_LIST ',' D 
|           D
|           %empty
;

D:      DTYPE VAR;

FUNC:  MOD STAT FTYPE ID '(' IN_LIST ')' BLCKFUNC;

BLCKFUNC:   '{' BODY '}'
|           '{' '}'
|           ';'
;

CLASSBODY:  CLASSBODY FUNC
|           CLASSBODY DEF_VAR
|           FUNC
|           DEF_VAR
|           %empty
;

CLASS:  MOD STAT KEY_CLASS ID '{' CLASSBODY '}'; */
