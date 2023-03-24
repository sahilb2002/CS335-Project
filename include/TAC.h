#ifndef TAC_H
#define TAC_H

#include <string>
#include <vector>
using namespace std;


#define GOTO "goto"
#define IF "if"
#define CALL "call"
#define IFFALSE "ifFalse"
#define ASSERT_FAIL "Raise Assersion failure"

typedef string qel_t;


struct quad{
    
    qel_t op;
    qel_t arg1;
    qel_t arg2;
    qel_t res;
    
    // index of the quad in the vector if quad is not a jump instruction else destination of jump
    int idx;        
    
    quad(qel_t op, qel_t arg1, qel_t arg2, qel_t res, int id):op(op), arg1(arg1), arg2(arg2), res(res), idx(id) {}
    quad():op(""), arg1(""), arg2(""), res(""){}
};

void emit(qel_t op, qel_t arg1, qel_t arg2, qel_t res);
void print_code(char* outfile);
qel_t get_temp(string type);

void backPatch(int instr, int target);

#endif