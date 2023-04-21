%{
    #include<iostream>
    #include<vector>
    #include<fstream>
    #include<string>
    #include <AST.h>
    #include <parse.tab.h>

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
"short" return KEY_SHORT;
"String" return KEY_STRING;
"float" return KEY_FLOAT;
"private" return KEY_PRIVATE;
"public" return KEY_PUBLIC;
"return" return KEY_RETURN;
"static" return KEY_STATIC;
"protected" return KEY_PROTECTED;
"final" return KEY_FINAL;
"class" return KEY_CLASS;
"break" return KEY_BREAK;
"continue" return KEY_CONTINUE;
"import" return KEY_IMPORT;
"new" return KEY_NEW;
"switch" return KEY_SWITCH;
"case" return KEY_CASE;
"default" return KEY_DEFAULT;
"throw" return KEY_THROW;
"do" return KEY_DO;




{BOOLEAN} {yylval.str = new std::string(yytext); return BOOL;};;



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
    yylval.str = new std::string(yytext); 
    return STRING;
}

[a-zA-Z_][a-zA-Z_0-9]* {yylval.str = new std::string(yytext); return ID;};

{INTEGER} {yylval.str = new std::string(yytext); return INT;}
{INTEGER}[lL] {yylval.str = new std::string(yytext); return LONG;}
{HEX_NUM} {yylval.str = new std::string(yytext); return INT;}
{HEX_NUM}[lL] {yylval.str = new std::string(yytext); return LONG;}
{BINARY_NUM} {yylval.str = new std::string(yytext); return INT;}
{BINARY_NUM}[lL] {yylval.str = new std::string(yytext); return LONG;}
{OCTAL_NUM} {yylval.str = new std::string(yytext); return INT;}
{OCTAL_NUM}[lL] {yylval.str = new std::string(yytext); return LONG;}


{DIGIT}*("."{DIGIT}+)?([eE][+-]?{DIGIT}+)?[fF]|{DIGIT}+("."{DIGIT}*)?([eE][+-]?{DIGIT}+)?[fF] {yylval.str = new std::string(yytext); return FLOAT;}
{DIGIT}*("."{DIGIT}+)?([eE][+-]?{DIGIT}+)?[Dd]?|{DIGIT}+("."{DIGIT}*)?([eE][+-]?{DIGIT}+)?[Dd]? {yylval.str = new std::string(yytext); return DOUBLE;}
{HEX_NUM}"."|{HEX_NUM}"."{HEX_NUM}[+-]?{HEX_NUM}[fF] {yylval.str = new std::string(yytext); return FLOAT;}
{HEX_NUM}"."|{HEX_NUM}"."{HEX_NUM}[+-]?{HEX_NUM}[Dd]? {yylval.str = new std::string(yytext); return DOUBLE;}

\'[^\'\\\n\r]\'|\'{ESCAPE_SEQUENCE}\' {yylval.str = new std::string(yytext); return CHAR;}
\"[^\"\\\n\r]*\"|\"{ESCAPE_SEQUENCE}*\" {yylval.str = new std::string(yytext); return STRING;}


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
">="    return GTR_EQUAL;
"<="    return LESS_EQUAL;
"<<"    return LEFT_SHIFT;
">>"    return RIGHT_SHIFT;
">>>"   return SIGN_SHIFT;
"->"    return ARROW;
{ASSIGNOPERATOR} {yylval.str = new std::string(yytext); return ASSIGN_OP;}

. {
    cout<<"Invalid character in line: "<<yylineno<<endl;
    exit(0);
}
%%

int yywrap(){
    return 1;
}