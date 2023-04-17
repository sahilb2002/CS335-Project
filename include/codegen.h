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

// free_reg frees the register r
// returns 0 on success, -1 if no such reg r
int free_reg(reg r);
reg get_reg(quad& instr);

#endif