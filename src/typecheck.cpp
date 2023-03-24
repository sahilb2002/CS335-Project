#include<symbol_table.h>
#include<typecheck.h>
#include<iostream>

using namespace std;

extern void yyerror(string s);

string maxType(string& type1, string& type2){
    if(type1 == TYPE_ERROR || type2 == TYPE_ERROR)
        return TYPE_ERROR;
    if(type1==type2)
        return type1;
    if(type1 == TYPE_DOUBLE || type2 == TYPE_DOUBLE)
        return TYPE_DOUBLE;
    else if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT)
        return TYPE_FLOAT;
    else if(type1 == TYPE_LONG || type2 == TYPE_LONG)
        return TYPE_LONG;
    else if(type1 == TYPE_INT || type2 == TYPE_INT)
        return TYPE_INT;
    else if(type1 == TYPE_SHORT || type2 == TYPE_SHORT)
        return TYPE_SHORT;
    else if(type1 == TYPE_CHAR || type2 == TYPE_CHAR)
        return TYPE_CHAR;
    else if(type1 == TYPE_BOOL || type2 == TYPE_BOOL)
        return TYPE_BOOL;
    else
        return TYPE_ERROR;
}
string addCheck(string& type1, string& type2,string op){
    if(isNum(type1) && isNum(type2))
        return maxType(type1, type2);
    if(isNum(type1) && type2 == TYPE_STRING)return TYPE_STRING;
    if(isNum(type2) && type1 == TYPE_STRING)return TYPE_STRING;
    if(type1 == TYPE_STRING && type2 == TYPE_STRING)
        return TYPE_STRING;
    yyerror("Invalid operands for operator " + op);
    return "";

}

string multCheck(string& type1, string& type2,string op){
    return addCheck(type1, type2, op);
    return maxType(type1, type2);
}

string relCheck(string& type1, string& type2){
    if(isNum(type1) && isNum(type2))
        return TYPE_BOOL;
    yyerror("TypeError: Relational operator can only be applied to numeric types");
    return "";
}

string onlyIntCheck(string& type){
    if(type == TYPE_INT || type == TYPE_BOOL || type == TYPE_CHAR || type == TYPE_LONG || type == TYPE_SHORT)
        return type;
    else return TYPE_ERROR;
}

string onlyIntCheck(string& type1, string& type2, string op){
    if(onlyIntCheck(type1)!=TYPE_ERROR && onlyIntCheck(type2)!=TYPE_ERROR)
        return maxType(type1, type2);
    yyerror("TypeError: Invalid operand types for operator "+op);
    return "";
}

int isNum(string& type){
    if(type == TYPE_INT || type == TYPE_CHAR || type == TYPE_LONG || type == TYPE_FLOAT || type == TYPE_DOUBLE || type == TYPE_BOOL || type == TYPE_SHORT)
        return 1;
    else return 0;
}

bool can_be_TypeCasted(string& from, string to ){
    if(isNum(from) && isNum(to))
        return true;
    if(from == to)
        return true;
    return false;
}

bool compareMethTypes(vector<string>& type_def, vector<string>& type_invoc){
    if(type_invoc.size() != type_def.size()-1)
        return false;
    for(int i=0;i<type_invoc.size();i++){
        if(!can_be_TypeCasted(type_invoc[i], type_def[i]))
            return false;
    }
    return true;
    
}
