#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <vector>
#include <string>
#include <map>
using namespace std;


bool can_be_TypeCasted(string& from, string to );
bool compareMethTypes(vector<string>& type_def, vector<string>& type_invoc);
string maxType(string& type1, string& type2);
string addCheck(string& type1, string& type2, string op);
string multCheck(string& type1, string& type2, string op);
string relCheck(string& type1, string& type2);
string onlyIntCheck(string& type);
string onlyIntCheck(string& type1, string& type2, string op);
int isNum(string& type);


#endif