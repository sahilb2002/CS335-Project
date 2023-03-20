#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <vector>
#include <string>
#include <map>

#define ALREADY_EXIST -1
#define INSERT_SUCC 1

#define TYPE_CLASS 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_CHAR 3
#define TYPE_VOID 4
#define TYPE_BOOL 5
#define TYPE_STRING 6
#define TYPE_DOUBLE 7
#define TYPE_LONG 8

#define NUM_TYPES 9

#define PRIVATE_FLAG 1
#define PUBLIC_FLAG 2
#define PROTECTED_FLAG 3    

using namespace std;


struct SymbTbl_key{
    string lexeme;
    vector<int> type;
    SymbTbl_key(string lex):lexeme(lex){}
    SymbTbl_key():lexeme(""){}
};

struct SymbTbl_entry{
    string category;
    string lexeme;
    vector<int> type;
    unsigned int lineno;
    int mod_flag;
    bool func_is_defined;
    SymbTbl_entry(string cat, string lex, unsigned int l,int mod):category(cat), lexeme(lex), lineno(l), mod_flag(mod), func_is_defined(true) {}
    SymbTbl_entry():category(""), lexeme(""), lineno(0), func_is_defined(true){}
};

struct SymbolTable{
    int tbl_id;
    SymbolTable *parent;
    vector<SymbolTable*> children;
    map<SymbTbl_key, SymbTbl_entry*> table;
    SymbolTable(int id, SymbolTable* p):tbl_id(id), parent(p){
        children.clear();
        table.clear();
    }
    SymbolTable():tbl_id(0), parent(NULL){
        children.clear();
        table.clear();
    }
};

#define CREATE_ST_KEY(name, lex) SymbTbl_key* name = new SymbTbl_key(lex)
#define CREATE_ST_ENTRY(name, cat, lex, line, mod) SymbTbl_entry* name = new SymbTbl_entry(cat, lex, line,mod)
// #define CREATE_ST_ENTRY(name) SymbTbl_entry* name = new SymbTbl_entry()

SymbolTable* create_symtbl();
SymbTbl_entry* lookup(SymbTbl_key* key);
int insert_symtbl(SymbTbl_key* key, SymbTbl_entry* entry);
// void print_symtbl(SymbolTable* tbl);

void printSymbolTable(SymbolTable* tbl);

#endif