#include<TAC.h>
#include<iostream>
#include<symbol_table.h>
using namespace std;

vector<quad> code;
extern int temp_addr;

void emit(qel_t op, qel_t arg1, qel_t arg2, qel_t res){
    if(op == GOTO || op == CALL)
        code.push_back(quad(op, arg1, arg2, res, -1));
    else
        code.push_back(quad(op, arg1, arg2, res, code.size()));

}

qel_t get_temp(string type){
    qel_t temp = "#T" + to_string(temp_addr);
    temp_addr++;
    CREATE_ST_KEY(temp_key, temp);
    CREATE_ST_ENTRY(temp_entry, "Register", temp, -1, 0);
    temp_entry->type.push_back(type);
    insert_symtbl(temp_key, temp_entry);
    return temp;
}

void print_code(){
    for(int i = 0; i < code.size(); i++){
        if(code[i].op == "param"){
            cout << i << " : " << code[i].op << " " << code[i].arg1 << endl;
        }
        else if(code[i].op == "call")
            cout << i << " : " << code[i].res << " = " << code[i].op << " " << code[i].arg1 << endl;
        else if(code[i].res.size()!=0)
            cout << i << " : " << code[i].res << " = " << code[i].arg1 << " " << code[i].op << " " << code[i].arg2 << endl;
        else
        cout << i << " : " << code[i].op <<" " << code[i].arg1<<" " <<code[i].arg2<<" " << code[i].idx<<endl;
    }
}

void backPatch(int instr, int target){
    code[instr].idx = target;
}