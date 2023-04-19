#ifndef CODEGEN_H
#define CODEGEN_H


#include <vector>
#include <string>
#include <TAC.h>
#include <symbol_table.h>

using namespace std;


#define RSP "%rsp"
#define RBP "%rbp"

#define RAX "rax"
#define RBX "rbx"
#define RCX "rcx"
#define RDX "rdx"
#define RSI "rsi"
#define RDI "rdi"
#define R8  "r8" 
#define R9  "r9" 
#define R10 "r10"
#define R11 "r11"
#define R12 "r12"
#define R13 "r13"
#define R14 "r14"
#define R15 "r15"

#define NO_FREE_REG ""

typedef string reg;
typedef pair<string, SymbTbl_entry*> var;
typedef vector<var> reg_desc;

void basicBlock();

void init_reg_map();
reg get_free_reg();
int free_reg(reg r);

bool is_int(string s);

void init_reg_map();

reg get_reg_arg(var arg);
reg get_reg_res(var arg);

void bin_op(quad instr);

void un_op(quad instr);

// void assign(quad instr){
//     string reg1;

//     if(is_int(instr.arg1.first)) reg1 = '$' + instr.arg1.first;
//     else reg1 = get_reg_arg(instr.arg1);

//     instr.res.second->addr_desc.reg = reg1;
//     instr.res.second->addr_desc.in_mem = false;
//     reg_map[reg1].push_back(instr.res);

//     return;
// }

void shift_op(quad instr);
void div_op(quad instr);
void comp_op(quad instr);
void assign(quad instr);
void jmp_instr(quad instr);
void gen_x86_code();
            


#endif