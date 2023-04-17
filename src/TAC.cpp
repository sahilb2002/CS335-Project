#include<TAC.h>
#include<iostream>
#include<symbol_table.h>
using namespace std;

vector<quad> code;
extern int temp_addr;
extern int stack_top;
extern map<char, int> Size;

void emit(qel_t op, qel_t arg1, qel_t arg2, qel_t res){
    if(op == GOTO || op == CALL || op == ASSERT_FAIL)
        code.push_back(quad(op, arg1, arg2, res, -1));
    else
        code.push_back(quad(op, arg1, arg2, res, code.size()));

}

qel_t get_temp(string type){
    qel_t temp;
    temp = "#T" + to_string(temp_addr);
    temp_addr++;
    CREATE_ST_KEY(temp_key, temp);
    CREATE_ST_ENTRY(temp_entry, "Register", temp, -1, 0);
    temp_entry->type.push_back(type);
    stack_top += Size[type[0]];
    temp_entry->offset = stack_top;
    insert_symtbl(temp_key, temp_entry);
    return temp;
}

void print_code(){
    FILE *tac = fopen("tac.txt", "w");
    // fstream tac = fstream("tac.txt", ios::out);
    if(tac == NULL){
        cout << "Error opening file tac.txt"<< endl;
        exit(1);
    }

    for(int i = 0; i < code.size(); i++){
        if(code[i].op.first == "push" || code[i].op.first == "pop"){
            cout << i << " : " << code[i].op.first << " " << code[i].arg1.first << endl;
            fprintf(tac, "%d : %s %s\n", i, code[i].op.first.c_str(), code[i].arg1.first.c_str()); 
        }
        else if(code[i].op.first == "call"){
            cout << i << " : " << code[i].res.first << " = " << code[i].op.first << " " << code[i].arg1.first<<" @ "<<code[i].arg2.first << endl;
            fprintf(tac, "%d : %s = %s %s\n", i, code[i].res.first.c_str(), code[i].op.first.c_str(), code[i].arg1.first.c_str());
        }
        else if(code[i].op.first == "RET" ){
            cout << i << " : " << code[i].op.first << " " << code[i].arg1.first << endl;
            fprintf(tac, "%d : %s %s\n", i, code[i].op.first.c_str(), code[i].arg1.first.c_str());
        }
        else if(code[i].res.first.size()!=0){
            cout << i << " : " << code[i].res.first << " = " << code[i].arg1.first << " " << code[i].op.first << " " << code[i].arg2.first << endl;
            fprintf(tac, "%d : %s = %s %s %s\n", i, code[i].res.first.c_str(), code[i].arg1.first.c_str(), code[i].op.first.c_str(), code[i].arg2.first.c_str());
        }
        else{
            cout << i << " : " << code[i].op.first <<" " << code[i].arg1.first<<" " <<code[i].arg2.first;
            fprintf(tac, "%d : %s %s %s", i, code[i].op.first.c_str(), code[i].arg1.first.c_str(), code[i].arg2.first.c_str());
            if(code[i].idx != -1){
                cout<<" "<<code[i].idx;
                fprintf(tac, " %d", code[i].idx);
            }
            cout<<endl;
            fprintf(tac, "\n");
        }

    }
    fclose(tac);
}

void backPatch(int instr, int target){
    code[instr].idx = target;
}