#ifndef COMMON_H
#define COMMON_H

#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<iostream>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"

// Token IDs
#define OP 0
#define SEP 1
#define KEY 2
#define ID 3
#define STR 4
#define INT 5
#define BOOL 6
#define NULL_LIT 7
#define FP 8
#define CHAR 9
#define TB 10
#define ERR 11

// Error Codes
#define InvTxtBlk 0
#define InvChar 1
#define InvChrVar 2
#define InvInt 3
#define InvHexFloat 4
#define InvComm 5
#define InvEOF 6

// flex functions and variables used
extern "C" int yylex();
extern FILE* yyin;
extern int yylineno;
extern char* yytext;

// global variables
extern vector<string> tokens;
extern int ind;
extern int errcode;
extern string text;
extern map<string, vector<int>> csvmap;                            // (lexeme: {count, token_id, index})


void init();
int check_token(set<string> &keywords);
void add_lexeme(int tok);
void dump_data(char* file_name);

int __main(int argc, char** argv);
#endif