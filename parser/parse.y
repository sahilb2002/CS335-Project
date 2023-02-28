%{

    #include<iostream>
    #include<fstream>
    #include"AST.h"
    using namespace std;

    
    extern int yylex();
    extern int yyparse();
    extern int yylineno;
    extern FILE* yyin;
    FILE* dotfile;

    void yyerror(const char *s) {
        cout << "[Line no: " << yylineno << "] " << "error: " << "parse error: " << s << endl;
        exit(-1);
    }


%}

%union{
    char *str;
    treeNode* ptr;

}

%start START
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


%token<str> ASSIGN_OP           // Assignment operators except '='
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
%type<ptr> START ImportDecl_list ClassDeclaration_list ClassDeclaration AmbiguousName ImportDecl PrimaryNoNewArray BODY BLCK STMNT_without_sub  Assert_stmnt STMNT STMNT_noshortif WHILE_STMNT WHILE_STMNT_noshortif BASIC_FOR BASIC_FOR_noshortif FOR_UPDATE FOR_INIT STMNT_EXPR_list IF_THEN IF_THEN_ELSE IF_THEN_ELSE_noshortif DEF_VAR VAR_LIST VARA VAR STMNT_EXPR Meth_invoc Expr AssignmentExpression Assignment LeftHandSide ConditionalAndExpression ConditionalOrExpression ConditionalExpression InclusiveOrExpression ExclusiveOrExpression AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression PreIncrementExpression PreDecrementExpression UnaryExpressionNotPlusMinus PostfixExpression FieldAccess Primary ArrayCreationExpr DimExpr ArrayAccess PostDecrementExpression PostIncrementExpression EMP_EXPR ARG_LIST ARG_LISTp LIT STAT DTYPE Class_body Class_body_dec_list Class_body_dec Class_DEF_VAR MethodDeclaration Meth_Body DIMS_list Meth_Head DIMS Meth_decl Param_list Param MOD_EMPTY_LIST MOD_LIST MOD ConstructorDeclaration ExpressionName 


%%
START: ImportDecl_list ClassDeclaration_list{
    vector<data> v;
    insertAttr(v, $1, "ImportList", 1);
    insertAttr(v, $2, "ClassList", 1);
    $$ = makenode("Program", v);
}
|       ClassDeclaration_list{
    vector<data> v;
    insertAttr(v, $1, "ClassList", 1);
    $$ = makenode("Program", v);
}
;

ClassDeclaration_list:  ClassDeclaration_list ClassDeclaration{
    vector<data> v;
    insertAttr(v, $1, "ClassList", 1);
    insertAttr(v, $2, "Class", 1);
    $$ = makenode("Classes", v);
}
|                       ClassDeclaration{
    vector<data> v;
    insertAttr(v, $1, "Class", 1);
    $$ = makenode("ClassList", v);
}
;

ImportDecl_list:    ImportDecl_list ImportDecl{
    vector<data> v;
    insertAttr(v, $1, "ImportList", 1);
    insertAttr(v, makeleaf("Imported package"), "", 1);
    $$ = makenode("ImportList", v);
}
|                   ImportDecl{
    vector<data> v;
    insertAttr(v, makeleaf("IMported package"), "", 1);
    $$ = makenode("ImportList", v);
}
;

ImportDecl:     KEY_IMPORT STAT Imp_list ';' {$$ = NULL;}
|               KEY_IMPORT STAT Imp_list '.' '*' ';' {$$ = NULL;}

;

Imp_list:   Imp_list '.' ID 
|           ID
;

BODY:   BODY STMNT{
    vector<data> v;
    insertAttr(v, $1, "Body", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Body", v);
}
|       STMNT{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("Body", v);
}
;

BLCK:   '{' BODY '}'{
    vector<data> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);
}
|       '{' '}'{
    vector<data> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);
}
;

STMNT_without_sub:  BLCK{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_without_sub", v);
} 
|                   Expr ';'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   DEF_VAR ';'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   KEY_RETURN EMP_EXPR ';'{
    vector<data> v;
    insertAttr(v, makeleaf("return"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   KEY_CONTINUE ';'{
    vector<data> v;
    insertAttr(v, makeleaf("continue"), "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   KEY_BREAK ';'{
    vector<data> v;
    insertAttr(v, makeleaf("break"), "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   KEY_YIELD Expr ';'{
    vector<data> v;
    insertAttr(v, makeleaf("yield"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   Assert_stmnt{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   ';' {$$ = NULL;}
;

Assert_stmnt:   KEY_ASSERT Expr ';' {
    vector<data> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Assert_stmnt", v);
}
|               KEY_ASSERT Expr ':' Expr ';'{
    vector<data> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("Assert_stmnt", v);
}
;

STMNT:  STMNT_without_sub{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT", v);
}
|       IF_THEN{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT", v);
}
|       IF_THEN_ELSE{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT", v);
}
|       WHILE_STMNT{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT", v);
}
|       BASIC_FOR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT", v);
}
;

STMNT_noshortif:    STMNT_without_sub{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_noshortif", v);
}
|                   IF_THEN_ELSE_noshortif{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_noshortif", v);
}
|                   WHILE_STMNT_noshortif{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_noshortif", v);
}
|                   BASIC_FOR_noshortif{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_noshortif", v);
}
;

WHILE_STMNT: KEY_WHILE '(' Expr ')' STMNT{
    vector<data> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("WHILE_STMNT", v);
}
;
WHILE_STMNT_noshortif: KEY_WHILE '(' Expr ')' STMNT_noshortif{
    vector<data> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("WHILE_STMNT_noshortif", v);
}
;
BASIC_FOR:  KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT{
    vector<data> v;
    insertAttr(v, makeleaf("FOR"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, $7, "", 1);
    insertAttr(v, $9, "", 1);
    $$ = makenode("BASIC_FOR", v);
}
;
BASIC_FOR_noshortif:    KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT_noshortif{
    vector<data> v;
    insertAttr(v, makeleaf("FOR"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, $7, "", 1);
    insertAttr(v, $9, "", 1);
    $$ = makenode("BASIC_FOR_noshortif", v);
}
;

FOR_UPDATE: STMNT_EXPR_list {
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_UPDATE", v);
}
| %empty{
    $$ = NULL;
}
;

FOR_INIT:   DEF_VAR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_INIT", v);
}
|           STMNT_EXPR_list{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_INIT", v);
}
|           %empty{
    $$ = NULL;
}
;

STMNT_EXPR_list:    STMNT_EXPR_list ',' STMNT_EXPR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("STMNT_EXPR_list", v);
}
|                   STMNT_EXPR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_EXPR_list", v);
}
;

IF_THEN:    KEY_IF '(' Expr ')' STMNT{
    vector<data> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("IF_THEN", v);
}
;
IF_THEN_ELSE:   KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT{
    vector<data> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $7, "", 1);
    $$ = makenode("IF_THEN_ELSE", v);
}
;
IF_THEN_ELSE_noshortif: KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT_noshortif{
    vector<data> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $7, "", 1);
    $$ = makenode("IF_THEN_ELSE_noshortif", v);
}
;


DEF_VAR: STAT DTYPE VAR_LIST{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("DEF_VAR", v);
}
;

VAR_LIST:   VAR_LIST ',' VAR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);
}
|           VAR_LIST ',' VARA{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);
}
|           VAR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("VAR_LIST", v);
}
|           VARA{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("VAR_LIST", v);
}
;

VARA:   ID '=' Expr{
    vector<data> v;
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '=' L1D{
    vector<data> v;
    insertAttr(v, makeleaf("ID[EMP_EXPR]"), "", 1);
    insertAttr(v, makeleaf("1D Array Initializer"), "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' L2D{
    vector<data> v;
    insertAttr(v, makeleaf("ID[EMP_EXPR][EMP_EXPR]"), "", 1);
    insertAttr(v, makeleaf("2D Array Initializer"), "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' L3D{
    vector<data> v;
    insertAttr(v, makeleaf("ID[EMP_EXPR][EMP_EXPR][EMP_EXPR]"), "", 1);
    insertAttr(v, makeleaf("3D Array Initializer"), "", 1);
    $$ = makenode("=", v);
}
;

VAR:    ID{
    $$ = makeleaf("ID");
}
|       ID '[' EMP_EXPR ']'{
    $$ = makeleaf("ID[EMP_EXPR]");
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']'{
    $$ = makeleaf("ID[EMP_EXPR][EMP_EXPR]");
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']'{
    $$ = makeleaf("ID[EMP_EXPR][EMP_EXPR][EMP_EXPR]");
}
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

STMNT_EXPR: Assignment{
    $$ = $1;
}
|           PreIncrementExpression{$$ = $1;}
|           PreDecrementExpression{$$ = $1;}
|           PostDecrementExpression{$$ = $1;}
|           PostIncrementExpression{$$ = $1;}
|           Meth_invoc{$$ = $1;}
;

Meth_invoc: ExpressionName '(' ARG_LIST ')'{
    vector<data> v;
    insertAttr(v, makeleaf("ExpressionName"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("Meth_invoc", v);
}
;

Expr: AssignmentExpression{$$ = $1;}
;

AssignmentExpression: ConditionalExpression{$$ = $1;}
|                     Assignment{$$ = $1;}
;

Assignment: LeftHandSide AssignmentOperator Expr{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("AssignmentOperator", v);
}
;

AssignmentOperator: ASSIGN_OP
|                  '='
;

ExpressionName:  AmbiguousName '.' ID
|                ID {$$ = NULL;}
;
AmbiguousName:  ID  {$$ = NULL;}
|               AmbiguousName '.' ID
;

LeftHandSide:   ExpressionName{$$ = $1;}
|               FieldAccess{$$ = $1;}
|               ArrayAccess{$$ = $1;}
/* |               VAR */
;

ConditionalExpression:  ConditionalOrExpression{$$ = $1;}
|                       ConditionalOrExpression '?' Expr ':' ConditionalExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("?:", v);
}
;

ConditionalOrExpression:    ConditionalAndExpression{$$ = $1;}
|                           ConditionalOrExpression LOG_OR ConditionalAndExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("||", v);
}
;

ConditionalAndExpression:   InclusiveOrExpression{$$ = $1;}
|                           ConditionalAndExpression LOG_AND InclusiveOrExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&&", v);
}
;

InclusiveOrExpression:      ExclusiveOrExpression{$$ = $1;}
|                           InclusiveOrExpression '|' ExclusiveOrExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("|", v);
}
;

ExclusiveOrExpression:      AndExpression{$$ = $1;}
|                           ExclusiveOrExpression '^' AndExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("^", v);}
;

AndExpression:              EqualityExpression{$$ = $1;}
|                           AndExpression '&' EqualityExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&", v);
}
;

EqualityExpression:         RelationalExpression{$$ = $1;}
|                           EqualityExpression EQUAL RelationalExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("==", v);}
|                           EqualityExpression NOT_EQUAL RelationalExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("!=", v);
}
;

RelationalExpression:       ShiftExpression{$$ = $1;}
|                           RelationalExpression '<' ShiftExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<", v);
}
|                           RelationalExpression '>' ShiftExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">", v);
}
|                           RelationalExpression GTR_EQUAL ShiftExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">=", v);
}
|                           RelationalExpression LESS_EQUAL ShiftExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<=", v);
}
;

ShiftExpression:            AdditiveExpression{$$ = $1;}
|                           ShiftExpression LEFT_SHIFT AdditiveExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<<", v);
}
|                           ShiftExpression RIGHT_SHIFT AdditiveExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>", v);
}
|                           ShiftExpression SIGN_SHIFT AdditiveExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>>", v);
}
;

AdditiveExpression:         MultiplicativeExpression{$$ = $1;}
|                           AdditiveExpression '+' MultiplicativeExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("+", v);
}
|                           AdditiveExpression '-' MultiplicativeExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("-", v);
}
;

MultiplicativeExpression:   UnaryExpression{$$ = $1;}
|                           MultiplicativeExpression '*' UnaryExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("*", v);
}
|                           MultiplicativeExpression '/' UnaryExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("/", v);
}
|                           MultiplicativeExpression '%' UnaryExpression{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("%", v);
}
;

UnaryExpression:            PreIncrementExpression{$$ = $1;}
|                           PreDecrementExpression{$$ = $1;}
|                           '+' UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("+", v);
}
|                           '-' UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("-", v);
}
|                           UnaryExpressionNotPlusMinus{$$ = $1;}
;

PreIncrementExpression:     INCREMENT UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("++", v);
}
;

PreDecrementExpression:     DECREMENT UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("--", v);
}
;

UnaryExpressionNotPlusMinus:    PostfixExpression{
    $$ = $1;
}
|                               '~' UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("~", v);
}
|                               '!' UnaryExpression{
    vector<data> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("!", v);
}
;

PostfixExpression:              Primary{
    $$ = $1;
}
|                               ExpressionName{
    $$ = $1;
}
|                               PostIncrementExpression{
    $$ = $1;
}
|                               PostDecrementExpression{
    $$ = $1;
}
;

FieldAccess:    Primary '.' ID{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    $$ = makenode("FieldAccess", v);
}
|               KEY_SUPER '.' ID{
    vector<data> v;
    insertAttr(v, makeleaf("super"), "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    $$ = makenode("FieldAccess", v);
}
;


Primary:    PrimaryNoNewArray{
    $$ = $1;
}
|           ArrayCreationExpr{
    $$ = $1;
}
/* |           VAR */
;

PrimaryNoNewArray:  LIT{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("PrimaryNoNewArray", v);
}
|                   '(' Expr ')'{
    vector<data> v;
    insertAttr(v, makeleaf("("), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf(")"), "", 1);
    $$ = makenode("PrimaryNoNewArray", v);
}
|                   ArrayAccess{$$ = $1;}
|                   Meth_invoc{$$ = $1;}
|                   FieldAccess{$$ = $1;}
|                   KEY_NEW ID '(' ARG_LIST ')' Class_body{
    vector<data> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, makeleaf(")"), "", 0);
    insertAttr(v, $6, "", 1);
    $$ = makenode("PrimaryNoNewArray", v);
}
|                   KEY_NEW ID '(' ARG_LIST ')'{
    vector<data> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, makeleaf(")"), "", 0);
    $$ = makenode("PrimaryNoNewArray", v);
}
;

ArrayCreationExpr:  KEY_NEW DTYPE DimExpr{
    vector<data> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);
}
|                   KEY_NEW ID DimExpr{
    vector<data> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);
}
;

DimExpr:    '[' Expr ']'{
    vector<data> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);
}
|           DimExpr '[' Expr ']'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);
}
;

ArrayAccess:    ExpressionName '[' Expr ']'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);
}
|               PrimaryNoNewArray '[' Expr ']'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);
}
;

PostIncrementExpression:        PostfixExpression INCREMENT{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("++", v);
}
;

PostDecrementExpression:        PostfixExpression DECREMENT {
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("--", v);
}
;



EMP_EXPR:   Expr{$$ = $1;}
| %empty{$$ = NULL;}
;

ARG_LIST: ARG_LISTp {$$ = $1;}
| %empty{
    $$ = NULL;
}
;

ARG_LISTp:   ARG_LISTp ',' Expr{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Argument List", v);
}
|           Expr{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("Argument List", v);
}
;

LIT:    INT{
    $$ = makeleaf("int");
}
|       FLOAT{
    $$ = makeleaf("float");
}
|       CHAR{
    $$ = makeleaf("char");
}
|       STRING{
    $$ = makeleaf("string");
}
|       BOOL{
    $$ = makeleaf("bool");}
|       LONG{
    $$ = makeleaf("long");
}
|       DOUBLE{
    $$ = makeleaf("double");
}
;


STAT:   KEY_STATIC{
    $$ = makeleaf("static");
}
|       %empty{
    $$ = NULL;
}
;


DTYPE:  KEY_INT{
    $$ = makeleaf("int");
}
|       KEY_BOOL{
    $$ = makeleaf("bool");
}
|       KEY_DOUBLE{
    $$ = makeleaf("double");
}
|       KEY_FLOAT{
    $$ = makeleaf("float");
}
|       KEY_LONG{
    $$ = makeleaf("long");
}
|       KEY_CHAR{
    $$ = makeleaf("char");
}
|       KEY_STRING{
    $$ = makeleaf("string");
}
;


ClassDeclaration: MOD_EMPTY_LIST KEY_CLASS ID Class_body {
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("class"), "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("ClassDeclaration", v);
}
;

Class_body: '{' Class_body_dec_list '}'{
    vector<data> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    $$ = makenode("ClassBody", v);
}
|               '{' '}'{
    vector<data> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    $$ = makenode("ClassBody", v);
}
;

Class_body_dec_list :   Class_body_dec_list Class_body_dec{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("ClassBody Declaration", v);
}
|                       Class_body_dec{$$ = $1;}
;

Class_body_dec:     Class_DEF_VAR{$$ = $1;}
|                   MethodDeclaration{$$ = $1;}
|                   ClassDeclaration{$$ = $1;}
|                   STAT BLCK{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("ClassBody Declaration", v);
}
|                   ConstructorDeclaration{$$ = $1;}
;

Class_DEF_VAR:  MOD_EMPTY_LIST DTYPE VAR_LIST ';'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ClassVariableDeclaration", v);
}
;
MethodDeclaration: MOD_EMPTY_LIST Meth_Head Meth_Body{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("MethodDeclaration", v);
}
;

Meth_Body:   BLCK{$$ = $1;}
|           ';'{
    $$ = NULL;
}
;

DIMS_list: DIMS_list '[' ']'{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensions", v);
}
|     '[' ']'{
    vector<data> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensions", v);
}
;

DIMS: DIMS_list{$$ = $1;}
;

Meth_Head:  DTYPE DIMS Meth_decl{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Method Header", v);
}
|           KEY_VOID DIMS Meth_decl{
    vector<data> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Method Header", v);
}
|           DTYPE Meth_decl{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Method Header", v);
}
|           KEY_VOID Meth_decl{
    vector<data> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Method Header", v);
}
;

Meth_decl:  ID '(' Param_list ')'{
    vector<data> v;
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf(")"), "", 1);
    $$ = makenode("Method Declaration", v);
}
|           ID '(' ')'{
    vector<data> v;
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 1);
    insertAttr(v, makeleaf(")"), "", 1);
    $$ = makenode("Method Declaration", v);
}
;

Param_list: Param_list ',' Param{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("parameter list", v);
}
|           Param
;

Param:  DTYPE VAR{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("parameter", v);
}
;

MOD_EMPTY_LIST: MOD_LIST{$$ = $1;}
|               %empty{
    $$ = NULL;
}
;

MOD_LIST:   MOD_LIST MOD{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("modifier list", v);
}
|           MOD{$$ = $1;}
;

MOD :   KEY_PRIVATE{
    vector<data> v;
    insertAttr(v, makeleaf("private"), "", 1);
    $$ = makenode("modifier", v);
}
|       KEY_PUBLIC{
    vector<data> v;
    insertAttr(v, makeleaf("public"), "", 1);
    $$ = makenode("modifier", v);
}
|       KEY_STATIC{
    vector<data> v;
    insertAttr(v, makeleaf("static"), "", 1);
    $$ = makenode("modifier", v);
}
;

ConstructorDeclaration : MOD_EMPTY_LIST ID '(' Param_list ')' BLCK{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 1);
    insertAttr(v, $4, "", 1);
    insertAttr(v, makeleaf(")"), "", 1);
    insertAttr(v, $6, "", 1);
    $$ = makenode("construtor", v);
}
|                       MOD_EMPTY_LIST ID '(' ')' BLCK{
    vector<data> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID"), "", 1);
    insertAttr(v, makeleaf("("), "", 1);
    insertAttr(v, makeleaf(")"), "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("construtor", v);
}
;

%%


int main(int argc, char** argv) {

    FILE *myfile = fopen("test.java", "r");
    if (!myfile) {
        cout <<"ERROR: "  << "Could not open file: "<< argv[1] << endl;
        return -1;
    }
    yyin = myfile;
    dotfile = fopen("AST.dot", "w");
    beginAST();
    do {
        yyparse();
    } while (!feof(yyin));
    endAST();
  
}