%{
    #include<iostream>
    #include<map>
    #include<vector>
    #include<fstream>
    #include<string>
    #include "../parser/parse.tab.c"

    using namespace std;
    //vector<string> names{"NULL", "Error", "Operator", "Separator", "Identifier", "Keyword", "String Literal", "Literal", "Comment", "EOFError"};

%}

%option yylineno

DIGIT [0-9]
HEX_DIGIT [0-9a-fA-F]
BINARY [01]
OCTAL_DIGIT [0-7]



OPERATOR ">"|"<"|"=="|">="|"<="|"!="|"&&"|"||"|"+"|"-"|"*"|"/"|"&"|"|"|"^"|"%"|"<<"|">>"|">>>"
UNINARYOPERATOR "+"|"-"|"!"|"~"
INCDEC "++"|"--"
ASSIGNOPERATOR "+="|"-="|"*="|"/="|"&="|"|="|"^="|"%="|"<<="|">>="|">>>="

/*INTEGER*/
HEX_NUM 0[xX]{HEX_DIGIT}+({HEX_DIGIT}|_)*{HEX_DIGIT}+
BINARY_NUM 0[bB]{BINARY}+({BINARY}|_)*{BINARY}*
OCTAL_NUM 0{OCTAL_DIGIT}+({OCTAL_DIGIT}|_)*{OCTAL_DIGIT}+
INTEGER {DIGIT}|[1-9]({DIGIT}|_)*{DIGIT}+



/*String*/
BOOLEAN true|false
ESCAPE_SEQUENCE \b|\s|\t|\n|\f|\r|\"|\'|\\

%x COMMENT
%x TEXTBLOCK


%%
[ \t\n\f\r] ;

"System.out.println" return KEY_PRINT;

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
"new" return KEY_NEW;
"private" return KEY_PRIVATE;
"public" return KEY_PUBLIC;
"return" return KEY_RETURN;
"static" return KEY_STATIC;
"class" return KEY_CLASS;
"const" return KEY_CONST;
"System" return KEY_SYSTEM;
"out" return KEY_OUT;
"NULL" return KEY_NULL;
"var" return KEY_VAR;
"break" return KEY_BREAK;
"continue" return KEY_CONTINUE;

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


{INCDEC} return INC_DEC;
{UNINARYOPERATOR} return UNR_OP;
{OPERATOR} return BIN_OP;
{ASSIGNOPERATOR} return ASSIGN_OP;


%%

int yywrap(){
    return 1;
}
int main(){
    // int ntoken, vtoken;
    // ntoken = yylex();
    // vector<string> tokens;
    // map<string, pair<string, int>> token_map;
    // fstream fout;
    // fout.open("output.csv", ios::out);
    // while(ntoken){
    //     //printf("%d %s\n", ntoken, yytext);
    //     if(names[ntoken] == "Error"){ 
    //         //perror("Unexpected character Found");
    //         cout<<"Error at line "<<yylineno<<" illegal character "<<yytext<<" found"<<endl;

    //     }
    //     else {
    //         if(names[ntoken] == "EOFError"){
    //             cout<<"Error at line "<<yylineno<<" unexpected end of file, missing \"\"\"."<<endl;
    //             break;
    //         }
    //         else{
    //             if(ntoken!=8){
    //                 if(token_map.find(yytext) == token_map.end()){
    //                     tokens.push_back(yytext);
    //                     token_map[yytext] = make_pair(names[ntoken], 1);
    //                 }
    //             else token_map[yytext].second++;
    //             }
    //         }
    //     }
    //     ntoken = yylex();
    // }
    // fout<<"Lexeme"<<","<<"Token"<<","<<"Count"<<"\n";
    // for(auto i: tokens){
    //     // if(i=="," | i==";"){
    //     //     fout<<"\""<<i<<"\""<<","<<token_map[i].first<<","<<token_map[i].second<<"\n";
    //     //     continue;
    //     // }
    //     fout<<i<<","<<token_map[i].first<<","<<token_map[i].second<<"\n";
    // }
    
    // fout.close();
    return 0;
}