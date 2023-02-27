%{
    #include<iostream>
    #include<map>
    #include<vector>
    #include<fstream>
    #include<string>
    #include "../parser/parse.tab.h"

    using namespace std;
    //vector<string> names{"NULL", "Error", "Operator", "Separator", "Identifier", "Keyword", "String Literal", "Literal", "Comment", "EOFError"};

%}

%option yylineno

DIGIT [0-9]
HEX_DIGIT [0-9a-fA-F]
BINARY [01]
OCTAL_DIGIT [0-7]

/*INTEGER*/
HEX_NUM 0[xX]{HEX_DIGIT}+({HEX_DIGIT}|_)*{HEX_DIGIT}+
BINARY_NUM 0[bB]{BINARY}+({BINARY}|_)*{BINARY}*
OCTAL_NUM 0{OCTAL_DIGIT}+({OCTAL_DIGIT}|_)*{OCTAL_DIGIT}+
INTEGER {DIGIT}|[1-9]({DIGIT}|_)*{DIGIT}+

ASSIGNOPERATOR "+="|"-="|"*="|"/="|"&="|"|="|"^="|"%="|"<<="|">>="|">>>="

/*String*/
BOOLEAN true|false
ESCAPE_SEQUENCE "\\b"|"\\s"|"\\t"|"\\n"|"\\f"|"\\r"|"\\\""|"\\\'"|"\\\\"

%x COMMENT
%x TEXTBLOCK

/* "const" return KEY_CONST; */
/* "System" return KEY_SYSTEM; */
/* "new" return KEY_NEW; */
/* "out" return KEY_OUT; */
/* "NULL" return KEY_NULL; */
/* "var" return KEY_VAR; */
/* "System.out.println" return KEY_PRINT; */
/*"this" return KEY_THIS;*/
/*"import" return KEY_IMPORT;*/
/*"package" return KEY_PACKAGE;*/
/*"extends" return KEY_EXTENDS;*/
/*"implements" return KEY_IMPLEMENTS;*/
/*"interface" return KEY_INTERFACE;*/

%%
[ \t\n\f\r] ;


"for" return KEY_FOR;
"if" return KEY_IF;
"else" return KEY_ELSE;
"while" return KEY_WHILE;
"bool" return KEY_BOOL;
"double" return KEY_DOUBLE;
"void" return KEY_VOID;
"int" return KEY_INT;
"long" return KEY_LONG;
"char" return KEY_CHAR;
"string" return KEY_STRING;
"float" return KEY_FLOAT;
"private" return KEY_PRIVATE;
"public" return KEY_PUBLIC;
"return" return KEY_RETURN;
"static" return KEY_STATIC;
"class" return KEY_CLASS;
"break" return KEY_BREAK;
"continue" return KEY_CONTINUE;
"super" return KEY_SUPER;
"import" return KEY_IMPORT;




{BOOLEAN} return BOOL;



"/*" {
    yymore();
    BEGIN(COMMENT);
}
<COMMENT>\n|. { 
    yymore(); 
}
<COMMENT><<EOF>> {
    printf("Error: EOF in comment\n");
    exit(0);
}
<COMMENT>"*/" {
    BEGIN(INITIAL);
    ;
}
"//".* ;

\"\"\" {
    yymore();
    BEGIN(TEXTBLOCK);
}

<TEXTBLOCK>.|\n {
    yymore();
}
<TEXTBLOCK><<EOF>> {
    printf("Error: EOF in textblock\n");
    exit(0);
}
<TEXTBLOCK>\"\"\"  {
    // yymore();
    BEGIN(INITIAL);
    return STRING;
}

[a-zA-Z_][a-zA-Z_0-9]* return ID;

{INTEGER} return INT;
{INTEGER}[lL] return LONG;
{HEX_NUM} return INT;
{HEX_NUM}[lL] return LONG;
{BINARY_NUM} return INT;
{BINARY_NUM}[lL] return LONG;
{OCTAL_NUM} return INT;
{OCTAL_NUM}[lL] return LONG;


{DIGIT}*("."{DIGIT}+)?([eE][+-]?{DIGIT}+)?[fF]|{DIGIT}+("."{DIGIT}*)?([eE][+-]?{DIGIT}+)?[fF] return FLOAT;
{DIGIT}*("."{DIGIT}+)?([eE][+-]?{DIGIT}+)?[Dd]?|{DIGIT}+("."{DIGIT}*)?([eE][+-]?{DIGIT}+)?[Dd]? return DOUBLE;
{HEX_NUM}"."|{HEX_NUM}"."{HEX_NUM}[+-]?{HEX_NUM}[fF] return FLOAT;
{HEX_NUM}"."|{HEX_NUM}"."{HEX_NUM}[+-]?{HEX_NUM}[Dd]? return DOUBLE;

\'[^\'\\\n\r]\'|\'{ESCAPE_SEQUENCE}\' return CHAR;
\"[^\"\\\n\r]*\"|\"{ESCAPE_SEQUENCE}*\" return STRING;


"=" return '=';
"[" return '[';
"]" return ']';
"(" return '(';
")" return ')';
"{" return '{';
"}" return '}';
";" return ';';
"," return ',';
"?" return '?';
":" return ':';
"@" return '@';
"." return '.';
"|" return '|';
"&" return '&';
"^" return '^';
">" return '>';
"<" return '<';
"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"%" return '%';
"~" return '~';
"!" return '!';

"++"    return INCREMENT;
"--"    return DECREMENT;
"||"    return LOG_OR;
"&&"    return LOG_AND;
"=="    return EQUAL;
"!="    return NOT_EQUAL;
"<="    return GTR_EQUAL;
">="    return LESS_EQUAL;
"<<"    return LEFT_SHIFT;
">>"    return RIGHT_SHIFT;
">>>"   return SIGN_SHIFT;
{ASSIGNOPERATOR} return ASSIGN_OP;


%%

int yywrap(){
    return 1;
}