#include<symbol_table.h>
#include<iostream>

using namespace std;
SymbolTable *current = new SymbolTable(0, NULL);
vector<SymbTbl_entry*> methKeys;
int tbl_id = 0;

bool operator <(const SymbTbl_key& a, const SymbTbl_key& b){
    if(a.lexeme != b.lexeme)
        return a.lexeme < b.lexeme;
    if(a.type.size() != b.type.size())
        return a.type.size() < b.type.size();
    for(int i=0; i<a.type.size(); i++){
        if(a.type[i]!=b.type[i])
            return a.type[i]<b.type[i];
    }
    return false;
}

SymbTbl_entry* lookup(SymbTbl_key* key){
    SymbolTable* temp = current;
    while(temp!=NULL){
        if(temp->table.find(*key) != temp->table.end()){
            return temp->table[*key];
        }
        temp = temp->parent;
    }
    return NULL;
}

int insert_symtbl(SymbTbl_key* key, SymbTbl_entry* entry){
    if(current->table.find(*key) != current->table.end()){
        return ALREADY_EXIST;
    }
    current->table.insert({*key, entry});
    return INSERT_SUCC;
}

SymbolTable* create_symtbl(){
    SymbolTable * child_tbl = new SymbolTable(++tbl_id, current);
    current->children.push_back(child_tbl);
    current = child_tbl;
    for(auto p:methKeys){
        
        CREATE_ST_KEY(temp, p->lexeme );
        insert_symtbl(temp, p);
        free(temp);
    }
    methKeys.clear();
    return current;
}

// void print_symtbl(SymbolTable* tbl){

// }
void printSymbolTable(SymbolTable* tbl){
    cout<<"Symbol Table ID: "<<tbl->tbl_id<<endl;
    for(auto p:tbl->table){
        cout<< p.second->lexeme << " lineno:" <<p.second->lineno<<" Type: "<<p.second->type[0]<<endl;
    }
    for(auto child:tbl->children){
        printSymbolTable(child);
    }
}