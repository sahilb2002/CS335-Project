#ifndef TYPECHECK_H
#define TYPECHECK_H

#include <vector>
#include <string>
#include <map>

int maxType(int type1, int type2);
int addCheck(int type1, int type2);
int multCheck(int type1, int type2);
int relCheck(int type1, int type2);
int onlyIntCheck(int type);
int onlyIntCheck(int type1, int type2, string op);
int isNum(int type);


#endif