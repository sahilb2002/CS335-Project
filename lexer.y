%{
    #include "common.h"
    using namespace std;
    bool content = false, error = false;

    set<string> java_keys = {
            "abstract"      ,"continue"     ,"for"              ,"new"          ,"switch",
            "assert"        ,"default"      ,"if"               ,"package"      ,"synchronized",
            "boolean"       ,"do"           ,"goto"             ,"private"      ,"this",
            "break"         ,"double"       ,"implements"       ,"protected"    ,"throw",
            "byte"          ,"else"         ,"import"           ,"public"       ,"throws",
            "case"          ,"enum"         ,"instanceof"       ,"return"       ,"transient",
            "catch"         ,"extends"      ,"int"              ,"short"        ,"try",
            "char"          ,"final"        ,"interface"        ,"static"       ,"void",
            "class"         ,"finally"      ,"long"             ,"strictfp"     ,"volatile",
            "const"         ,"float"        ,"native"           ,"super"        ,"while", "_",
            
            "exports"       ,"opens"        ,"requires"         ,"uses",
            "module"        ,"permits"      ,"sealed"           ,"var",
            "nonsealed"     ,"provides"     ,"to"               ,"with",
            "open"          ,"record"       ,"transitive"       ,"yield",
    };


%}


%option yylineno

/* Definations */
DGT [0-9]
xDGT [0-9a-fA-F]
LETTER [a-zA-Z_]
ID [a-zA-Z0-9_]
LT \n|\r|(\n\r)

/*Start conditions for comments & text blocks */
%x COMMENT
%x TEXTBLOCK


/* Rules */
%%




"/*" {
    BEGIN(COMMENT);                                           /* COMMENTS */
    // printf(" Comment");

}
<COMMENT>"*/" {
    BEGIN(INITIAL);
}
<COMMENT>.|{LT} {
   ;
}

<COMMENT><<EOF>> {
    errcode = InvComm;
    add_lexeme(ERR);
    yyterminate();
}
"//".* {
    // printf(" Comment");
}





[ \t\f]+                                                        /* LINE TERMINATORS */ 
{LT} {
    // printf("\n");
}





{LETTER}{ID}* {                                                 /*  IDENTIFIERS and KEYWORDS */
    add_lexeme(check_token(java_keys));
}





(([1-9]({DGT}|"_")*{DGT})|{DGT})("L"|"l")? {                    /* INTEGER LITERALS */
    // printf(" Integer_literal");
    add_lexeme(INT);
}
"0"[xX](({xDGT}({xDGT}|"_")*{xDGT})|{xDGT})("L"|"l")? {
    // printf(" Integer_literal");
    add_lexeme(INT);
}
"0"[bB](([01][01_]*[01])|[01])("L"|"l")? {
    // printf(" Integer_literal");
    add_lexeme(INT);
}
"0"(([0-7_]*[0-7])|[0-7])("L"|"l")? {
    // printf(" Integer_literal");
    add_lexeme(INT);
}


(({DGT}[0-9_]*"."[0-9_]*)|("."[0-9_]+))([eE][+-]?[0-9_])?[fFdD]? {      /* FLOATING POINT LITERALS */
    // printf(" Floating_point_literal");
    add_lexeme(FP);
}
{DGT}[0-9_]*(([eE][+-]?[0-9_])|[fFdD]) {
    add_lexeme(FP);
}
"0"[xX](({xDGT}({xDGT}|_)*("."({xDGT}|_)*)?)|("."{xDGT}({xDGT}|_)*))[pP][+-]?({xDGT}|_)*[fFdD]? {      
    // printf(" Floating_point_literal");
    add_lexeme(FP);
}
"0"[xX](({xDGT}({xDGT}|_)*("."({xDGT}|_)*)?)|("."{xDGT}({xDGT}|_)*))[fFdD]? {
    errcode = InvHexFloat;
    add_lexeme(ERR);
}






"'"."'" {                                                            /* CHARACTER LITERALS */
    // printf(" Character_literal");
    add_lexeme(CHAR);
}
\'.(.|\n)+"'" {                                                      
    // printf(" Error");
    errcode = InvChrVar;
    add_lexeme(ERR);
    
}


\"[^\"\\\n\r]*\" {                                                    /* STRING LITERALS */
    // printf(" String_literal");
    add_lexeme(STR);
}





\"\"\" {                                                            /* TEXT BLOCKS */
    BEGIN(TEXTBLOCK);
    yymore();
}
<TEXTBLOCK>\"\"\" {
    BEGIN(INITIAL);
    // text = text + "\"\"\"";
    if (error){
        // printf(" Error\n");
        errcode = InvTxtBlk;
        add_lexeme(ERR);
    }
    else
        // printf(" Text_block\n");
        add_lexeme(TB);

    content = false;
    error = false;
}
<TEXTBLOCK><<EOF>> {
    errcode = InvEOF;
    add_lexeme(ERR);
    yyterminate();
}
<TEXTBLOCK>.|[\n\r] {
    char c = yytext[yyleng-1];
    // text.push_back(c);
    yymore();
    if (content);
    else if (!error && (c == '\n' || c == '\r'))
        content = true;
    else if (c != ' ' && c != '\t' && c != '\f')
        error = true;
    
}





"("|")"|"{"|"}"|"["|"]"|";"|","|"."|"..."|"@"|"::" {            /* SEPERATORS & OPERATORS */
    // printf(" Seperator");
    add_lexeme(SEP);
}
"="|">"|"<"|"!"|"~"|"?"|":"|"->"|"=="|">="|"<="|"!="|"&&"|"||"|"++"|"--"|"+"|"-"|"*"|"/"|"&"|"|"|"^"|"%"|"<<"|">>"|">>>"|"+="|"-="|"*="|"/="|"&=""|="|"^="|"%="|"<<="|">>="|">>>=" {
    // printf(" Operator");
    add_lexeme(OP);
}


.|\n {
    errcode = InvChar;
    add_lexeme(ERR);
}
%%

int main( int argc, char** argv ){
    return __main(argc, argv);
}
