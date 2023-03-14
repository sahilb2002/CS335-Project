#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <vector>
#include <string>
#include <map>

#define ALREADY_EXIST -1
#define INSERT_SUCC 1

using namespace std;


struct SymbTbl_key{
    string lexeme;
    int type;
    SymbTbl_key(string lex, int t):lexeme(lex), type(t){}
    SymbTbl_key():lexeme(""), type(0){}
};

struct SymbTbl_entry{
    string category;
    string lexeme;
    int type;
    unsigned int lineno;
    SymbTbl_entry(string cat, string lex, int t, unsigned int l):category(cat), lexeme(lex), type(t), lineno(l){}
    SymbTbl_entry():category(""), lexeme(""), type(0), lineno(0){}
};

struct SymbolTable{
    int tbl_id;
    SymbolTable *parent;
    vector<SymbolTable*> children;
    map<SymbTbl_key*, SymbTbl_entry*> table;
    SymbolTable(int id, SymbolTable* p):tbl_id(id), parent(p){
        children.clear();
        table.clear();
    }
    SymbolTable():tbl_id(0), parent(NULL){
        children.clear();
        table.clear();
    }
};

#define CREATE_ST_KEY(name, lex, id) SymbTbl_key* name = new SymbTbl_key(lex, id)
#define CREATE_ST_ENTRY(name, cat, lex, id, line) SymbTbl_entry* name = new SymbTbl_entry(cat, lex, id, line)
#define CREATE_ST_ENTRY(name) SymbTbl_entry* name = new SymbTbl_entry()

SymbolTable* create_symtbl();
SymbTbl_entry* lookup(SymbTbl_key* key);
int insert_symtbl(SymbTbl_key* key, SymbTbl_entry* entry);
void print_symtbl(SymbolTable* tbl);

#endif