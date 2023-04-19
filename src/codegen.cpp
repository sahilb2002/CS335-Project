#include <codegen.h>
#include <iostream>

#define INT_MAX 198
extern vector<quad>code;

typedef vector<string> x86_instr;
vector<x86_instr> x86_code;

vector<int>leaders;
using namespace std;

bool is_int(string s){
    if(s[0] == '-' || s[0] == '+')
        s = s.substr(1, s.size()-1);

    for(int i=0; i<s.size(); i++){
        if(s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

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
    // reg_map.insert({RBX, {}});
    // reg_map.insert({RCX, {}});
    // reg_map.insert({RDX, {}});
    // reg_map.insert({RSI, {}});
    // reg_map.insert({RDI, {}});
    // reg_map.insert({R8, {}});
    // reg_map.insert({R9, {}});
    // reg_map.insert({R10, {}});
    // reg_map.insert({R11, {}});
    // reg_map.insert({R12, {}});
    // reg_map.insert({R13, {}});
    // reg_map.insert({R14, {}});
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
            x86_instr ins = {"mov", r, to_string(location) + "(" + RBP + ")"};
            x86_code.push_back(ins);
            vars.second->addr_desc.in_mem = true;
        }
        vars.second->addr_desc.reg = NO_FREE_REG;
    }
    it->second.clear();
    return 0;
}

reg get_reg_arg(var arg){
    // for argument 1
    if(arg.second->addr_desc.reg != NO_FREE_REG){
        // it is present in some register.
        return arg.second->addr_desc.reg;
    }
    reg freereg = get_free_reg();
    if(freereg != NO_FREE_REG){
        arg.second->addr_desc.reg = freereg;
        reg_map[freereg].push_back(arg);
        int location = -arg.second->offset;
        x86_instr ins = {"mov",to_string(location) + "(" + RBP + ")", freereg};
        reg_map[freereg].push_back(arg);
        arg.second->addr_desc.reg = freereg;
        return freereg;
    }
    cout << "HE2" << endl;
    int mincount = INT_MAX;
    reg minreg;
    for(auto it:reg_map){
        int count = 0;
        for(auto vars: it.second){
            if(!vars.second){
                // symbltbl entry is null 
                continue;
            }
            if(!vars.second->addr_desc.in_mem){
                // var is not in mem so need to push it to its location in stack.
                count++;
            }
        }
        if(count < mincount){
            mincount = count;
            minreg = it.first;
        }
    }
    free_reg(minreg);
    int location = -arg.second->offset;
    x86_instr ins = {"mov",to_string(location) + "(" + RBP + ")", minreg};
    x86_code.push_back(ins);
    reg_map[minreg].push_back(arg);
    arg.second->addr_desc.reg = minreg;
    return minreg;

}
reg get_reg_res(var arg){
    // reg for argument 2
    // if(arg.second==NULL)cout << "He" << endl;
    if(arg.second->addr_desc.reg != NO_FREE_REG){
        // it is present in some register.
        reg resreg = arg.second->addr_desc.reg;
        // remove all vars  from reg_map[resreg]
        free_reg(resreg);
        return resreg;
    }
    reg freereg = get_free_reg();
    if(freereg != NO_FREE_REG){
        // arg.second->addr_desc.reg = freereg;
        // reg_map[freereg].push_back(arg);
        int location = -arg.second->offset;
        x86_instr ins = {"mov",to_string(location) + "(" + RBP + ")", freereg};
        return freereg;
    }
    int mincount = INT_MAX;
    reg minreg;
    for(auto it:reg_map){
        int count = 0;
        for(auto vars: it.second){
            if(!vars.second){
                // symbltbl entry is null 
                continue;
            }
            if(!vars.second->addr_desc.in_mem){
                // var is not in mem so need to push it to its location in stack.
                count++;
            }
        }
        if(count < mincount){
            mincount = count;
            minreg = it.first;
        }
    }
    free_reg(minreg);
    int location = -arg.second->offset;
    x86_instr ins = {"mov",to_string(location) + "(" + RBP + ")", minreg};
    x86_code.push_back(ins);
    return minreg;
}

void bin_op(quad instr){
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        // both are constants
        int res = 0;
        if(instr.op.first[0]='+') res = stoi(instr.arg1.first) + stoi(instr.arg2.first);
        else if(instr.op.first[0]='-') res = stoi(instr.arg1.first) - stoi(instr.arg2.first);
        else if(instr.op.first[0]='*') res = stoi(instr.arg1.first) * stoi(instr.arg2.first);
        else if(instr.op.first[0]='^') res = stoi(instr.arg1.first) ^ stoi(instr.arg2.first);
        else if(instr.op.first[0]='|') res = stoi(instr.arg1.first) | stoi(instr.arg2.first);
        else if(instr.op.first[0]='&') res = stoi(instr.arg1.first) & stoi(instr.arg2.first);
        
        string reg = get_reg_res(instr.res);
        x86_instr ins = {"mov", "$" + to_string(res), reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        reg_map[reg].push_back(instr.res);
        return;
    }
    string reg1, reg2;
    if(is_int(instr.arg1.first)) reg1 = "$" + instr.arg1.first;
    else reg1 = get_reg_arg(instr.arg1);

    if(is_int(instr.arg2.first)){
        reg2 = "$" + instr.arg2.first;
    }
    else reg2 = get_reg_res(instr.arg2);

    instr.res.second->addr_desc.reg = reg2;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg2].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first[0]='+') ins = {"add", reg1, reg2};
    else if(instr.op.first[0]='-') ins = {"sub", reg1, reg2};
    else if(instr.op.first[0]='*') ins = {"imul", reg1, reg2};
    else if(instr.op.first[0]='^') ins = {"xor", reg1, reg2};
    else if(instr.op.first[0]='|') ins = {"or", reg1, reg2};
    else if(instr.op.first[0]='&') ins = {"and", reg1, reg2};    

    x86_code.push_back(ins);
    return;
}

void un_op(quad instr){
    string reg1;

    reg1 = get_reg_res(instr.arg1);

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first[0]='-') ins = {"neg", reg1};
    if(instr.op.first[0]='!') ins = {"not", reg1};

    x86_code.push_back(ins);
    return;
}

//Assigning a value to a variable
void assign(quad instr){
    string reg1, reg2;
    if(is_int(instr.arg1.first)){
        reg1 = '$' + instr.arg1.first;
        reg2 = get_reg_res(instr.res);
        instr.res.second->addr_desc.reg = reg2;
        instr.res.second->addr_desc.in_mem = false;
        reg_map[reg2].push_back(instr.res);
    }
    else if(instr.arg1.first == "%rbp" || instr.arg1.first == "%rsp"){
        reg1 = instr.arg1.first;
        reg2 = instr.res.first;
    }
    else{
        reg1 = get_reg_arg(instr.arg1);
        instr.res.second->addr_desc.reg = reg1;
        instr.res.second->addr_desc.in_mem = false;
        reg_map[reg1].push_back(instr.res);
        return;
    }
    x86_instr ins = {"mov", reg1, reg2};
    x86_code.push_back(ins);
    return;
}
// void assign(quad instr){
//     string reg1;

//     if(instr.arg1.first == "%rbp" || instr.arg1.first == "%rsp"){
//         reg1 = instr.arg1.first;
//     }
//     else{
//         if(is_int(instr.arg1.first)) reg1 = '$' + instr.arg1.first;
//         else{
//             reg1 = get_reg_arg(instr.arg1);
//             instr.res.second->addr_desc.reg = reg1;
//             instr.res.second->addr_desc.in_mem = false;
//             reg_map[reg1].push_back(instr.res);
//         }
//     }

//     cout << "HEY2" << endl;
//     string reg2;
//     if(instr.res.first == "%rbp" || instr.res.first == "%rsp"){
//         reg2 = instr.res.first;
//     }
//     else{
//         if(is_int(instr.res.first)) reg2 = '$' + instr.res.first;
//         else reg2 = get_reg_res(instr.res);
//         cout << reg2;
//     }
//     cout << "HEY" << endl;
//     x86_instr ins = {"mov", reg1, reg2};
//     x86_code.push_back(ins);

//     return;
// }

void shift_op(quad instr){
    string reg1, reg2;
    if(is_int(instr.arg2.first)) reg1 = "$" + instr.arg2.first;
    else reg1= "$1";

    if(is_int(instr.arg1.first)){
        int k=0;
        if(is_int(instr.arg2.first)){
            k=stoi(instr.arg2.first);
        }
        else k=1;

        int res = stoi(instr.arg1.first);
        if(instr.op.first=="<<") res = res << k;
        if(instr.op.first==">>") res = res >> k;

        string reg = get_reg_res(instr.res);
        x86_instr ins = {"mov", "$" + to_string(res), reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        return;
    }

    reg2 = get_reg_res(instr.arg1);
    instr.res.second->addr_desc.reg = reg2;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg2].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first=="<<") ins = {"shl", reg1, reg2};
    if(instr.op.first==">>") ins = {"shr", reg1, reg2};

    return;
}

void div_op(quad instr){
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        int res;
        if(instr.op.first[0]=='/') res = stoi(instr.arg1.first) / stoi(instr.arg2.first);
        else res = stoi(instr.arg1.first) % stoi(instr.arg2.first);
        string reg = get_reg_res(instr.res);
        x86_instr ins = {"mov", "$" + to_string(res), reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        return;
    }
    string reg1;
    if(is_int(instr.arg2.first)) reg1 = "$" + instr.arg2.first;
    else reg1 = get_reg_arg(instr.arg2);

    free_reg(RAX);
    free_reg(RDX);

    if(is_int(instr.arg1.first)){ 
        x86_instr ins = {"mov", "$" + instr.arg1.first, RAX};
        x86_code.push_back(ins);
    } 
    else{
        string res2 = get_reg_res(instr.arg1);
        if(res2 != RAX){
            x86_instr ins = {"mov", res2, RAX};
            x86_code.push_back(ins);
        }
    }   

    x86_instr ins = {"cqo"};
    x86_code.push_back(ins);
    ins = {"idiv", reg1};
    x86_code.push_back(ins);
    
    if(instr.op.first[0]=='/') reg1 = RAX;
    else reg1 = RDX;

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);
    return;
}

void comp_op(quad instr){
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        int res=0;
        if(instr.op.first=="<") res = stoi(instr.arg1.first) < stoi(instr.arg2.first);
        else if(instr.op.first==">") res = stoi(instr.arg1.first) > stoi(instr.arg2.first);
        else if(instr.op.first=="==") res = stoi(instr.arg1.first) == stoi(instr.arg2.first);
        else if(instr.op.first == "!=") res = stoi(instr.arg1.first) != stoi(instr.arg2.first);
        else if(instr.op.first == "<=") res = stoi(instr.arg1.first) <= stoi(instr.arg2.first);
        else if(instr.op.first == ">=") res = stoi(instr.arg1.first) >= stoi(instr.arg2.first);

        string reg = get_reg_res(instr.res);
        x86_instr ins = {"mov", "$" + to_string(res), reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        return;
    }

    string reg1, reg2;

    if(is_int(instr.arg1.first)) reg1 = "$" + instr.arg1.first;
    else reg1 = get_reg_arg(instr.arg1);

    if(is_int(instr.arg2.first)) reg2 = "$" + instr.arg2.first;
    else reg2 = get_reg_arg(instr.arg2);

    x86_instr ins = {"cmp", reg1, reg2};
    x86_code.push_back(ins);

    string op;

    if(instr.op.first=="<") op = "setl";
    else if(instr.op.first==">") op = "setg";
    else if(instr.op.first=="==") op = "sete";
    else if(instr.op.first == "!=") op = "setne";
    else if(instr.op.first == "<=") op = "setle";
    else if(instr.op.first == ">=") op = "setge";

    reg1 = get_reg_res(instr.res);
    ins = {op, reg1};
    x86_code.push_back(ins);

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);
    return;
}

void jmp_instr(quad instr){
    if(instr.op.first == "goto"){
        x86_instr ins = {"jmp", to_string(instr.idx)};
        x86_code.push_back(ins);
        return;
    }
    if(instr.op.first == "ifFalse"){
        string reg1 = get_reg_arg(instr.arg1);
        x86_instr ins = {"cmp", "$0", reg1};
        x86_code.push_back(ins);
        ins = {"je", to_string(instr.idx)};
        x86_code.push_back(ins);
        return;
    }
}




void gen_x86_code(){
    x86_code.clear();
    init_reg_map();
    basicBlock();
    for(int i=0;i<leaders.size();i++){
        int start = leaders[i];
        int end = (i+1 < leaders.size()) ? leaders[i+1] : code.size();
        for(int j=start;j<end;j++){
            if(code[j].op.first == "func"){
                // x86_instr ins = {"func", code[j].op.second};
                // x86_code.push_back(ins);
                continue;
            }
            if(code[j].op.first == "call"){
                // x86_instr ins = {"call", code[j].op.second};
                // x86_code.push_back(ins);
                continue;
            }
            if(code[j].op.first == "ret"){
                x86_instr ins = {"ret"};
                x86_code.push_back(ins);
                continue;
            }
            if(code[j].op.first == "push"){
                // reg r = get_reg_arg(code[j].op.second);
                // x86_instr ins = {"push", r};
                // x86_code.push_back(ins);
                continue;
            }
            if(code[j].op.first == "label"){
                // x86_instr ins = {"label", code[j].op.second};
                // x86_code.push_back(ins);
                continue;
            }
            if(code[j].op.first == "goto" | code[j].op.first == "ifFalse"){
                jmp_instr(code[j]);
                continue;
            }
            if(code[j].op.first[0] == '+' | code[j].op.first[0] == '-' | code[j].op.first[0] == '*' | code[j].op.first[0] == '^' | code[j].op.first[0] == '|' | code[j].op.first[0] == '&' ){
                if(code[j].res.first == "%rsp"){
                    if(code[j].op.first == "+"){
                        x86_instr ins = {"add", "$" + code[j].arg1.first, code[j].res.first};
                        x86_code.push_back(ins);
                    }
                    else if(code[j].op.first == "-"){
                        x86_instr ins = {"sub", "$" + code[j].arg1.first, code[j].res.first};
                        x86_code.push_back(ins);
                    }
                }
                else bin_op(code[j]);
                continue;
            } 
            if(code[j].op.first[0] == '/' | code[j].op.first[0] == '%'){
                div_op(code[j]);
                continue;
            }
            if(code[j].op.first == "<" | code[j].op.first == ">" | code[j].op.first == "==" | code[j].op.first == "!=" | code[j].op.first == "<=" | code[j].op.first == ">="){
                comp_op(code[j]);
                continue;
            }
            if(code[j].op.first == ""){
                cout << code[j].res.first << " " << code[j].arg1.first << " " << code[j].arg2.first << endl;
                assign(code[j]);
                continue;
            }
        }
    }
    for(auto it:x86_code){
        for(auto ir:it){
            cout<<ir<<" ";
        }
        cout << endl;
    }
}
            
