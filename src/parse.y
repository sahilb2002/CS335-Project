%{

    #include<iostream>
    #include<fstream>
    #include <AST.h>
    #include<cstring>
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
    string *str;
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
%token<str> KEY_THROW
%token<str> KEY_CASE
%token<str> KEY_DEFAULT
%token<str> KEY_SWITCH
%token<str> KEY_DO

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_STATIC
%token<str> KEY_PROTECTED
%token<str> KEY_CLASS



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
%token<str> ARROW               // ->


%type<str> Imp_list AmbiguousName ExpressionName AssignmentOperator 
%type<ptr> START ImportDecl_list ClassDeclaration_list CastExpression ClassDeclaration ImportDecl BLCK_STMNT
%type<ptr> PrimaryNoNewArray BODY BLCK STMNT_without_sub  Assert_stmnt STMNT STMNT_noshortif ConstructorDeclaration
%type<ptr> WHILE_STMNT WHILE_STMNT_noshortif BASIC_FOR BASIC_FOR_noshortif FOR_UPDATE FOR_INIT
%type<ptr> STMNT_EXPR_list IF_THEN IF_THEN_ELSE IF_THEN_ELSE_noshortif DEF_VAR VAR_LIST VARA VAR
%type<ptr> STMNT_EXPR Meth_invoc Expr AssignmentExpression Assignment LeftHandSide ConditionalAndExpression
%type<ptr> ConditionalOrExpression ConditionalExpression InclusiveOrExpression ExclusiveOrExpression 
%type<ptr> AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression
%type<ptr> MultiplicativeExpression UnaryExpression PreIncrementExpression PreDecrementExpression
%type<ptr> UnaryExpressionNotPlusMinus PostfixExpression FieldAccess Primary ArrayCreationExpr DimExpr
%type<ptr> ArrayAccess PostDecrementExpression PostIncrementExpression EMP_EXPR ARG_LIST ARG_LISTp LIT
%type<ptr> STAT DTYPE Class_body Class_body_dec_list Class_body_dec Class_DEF_VAR MethodDeclaration 
%type<ptr> Meth_Body DIMS_list Meth_Head DIMS Meth_decl Param_list Param MOD_EMPTY_LIST MOD_LIST MOD
%type<ptr> SwitchBlock SwitchBlockStatementGroup SwitchBlockStatementGroup_list SwitchLabel 
%type<ptr> SwitchLabel_list SwitchRule SwitchRule_list SwitchStatement ThrowStatement CaseConstant_list 
%type<ptr> CONT1D CONT2D CONT3D Array_init_1D Array_init_2D Array_init_3D L1D L2D L3D

%%
START:  ImportDecl_list ClassDeclaration_list {
    vector<treeNode*> v;
    insertAttr(v, $1, "ImportList", 1);
    insertAttr(v, $2, "ClassList", 1);
    $$ = makenode("Program", v);
}
|       ClassDeclaration_list{
    vector<treeNode*> v;
    insertAttr(v, $1, "ClassList", 1);
    $$ = makenode("Program", v);
}
;

ClassDeclaration_list:  ClassDeclaration_list ClassDeclaration{
    vector<treeNode*> v;
    insertAttr(v, $1, "ClassList", 1);
    insertAttr(v, $2, "Class", 1);
    $$ = makenode("Classes", v);
}
|                       ClassDeclaration{
    vector<treeNode*> v;
    insertAttr(v, $1, "Class", 1);
    $$ = makenode("ClassList", v);
}
;

ImportDecl_list:    ImportDecl_list ImportDecl{
    vector<treeNode*> v;
    insertAttr(v, $1, "ImportList", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("ImportList", v);
}
|                   ImportDecl{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("ImportList", v);
}
;

ImportDecl:     KEY_IMPORT STAT Imp_list ';' {$$ = makeleaf("ID(" + *$3 + ")");}
|               KEY_IMPORT STAT Imp_list '.' '*' ';' {$$ = makeleaf("ID(" + *$3 + ")");}

;

Imp_list:   Imp_list '.' ID {
    *$$ = *$1 + "." + *$3;
}
|           ID{
    *$$ = *$1;
}
;

BODY:   BODY BLCK_STMNT{
    vector<treeNode*> v;
    insertAttr(v, $1, "Body", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Body", v);
}
|       BLCK_STMNT{
    $$ = $1;
}
;

BLCK_STMNT: STMNT {
    $$ = $1;
} 
|           DEF_VAR ';' {
    $$ = $1;
}
;

BLCK:   '{' BODY '}'{
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);
}
|       '{' '}'{
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);
}
;

STMNT_without_sub:  BLCK{
    $$ = $1;
} 
|                   Expr ';'{
    $$ = $1;
}
|                   KEY_RETURN EMP_EXPR ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("return"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   KEY_CONTINUE ';'{
    $$ = makeleaf("continue");
}
|                   KEY_BREAK ';'{
    $$ = makeleaf("break");
}
|                   KEY_YIELD Expr ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("yield"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("STMNT_without_sub", v);
}
|                   Assert_stmnt{
    $$ = $1;
}
|                   ThrowStatement{
    $$ = $1;
}
|                   SwitchStatement{
    $$ = $1;
}
|                   KEY_DO STMNT KEY_WHILE '(' Expr ')' ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("do"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $5, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("STMNT_without_sub", v);
}
|                   ';' {$$ = NULL;}

;

SwitchStatement:    KEY_SWITCH '(' Expr ')' SwitchBlock{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("switch"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, $5, "", 1);
    $$ = makenode("SwitchStatement", v);
}
;
SwitchBlock:    '{' SwitchRule_list '}' {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("SwitchBlock", v);
}
|
    '{' SwitchBlockStatementGroup_list '}' {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("SwitchBlock", v);
}
|   '{' '}' {
    $$ = NULL;
}
|
    '{' SwitchBlockStatementGroup_list SwitchLabel_list '}' {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("SwitchBlock", v);
}
|
    '{'SwitchLabel_list '}' {
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("SwitchBlock", v);
}
;

SwitchBlockStatementGroup_list: SwitchBlockStatementGroup_list SwitchBlockStatementGroup{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("SwitchBlockStatementGroupList", v);
}
|                    SwitchBlockStatementGroup{
    $$ = $1;
}
;
SwitchRule_list:    SwitchRule_list SwitchRule{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("SwitchRuleList", v);
}
|                   SwitchRule{
    $$ = $1;
}
;

SwitchBlockStatementGroup:  SwitchLabel_list BODY{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("SwitchBlockStatementGroup", v);
}

SwitchLabel_list:  SwitchLabel_list SwitchLabel ':' {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("SwitchLabelList", v);
}
|                SwitchLabel ':' {
    $$ = $1;
}
;

SwitchRule: SwitchLabel ARROW Expr ';' {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("SwitchRule", v);
}
|           SwitchLabel ARROW BLCK {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("SwitchRule", v);
}
|           SwitchLabel ARROW ThrowStatement {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("->"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("SwitchRule", v);
}
;

SwitchLabel: KEY_CASE CaseConstant_list {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("case"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("SwitchLabel", v);
}
| KEY_DEFAULT {
    $$ = makeleaf("default");
}
;

CaseConstant_list: CaseConstant_list ',' ConditionalExpression {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("CaseConstantList", v);
}
|
ConditionalExpression {
    $$ = $1;
}
;

ThrowStatement: KEY_THROW Expr ';' {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("throw"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("ThrowStatement", v);
}

Assert_stmnt:   KEY_ASSERT Expr ';' {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Assert_stmnt", v);
}
|               KEY_ASSERT Expr ':' Expr ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("Assert_stmnt", v);
}
;

STMNT:  STMNT_without_sub{
    $$ = $1;
}
|       IF_THEN{
    $$  =$1;
}
|       IF_THEN_ELSE{
    $$ = $1;
}
|       WHILE_STMNT{
    $$ = $1;
}
|       BASIC_FOR{
    $$ = $1;
}
;

STMNT_noshortif:    STMNT_without_sub{
    $$ = $1;
}
|                   IF_THEN_ELSE_noshortif{
    $$ = $1;
}
|                   WHILE_STMNT_noshortif{
    $$ = $1;
}
|                   BASIC_FOR_noshortif{
    $$ = $1;
}
;

WHILE_STMNT: KEY_WHILE '(' Expr ')' STMNT{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $3, "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, $5, "", 1);
    $$ = makenode("WHILE_STMNT", v);
}
;
WHILE_STMNT_noshortif: KEY_WHILE '(' Expr ')' STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $3, "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, $5, "", 1);
    $$ = makenode("WHILE_STMNT_noshortif", v);
}
;
BASIC_FOR:  KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("for"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, $5, "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, $7, "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, $9, "", 1);
    $$ = makenode("BASIC_FOR", v);
}
;
BASIC_FOR_noshortif:    KEY_FOR '(' FOR_INIT ';' EMP_EXPR ';' FOR_UPDATE ')' STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("FOR"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, $7, "", 1);
    insertAttr(v,NULL, ")",0);
    insertAttr(v, $9, "", 1);
    $$ = makenode("BASIC_FOR_noshortif", v);
}
;

FOR_UPDATE: STMNT_EXPR_list {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_UPDATE", v);
}
| %empty{
    $$ = NULL;
}
;

FOR_INIT:   DEF_VAR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_INIT", v);
}
|           STMNT_EXPR_list{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_INIT", v);
}
|           %empty{
    $$ = NULL;
}
;

STMNT_EXPR_list:    STMNT_EXPR_list ',' STMNT_EXPR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("STMNT_EXPR_list", v);
}
|                   STMNT_EXPR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("STMNT_EXPR_list", v);
}
;

IF_THEN:    KEY_IF '(' Expr ')' STMNT{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("IF_THEN", v);
}
;
IF_THEN_ELSE:   KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $7, "", 1);
    $$ = makenode("IF_THEN_ELSE", v);
}
;
IF_THEN_ELSE_noshortif: KEY_IF '(' Expr ')' STMNT_noshortif KEY_ELSE STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $7, "", 1);
    $$ = makenode("IF_THEN_ELSE_noshortif", v);
}
;


DEF_VAR: STAT DTYPE VAR_LIST{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("DEF_VAR", v);
}
;

VAR_LIST:   VAR_LIST ',' VAR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);
}
|           VAR_LIST ',' VARA{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);
}
|           VAR{
    $$ = $1;
}
|           VARA{
    $$ = $1;
}
;

VARA:   ID '=' Expr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '=' Array_init_1D{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, $6, "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' Array_init_2D{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, $9, "", 1);
    $$ = makenode("=", v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']' '=' Array_init_3D{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $9, "", 1);
    insertAttr(v, NULL, "]", 0);
    treeNode* temp = makenode("LeftHandSide", v);
    v.clear();
    insertAttr(v, temp, "", 1);
    insertAttr(v, $12, "", 1);
    $$ = makenode("=", v);
}
;

Array_init_1D: L1D{
    $$ = $1;
}
|               KEY_NEW DTYPE '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("Array-1D", v);
}
;
Array_init_2D: L2D{
    $$ = $1;
}
|               KEY_NEW DTYPE '[' Expr ']' '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $7, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("Array-2D", v);
}
;
Array_init_3D: L3D{
    $$ = $1;
}
|               KEY_NEW DTYPE '[' Expr ']' '[' Expr ']' '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $7, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $10, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("Array-3D", v);
}
;

VAR:    ID{
    $$ = makeleaf("ID(" + *$1 + ")");
}
|       ID '[' EMP_EXPR ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("1D Array",v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("2D Array",v);
}
|       ID '[' EMP_EXPR ']' '[' EMP_EXPR ']' '[' EMP_EXPR ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, "]", 0);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $9, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("3D Array",v);
}
;

L3D:    '{' CONT3D '}'{
    $$ = $2;
}
;
CONT3D: CONT3D ',' L2D{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-3D", v);
}
|       L2D{
    $$ = $1;
}
;

L2D:    '{' CONT2D '}'{
    $$ = $2;
}
;
CONT2D: CONT2D ',' L1D{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-2D", v);
}
|       L1D{
    $$ = $1;
}
;

L1D: '{' CONT1D '}' {
    $$ = $2;
} 
;
CONT1D: CONT1D ',' Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-1D", v);
}
|       Expr{
    $$ = $1;
}
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
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("Meth_invoc", v);
}
;

Expr: AssignmentExpression{
    $$ = $1;
}
;

AssignmentExpression: ConditionalExpression{$$ = $1;}
|                     Assignment{$$ = $1;}
;

Assignment: LeftHandSide AssignmentOperator Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(*$2, v);
}
;

AssignmentOperator: ASSIGN_OP{
    *$$ = *$1;
}
|                  '='{
    *$$ = "=";
}
;

ExpressionName:  AmbiguousName '.' ID{
    *$$ = *$1 + "." + *$3;
}
|                ID {
    *$$ = *$1;
}
;
AmbiguousName:  ID  {
    *$$ = *$1;
}
|               AmbiguousName '.' ID{
    *$$ = *$1 + "." + *$3;
}
;

LeftHandSide:   ExpressionName{$$ = makeleaf("ID(" + *$1 + ")");}
|               FieldAccess{$$ = $1;}
|               ArrayAccess{$$ = $1;}
/* |               VAR */
;

ConditionalExpression:  ConditionalOrExpression{$$ = $1;}
|                       ConditionalOrExpression '?' Expr ':' ConditionalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("?:", v);
}
;

ConditionalOrExpression:    ConditionalAndExpression{$$ = $1;}
|                           ConditionalOrExpression LOG_OR ConditionalAndExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("||", v);
}
;

ConditionalAndExpression:   InclusiveOrExpression{$$ = $1;}
|                           ConditionalAndExpression LOG_AND InclusiveOrExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&&", v);
}
;

InclusiveOrExpression:      ExclusiveOrExpression{$$ = $1;}
|                           InclusiveOrExpression '|' ExclusiveOrExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("|", v);
}
;

ExclusiveOrExpression:      AndExpression{$$ = $1;}
|                           ExclusiveOrExpression '^' AndExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("^", v);}
;

AndExpression:              EqualityExpression{$$ = $1;}
|                           AndExpression '&' EqualityExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&", v);
}
;

EqualityExpression:         RelationalExpression{$$ = $1;}
|                           EqualityExpression EQUAL RelationalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("==", v);}
|                           EqualityExpression NOT_EQUAL RelationalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("!=", v);
}
;

RelationalExpression:       ShiftExpression{$$ = $1;}
|                           RelationalExpression '<' ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<", v);
}
|                           RelationalExpression '>' ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">", v);
}
|                           RelationalExpression GTR_EQUAL ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">=", v);
}
|                           RelationalExpression LESS_EQUAL ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<=", v);
}
;

ShiftExpression:            AdditiveExpression{$$ = $1;}
|                           ShiftExpression LEFT_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<<", v);
}
|                           ShiftExpression RIGHT_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>", v);
}
|                           ShiftExpression SIGN_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>>", v);
}
;

AdditiveExpression:         MultiplicativeExpression{$$ = $1;}
|                           AdditiveExpression '+' MultiplicativeExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("+", v);
}
|                           AdditiveExpression '-' MultiplicativeExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("-", v);
}
;

MultiplicativeExpression:   UnaryExpression{$$ = $1;}
|                           MultiplicativeExpression '*' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("*", v);
}
|                           MultiplicativeExpression '/' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("/", v);
}
|                           MultiplicativeExpression '%' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("%", v);
}
;

UnaryExpression:            PreIncrementExpression{$$ = $1;}
|                           PreDecrementExpression{$$ = $1;}
|                           '+' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("+", v);
}
|                           '-' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("-", v);
}
|                           UnaryExpressionNotPlusMinus{$$ = $1;}
;

PreIncrementExpression:     INCREMENT UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("++", v);
}
;

PreDecrementExpression:     DECREMENT UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("--", v);
}
;

UnaryExpressionNotPlusMinus:    PostfixExpression{
    $$ = $1;
}
|                               '~' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("~", v);
}
|                               '!' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("!", v);
}
|   CastExpression {
    $$ = $1;
}
;

CastExpression:             '(' DTYPE ')' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, $4, "", 1);
    $$ = makenode("CastExpression", v);
}

PostfixExpression:              Primary{
    $$ = $1;
}
|                               ExpressionName{
    $$ = makeleaf("ID(" + *$1 + ")");
}
|                               PostIncrementExpression{
    $$ = $1;
}
|                               PostDecrementExpression{
    $$ = $1;
}
;

FieldAccess:    Primary '.' ID{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID(" + *$3 + ")"), "", 1);
    $$ = makenode("FieldAccess", v);
}
|               KEY_SUPER '.' ID{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("super"), "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID(" + *$3 + ")"), "", 1);
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
    $$ = $1;
}
|                   '(' Expr ')'{
    vector<treeNode*> v;
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $2, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("PrimaryNoNewArray", v);
}
|                   ArrayAccess{$$ = $1;}
|                   Meth_invoc{$$ = $1;}
|                   FieldAccess{$$ = $1;}
|                   KEY_NEW ID '(' ARG_LIST ')' Class_body{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, $6, "", 1);
    $$ = makenode("PrimaryNoNewArray", v);
}
|                   KEY_NEW ID '(' ARG_LIST ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("PrimaryNoNewArray", v);
}
;

ArrayCreationExpr:  KEY_NEW DTYPE DimExpr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);
}
|                   KEY_NEW ID DimExpr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);
}
;

DimExpr:    '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);
}
|           DimExpr '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);
}
;

ArrayAccess:    ExpressionName '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);
}
|               PrimaryNoNewArray '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);
}
;

PostIncrementExpression:        PostfixExpression INCREMENT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("++", v);
}
;

PostDecrementExpression:        PostfixExpression DECREMENT {
    vector<treeNode*> v;
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
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Argument List", v);
}
|           Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("Argument List", v);
}
;

LIT:    INT{
    string s = "INT(" + *$1 + ")";
    $$ = makeleaf(s);
}
|       FLOAT{
    string s = "FLOAT(" + *$1 + ")";
    $$ = makeleaf(s);
}
|       CHAR{
    string temp = *$1;
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "CHAR(" + temp + ")";
    $$ = makeleaf(s);
}
|       STRING{
    string temp = *$1;
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "STRING(" + temp + ")";
    $$ = makeleaf(s);
}
|       BOOL{
    string s = "BOOL(" + *$1 + ")";
    $$ = makeleaf(s);}
|       LONG{
    string s = "LONG(" + *$1 + ")";
    $$ = makeleaf(s);
}
|       DOUBLE{
    string s = "DOUBLE(" + *$1 + ")";
    $$ = makeleaf(s);
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
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("class"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$3 + ")"), "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("ClassDeclaration", v);
}
;

Class_body: '{' Class_body_dec_list '}'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    $$ = makenode("ClassBody", v);
}
|               '{' '}'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("{"), "", 1);
    insertAttr(v, makeleaf("}"), "", 1);
    $$ = makenode("ClassBody", v);
}
;

Class_body_dec_list :   Class_body_dec_list Class_body_dec{
    vector<treeNode*> v;
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
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("ClassBody Declaration", v);
}
|                   ConstructorDeclaration{$$ = $1;}
;

Class_DEF_VAR:  MOD_EMPTY_LIST DTYPE VAR_LIST ';'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ClassVariableDeclaration", v);
}
;
MethodDeclaration: MOD_EMPTY_LIST Meth_Head Meth_Body{
    vector<treeNode*> v;
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
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensions", v);
}
|     '[' ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensions", v);
}
;

DIMS: DIMS_list{$$ = $1;}
;

Meth_Head:  DTYPE DIMS Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Method Header", v);
}
|           KEY_VOID DIMS Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Method Header", v);
}
|           DTYPE Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Method Header", v);
}
|           KEY_VOID Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Method Header", v);
}
;

Meth_decl:  ID '(' Param_list ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("Method Declaration", v);
}
|           ID '(' ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "( )", 0);
    $$ = makenode("Method Declaration", v);
}
;

Param_list: Param_list ',' Param{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("parameter list", v);
}
|           Param{
    $$ = $1;
}
;

Param:  DTYPE VAR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("parameter", v);
}
;

MOD_EMPTY_LIST: MOD_LIST{
    $$ = $1;
}
|               %empty{
    $$ = NULL;
}
;

MOD_LIST:   MOD_LIST MOD{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("modifier list", v);
}
|           MOD{$$ = $1;}
;

MOD :   KEY_PRIVATE{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("private"), "", 1);
    $$ = makenode("modifier", v);
}
|       KEY_PUBLIC{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("public"), "", 1);
    $$ = makenode("modifier", v);
}
|       KEY_STATIC{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("static"), "", 1);
    $$ = makenode("modifier", v);
}
|      KEY_PROTECTED{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("protected"), "", 1);
    $$ = makenode("modifier", v);
}
;

ConstructorDeclaration : MOD_EMPTY_LIST ID '(' Param_list ')' BLCK{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, $6, "", 1);
    $$ = makenode("construtor", v);
}
|                       MOD_EMPTY_LIST ID '(' ')' BLCK{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "( )", 0);
    insertAttr(v, $5, "", 1);
    $$ = makenode("construtor", v);
}
;

%%


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
        cout<<i<<endl;
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
    if(verbose){
        cout<<"Parsing Complete"<<endl;
        cout<<"Output written to "<<outfile<<endl;
    }
  
}