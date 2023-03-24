%{

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
    extern vector<quad> code;

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
    int flag_return = 0;

    int is_stat_scope = 0;
    int stat_flag = 0;
    int fin_flag = 0;

    map<char, int> Size ={
        {'I', 4},
        {'F', 4},
        {'D', 8},
        {'L', 8},
        {'C', 1},
        {'S', 2}
    };
    
    FILE* dotfile;

    void yyerror(string s) {
        cout << "[Line no: " << yylineno << "] " << "Error: " << s << endl;
        exit(-1);
    }

    void yywarn(string s) {
        cout << "[Line no: " << yylineno << "] " << "Warning: " << s << endl;
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
%token<str> KEY_SHORT

%token<str> KEY_FOR
%token<str> KEY_WHILE
%token<str> KEY_IF
%token<str> KEY_ELSE

%token<str> KEY_CONTINUE
%token<str> KEY_BREAK
%token<str> KEY_RETURN
%token<str> KEY_ASSERT
%token<str> KEY_YIELD
%token<str> KEY_IMPORT
%token<str> KEY_THROW
%token<str> KEY_CASE
%token<str> KEY_DEFAULT
%token<str> KEY_SWITCH
%token<str> KEY_DO

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_STATIC
%token<str> KEY_FINAL
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


%type<str> Imp_list AssignmentOperator
%type<ptr> START ImportDecl_list AmbiguousName ExpressionName ClassDeclaration_list CastExpression ClassDeclaration ImportDecl BLCK_STMNT
%type<ptr> PrimaryNoNewArray BODY BLCK STMNT_without_sub ASSERT_HEAD Assert_stmnt STMNT STMNT_noshortif ConstructorDeclaration ConstructorHead START_INSTR
%type<ptr> WHILE_STMNT WHILE_STMNT_noshortif BASIC_FOR BASIC_FOR_noshortif FOR_UPDATE FOR_INIT IF_HEAD IF_STMNT WHILE_HEAD FOR_HEAD
%type<ptr> STMNT_EXPR_list IF_THEN IF_THEN_ELSE IF_THEN_ELSE_noshortif DEF_VAR VAR_LIST VARA VAR
%type<ptr> STMNT_EXPR Meth_invoc Expr AssignmentExpression Assignment LeftHandSide ConditionalAndExpression
%type<ptr> ConditionalOrExpression ConditionalExpression InclusiveOrExpression ExclusiveOrExpression 
%type<ptr> AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression
%type<ptr> MultiplicativeExpression UnaryExpression PreIncrementExpression PreDecrementExpression
%type<ptr> UnaryExpressionNotPlusMinus PostfixExpression FieldAccess Primary ArrayCreationExpr DimExpr
%type<ptr> ArrayAccess PostDecrementExpression PostIncrementExpression EMP_EXPR ARG_LIST ARG_LISTp LIT
%type<ptr> STAT DTYPE Class_body Class_body_dec_list Class_body_dec Class_DEF_VAR MethodDeclaration 
%type<ptr> Meth_Body DIMS_list Meth_Head DIMS Meth_decl Param_list Param MOD_EMPTY_LIST MOD_LIST MOD FIN
%type<ptr> SwitchBlock SwitchBlockStatementGroup SwitchBlockStatementGroup_list SwitchLabel 
%type<ptr> SwitchLabel_list SwitchRule SwitchRule_list SwitchStatement ThrowStatement CaseConstant_list 
%type<ptr> CONT1D CONT2D CONT3D Array_init_1D Array_init_2D Array_init_3D L1D L2D L3D

%%
START:  ImportDecl_list ClassDeclaration_list {
    vector<treeNode*> v;
    insertAttr(v, $1, "ImportList", 1);
    insertAttr(v, $2, "ClassList", 1);
    $$ = makenode("Program", v);
    root = $$;

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

    $$->first_instr = $1->first_instr;
    $$->last_instr = $2->last_instr;
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

BLCK:   '{' {create_symtbl();} BODY '}'{
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);

    // semantics
    current = current->parent;
    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
    stat_flag = 0;
}
|       '{' {create_symtbl();} '}'{
    vector<treeNode*> v;
    insertAttr(v, NULL, "{", 0);
    insertAttr(v, NULL, "}", 0);
    $$ = makenode("Block", v);

    current = current->parent;
    $$->first_instr = code.size();
    $$->last_instr = code.size()-1;
    stat_flag = 0;
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

    // semantics
    if(!can_be_TypeCasted($2->type, retType))
        yyerror("Invalid Return Type, expected " + retType );

    flag_return = 1;
    emit("RET",$2->addr,"","");

    $$->last_instr = code.size()-1;
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

    emit("yield", $2->addr, "", "");
    
    $$->first_instr = $2->first_instr;
    $$->last_instr = code.size()-1;
}
|                   Assert_stmnt{
    $$ = $1;
}
|                   SwitchStatement{
    $$ = $1;
}
|                   KEY_DO START_INSTR STMNT KEY_WHILE '(' Expr ')' ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("do"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("STMNT_without_sub", v);

    emit(IF, $6->addr, GOTO, "");
    backPatch(code.size()-1, $2->last_instr);
    $$->last_instr = code.size()-1;
}
|                   ';' {
    $$ = new treeNode;
    $$->last_instr = code.size();
    $$->addr = "";
}

;

SwitchStatement:    KEY_SWITCH '(' Expr ')' {create_symtbl();} SwitchBlock{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("switch"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    insertAttr(v, $6, "", 1);
    $$ = makenode("SwitchStatement", v);
    
    //end of scope
    current = current->parent;
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

    // 3ac
    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
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

ASSERT_HEAD: KEY_ASSERT Expr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Assert_stmnt", v);

    // 3ac
    emit(IFFALSE, $2->addr, GOTO, "");
    $$->falselist = code.size()-1;
    $$->last_instr = code.size()-1;
}

Assert_stmnt:   ASSERT_HEAD ';' {
    $$ = $1;
    emit(ASSERT_FAIL,to_string(yylineno),"","");
    backPatch($$->falselist, code.size());
    $$->last_instr = code.size()-1;
    
}
|               ASSERT_HEAD ':' Expr ';'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("assert"), "", 1);
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Assert_stmnt", v);

    // 3ac
    emit(ASSERT_FAIL,to_string(yylineno),"","");
    backPatch($$->falselist, code.size());
    $$->last_instr = code.size()-1;

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

START_INSTR: %empty {
    $$ = new treeNode;
    $$->last_instr = code.size();
}

WHILE_HEAD: KEY_WHILE '(' START_INSTR Expr ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("while"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $4, "", 1);
    insertAttr(v,NULL, ")",0);
    $$ = makenode("WHILE_HEAD", v);

    $$->first_instr = $3->last_instr;
    emit(IFFALSE, $4->addr, GOTO, "");
    $$->falselist = code.size()-1;
    $$->last_instr = code.size()-1;
}

WHILE_STMNT: WHILE_HEAD STMNT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("WHILE_STMNT", v);

    // 3ac
    emit(GOTO, to_string($1->first_instr), "", "");
    $$->last_instr = code.size()-1;
    backPatch($1->falselist, code.size());
}
;
WHILE_STMNT_noshortif: WHILE_HEAD STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("WHILE_STMNT_noshortif", v);
    
    // 3ac
    emit(GOTO, to_string($1->first_instr), "", "");
    $$->last_instr = code.size()-1;
    backPatch($1->falselist, code.size());
}
;

FOR_HEAD: KEY_FOR '(' {create_symtbl();} FOR_INIT ';'START_INSTR EMP_EXPR { emit(IFFALSE, $7->addr, GOTO, ""); $7->falselist = code.size()-1; emit(GOTO, "","",""); $7->truelist = code.size()-1; } ';'START_INSTR FOR_UPDATE ')' {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("for"), "", 1);
    insertAttr(v,NULL, "(",0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, $6, "", 1);
    insertAttr(v, NULL, ";", 0);
    insertAttr(v, $10, "", 1);
    insertAttr(v,NULL, ")",0);
    $$ = makenode("FOR_HEAD", v);

    emit(GOTO, to_string($6->last_instr), "", "");
    backPatch($7->truelist, code.size());
    $$->last_instr = code.size()-1;
    $$->first_instr = $10->last_instr;
    $$->falselist = $7->falselist;
}



BASIC_FOR:  FOR_HEAD STMNT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("BASIC_FOR", v);

    // end of scope
    current = current->parent;

    // 3ac
    emit(GOTO, to_string($1->first_instr), "", "");
    backPatch($1->falselist, code.size());
    $$->last_instr = code.size()-1;
}
;
BASIC_FOR_noshortif:    FOR_HEAD STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("BASIC_FOR_noshortif", v);

    // end of scope
    current = current->parent;
    
    // 3ac
    emit(GOTO, to_string($1->first_instr), "", "");
    backPatch($1->falselist, code.size());
    $$->last_instr = code.size()-1;
}
;

FOR_UPDATE: STMNT_EXPR_list {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("FOR_UPDATE", v);
}
| %empty{
    $$ = new treeNode;
    $$->first_instr = code.size();
    $$->last_instr = code.size();
}
;

FOR_INIT:   DEF_VAR{
    $$ = $1;
}
|           STMNT_EXPR_list{
    $$ = $1;
}
|           %empty{
    $$ = new treeNode;
    $$->first_instr = code.size();
    $$->last_instr = code.size();
}
;

STMNT_EXPR_list:    STMNT_EXPR_list ',' STMNT_EXPR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("STMNT_EXPR_list", v);
    
    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;

    
}
|                   STMNT_EXPR{
    $$ = $1;
}
;

IF_HEAD: KEY_IF '(' Expr ')' {
    vector<treeNode*> v;
    insertAttr(v, makeleaf("if"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("IF_HEAD", v);
    
    $$->first_instr = $3->first_instr;
    $$->last_instr = code.size();
    emit(IFFALSE, $3->addr, GOTO, "");
    $$->falselist = $$->last_instr;
}

IF_THEN:    IF_HEAD STMNT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("IF_THEN", v);

    $$->first_instr = $1->first_instr;
    $$->last_instr = $2->last_instr;
    backPatch($1->falselist, $2->last_instr+1);
}
;

IF_STMNT: IF_HEAD STMNT_noshortif {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("IF_STMNT", v);
    $$->first_instr = $1->first_instr;
    $$->last_instr = code.size();
    emit(GOTO, "", "", "");
    $$->truelist = $$->last_instr;
    backPatch($1->falselist, code.size());
}
IF_THEN_ELSE:  IF_STMNT  KEY_ELSE STMNT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("IF_THEN_ELSE", v);

    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
    backPatch($1->truelist, $3->last_instr+1); 
}
;
IF_THEN_ELSE_noshortif: IF_STMNT KEY_ELSE STMNT_noshortif{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("else"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("IF_THEN_ELSE_noshortif", v);

    // 3ac
    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
    backPatch($1->truelist, $3->last_instr+1); 
}
;


DEF_VAR: STAT FIN DTYPE VAR_LIST{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("DEF_VAR", v);

    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
    stat_flag = 0;
    fin_flag = 0;
}
|       KEY_STATIC {stat_flag = 1;} ID{CREATE_ST_KEY(temp, *$3); temp->type.push_back(TYPE_CLASS); if(lookup(temp)){dType = *$3;} else {yyerror(*$3 + "doesn't name a type");} free(temp); } VAR_LIST{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("static"),"",1);
    insertAttr(v,makeleaf("ID(" + *$3 + ")"), "", 1 );
    insertAttr(v, $5, "", 1);
    $$ = makenode("DEF_VAR", v);

    $$->first_instr = $5->first_instr;
    $$->last_instr = $5->last_instr;
    stat_flag = 0;

}
|        ID{CREATE_ST_KEY(temp, *$1); temp->type.push_back(TYPE_CLASS); if(lookup(temp)){dType = *$1;} else {yyerror(*$1 + "doesn't name a type");} free(temp); } VAR_LIST{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("DEF_VAR", v);

    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
}
;

VAR_LIST:   VAR_LIST ',' VAR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);

    // sematics
    CREATE_ST_KEY(temp, $3->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", $3->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $3->dim));
    temp_entry->arr_dims = $3->arr_dims;
    temp_entry->stat_flag = stat_flag;
    temp_entry->fin_flag = fin_flag;
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + $3->lexeme);
    }
    free(temp);
    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;


}
|           VAR_LIST ',' VARA{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("VAR_LIST", v);
    // sematics
    CREATE_ST_KEY(temp, $3->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", $3->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $3->dim));
    temp_entry->arr_dims = $3->arr_dims;
    temp_entry->stat_flag = stat_flag;
    temp_entry->fin_flag = fin_flag;
    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + $3->lexeme);
    }
    free(temp);

    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
}
|           VAR{
    $$ = $1;

    // sematics
    CREATE_ST_KEY(temp, $1->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", $1->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $1->dim));
    temp_entry->arr_dims = $1->arr_dims;
    temp_entry->stat_flag = stat_flag;
    temp_entry->fin_flag = fin_flag;

    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + $1->lexeme);
    }
    free(temp);

    $$->first_instr = $1->first_instr;
    $$->last_instr = $1->last_instr;
}
|           VARA{
    $$ = $1;

    // sematics
    CREATE_ST_KEY(temp, $1->lexeme);
    CREATE_ST_ENTRY(temp_entry,"ID", $1->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $1->dim));
    temp_entry->arr_dims = $1->arr_dims;
    temp_entry->stat_flag = stat_flag;
    temp_entry->fin_flag = fin_flag;
    
    int err = insert_symtbl(temp,temp_entry);
    if(err == ALREADY_EXIST){
        yyerror("Variable already declared: " + $1->lexeme);
    }
    free(temp);

    $$->first_instr = $1->first_instr;
    $$->last_instr = $1->last_instr;
}
;

VARA:   ID '=' Expr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("=", v);

    $$->lexeme = *$1;
    $$->dim = 0;

    // sematics
    if(!can_be_TypeCasted($3->type, dType)){
        yyerror("Type Mismatch " + $3->type + " cannot be typecasted to " + dType);
    }

    if(dType != $3->type){
        string temp = get_temp(dType);
        emit($3->type + "TO" + dType, $3->addr, "", temp);
        $3->addr = temp;
    }
    emit("",$3->addr,"",*$1);
    $$->type = dType;

    $$->first_instr = $3->first_instr;
    $$->last_instr = code.size()-1;

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

    $$->lexeme = *$1;
    $$->dim = 1;
    // sematics
    if(!can_be_TypeCasted($6->type, dType + TYPE_ARRAY)){
        yyerror("Type Mismatch " + $6->type + " cannot be typecasted to " + dType + TYPE_ARRAY);
    }
    if($3->addr != "" && $3->addr != $6->arr_dims[0]){
        yyerror("Size Mismatch");
    }

    $$->arr_dims = $6->arr_dims;

    $$->first_instr = $3->first_instr;
    $$->last_instr = code.size()-1;
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

    $$->lexeme = *$1;
    $$->dim = 2;
    // sematics
    if(!can_be_TypeCasted($9->type, dType + TYPE_ARRAY + TYPE_ARRAY)){
        yyerror("Type Mismatch " + $9->type + " cannot be typecasted to " + dType + TYPE_ARRAY + TYPE_ARRAY);
    }
    if($3->addr != "" && $3->addr != $9->arr_dims[0]){
        yyerror("Size Mismatch");
    }
    if($6->addr != "" && $6->addr != $9->arr_dims[1]){
        yyerror("Size Mismatch");
    }
    $$->arr_dims = $9->arr_dims;

    $$->first_instr = $3->first_instr;
    $$->last_instr = code.size()-1;
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

    $$->lexeme = *$1;
    $$->dim = 3;
    // sematics
    if(!can_be_TypeCasted($12->type, dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY)){
        yyerror("Type Mismatch " + $12->type + " cannot be typecasted to " + dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY);
    }
    if($3->addr != "" && $3->addr != $12->arr_dims[0]){
        yyerror("Size Mismatch");
    }
    if($6->addr != "" && $6->addr != $12->arr_dims[1]){
        yyerror("Size Mismatch");
    }
    if($9->addr != "" && $9->addr != $12->arr_dims[2]){
        yyerror("Size Mismatch");
    }
    $$->arr_dims = $12->arr_dims;

    $$->first_instr = $3->first_instr;
    $$->last_instr = code.size()-1;
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
    $$->type = dType + TYPE_ARRAY;

    $$->arr_dims.push_back($4->addr);

    $$->first_instr = $4->first_instr;
    $$->last_instr = $4->last_instr;

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

    $$->type = dType + TYPE_ARRAY + TYPE_ARRAY;

    $$->arr_dims.push_back($4->addr);
    $$->arr_dims.push_back($7->addr);

    $$->first_instr = $4->first_instr;
    $$->last_instr = $7->last_instr;
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

    $$->type = dType + TYPE_ARRAY + TYPE_ARRAY + TYPE_ARRAY;

    $$->arr_dims.push_back($4->addr);
    $$->arr_dims.push_back($7->addr);
    $$->arr_dims.push_back($10->addr);

    $$->first_instr = $4->first_instr;
    $$->last_instr = $10->last_instr;
}
;

VAR:    ID{
    $$ = makeleaf("ID(" + *$1 + ")");

    $$->lexeme = *$1;
    $$->dim = 0;

    $$->addr = *$1;

    $$->first_instr = code.size()-1;
    $$->last_instr = code.size()-1;
}
|       ID '[' EMP_EXPR ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "[", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, "]", 0);
    $$ = makenode("1D Array",v);

    $$->lexeme = *$1;
    $$->dim = 1;
    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
    $$->arr_dims.push_back($3->addr);
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

    $$->lexeme = *$1;
    $$->dim = 2;

    $$->first_instr = $3->first_instr;
    $$->last_instr = $6->last_instr;
    $$->arr_dims.push_back($3->addr);
    $$->arr_dims.push_back($6->addr);
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

    $$->lexeme = *$1;
    $$->dim = 3;

    $$->first_instr = $3->first_instr;
    $$->last_instr = $9->last_instr;
    $$->arr_dims.push_back($3->addr);
    $$->arr_dims.push_back($6->addr);
    $$->arr_dims.push_back($9->addr);
}
;

L3D:    '{' CONT3D '}'{
    $$ = $2;
    $$->type = $2->type + TYPE_ARRAY;

    $$->dims_count_1 = dims_count_1;
    $$->dims_count_2 = dims_count_2;
    $$->dims_count_3 = dims_count_3;
    $$->arr_dims.push_back(to_string(dims_count_1));
    $$->arr_dims.push_back(to_string(dims_count_2));
    $$->arr_dims.push_back(to_string(dims_count_3));
}   
;
CONT3D: CONT3D ',' L2D{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-3D", v);
    if($1->type == $3->type){
        $$->type = $1->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }

    dims_count_3 += 1;
    $$->dims_count_3 = dims_count_3;
    $$->dims_count_2 = dims_count_2;
    $$->dims_count_1 = dims_count_1;

    //cout<<"3d dims_count_2: "<<dims_count_2<<endl;
    if(dims_count_2 != $1->dims_count_2){
        yyerror("Array dimensions mismatch");
    }

    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
}
|       L2D{
    $$ = $1;
    dims_count_3 = 1;

    $$->dims_count_3 = dims_count_3;
    $$->dims_count_2 = dims_count_2;
    $$->dims_count_1 = dims_count_1;
}
;

L2D:    '{' CONT2D '}'{
    $$ = $2;
    $$->type = $2->type + TYPE_ARRAY;

    $$->dims_count_1 = dims_count_1;
    $$->dims_count_2 = dims_count_2;

    $$->arr_dims.push_back(to_string(dims_count_1));
    $$->arr_dims.push_back(to_string(dims_count_2));

    
}
;
CONT2D: CONT2D ',' L1D{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-2D", v);
    if($1->type == $3->type){
        $$->type = $1->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }
    dims_count_2 += 1;
    $$->dims_count_2 = dims_count_2;
    $$->dims_count_1 = dims_count_1;

    //cout<<dims_count_1<<" "<<$1->dims_count_1<<endl;
    
    if(dims_count_1 != $1->dims_count_1){
        yyerror("Array dimensions mismatch");
    }  

    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr; 
}
|       L1D{
    $$ = $1;
    dims_count_2 = 1;
    $$->dims_count_2 = dims_count_2;
    $$->dims_count_1 = dims_count_1;
}
;

L1D: '{' CONT1D '}' {
    $$ = $2;
    $$->type = $2->type + TYPE_ARRAY;
    $$->dims_count_1 = dims_count_1;
    $$->arr_dims.push_back(to_string(dims_count_1));
} 
;
CONT1D: CONT1D ',' Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, NULL, ",", 0);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Array-1D", v);

    if($1->type == $3->type){
        $$->type = $1->type;
    }
    else{
        yyerror("Type mismatch in array initialization list");
    }

    dims_count_1 += 1;
    $$->dims_count_1 = dims_count_1;

    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
}
|       Expr{
    $$ = $1;

    dims_count_1 = 1;
    $$->dims_count_1 = dims_count_1;
    
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
    insertAttr(v, makeleaf("ID(" + $1->lexeme + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $3, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("Meth_invoc", v);

    /*type checking*/
    if($1->typevec.size()==0){
        // ExpressionName is just ID.
        CREATE_ST_KEY(temp, $1->lexeme);
        // if($3){
        //    temp->type = $3->typevec;
        // }

        SymbTbl_entry* entry = lookup(temp);
        if(entry){
            // typechecking
            if(compareMethTypes(entry->type, $3->typevec)){
                $$->type = *(entry->type.rbegin());
                // if(is_stat_scope && !entry->stat_flag){
                //     yyerror("cannot call non static function " + entry->lexeme + " from static scope");
                // }
                $$->addr = get_temp($$->type);
                for(int i=0;i<entry->type.size()-1;i++){
                    if(entry->type[i] != $3->typevec[i]){
                        string temp = get_temp(entry->type[i]);
                        emit($3->typevec[i] + "TO" + entry->type[i], "", $3->arg_addr[i], temp);
                        $3->arg_addr[i] = temp;
                    }
                    emit("param", $3->arg_addr[i], "", "");
                }
                emit("call", $1->lexeme + ", " + to_string($3->typevec.size()), to_string(entry->func_entry_addr), $$->addr);
            }
            else{
                yyerror("Invalid Argument Types for Method " + $1->lexeme);
            }
        }
        else{
            yyerror("method " + $1->lexeme + " not found");
        }
        free(temp);
    }
    else{
        // ExpressionName is ID.ID.ID...
        CREATE_ST_KEY(temp, $1->typevec[0]);
        temp->type.push_back(TYPE_CLASS);
        SymbTbl_entry* entry = lookup(temp);
        if(entry){
            SymbolTable* classTable = entry->table;
            CREATE_ST_KEY(classTemp, $1->typevec[1]);
            auto it = classTable->table.find(*classTemp);
            if(it != classTable->table.end()){
                SymbTbl_entry* entry = it->second;

                if(compareMethTypes(entry->type, $3->typevec)){
                    $$->type = *(entry->type.rbegin());
                    // if(is_stat_scope && !entry->stat_flag){
                    //     yyerror("cannot call non static function " + entry->lexeme + " from static scope");
                    // }
                    $$->addr = get_temp($$->type);
                    for(int i=0;i<entry->type.size();i++){
                        if(entry->type[i] != $3->typevec[i]){
                            emit($3->typevec[i] + "TO" + entry->type[i], "", $3->arg_addr[i], $3->arg_addr[i]);
                        }
                        emit("param", $3->arg_addr[i], "", "");
                    }
                    if(entry->mod_flag == PUBLIC_FLAG){
                        $$->type = *(entry->type.rbegin());
                        $$->addr = get_temp($$->type);
                        emit("call", $1->typevec[1] + ", " + to_string($3->typevec.size()), to_string(entry->func_entry_addr), $$->addr);
                    }
                    else{
                        yyerror("Non-Public member " + $1->typevec[1] + " of class " + $1->typevec[0] + " cannot be accessed");
                    }
                }
                else{
                    yyerror("Invalid Argument Types for Method " + $1->lexeme);
                }

            }
            else {
                yyerror("No method " + $1->typevec[1] + " found in class " + $1->typevec[0]);

            }
            free(classTemp);
        }
        else{
            yyerror("No class " + $1->type + " found");
        }
        free(temp);
    }
    $$->last_instr = code.size()-1;
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

    // type checking
    if(can_be_TypeCasted($1->type, $3->type))$$->type = $1->type;
    else{
        yyerror("Type Mismatched cannot cast " + $3->type + " to " + $1->type);
    }

    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    
    

    $$->first_instr = $1->first_instr;
    $$->last_instr = code.size();
    emit("", $3->addr, "", $1->addr);
    flag_array = 0; 
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
    $$ = new treeNode;
    $$->lexeme = $1->lexeme + "." + *$3;

    // semantics
    CREATE_ST_KEY(temp, $1->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *$3);
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end() && !it->second->is_func){
            SymbTbl_entry* entry = it->second;
            if(entry->mod_flag == PUBLIC_FLAG){
                $$->type = entry->type[0];
                $$->fin_flag = entry->fin_flag;
                $$->addr = $$->lexeme;
            }
            else{
                yyerror("Non-Public member " + *$3 + " of class " + $1->type + " cannot be accessed");
            }
        }
        else {
            $$->typevec.push_back($1->type);
            $$->typevec.push_back(*$3);
            $$->type = TYPE_ERROR;

        }
        free(classTemp);
    }
    else{
        yyerror("No class " + $1->type + " found");
    } 
    free(temp);


}
|                ID {
    $$ = new treeNode;
    $$->lexeme = *$1;
    CREATE_ST_KEY(temp, *$1);
    SymbTbl_entry* entry = lookup(temp);
    if(entry && !entry->is_func){
        if(is_stat_scope && !entry->stat_flag){
            yyerror("cannot access static variable " + entry->lexeme + " from non static scope.");
        }
        $$->type = entry->type[0];
        $$->fin_flag = entry->fin_flag;
        $$->addr = *$1;
    }
    else{
        $$->type = TYPE_ERROR;
    }

    free(temp);
}
;
AmbiguousName:  ID  {
    $$ = new treeNode;
    $$->lexeme = *$1;
    CREATE_ST_KEY(temp, *$1);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        $$->type = entry->type[0];
        $$->fin_flag = entry->fin_flag;
    }
    else{
        yyerror("undeclared variable " + *$1 );
    }
    free(temp);
}
|               AmbiguousName '.' ID{
    $$ = new treeNode;
    $$->lexeme = $1->lexeme + "." + *$3;

    // semantics
    CREATE_ST_KEY(temp, $1->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *$3);
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            // SymbTbl_entry* entry;
            if(entry->mod_flag == PUBLIC_FLAG){
                $$->type = entry->type[0];
                $$->fin_flag = entry->fin_flag;
            }
            else{
                yyerror("Non-Public member " + *$3 + " of class " + $1->type + " cannot be accessed");
            }
        }
        else {
            yyerror("No member " + *$3 + " in class " + $1->type);
        }
        free(classTemp);
    }
    else{
        yyerror("No class " + $1->type + " found");
    } 
    free(temp);
}
;

LeftHandSide:   ExpressionName{
    $$ = makeleaf("ID(" + $1->lexeme + ")");
    $$->lexeme = $1->lexeme;
    //type checking
    $$->type = $1->type;
    if($1->type == TYPE_ERROR){
        yyerror("Unidentified Symbol "+ $$->lexeme);
    }
    if($1->fin_flag){
        yyerror("Cannot Reassign Final Variable " + $$->lexeme);
    }

    //3ac
    $$->addr = $1->addr;
    $$->first_instr = $1->first_instr;
    $$->last_instr = $1->last_instr;
}
|               FieldAccess{$$ = $1;}
|               ArrayAccess{
                                $$ = $1;
                                $$->addr = $1->lexeme + "[" + $1->addr + "]";
                                flag_array = 0;
                                if($1->fin_flag){
                                    yyerror("Cannot Reassign Final Variable " + $$->lexeme);
                                }
}
;

ConditionalExpression:  ConditionalOrExpression{$$ = $1;}
|                       ConditionalOrExpression '?'{emit(IFFALSE, $1->addr, GOTO, ""); $1->falselist = code.size()-1;} Expr ':' {$1->addr = get_temp($4->type); emit("", $4->addr, "", $1->addr);emit(GOTO, "","",""); $4->truelist = code.size()-1;} START_INSTR ConditionalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $4, "", 1);
    insertAttr(v, $8, "", 1);
    $$ = makenode("?:", v);

    //type checking
    emit("", $8->addr, "", $1->addr);
    $$->addr = $1->addr;
    
    if($1->type == TYPE_BOOL)
        $$->type = maxType($4->type, $8->type);
    else{
        yyerror("TypeError: Conditional Expression: Type Mismatch");
    }

    backPatch($1->falselist, $7->last_instr);
    backPatch($4->truelist, code.size());
    if($$->type != $4->type){
        string temp = get_temp($$->type);
        emit($4->type + "TO" + $$->type, $$->addr, "", temp);
        $$->addr = temp;
    }
    else if($$->type != $8->type){
        string temp = get_temp($$->type);
        emit($8->type + "TO" + $$->type, $$->addr, "", temp);
        $$->addr = temp;
    }

    $$->last_instr = code.size()-1;
}
;

ConditionalOrExpression:    ConditionalAndExpression{$$ = $1;}
|                           ConditionalOrExpression LOG_OR ConditionalAndExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("||", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("||", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

ConditionalAndExpression:   InclusiveOrExpression{$$ = $1;}
|                           ConditionalAndExpression LOG_AND InclusiveOrExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&&", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    // 3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("&&", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;

}
;

InclusiveOrExpression:      ExclusiveOrExpression{$$ = $1;}
|                           InclusiveOrExpression '|' ExclusiveOrExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("|", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type, "|");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("|", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

ExclusiveOrExpression:      AndExpression{$$ = $1;}
|                           ExclusiveOrExpression '^' AndExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("^", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type, "^");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("^", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

AndExpression:              EqualityExpression{$$ = $1;}
|                           AndExpression '&' EqualityExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("&", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type,"&" );
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("&", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

EqualityExpression:         RelationalExpression{$$ = $1;}
|                           EqualityExpression EQUAL RelationalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("==", v);
    
    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("==", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           EqualityExpression NOT_EQUAL RelationalExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("!=", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("!=", $1->addr, $3->addr, $$->addr);    
    $$->last_instr = code.size()-1;
}
;

RelationalExpression:       ShiftExpression{$$ = $1;}
|                           RelationalExpression '<' ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("<", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           RelationalExpression '>' ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit(">", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           RelationalExpression GTR_EQUAL ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">=", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit(">=", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           RelationalExpression LESS_EQUAL ShiftExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<=", v);

    //type checking
    $$->type = relCheck($1->type, $3->type);
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("<=", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

ShiftExpression:            AdditiveExpression{$$ = $1;}
|                           ShiftExpression LEFT_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("<<", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type, "<<");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("<<", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           ShiftExpression RIGHT_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type, ">>");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit(">>", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           ShiftExpression SIGN_SHIFT AdditiveExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode(">>>", v);

    //type checking
    $$->type = onlyIntCheck($1->type, $3->type, ">>>");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit(">>>", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

AdditiveExpression:         MultiplicativeExpression{$$ = $1;}
|                           AdditiveExpression '+' MultiplicativeExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("+", v);

    //typeChecking
    $$->type = addCheck($1->type, $3->type,"+");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("+" + $$->type, $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           AdditiveExpression '-' MultiplicativeExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("-", v);

    //typeChecking
    $$->type = addCheck($1->type, $3->type,"-");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("-", $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

MultiplicativeExpression:   UnaryExpression{$$ = $1;}
|                           MultiplicativeExpression '*' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("*", v);

    //typeChecking
    $$->type = multCheck($1->type, $3->type,"*");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("*" + $$->type, $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           MultiplicativeExpression '/' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("/", v);

    //typeChecking
    $$->type = multCheck($1->type, $3->type,"/");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("/"+$$->type, $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
|                           MultiplicativeExpression '%' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("%", v);

    //typeChecking
    $$->type = onlyIntCheck($1->type, $3->type, "%");
    if($$->type != $1->type){
        string temp = get_temp($$->type);
        emit($1->type + "TO" + $$->type, $1->addr, "", temp);
        $1->addr = temp;
    }
    if($$->type != $3->type){
        string temp = get_temp($$->type);
        emit($3->type + "TO" + $$->type, $3->addr, "", temp);
        $3->addr = temp;
    }
    
    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $1->first_instr;
    emit("%"+$$->type, $1->addr, $3->addr, $$->addr);
    $$->last_instr = code.size()-1;
}
;

UnaryExpression:            PreIncrementExpression{$$ = $1;}
|                           PreDecrementExpression{$$ = $1;}
|                           '+' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("+", v);

    //type checking
    $$->type = $2->type;

    //3ac
    $$->addr = $2->addr;
    $$->first_instr = $2->first_instr;
    emit("+", $2->addr, "", $$->addr);
    $$->last_instr = code.size()-1;
}
|                           '-' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("-", v);

    //type checking
    $$->type = $2->type;

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $2->first_instr;
    emit("-", $2->addr, "", $$->addr);
    $$->last_instr = code.size()-1;
}
|                           UnaryExpressionNotPlusMinus{$$ = $1;}
;

PreIncrementExpression:     INCREMENT UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("++", v);

    //type checking
    if(isNum($2->type)){
        $$->type = $2->type;

    }
    else{
        yyerror("Cannot increment non-numeric type");
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $2->first_instr;
    emit("+", $2->addr, "1", $2->addr);
    emit("", $2->addr, "", $$->addr);
    $$->last_instr = code.size()-1;
}
;

PreDecrementExpression:     DECREMENT UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("--", v);

    //type checking
    if(isNum($2->type)){
        $$->type = $2->type;

    }
    else{
        yyerror("Cannot decrement non-numeric type");
    }

    //3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $2->first_instr;
    emit("-", $2->addr, "1", $2->addr);
    emit("", $2->addr, "", $$->addr);
    $$->last_instr = code.size()-1;
}
;

UnaryExpressionNotPlusMinus:    PostfixExpression{
    $$ = $1;
}
|                               '~' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("~", v);

    //type checking
    $$->type = $2->type;

    $$->addr = get_temp($$->type);
    $$->first_instr = $2->first_instr;
    emit("~", $2->addr, "", $$->addr);
    $$->last_instr = code.size()-1;
}
|                               '!' UnaryExpression{
    vector<treeNode*> v;
    insertAttr(v, $2, "", 1);
    $$ = makenode("!", v);

    //type checking
    $$->type = $2->type;
    
    // 3ac
    $$->addr = get_temp($$->type);
    $$->first_instr = $2->first_instr;
    $$->last_instr = code.size();
    emit("!", $2->addr, "", $$->addr);
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

    //type checking
    if(can_be_TypeCasted($2->type, $4->type)){
        $$->type = $2->type;
    }
    else{
        $$->type = TYPE_ERROR;
        yyerror("Cannot cast " + $4->type + " to " + $2->type);
    }

    //3ac
    if($2->type!= $4->type){
        $$->addr = get_temp($2->type);
        emit($4->type + "TO" + $2->type , $4->addr, "", $$->addr);
    }
    else{
        $$->addr = $4->addr;
    }

    $$->first_instr = $4->first_instr;
    $$->last_instr = code.size()-1;
}

PostfixExpression:              Primary{
    $$ = $1;
}
|                               ExpressionName{
    $$ = makeleaf("ID(" + $1->lexeme + ")");
    if($1->type == TYPE_ERROR){
        yyerror("Undeclared variable " + $1->lexeme);
    }
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
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    //insertAttr(v, makeleaf("."), "", 1);
    insertAttr(v, makeleaf("ID(" + *$3 + ")"), "", 1);
    $$ = makenode("FieldAccess", v);

    /*type checking*/
    CREATE_ST_KEY(temp, $1->type);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *$3);
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            if(entry->mod_flag == PUBLIC_FLAG){
                $$->type = entry->type[0];
            }
            else{
                yyerror("Non-Public member " + *$3 + " of class " + $1->type + " cannot be accessed");
            }
        }
        else {
            yyerror("No member " + *$3 + " in class " + $1->type);
        }
        free(classTemp);
    }
    else{
        yyerror("No class " + $1->type + " found");
    } 
    free(temp);
}
;


Primary:    PrimaryNoNewArray{
    $$ = $1;
    // $$ = new treeNode;
    // flag_array=0;
    // cout<<"hey ";
    // cout<<"flag_array "<<flag_array<<endl;
    // cout<<$$->addr<< $1->lexeme + "[" + $1->addr + "]"<<endl;;

    if(flag_array){
        $$->addr = $1->lexeme + "[" + $1->addr + "]";
        // string id = $1->addr;
        // $$->addr = get_temp($1->type);
        // emit("", $1->lexeme + "["+ id + "]", "", $$->addr);
        flag_array = 0;
    }
    // $$->type= $1->type;

    
}
|           ArrayCreationExpr{
    $$ = $1;
}
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

    //type checking
    $$->type = $2->type;

    //3ac
    $$->addr = $2->addr;
    $$->first_instr = $2->first_instr;
    $$->last_instr = $2->last_instr;
}
|                   ArrayAccess{
                        $$ = $1;
}
|                   Meth_invoc{$$ = $1;}
|                   FieldAccess{$$ = $1;}
|                   KEY_NEW ID '(' ARG_LIST ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("PrimaryNoNewArray", v);

    // semantics
    CREATE_ST_KEY(temp, *$2);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        SymbolTable* classTable = entry->table;
        CREATE_ST_KEY(classTemp, *$2);
        auto it = classTable->table.find(*classTemp);
        if(it != classTable->table.end()){
            SymbTbl_entry* entry = it->second;
            if(compareMethTypes(entry->type, $4->typevec))
                $$->type = *$2;
            else{
                yyerror("Invalid argument list to contructor of class " + entry->lexeme);
            }
        }
        else {
            if($4->typevec.size()==0){
                // give a default constructor
                $$->type = *$2;
            }
            else{
                yyerror("No constructor found for class " + *$2);
            }
        }
        free(classTemp);
    }
    else{
        yyerror("No class " + *$2 + " found");
    } 
    free(temp);
}
;

ArrayCreationExpr:  KEY_NEW DTYPE DimExpr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);

    //type checking
    $$->type = $2->type + $3->type;
    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
}
|                   KEY_NEW ID DimExpr{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("new"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ArrayCreationExpr", v);

    //type checking
    CREATE_ST_KEY(temp, *$2);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* entry = lookup(temp);
    if(entry){
        $$->type = *$2 + $3->type;
    }
    else{
        yyerror("No class " + *$2 + " found");
    }
    $$->first_instr = $3->first_instr;
    $$->last_instr = $3->last_instr;
}
;

DimExpr:    '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);

    //type checking
    if(onlyIntCheck($2->type) == TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    $$->type = TYPE_ARRAY;

    $$->first_instr = $2->first_instr;
    $$->last_instr = $2->last_instr;

}
|           DimExpr '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("Dimensional Expression", v);

    //type checking
    if(onlyIntCheck($3->type) == TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    $$->type = $1->type + TYPE_ARRAY;
    $$->first_instr = $1->first_instr;
    $$->last_instr = $3->last_instr;
}
;

ArrayAccess:    ExpressionName '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + $1->lexeme + ")"), "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);

    /* type checking */
    arr_d = 1;
    if(onlyIntCheck($3->type)==TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    if($1->type.compare($1->type.size()-2, 2, TYPE_ARRAY)==0){
        $$->type = $1->type.substr(0, $1->type.size()-2);
        int width = 1;
        CREATE_ST_KEY(temp, $1->lexeme);
        SymbTbl_entry* entry = lookup(temp);
        string w = get_temp($1->type.substr(0, $1->type.size()-2));
        emit("*", $3->addr,to_string(Size[$1->type[0]]),w);
        for(int i=arr_d; i<entry->arr_dims.size(); i++){
            emit("*", entry->arr_dims[i], w, w);
        }
        $$->addr = w;
        $$->lexeme = $1->lexeme;
        $$->fin_flag = entry->fin_flag;
        $$->first_instr = $1->first_instr;
        
        if(arr_d==entry->arr_dims.size()){
            flag_array = 1;
            $$->last_instr = code.size()-1;
        }
    }
    else{
        yyerror("Cannot access array of type " + $$->type);
    }
}
|               PrimaryNoNewArray '[' Expr ']'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("["), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, makeleaf("]"), "", 1);
    $$ = makenode("ArrayAccess", v);

    /* type checking */
    if(onlyIntCheck($3->type)==TYPE_ERROR){
        yyerror("Array index must be of type int");
    }
    if($1->type.compare($1->type.size()-2, 2, TYPE_ARRAY)==0){
        arr_d++;
        int width = 1;
        CREATE_ST_KEY(temp, $1->lexeme);
        SymbTbl_entry* entry = lookup(temp);
        string w=get_temp($1->type.substr(0, $1->type.size()-2));
        emit("*", $3->addr,to_string(Size[$1->type[0]]),w);

        for(int i=arr_d; i<entry->arr_dims.size(); i++){
            emit("*", entry->arr_dims[i], w, w);
        }
        $$->type = $1->type.substr(0, $1->type.size()-2);
        $$->addr = w;
        $$->fin_flag = entry->fin_flag;
        $$->lexeme = $1->lexeme;
        emit("+", $1->addr, w, $$->addr);
        
        if(arr_d==entry->arr_dims.size()){
            flag_array = 1;
            $$->last_instr = code.size()-1;
        }
        
    }
    else{
        yyerror("Cannot access array of type " + $$->type);
    }

}
;

PostIncrementExpression:        PostfixExpression INCREMENT{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("++", v);
    
    //type checking
    if(isNum($1->type)){
        $$->type = $1->type;

    }
    else{
        yyerror("Cannot increment non-numeric type");
    }

    //3ac
    $$->addr = get_temp($1->type);
    emit("", $1->addr, "", $$->addr);
    emit("+", $1->addr, "1", $1->addr);

    $$->first_instr = $1->first_instr;
    $$->last_instr = code.size()-1;

}
;

PostDecrementExpression:        PostfixExpression DECREMENT {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("--", v);
    
    //type checking
    if(isNum($1->type)){
        $$->type = $1->type;

    }
    else{
        yyerror("Cannot decrement non-numeric type");
    }

    //3ac
    $$->addr = get_temp($1->type);
    emit("", $1->addr, "", $$->addr);
    emit("-", $1->addr, "1", $1->addr);
    $$->first_instr = $1->first_instr;
    $$->last_instr = code.size()-1;
}
;



EMP_EXPR:   Expr{
    $$ = $1;
    $$->first_instr = $1->first_instr;
    $$->last_instr = $1->last_instr;
}
| %empty{
    $$ = new treeNode;
    $$->type = TYPE_VOID;
    $$->first_instr = code.size();
    $$->last_instr = code.size();
    $$->addr = "";
}
;

ARG_LIST: ARG_LISTp {$$ = $1;}
| %empty{
    $$ = new treeNode;
}
;

ARG_LISTp:   ARG_LISTp ',' Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Argument List", v);
    free($$);
    // type checking
    $$ = $1;
    $$->typevec.push_back($3->type);
    $$->arg_addr.push_back($3->addr);
    // emit("param", $3->addr, "", "");
}
|           Expr{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    $$ = makenode("Argument List", v);

    // type checking
    $$->typevec.push_back($1->type);
    $$->arg_addr.push_back($1->addr);
    // emit("param", $1->addr, "", "");
}
;

LIT:    INT{
    string s = "INT(" + *$1 + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_INT;

    //3ac
    $$->addr = *$1;
}
|       FLOAT{
    string s = "FLOAT(" + *$1 + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_FLOAT;

    //3ac
    $$->addr = *$1;
}
|       CHAR{
    string temp = *$1;
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "CHAR(" + temp + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_CHAR;

    //3ac
    $$->addr = *$1;
}
|       STRING{
    string temp = *$1;
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);
    string s = "STRING(" + temp + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_STRING;

    //3ac
    $$->addr = *$1;
}
|       BOOL{
    string s = "BOOL(" + *$1 + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_BOOL;
    $$->addr = *$1;
}
|       LONG{
    string s = "LONG(" + *$1 + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_LONG;
    $$->addr = *$1;
}
|       DOUBLE{
    string s = "DOUBLE(" + *$1 + ")";
    $$ = makeleaf(s);
    $$->type = TYPE_DOUBLE;
    $$->addr = *$1;
}
;


STAT:   KEY_STATIC{
    $$ = makeleaf("static");
    stat_flag = 1;
}
|       %empty{
    $$ = NULL;
    stat_flag = 0;
}
;

FIN:   KEY_FINAL{
    $$ = makeleaf("final");
    fin_flag = 1;
}
|       %empty{
    $$ = NULL;
    fin_flag = 0;
}


DTYPE:  KEY_INT{
    $$ = makeleaf("int");
    dType = TYPE_INT;
    $$->type = dType;
}
|       KEY_BOOL{
    $$ = makeleaf("bool");
    dType = TYPE_BOOL;
    $$->type = dType;
}
|       KEY_DOUBLE{
    $$ = makeleaf("double");
    dType = TYPE_DOUBLE;
    $$->type = dType;
}
|       KEY_FLOAT{
    $$ = makeleaf("float");
    dType = TYPE_FLOAT;
    $$->type = dType;
}
|       KEY_LONG{
    $$ = makeleaf("long");
    dType = TYPE_LONG;
    $$->type = dType;
}
|       KEY_CHAR{
    $$ = makeleaf("char");
    dType = TYPE_CHAR;
    $$->type = dType;
}
|       KEY_STRING{
    $$ = makeleaf("string");
    dType = TYPE_STRING;
    $$->type = dType;
}
|       KEY_SHORT{
    $$ = makeleaf("short");
    dType = TYPE_SHORT;
    $$->type = dType;
}
;


ClassDeclaration: MOD_EMPTY_LIST KEY_CLASS ID{CREATE_ST_KEY(temp,*$3);temp->type.push_back(TYPE_CLASS); CREATE_ST_ENTRY(temp_entry, "ID", *$3, yylineno, 0); temp_entry->type.push_back(TYPE_CLASS); if(insert_symtbl(temp,temp_entry ) == ALREADY_EXIST) yyerror("Class " + *$3 + " Already Exist!") ;create_symtbl(); temp_entry->table = current; free(temp); stat_flag = 0;} Class_body {
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("class"), "", 1);
    insertAttr(v, makeleaf("ID(" + *$3 + ")"), "", 1);
    insertAttr(v, $5, "", 1);
    $$ = makenode("ClassDeclaration", v);

    //end scope
    current = current->parent;
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
|                    STAT { stat_flag = 0;} BLCK{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ClassBody Declaration", v);
    is_stat_scope = 0;
}
|                   ConstructorDeclaration{$$ = $1;}
;

Class_DEF_VAR:  MOD_EMPTY_LIST DTYPE VAR_LIST ';'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("ClassVariableDeclaration", v);

    stat_flag = 0;
    mod_flag = PRIVATE_FLAG;
}
;
MethodDeclaration: MOD_EMPTY_LIST Meth_Head Meth_Body{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("MethodDeclaration", v);

    if(!flag_return){
        yywarn("No return statement in function ");
        emit("RET","","","");
    }
    flag_return = 0;
    is_stat_scope = 0;
}
;

Meth_Body:   BLCK{
    $$ = $1;
}
|           ';'{
    $$ = NULL;
    *ptr_func_def = false;
    ptr_func_def = NULL;

    //sematics
    methKeys.clear();
    stat_flag = 0;
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
|           KEY_VOID{dType = TYPE_VOID;} DIMS Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $3, "", 1);
    insertAttr(v, $4, "", 1);
    $$ = makenode("Method Header", v);
}
|           DTYPE Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("Method Header", v);
}
|           KEY_VOID{dType = TYPE_VOID;} Meth_decl{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("void"), "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("Method Header", v);
}
;


Meth_decl:  ID '('{retType = dType;} Param_list ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("Method Declaration", v);

    //sematics
    CREATE_ST_KEY(temp, *$1);
    CREATE_ST_ENTRY(temp_entry, "ID", *$1, yylineno, mod_flag);
    for(auto p:methKeys){
        temp_entry->type.push_back(p->type[0]);
    }
    temp_entry->type.push_back(retType);
    temp_entry->is_func = true;
    temp_entry->stat_flag = stat_flag;
    ptr_func_def = &(temp_entry->func_is_defined);
    temp_entry->func_entry_addr = code.size();
    if(insert_symtbl(temp, temp_entry) == ALREADY_EXIST){
        SymbTbl_entry* __temp = lookup(temp);
        if(__temp->func_is_defined){
            yyerror("Redeclaration of function " + *$1);
        }
        __temp->func_entry_addr = code.size();
        ptr_func_def = &(__temp->func_is_defined);
    }
    if(stat_flag == 1)
        is_stat_scope = 1;
    stat_flag = 0;
}
|           ID '('{retType = dType;} ')'{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("ID(" + *$1 + ")"), "", 1);
    insertAttr(v, NULL, "( )", 0);
    $$ = makenode("Method Declaration", v);

    //sematics
    CREATE_ST_KEY(temp, *$1);
    CREATE_ST_ENTRY(temp_entry, "ID", *$1, yylineno, mod_flag);
    temp_entry->type.push_back(dType);
    ptr_func_def = &(temp_entry->func_is_defined);
    if(insert_symtbl(temp, temp_entry) == ALREADY_EXIST){
        SymbTbl_entry* __temp = lookup(temp);
        if(__temp->func_is_defined){
            yyerror("Redeclaration of function " + *$1);
        }
        ptr_func_def = &(__temp->func_is_defined);
    }
    if(stat_flag == 1)
        is_stat_scope = 1;
    stat_flag = 0;
}
;

Param_list: Param_list ',' Param{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $3, "", 1);
    $$ = makenode("parameter list", v);

    // sematics
    CREATE_ST_ENTRY(temp_entry,"ID", $3->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $3->dim));
    
    methKeys.push_back(temp_entry);
}
|           Param{
    $$ = $1;

    // sematics
    CREATE_ST_ENTRY(temp_entry,"ID", $1->lexeme, yylineno, mod_flag);
    temp_entry->type.push_back(get_type(dType, $1->dim));
    temp_entry->arr_dims = $1->arr_dims;

        
    methKeys.push_back(temp_entry);

    
}
;

Param:  DTYPE VAR{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("parameter", v);
    $$->lexeme = $2->lexeme;
    $$->dim = $2->dim;
    $$->arr_dims = $2->arr_dims;
}
;

MOD_EMPTY_LIST: MOD_LIST{
    $$ = $1;
}
|               %empty{
    $$ = NULL;
    mod_flag = 0;
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

    mod_flag = PRIVATE_FLAG;
}
|       KEY_PUBLIC{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("public"), "", 1);
    $$ = makenode("modifier", v);

    mod_flag = PUBLIC_FLAG;
}
|       KEY_STATIC{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("static"), "", 1);
    $$ = makenode("modifier", v);

    stat_flag = 1;
}
|      KEY_PROTECTED{
    vector<treeNode*> v;
    insertAttr(v, makeleaf("protected"), "", 1);
    $$ = makenode("modifier", v);

    mod_flag = PROTECTED_FLAG;
}
;

ConstructorHead:    MOD_EMPTY_LIST ID  '('  Param_list ')'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    insertAttr(v, NULL, "(", 0);
    insertAttr(v, $4, "", 1);
    insertAttr(v, NULL, ")", 0);
    $$ = makenode("construtorhead", v);

    //sematics
    CREATE_ST_KEY(temp, *$2);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* temp_entry;
    temp_entry = lookup(temp);
    if(temp_entry->table == current && *$2 == temp_entry->lexeme){
        // correct constructor declaration.
        // create a new entry in the symbol table for class.
        CREATE_ST_KEY(temp_construct, *$2);
        CREATE_ST_ENTRY(temp_centry, "ID", *$2, yylineno, PUBLIC_FLAG);
        temp_centry->is_func = true;
        for(auto p:methKeys){
            temp->type.push_back(p->type[0]);
        }
        temp->type.push_back(TYPE_NORET);
        if(insert_symtbl(temp_construct, temp_centry)==ALREADY_EXIST){
            yyerror("Constructor already declared in class " + *$2);
        }
        free(temp_construct);
        
    }
    else{
        yyerror("No return type for the function " + *$2 );
    }
    free(temp);
    if(stat_flag)
    is_stat_scope = 1;
    stat_flag = 0;
    
}
|                   MOD_EMPTY_LIST ID '(' ')'{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, makeleaf("ID(" + *$2 + ")"), "", 1);
    $$ = makenode("construtorhead", v);

    //sematics
    CREATE_ST_KEY(temp, *$2);
    temp->type.push_back(TYPE_CLASS);
    SymbTbl_entry* temp_entry;
    temp_entry = lookup(temp);
    if(temp_entry->table == current && *$2 == temp_entry->lexeme){
        // correct constructor declaration.
        // create a new entry in the symbol table for class.
        CREATE_ST_KEY(temp_construct, *$2);
        CREATE_ST_ENTRY(temp_centry, "ID", *$2, yylineno, PUBLIC_FLAG);
        temp_centry->is_func = true;
        temp->type.push_back(TYPE_NORET);
        if(insert_symtbl(temp_construct, temp_centry)==ALREADY_EXIST){
            yyerror("Constructor already declared in class " + *$2);
        }
        free(temp_construct);
    }
    else{
        yyerror("No return type for the function " + *$2 );
    }
    free(temp);
    retType = TYPE_NORET;
    if(stat_flag)
    is_stat_scope = 1;
    stat_flag = 0;

}
;

ConstructorDeclaration : ConstructorHead BLCK{
    vector<treeNode*> v;
    insertAttr(v, $1, "", 1);
    insertAttr(v, $2, "", 1);
    $$ = makenode("construtor", v);
    is_stat_scope = 0;

}
;

%%


int main(int argc, char** argv) {
    if(argc < 2){
        cout << "Usage: " << argv[0] << " <input file> [--input=<input file>] [--output=<output file>] [--verbose] [--help]" << endl;
        return 0;
    }
    char* infile = argv[1];
    char* dotfile_path = NULL;
    bool verbose = false;
    for(int i=1;i<argc;i++){
        
        /* cout<<i<<endl; */
        /* if argv contains --input= take it as input file */
        if(strncmp(argv[i], "--input=", 8) == 0){
            infile = argv[i] + 8;
        }
        /* if argv contains --output= take it as output file */
        else if(strncmp(argv[i], "--dot=", 6) == 0){
            dotfile_path = argv[i] + 6;
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
            cout << "  --dot=FILE\t\tWrite AST output to FILE" << endl;
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
    if(dotfile_path)
    dotfile = fopen(dotfile_path, "w");
    else
    dotfile = NULL;

    /* start parsing */
    if(verbose){
        cout<<"Started Parsing"<<endl;
    }
    beginAST();
    initSymbolTable();
    do {
        yyparse();
    } while (!feof(yyin));
    endAST();
    printSymbolTable(current);
    print_code();
    if(verbose){
        cout<<"Parsing Complete"<<endl;
        cout<<"Output written to "<<dotfile_path<<endl;
    }
    if(dotfile)
    fclose(dotfile);

    return 0;
}