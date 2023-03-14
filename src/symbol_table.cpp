#include<symbol_table.h>

SymbolTable *current;
int tbl_id = 0;

SymbTbl_entry* lookup(SymbTbl_key* key){
    SymbolTable* temp = current;
    while(temp!=NULL){
        if(temp->table.find(key) != temp->table.end()){
            return temp->table[key];
        }
        temp = temp->parent;
    }
    return NULL;
}

int insert_symtbl(SymbTbl_key* key, SymbTbl_entry* entry){
    if(current->table.find(key) != current->table.end()){
        return ALREADY_EXIST;
    }
    current->table.insert({key, entry});
    return INSERT_SUCC;
}

SymbolTable* create_symtbl(){
    SymbolTable * child_tbl = new SymbolTable(++tbl_id, current);
    current->children.push_back(child_tbl);
    current = child_tbl;
    return current;
}

void print_symtbl(SymbolTable* tbl){

}