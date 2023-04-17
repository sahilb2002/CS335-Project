#include <codegen.h>

extern vector<quad>code;

typedef vector<string> x86_instr;
vector<x86_instr> x86_code;

vector<int>leaders;
void basicBlock(){
    for(int i=0; i<code.size(); i++){
        if(i==0){
            leaders.push_back(i);
        }
        else if(code[i].op.first == GOTO){
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op.first == IFFALSE){
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op.first == "func"){
            leaders.push_back(i);
        }
    }
}

map<reg, reg_desc> reg_map;

void init_reg_map(){
    reg_map.clear();
    reg_map.insert({RAX, {}});
    reg_map.insert({RBX, {}});
    reg_map.insert({RCX, {}});
    reg_map.insert({RDX, {}});
    reg_map.insert({RSI, {}});
    reg_map.insert({RDI, {}});
    reg_map.insert({R8, {}});
    reg_map.insert({R9, {}});
    reg_map.insert({R10, {}});
    reg_map.insert({R12, {}});
    reg_map.insert({R13, {}});
    reg_map.insert({R14, {}});
    reg_map.insert({R15, {}});
}

reg get_free_reg(){
    for(auto it :reg_map){
        if(it.second.size() == 0)
            return it.first;
    }
    return NO_FREE_REG;
}

int free_reg(reg r){
    auto it = reg_map.find(r);
    if(it==reg_map.end())
    return -1;

    for(auto vars: it->second){
        if(!vars.second){
            // symbltbl entry is null
            continue;
        }
        if(!vars.second->addr_desc.in_mem){
            // var is not in mem so need to push it to its location in stack.

            // assumes all vars are in stack.
            int location = -vars.second->offset;
            x86_instr

        }
    }
}