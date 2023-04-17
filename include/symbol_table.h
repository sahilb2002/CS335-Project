#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <vector>
#include <string>
#include <map>

#define ALREADY_EXIST -1
#define INSERT_SUCC 1

#define TYPE_ERROR "ERROR"
#define TYPE_CLASS "CLASS"
#define TYPE_INT "INT"
#define TYPE_LONG "LONG"
#define TYPE_CHAR "CHAR"
#define TYPE_VOID "VOID"
#define TYPE_SHORT "SHORT"


#define TYPE_BOOL "BOOL"

#define TYPE_STRING "STRING"
#define TYPE_FLOAT "FLOAT"
#define TYPE_DOUBLE "DOUBLE"
#define TYPE_ARRAY "[]"
#define TYPE_NORET "NO_RETURN"

#define NUM_TYPES 9

#define PRIVATE_FLAG 1
#define PUBLIC_FLAG 2
#define PROTECTED_FLAG 3    

using namespace std;

typedef struct SymbolTable SymbolTable;

struct SymbTbl_key{
    string lexeme;
    vector<string> type;
    SymbTbl_key(string lex):lexeme(lex){}
    SymbTbl_key():lexeme(""){}
};

struct SymbTbl_entry{
    string category;
    string lexeme;
    vector<string> type;
    bool is_func;
    unsigned int lineno;
    int mod_flag;
    int stat_flag;
    int fin_flag;
    bool func_is_defined;
    int offset;
    int func_entry_addr;
    SymbolTable* table;
    SymbTbl_entry* obj_entry;
    string addr;
    vector<string>arr_dims;
    
    struct addr_desc{
        string reg;
        bool in_mem; // if in mem or not, if in mem addr is given by offset if on stack.
        bool stack;
    } addr_desc;
    int next_use=-1;
    
    SymbTbl_entry(string cat, string lex, unsigned int l,int mod):category(cat), lexeme(lex), lineno(l), mod_flag(mod), func_is_defined(true), is_func(false){}
    SymbTbl_entry():category(""), lexeme(""), lineno(0), func_is_defined(true), is_func(false){}
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
string get_type(string& dType, int dim);

void printSymbolTable(SymbolTable* tbl);
void initSymbolTable();

bool operator<(const SymbTbl_key& a, const SymbTbl_key& b);

#endif