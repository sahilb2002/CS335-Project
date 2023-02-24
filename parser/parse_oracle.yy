%{

    #include<iostream>
    using namespace std;   
%}

%union{
    int num;
    char chr;
    char* str;
}

%token<str> INCREMENT           // ++
%token<str> DECREMENT           // --
%token<str> DOUBLE_COLON        // ::
%token<str> LOG_OR              // ||
%token<str> LOG_AND             // &&
%token<str> EQUAL               // ==
%token<str> NOT_EQUAL           // ==
%token<str> GTR_EQUAL           // <=
%token<str> LESS_EQUAL          // >=
%token<str> LEFT_SHIFT          // <<
%token<str> RIGHT_SHIFT         // >>
%token<str> SIGN_SHIFT          // >>>
%token<str> ASSIGN_OP          // +=
%token<str> TRIPLE_DOT          // ...
%token<str> Identifier
%token<str> INT
%token<str> FLOAT
/* %token<str> DOUBLE */
%token<str> CHAR
%token<str> STRING
%token<str> BOOL
/* %token<str> LONG */
%token<str> TEXTBLOCK
%token<str> TypeIdentifier

%token<str> KEY_STATIC
%token<str> KEY_RETURN
%token<str> KEY_NEW
%token<str> KEY_THIS
%token<str> KEY_SUPER
%token<str> KEY_THROWS
%token<str> KEY_INSTANCEOF

%token<str> KEY_INT
%token<str> KEY_BYTE
%token<str> KEY_SHORT
%token<str> KEY_FLOAT
%token<str> KEY_LONG
%token<str> KEY_DOUBLE
%token<str> KEY_BOOL
%token<str> KEY_CHAR
/* %token<str> KEY_STRING */
%token<str> KEY_VOID
%token<str> KEY_VAR


%token<str> KEY_FOR
%token<str> KEY_WHILE
%token<str> KEY_IF
%token<str> KEY_ELSE
%token<str> KEY_FINAL

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_CLASS

/* %token<str> KEY_CONST */
%token<str> KEY_NULL

%token<str> KEY_BREAK
%token<str> KEY_CONTINUE

%left '+' '-' '*' '/' '%' 
%left LEFT_SHIFT RIGHT_SHIFT SIGN_SHIFT
%nonassoc '<' '>' GTR_EQUAL LESS_EQUAL




/* %right UNR_OP */
/* %right ASSIGN_OP */
/* %right '=' */
/* %left BIN_OP */
/* %left '?' */
/* %left ':' */
/* %left INC_DEC */
/* %right KEY_ELSE */

%%
START: ClassDeclaration;



IntegralType:   KEY_INT
|               KEY_BYTE
|               KEY_SHORT
|               KEY_LONG
|               KEY_CHAR
;

FloatingPointType:  KEY_FLOAT
|                   KEY_DOUBLE
;

NumericType:    IntegralType
|               FloatingPointType
;


PrimitiveType:  NumericType
|               KEY_BOOL


ReferenceType:  ClassType
|               ArrayType
|               TypeVariable
;



ClassType:  TypeIdentifier 
|           ClassType'.' TypeIdentifier 
;

TypeVariable:  TypeIdentifier
;

ArrayType:      PrimitiveType Dims
|               ClassType Dims
|               TypeVariable Dims
;

Dims:            %empty
|               Dim Dim
|               Dim Dim Dim
|               Dim
;

Dim:            '[' ']'

TypeParameter: TypeIdentifier
;




ClassModifier:      KEY_PUBLIC
|                   KEY_PRIVATE
|                   KEY_STATIC
;

ClassBody :     '{' ClassBodyDeclaration_c '}'
;

ClassBodyDeclaration_c: ClassBodyDeclaration_c ClassBodyDeclaration
|                       ClassBodyDeclaration
;

ClassBodyDeclaration:   ClassMemberDeclaration
|                       StaticInitializer
|                       ConstructorDeclaration
|                       InstanceInitializer
;

ClassMemberDeclaration: FieldDeclaration
|                       MethodDeclaration
|                       ClassDeclaration
|                       ';'
;

FieldDeclaration:   FieldModifier_c UnannType VariableDeclaratorList ';'
|                   UnannType VariableDeclaratorList ';'    
;

FieldModifier_c:    FieldModifier_c FieldModifier
|                   FieldModifier
;

FieldModifier:  KEY_PUBLIC
|               KEY_PRIVATE
|               KEY_STATIC
;

UnannType:  UnannPrimitiveType
|           UnannReferenceType
;

UnannPrimitiveType: NumericType
|                   KEY_BOOL
;

UnannReferenceType: UnannClassOrInterfaceType
|                   UnannArrayType
|                   UnannTypeVariable
;

UnannClassOrInterfaceType:  UnannClassType
|                           UnannInterfaceType
|                           UnannTypeVariable
;

UnannClassType:   UnannClassOrInterfaceType '.' TypeIdentifier 
;

UnannInterfaceType: UnannClassType
|                   UnannTypeVariable
;

UnannTypeVariable:  TypeIdentifier
;

UnannArrayType: UnannPrimitiveType Dims
|               UnannClassOrInterfaceType Dims
|               UnannTypeVariable Dims
;

MethodDeclaration:  MethodModifier_c MethodHeader MethodBody
|                   MethodHeader MethodBody
;

MethodModifier_c:   MethodModifier_c MethodModifier
|                   MethodModifier
;

MethodModifier: KEY_PUBLIC
|               KEY_PRIVATE
|               KEY_STATIC
;

MethodHeader:   Result MethodDeclarator Throws_b
;

Result:         UnannType
|               KEY_VOID
;

MethodDeclarator:   Identifier '('ReceiverParameter_b FormalParameterList_b ')' Dims
;


ReceiverParameter_b:    ReceiverParameter ','
|                       %empty
;

ReceiverParameter:  UnannType Identifier_b KEY_THIS
;

Identifier_b:   Identifier '.'
|               %empty
;

FormalParameterList_b:  FormalParameterList 
|                       %empty
;

FormalParameterList:    FormalParameter FormalParameter_c
;

FormalParameter_c:  FormalParameter_c ',' FormalParameter
|                   %empty
;

FormalParameter:    UnannType VariableDeclaratorId
|                   VariableArityParameter
;

VariableArityParameter:  UnannType TRIPLE_DOT Identifier
|                        KEY_FINAL UnannType TRIPLE_DOT Identifier
;

Throws_b:   Throws
|           %empty
;

Throws:     KEY_THROWS ExceptionTypeList
;

ExceptionTypeList:  ExceptionType ExceptionType_c
;

ExceptionType_c:    ExceptionType_c ',' ExceptionType
|                   %empty
;

ExceptionType:  ClassType
|               TypeVariable
;

MethodBody:     Block
|               ';'

StaticInitializer:  KEY_STATIC Block
;

InstanceInitializer:    Block
;

ConstructorDeclaration: ConstructorModifier_c ConstructorDeclarator Throws_b ConstructorBody
|                       ConstructorDeclarator Throws_b ConstructorBody
;

ConstructorModifier_c:  ConstructorModifier_c ConstructorModifier
|                       ConstructorModifier
;

ConstructorModifier:    KEY_PUBLIC
|                       KEY_PRIVATE
;

ConstructorDeclarator:  SimpleTypeName '('ReceiverParameter_b FormalParameterList_b ')'
;

SimpleTypeName: TypeIdentifier
;

ConstructorBody:    '{' ExplicitConstructorInvocation_b BlockStatements_b '}'
;

ExplicitConstructorInvocation_b:    ExplicitConstructorInvocation
|                                   %empty
;

ExplicitConstructorInvocation:  KEY_THIS '('ArgumentList_b ')' ';'
|                               KEY_SUPER '('ArgumentList_b ')' ';'
|                               Primary '.' KEY_SUPER '('ArgumentList_b ')' ';'
|                               ExpressionName '.' KEY_SUPER '('ArgumentList_b ')' ';'
;

ArgumentList_b: ArgumentList
|               %empty
;

ArgumentList:   Expression Expression_c
;

Expression_c:   Expression_c ',' Expression
|               %empty
;

BlockStatements_b:  BlockStatements
|                   %empty
;







/*sahil*/
Block:  '{' BlockStatements '}'
|       '{' '}'
;
BlockStatements:    BlockStatements BlockStatement
|                   BlockStatement
;
BlockStatement: LocalClassOrInterfaceDeclaration
|               LocalVariableDeclarationStatement
|               Statement
;

LocalClassOrInterfaceDeclaration:   ClassDeclaration
;

ClassDeclaration:   NormalClassDeclaration
;

NormalClassDeclaration: ClassModifier_b KEY_CLASS TypeIdentifier ClassBody
|                       KEY_CLASS TypeIdentifier ClassBody
;
ClassModifier_b:    ClassModifier_b ClassModifier
|                   ClassModifier
;
LocalVariableDeclaration: LocalVariableType VariableDeclaratorList
;

LocalVariableType:  UnannType
|                   KEY_VAR
;

VariableDeclaratorList: VariableDeclaratorList ',' VariableDeclarator
|                       VariableDeclarator
;

VariableDeclarator: VariableDeclaratorId '=' VariableInitializer
|                   VariableDeclaratorId
;
VariableDeclaratorId:   Identifier
|                       Identifier Dims
;
VariableInitializer:    Expression
|                       ArrayInitializer
;

LocalVariableDeclarationStatement:  LocalVariableDeclaration ';'
;
Statement:      StatementWithoutTrailingSubstatement
|               IfThenStatement
|               IfThenElseStatement
|               WhileStatement
|               ForStatement
;
StatementNoShortIf: StatementWithoutTrailingSubstatement
|                   IfThenElseStatementNoShortIf
|                   WhileStatementNoShortIf
|                   ForStatementNoShortIf
;

StatementWithoutTrailingSubstatement:   Block
|                                       EmptyStatement
|                                       ExpressionStatement
|                                       BreakStatement
|                                       ContinueStatement
|                                       ReturnStatement
;

IfThenStatement:    KEY_IF '(' Expression ')' Statement
;

IfThenElseStatement:    KEY_IF '(' Expression ')' StatementNoShortIf KEY_ELSE Statement
;

IfThenElseStatementNoShortIf:   KEY_IF '(' Expression ')' StatementNoShortIf KEY_ELSE StatementNoShortIf
;

EmptyStatement: ';'

ExpressionStatement:    StatementExpression ';'

StatementExpression:    Assignment
|                       PreIncrementExpression
|                       PreDecrementExpression
|                       PostIncrementExpression
|                       PostDecrementExpression
|                       MethodInvocation
|                       ClassInstanceCreationExpression
;

WhileStatement: KEY_WHILE '(' Expression ')' Statement
;
WhileStatementNoShortIf:    KEY_WHILE '(' Expression ')' StatementNoShortIf
;

ForStatement:   BasicForStatement
;
ForStatementNoShortIf:  BasicForStatementNoShortIf
;

BasicForStatement:  KEY_FOR '(' ForInit_s ';' Expression_s ';' ForUpdate_s ')' Statement
;
Expression_s: Expression | %empty ;
ForInit_s: ForInit  | %empty ;
ForUpdate_s: ForUpdate | %empty ;

BasicForStatementNoShortIf: KEY_FOR '(' ForInit_s ';' Expression_s ';' ForUpdate_s ')' StatementNoShortIf

ForInit:    StatementExpressionList
|           LocalVariableDeclaration
;
ForUpdate:  StatementExpressionList
;
StatementExpressionList:    StatementExpressionList ',' StatementExpression 
|                           StatementExpression
;
BreakStatement: KEY_BREAK Identifier ';'
|               KEY_BREAK ';'
;
ContinueStatement:  KEY_CONTINUE Identifier ';'
|                   KEY_CONTINUE ';'
;
ReturnStatement:    KEY_RETURN Expression ';'
|                   KEY_RETURN ';'
;

ArrayInitializer:   '{' VariableInitializerList_s comma_s '}'
VariableInitializerList_s:  VariableInitializer 
|                           VariableInitializerList_s ',' VariableInitializer
|                           %empty
comma_s :                   ',' | %empty
;


TypeName:   TypeIdentifier
ExpressionName: Identifier
|               AmbiguousName '.' Identifier
;
MethodName: Identifier
;
AmbiguousName:  Identifier
|               AmbiguousName '.' Identifier
;





Primary:    PrimaryNoNewArray
|           ArrayCreationExpression
;

PrimaryNoNewArray:  Literal
|                   ClassLiteral
|                   KEY_THIS
|                   TypeName '.' KEY_THIS
|                   '(' Expression ')'
|                   ClassInstanceCreationExpression
|                   FieldAccess
|                   ArrayAccess
|                   MethodInvocation
|                   MethodReference
;

Literal:            INT
|                   FLOAT
|                   BOOL
|                   CHAR
|                   STRING
|                   TEXTBLOCK
|                   KEY_NULL
;

ClassLiteral:       TypeName Dims '.' KEY_CLASS
|                   NumericType Dims '.' KEY_CLASS
|                   KEY_BOOL Dims '.' KEY_CLASS
|                   KEY_VOID '.' KEY_CLASS
;

ClassInstanceCreationExpression:    UnqualifiedClassInstanceCreationExpression
|                                   ExpressionName '.' UnqualifiedClassInstanceCreationExpression
|                                   Primary '.' UnqualifiedClassInstanceCreationExpression
;

UnqualifiedClassInstanceCreationExpression:     KEY_NEW '(' ArgumentList_s ')' ClassBody_s
;

ArgumentList_s:    %empty
|                  ArgumentList
;

ClassBody_s:       %empty
|                  ClassBody
;

FieldAccess:       Primary '.' Identifier
|                  KEY_SUPER '.' Identifier
;

ArrayAccess:       ExpressionName Expression_s
|                  PrimaryNoNewArray Expression_s
;

MethodInvocation:   MethodName '(' ArgumentList_s ')'
|                   TypeName '.' Identifier '(' ArgumentList_s ')'
|                   ExpressionName '.' Identifier '(' ArgumentList_s ')'
|                   Primary '.' Identifier '(' ArgumentList_s ')'
|                   KEY_SUPER '.' Identifier '(' ArgumentList_s ')'
;

MethodReference:    ExpressionName DOUBLE_COLON Identifier
|                   Primary DOUBLE_COLON Identifier
|                   ReferenceType DOUBLE_COLON Identifier
|                   KEY_SUPER DOUBLE_COLON Identifier
|                   TypeName '.' KEY_SUPER DOUBLE_COLON Identifier
|                   ClassType DOUBLE_COLON KEY_NEW
|                   ArrayType DOUBLE_COLON KEY_NEW
;

ArrayCreationExpression:    KEY_NEW PrimitiveType DimExprs Dims
|                           KEY_NEW PrimitiveType Dims ArrayInitializer
;

DimExprs:   DimExprs DimExpr
|           DimExpr
;


DimExpr:    Expression_s
;

Expression: AssignmentExpression
;

AssignmentExpression: ConditionalExpression
|                     Assignment
;

Assignment: LeftHandSide AssignmentOperator Expression
;

AssignmentOperator: ASSIGN_OP
|                  '='
;

LeftHandSide:   ExpressionName
|               FieldAccess
|               ArrayAccess
;

ConditionalExpression:  ConditionalOrExpression
|                       ConditionalOrExpression '?' Expression ':' ConditionalExpression
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
|                           InstanceofExpression
;

InstanceofExpression:       RelationalExpression KEY_INSTANCEOF ReferenceType
|                           RelationalExpression KEY_INSTANCEOF Pattern
;

Pattern:                    TypePattern
;

TypePattern:                LocalVariableDeclaration
;

ShiftExpression:            AdditiveExpression
|                           ShiftExpression LEFT_SHIFT AdditiveExpression
|                           ShiftExpression RIGHT_SHIFT AdditiveExpression
|                           ShiftExpression SIGN_SHIFT AdditiveExpression
;

AdditiveExpression:         AdditiveExpression '+' MultiplicativeExpression 
|                           AdditiveExpression '-' MultiplicativeExpression 
|                           MultiplicativeExpression
;

MultiplicativeExpression:   MultiplicativeExpression '*' UnaryExpression 
|                           MultiplicativeExpression '/' UnaryExpression 
|                           MultiplicativeExpression '%' UnaryExpression 
|                           UnaryExpression
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

PostIncrementExpression:        PostfixExpression INCREMENT
;

PostDecrementExpression:        PostfixExpression DECREMENT
;

ConstantExpression:             Expression
;









%%
