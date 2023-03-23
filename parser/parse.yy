%{

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


%}

%union{
    int num;
    char chr;
    char* str;
}

/* %token<chr> UNR_OP              // unary operator (+,-,~) */
/* %token<chr> BIN_OP              // BInary operators */
/* %token<str> KEY_NEW */

%token<str> ID
%token<str> INT
%token<str> FLOAT
%token<str> DOUBLE
%token<str> CHAR
%token<str> STRING
%token<str> BOOL
%token<str> LONG


%token<str> KEY_INT
%token<str> KEY_FLOAT
%token<str> KEY_LONG
%token<str> KEY_DOUBLE
%token<str> KEY_BOOL
%token<str> KEY_CHAR
%token<str> KEY_STRING
%token<str> KEY_VOID
%token<str> KEY_NEW

%token<str> KEY_FOR
%token<str> KEY_WHILE
%token<str> KEY_IF
%token<str> KEY_ELSE

%token<str> KEY_CONTINUE
%token<str> KEY_BREAK
%token<str> KEY_RETURN
%token<str> KEY_ASSERT
%token<str> KEY_YIELD
%token<str> KEY_SUPER
%token<str> KEY_IMPORT

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_STATIC
%token<str> KEY_CLASS

/* %token<str> KEY_CONST */
/* %token<str> KEY_NULL */


%token<chr> ASSIGN_OP           // Assignment operators except '='
%token<str> INCREMENT           // ++
%token<str> DECREMENT           // --
%token<str> LOG_OR              // ||
%token<str> LOG_AND             // &&
%token<str> EQUAL               // ==
%token<str> NOT_EQUAL           // ==
%token<str> GTR_EQUAL           // <=
%token<str> LESS_EQUAL          // >=
%token<str> LEFT_SHIFT          // <<
%token<str> RIGHT_SHIFT         // >>
%token<str> SIGN_SHIFT          // >>>
/* %token<str> DOUBLE_COLON        // :: */
/* %token<str> TRIPLE_DOT          // ... */

/* %right UNR_OP
%right ASSIGN_OP
%right '='
%left BIN_OP
%left '?'
%left ':'
%left INC_DEC
%right KEY_ELSE */

%%
/* START: ClassDeclaration; */
START: ImportDecl_list ClassDeclaration_list
|       ClassDeclaration_list
;

ClassDeclaration_list:  ClassDeclaration_list ClassDeclaration
|                       ClassDeclaration
;

ImportDecl_list:    ImportDecl_list ImportDecl
|                   ImportDecl
;

ImportDecl:     KEY_IMPORT STAT Imp_list ';'
|               KEY_IMPORT STAT Imp_list '.' '*' ';' 
;

Imp_list:   Imp_list '.' ID
|           ID
;

BODY:   BODY STMNT
|       STMNT
;

BLCK:   '{' BODY '}'
|       '{' '}'
;

STMNT_without_sub:  BLCK 
|                   Expr ';'
|                   DEF_VAR ';'
|                   KEY_RETURN EMP_EXPR ';'
|                   KEY_CONTINUE ';'
|                   KEY_BREAK ';'
|                   KEY_YIELD Expr ';'
|                   Assert_stmnt
|                   ';'
;

Assert_stmnt:   KEY_ASSERT Expr ';'
|               KEY_ASSERT Expr ':' Expr ';'
;

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

WHILE_STMNT: KEY_WHILE '(' Expr ')' STMNT
;
WHILE_STMNT_noshortif: KEY_WHILE '(' Expr ')' STMNT_noshortif
;
BASIC_FOR:  KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT
;
BASIC_FOR_noshortif:    KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT_noshortif
;

FOR_UPDATE: STMNT_EXPR_list 
| %empty
;

FOR_INIT:   DEF_VAR
|           STMNT_EXPR_list
|           %empty
;

STMNT_EXPR_list:    STMNT_EXPR_list ',' STMNT_EXPR
|                   STMNT_EXPR
;

IF_THEN:    KEY_IF '(' Expr ')' STMNT
;
IF_THEN_ELSE:   KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT
;
IF_THEN_ELSE_noshortif: KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT_noshortif
;


DEF_VAR: STAT DTYPE VAR_LIST
;

VAR_LIST:   VAR_LIST ',' VAR
|           VAR_LIST ',' VARA
|           VAR
|           VARA
;

VARA:   ID '=' Expr
|       ID '[' EMP_EXPR ']' '=' L1D
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' L2D
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' L3D
;

VAR:    ID
|       ID '[' EMP_EXPR ']'
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']'
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']'
;

L3D:    '{' CONT3D '}' 
;
CONT3D: CONT3D ',' L2D
|       L2D
;

L2D:    '{' CONT2D '}' 
;
CONT2D: CONT2D ',' L1D
|       L1D
;

L1D: '{' CONT1D '}' 
;
CONT1D: CONT1D ',' Expr
|       Expr
;

STMNT_EXPR: Assignment
|           PreIncrementExpression
|           PreDecrementExpression
|           PostDecrementExpression
|           PostIncrementExpression
|           Meth_invoc
;

Meth_invoc: ExpressionName '(' ARG_LIST ')'
;

Expr: AssignmentExpression
;

AssignmentExpression: ConditionalExpression
|                     Assignment
;

Assignment: LeftHandSide AssignmentOperator Expr
;

AssignmentOperator: ASSIGN_OP
|                  '='
;

ExpressionName:  AmbiguousName '.' ID
|                ID
;
AmbiguousName:  ID
|               AmbiguousName '.' ID
;

LeftHandSide:   ExpressionName
|               FieldAccess
|               ArrayAccess
/* |               VAR */
;

ConditionalExpression:  ConditionalOrExpression
|                       ConditionalOrExpression '?' Expr ':' ConditionalExpression
;

ConditionalOrExpression:    ConditionalAndExpression
|                           ConditionalOrExpression LOG_OR ConditionalAndExpression
;

ConditionalAndExpression:   InclusiveOrExpression
|                           ConditionalAndExpression LOG_AND InclusiveOrExpression
;

InclusiveOrExpression:      ExclusiveOrExpression
|                           InclusiveOrExpression '|' ExclusiveOrExpression
;

ExclusiveOrExpression:      AndExpression
|                           ExclusiveOrExpression '^' AndExpression
;

AndExpression:              EqualityExpression
|                           AndExpression '&' EqualityExpression
;

EqualityExpression:         RelationalExpression
|                           EqualityExpression EQUAL RelationalExpression
|                           EqualityExpression NOT_EQUAL RelationalExpression
;

RelationalExpression:       ShiftExpression
|                           RelationalExpression '<' ShiftExpression
|                           RelationalExpression '>' ShiftExpression
|                           RelationalExpression GTR_EQUAL ShiftExpression
|                           RelationalExpression LESS_EQUAL ShiftExpression
;

ShiftExpression:            AdditiveExpression
|                           ShiftExpression LEFT_SHIFT AdditiveExpression
|                           ShiftExpression RIGHT_SHIFT AdditiveExpression
|                           ShiftExpression SIGN_SHIFT AdditiveExpression
;

AdditiveExpression:         MultiplicativeExpression
|                           AdditiveExpression '+' MultiplicativeExpression
|                           AdditiveExpression '-' MultiplicativeExpression
;

MultiplicativeExpression:   UnaryExpression
|                           MultiplicativeExpression '*' UnaryExpression
|                           MultiplicativeExpression '/' UnaryExpression
|                           MultiplicativeExpression '%' UnaryExpression
;

UnaryExpression:            PreIncrementExpression
|                           PreDecrementExpression
|                           '+' UnaryExpression
|                           '-' UnaryExpression
|                           UnaryExpressionNotPlusMinus
;

PreIncrementExpression:     INCREMENT UnaryExpression
;

PreDecrementExpression:     DECREMENT UnaryExpression
;

UnaryExpressionNotPlusMinus:    PostfixExpression
|                               '~' UnaryExpression
|                               '!' UnaryExpression
;

PostfixExpression:              Primary
|                               ExpressionName
|                               PostIncrementExpression
|                               PostDecrementExpression
;

FieldAccess:    Primary '.' ID
|               KEY_SUPER '.' ID
;


Primary:    PrimaryNoNewArray
|           ArrayCreationExpr
/* |           VAR */
;

PrimaryNoNewArray:  LIT
|                   '(' Expr ')'
|                   ArrayAccess
|                   Meth_invoc
|                   FieldAccess
|                   KEY_NEW ID '(' ARG_LIST ')' Class_body
|                   KEY_NEW ID '(' ARG_LIST ')'
;

ArrayCreationExpr:  KEY_NEW DTYPE DimExpr
|                   KEY_NEW ID DimExpr
;

DimExpr:    '[' Expr ']'
|           DimExpr '[' Expr ']'
;

ArrayAccess:    ExpressionName '[' Expr ']'
|               PrimaryNoNewArray '[' Expr ']'
;

PostIncrementExpression:        PostfixExpression INCREMENT
;

PostDecrementExpression:        PostfixExpression DECREMENT
;



EMP_EXPR:   Expr | %empty
;

ARG_LIST: ARG_LISTp | %empty
;

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


ClassDeclaration: MOD_EMPTY_LIST KEY_CLASS ID Class_body 
;

Class_body: '{' Class_body_dec_list '}'
|               '{' '}'
;

Class_body_dec_list :   Class_body_dec_list Class_body_dec
|                       Class_body_dec
;

Class_body_dec:     Class_DEF_VAR
|                   MethodDeclaration
|                   ClassDeclaration
|                   STAT BLCK
|                   ConstructorDeclaration
;

Class_DEF_VAR:  MOD_EMPTY_LIST DTYPE VAR_LIST ';'
;
MethodDeclaration: MOD_EMPTY_LIST Meth_Head Meth_Body
;

Meth_Body:   BLCK
|           ';'
;

DIMS_list: DIMS_list '[' ']'
|     '[' ']'
;

DIMS: DIMS_list
;

Meth_Head:  DTYPE DIMS Meth_decl
|           KEY_VOID DIMS Meth_decl
|           DTYPE Meth_decl
|           KEY_VOID Meth_decl
;

Meth_decl:  ID '(' Param_list ')'
|           ID '(' ')'
;

Param_list: Param_list ',' Param
|           Param
;

Param:  DTYPE VAR
;

MOD_EMPTY_LIST: MOD_LIST
|               %empty
;

MOD_LIST:   MOD_LIST MOD
|           MOD
;

MOD :   KEY_PRIVATE
|       KEY_PUBLIC
|       KEY_STATIC
;

ConstructorDeclaration: MOD_EMPTY_LIST ID '(' Param_list ')' BLCK
|                       MOD_EMPTY_LIST ID '(' ')' BLCK
;

%%


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