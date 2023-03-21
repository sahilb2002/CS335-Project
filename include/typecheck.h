#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <vector>
#include <string>
#include <map>

string maxType(string type1, string type2);
string addCheck(string type1, string type2);
string multCheck(string type1, string type2);
string relCheck(string type1, string type2);
string onlyIntCheck(string type);
string onlyIntCheck(string type1, string type2, string op);
int isNum(string type);


#endif