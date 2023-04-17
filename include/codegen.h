#ifndef CODEGEN_H
#define CODEGEN_H


#include <vector>
#include <string>
#include <TAC.h>
#include <symbol_table.h>

using namespace std;

#define RAX

#define RAX "rax"
#define RBX "rbx"
#define RCX "rcx"
#define RDX "rdx"
#define RSI "rsi"
#define RDI "rdi"
#define R8 "r8"
#define R9 "r9"
#define R10 "r10"
#define R12 "r11"
#define R13"r12"
#define R14 "r13"
#define R15 "r14"
#define R16 "r15"

typedef string reg;
typedef pair<string, SymbTbl_entry*> var;
typedef vector<var> reg_desc;
map<reg, reg_desc> reg_map;

void basicBlock();
void regAlloc();

void init_reg_map();
reg get_free_reg();
void free_reg(reg r);
reg get_reg(quad instr);

#endif