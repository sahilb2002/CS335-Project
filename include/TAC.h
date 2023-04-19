#ifndef TAC_H
#define TAC_H

#include <string>
#include <vector>
#include <iostream>
#include <symbol_table.h>
using namespace std;


#define GOTO "goto"
#define IF "if"
#define CALL "call"
#define IFFALSE "ifFalse"
#define ASSERT_FAIL "Raise Assersion failure"

typedef string qel_t;
typedef pair<string, SymbTbl_entry*> qid;



struct quad{
    
    qid op;
    qid arg1;
    qid arg2;
    qid res;
    
    // index of the quad in the vector if quad is not a jump instruction else destination of jump
    int idx;        
    quad(qel_t _op, qel_t _arg1, qel_t _arg2, qel_t _res, int _id){
        CREATE_ST_KEY(op_key,_op);
        CREATE_ST_KEY(arg1_key, _arg1);
        CREATE_ST_KEY(arg2_key, _arg2);
        CREATE_ST_KEY(res_key, _res);
        op = {_op, lookup(op_key)};
        arg1 = {_arg1, lookup(arg1_key)};
        arg2 = {_arg2, lookup(arg2_key)};
        res = {_res, lookup(res_key)};
        idx = _id;
    }
};

void emit(qel_t op, qel_t arg1, qel_t arg2, qel_t res);
void print_code();
qel_t get_temp(string type);

void backPatch(int instr, int target);

#endif