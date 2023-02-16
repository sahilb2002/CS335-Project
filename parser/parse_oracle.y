The syntax {x} on the right-hand side of a production denotes zero or more occurrences of x.
The syntax [x] on the right-hand side of a production denotes zero or one occurrences of x. 

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
%token<str> Identifier
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
%token<str> KEY_THIS
%token<str> KEY_SUPER

%token<str> KEY_INT
%token<str> KEY_BYTE
%token<str> KEY_SHORT
%token<str> KEY_FLOAT
%token<str> KEY_LONG
%token<str> KEY_DOUBLE
%token<str> KEY_BOOL
%token<str> KEY_CHAR
%token<str> KEY_STRING
%token<str> KEY_VOID
%token<str> KEY_VAR


%token<str> KEY_FOR
%token<str> KEY_WHILE
%token<str> KEY_IF
%token<str> KEY_ELSE

%token<str> KEY_PRIVATE
%token<str> KEY_PUBLIC
%token<str> KEY_CLASS

%token<str> KEY_CONST
%token<str> KEY_NULL

%token<str> KEY_BREAK
%token<str> KEY_CONTINUE




%right UNR_OP
%right ASSIGN_OP
%right '='
%left BIN_OP
%left '?'
%left ':'
%left INC_DEC
%right KEY_ELSE

%%
/*parth*/
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


ReferenceType:  ClassOrInterfaceType
|               ArrayType
|               TypeVariable
;

ClassOrInterfaceType:   ClassType
|                       InterfaceType
;

ClassType:  TypeIdentifier 
|           ClassOrInterfaceType'.' TypeIdentifier 
;



TypeIdentifier: Identifier

InterfaceType:  InterfaceType_b
;

InterfaceType_b:    InterfaceType_b '.' TypeIdentifier;

ArrayType:      PrimitiveType Dims
|               ClassOrInterfaceType Dims
|               TypeVariable Dims
;

Dims:            %empty
|                   '[' ']'
|                   '[' ']' '[' ']'
|                   '[' ']' '[' ']' '[' ']'
;

TypeVariable:   Identifier


ClassModifier:      KEY_PUBLIC
|                   KEY_PRIVATE
|                   KEY_STATIC
;

ClassBody :     '{' ClassBodyDeclaration_s '}'
;

ClassBodyDeclaration_s: ClassBodyDeclaration_s ClassBodyDeclaration
|                       ClassBodyDeclaration
|                       %empty
;

ClassBodyDeclaration:   ClassMemberDeclaration
|                       StaticInitializer
|                       ConstructorDeclaration
|                       InstanceInitializer
;

ClassMemberDeclaration: FieldDeclaration
|                       MethodDeclaration
|                       ClassDeclaration
|                       InterfaceDeclaration
|                       ';'
;

FieldDeclaration:   FieldModifier_b UnannType VariableDeclaratorList ';'
;

FieldModifier_b:    FieldModifier_b FieldModifier
|                   FieldModifier
|                   %empty
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
;

UnannClassType: UnannClassType_b
;

UnannClassType_b:   UnannClassType_b '.' TypeIdentifier
|                   TypeIdentifier 
;

UnannInterfaceType: UnannClassType
;

UnannTypeVariable:  TypeIdentifier
;

UnannArrayType: UnannPrimitiveType Dims
|               UnannClassOrInterfaceType Dims
|               UnannTypeVariable Dims
;

MethodDeclaration:  MethodModifier_b MethodHeader MethodBody
;

MethodModifier_b:   MethodModifier_b MethodModifier
|                   MethodModifier
|                   %empty
;

MethodModifier: KEY_PUBLIC
|               KEY_PRIVATE
|               KEY_STATIC
;

MethodHeader:   Result MethodDeclarator Throws_b
|               Result MethodDeclarator
;

Result:         UnannType
|               KEY_VOID
;

MethodDeclarator:   Identifier '('ReceiverParameter_b FormalParameterList_b ')' Dims_b
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

FormalParameterList:    FormalParameter FormalParameter_b
;

FormalParameter_b:  FormalParameter_b ',' FormalParameter
|                   %empty
;

FormalParameter:    UnannType VariableDeclaratorId
|                   VariableArityParameter
;

VariableArityParameter: UnannType '...' Identifier
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
;
ClassModifier_b:    ClassModifier_b ClassModifier
|                   ClassModifier
|                   %empty
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
VariableInitializerList_s: VariableInitializerList | %empty
comma_s :                   ',' | %empty
;
VariableInitializerList:    VariableInitializerList ',' VariableInitializer
|                           VariableInitializer
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





/* 
##########################

Yash's War Zone


########################## */


Primary:    PrimaryNoNewArray
|           ArrayCreationExpression
;

PrimaryNoNewArray:  Literal
|                   ClassLiteral
|                   this
|                   TypeName '.' this
|                   ( Expression )
|                   ClassInstanceCreationExpression
|                   FieldAccess
|                   ArrayAccess
|                   MethodInvocation
|                   MethodReference
;

ClassLiteral:       TypeName Dims '.' class
|                   NumericType Dims '.' class
|                   boolean Dims '.' class
|                   void '.' class
;

ClassInstanceCreationExpression:    UnqualifiedClassInstanceCreationExpression
|                                   ExpressionName '.' UnqualifiedClassInstanceCreationExpression
|                                   Primary '.' UnqualifiedClassInstanceCreationExpression
;

UnqualifiedClassInstanceCreationExpression:     new TypeArguments_s ClassOrInterfaceTypeToInstantiate '(' ArgumentList_s ')' ClassBody_s
;

TypeArguments_s:    %empty
|                   TypeArguments
;

ArgumentList_s:    %empty
|                  ArgumentList
;

ClassBody_s:       %empty
|                  ClassBody
;

FieldAccess:       Primary '.' Identifier
|                  super '.' Identifier
|                  TypeName '.' super '.' Identifier
;

ArrayAccess:       ExpressionName Expression_s
|                  PrimaryNoNewArray Expression_s
;

MethodInvocation:   MethodName '(' ArgumentList_s ')'
|                   TypeName '.' TypeArguments_s Identifier '(' ArgumentList_s ')'
|                   ExpressionName '.' TypeArguments_s Identifier '(' ArgumentList_s ')'
|                   Primary '.' TypeArguments_s Identifier '(' ArgumentList_s ')'
|                   super '.' TypeArguments_s Identifier '(' ArgumentList_s ')'
|                   TypeName '.' super '.' TypeArguments_s Identifier '(' ArgumentList_s ')'
;

ArgumentList:       Expression
|                   ArgumentList ',' Expression
;

MethodReference:    ExpressionName "::" TypeArguments_s Identifier
|                   Primary "::" TypeArguments_s Identifier
|                   ReferenceType "::" TypeArguments_s Identifier
|                   super "::" TypeArguments_s Identifier
|                   TypeName '.' super "::" TypeArguments_s Identifier
|                   ClassType "::" TypeArguments_s new
|                   ArrayType "::" new
;

ArrayCreationExpression:    new PrimitiveType DimExprs Dims
|                           new ClassOrInterfaceType DimExprs Dims
|                           new PrimitiveType Dims ArrayInitializer
|                           new ClassOrInterfaceType Dims ArrayInitializer
;

DimExprs:   DimExpr DimExprs_b
;

DimExprs_b:     %empty
|               DimExpr
|               DimExprs_b DimExpr
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

LeftHandSide:   ExpressionName
|               FieldAccess
|               ArrayAccess
;

ConditionalExpression:  ConditionalOrExpression
|                       ConditionalOrExpression '?' Expression ':' ConditionalExpression
;

ConditionalOrExpression:    ConditionalAndExpression
|                           ConditionalOrExpression "||" ConditionalAndExpression
;

ConditionalAndExpression:   InclusiveOrExpression
|                           ConditionalAndExpression "&&" InclusiveOrExpression
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
|                           EqualityExpression "==" RelationalExpression
|                           EqualityExpression != RelationalExpression
;

RelationalExpression:       ShiftExpression
|                           RelationalExpression '<' ShiftExpression
|                           RelationalExpression '>' ShiftExpression
|                           RelationalExpression "<=" ShiftExpression
|                           RelationalExpression ">=" ShiftExpression
|                           InstanceofExpression
;

InstanceofExpression:       RelationalExpression instanceof ReferenceType
|                           RelationalExpression instanceof Pattern
;

ShiftExpression:            AdditiveExpression
|                           ShiftExpression "<<" AdditiveExpression
|                           ShiftExpression ">>" AdditiveExpression
|                           ShiftExpression ">>>" AdditiveExpression
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

PreIncrementExpression:     "++" UnaryExpression
;

PreDecrementExpression:     "--" UnaryExpression
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

PostIncrementExpression:        PostfixExpression "++"
;

PostDecrementExpression:        PostfixExpression "--"
;

ConstantExpression:             Expression
;









%%
