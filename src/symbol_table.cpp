#include<symbol_table.h>
#include<iostream>
#include<fstream>

using namespace std;
SymbolTable *current = new SymbolTable(0, NULL);
vector<SymbTbl_entry*> methKeys;
int tbl_id = 0;

// bool operator < (const string &a, const string &b){
//     return a.compare(b) < 0;
// }

bool operator<(const SymbTbl_key& a, const SymbTbl_key& b) { 
    if(a.lexeme != b.lexeme)
        return a.lexeme < b.lexeme;
    if(a.type.size() != b.type.size())
        return a.type.size() < b.type.size();
    for(int i=0; i<a.type.size(); i++){
        if(a.type[i]!=b.type[i])
            return a.type[i] < b.type[i];
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
    string path = "SymbolTable" + to_string(tbl->tbl_id) +".csv";
    fstream SymbolTableFile = fstream(path, ios::out);
    cout<<"Symbol Table ID: "<<tbl->tbl_id<<endl;
    //SymbolTableFile<<"Symbol Table ID: "<<tbl->tbl_id<<endl;
    for(auto p:tbl->table){
        if(p.second->lexeme[0] == '#') continue;
        cout<< p.second->lexeme << " lineno:" <<p.second->lineno<<" Type: "<<p.second->type[0]<<" ";
        SymbolTableFile<< p.second->lexeme << "," <<p.second->lineno<<","<<p.second->category<<","<<p.second->type[0]<<"";
        for(auto it:p.second->arr_dims){
            cout<<it<<" ";
            SymbolTableFile<<it<<" ";
        }
        cout << endl;
        SymbolTableFile << endl;
    }
    for(auto child:tbl->children){
        printSymbolTable(child);
    }
}
string get_type(string& dType, int dim){
    string type = dType;
    for(int i=0; i<dim; i++){
        type += TYPE_ARRAY;
    }
    return type;
}

void initSymbolTable(){
    CREATE_ST_KEY(sysClass, "system");
    sysClass->type.push_back(TYPE_CLASS);
    CREATE_ST_ENTRY(sysClassent,"ID","system",0,PUBLIC_FLAG);
    sysClassent->type.push_back(TYPE_CLASS);

    insert_symtbl(sysClass, sysClassent);
    CREATE_ST_KEY(sysKey, "System");
    CREATE_ST_ENTRY(sysKeyent,"ID","System",0,PUBLIC_FLAG);
    sysKeyent->type.push_back("system");

    insert_symtbl(sysKey, sysKeyent);

    create_symtbl();
    sysClassent->table = current;
    CREATE_ST_KEY(sysOut, "out");
    CREATE_ST_ENTRY(sysOutent,"ID","out",0,PUBLIC_FLAG);
    sysOutent->type.push_back("system");
    insert_symtbl(sysOut, sysOutent);

    CREATE_ST_KEY(sysprint, "println");
    CREATE_ST_ENTRY(sysprintent,"ID","println",0,PUBLIC_FLAG);
    sysprintent->type.push_back(TYPE_STRING);
    sysprintent->type.push_back(TYPE_VOID);
    sysprintent->is_func = true;
    insert_symtbl(sysprint, sysprintent);


    current = current->parent;
}