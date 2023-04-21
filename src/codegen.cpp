#include <codegen.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>
#define INT_MAX 198
extern vector<quad>code;

typedef vector<string> x86_instr;
vector<x86_instr> x86_code;

vector<int>leaders;
using namespace std;

int mark=0;

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
            //cout<<i<<" goto "<<code[i].idx<<" "<<code[i].arg1.first<<" "<<code[i].arg2.first<<endl;
            if(code[i].idx!=-1);
            else if(code[i].arg1.first != "") code[i].idx = stoi(code[i].arg1.first);
            else if(code[i].arg2.first != "") code[i].idx = stoi(code[i].arg2.first);
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op.first == IFFALSE){
            //cout<<i<<" iffalse "<<code[i].idx<<endl;
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op.first == "func"){
            //cout<<i<<" func "<<code[i].idx<<endl;
            leaders.push_back(i);
        }
    }
    sort(leaders.begin(), leaders.end());
    leaders.resize(distance(leaders.begin(), unique(leaders.begin(), leaders.begin() + leaders.size())));
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
    reg_map.insert({R11, {}});
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
    // cout << "freeing reg " << r << endl;
    if(it==reg_map.end())
    return -1;

    for(auto vars: it->second){
        if(!vars.second){
            // symbltbl entry is null
            // cout<<"bhhkhvhhf"<<endl;
            continue;
        }
        if(!vars.second->addr_desc.in_mem && vars.second->addr_desc.temp_free!=1){
            // var is not in mem so need to push it to its location in stack.

            // assumes all vars are in stack.
            int location = -vars.second->offset;
            x86_instr ins = {"movq\t", r, ", "+to_string(location) + "(" + RBP + ")"};
            x86_code.push_back(ins);
            vars.second->addr_desc.in_mem = true;
        }
        vars.second->addr_desc.reg = NO_FREE_REG;
    }
    it->second.clear();
    return 0;
}
reg get_reg_arg(var arg, reg dontuse="");
reg get_reg_arg(var arg, reg dontuse){
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
        x86_instr ins = {"movq\t",to_string(location) + "(" + RBP + "), ", freereg};
        x86_code.push_back(ins);
        reg_map[freereg].push_back(arg);
        arg.second->addr_desc.reg = freereg;
        return freereg;
    }
    int mincount = INT_MAX;
    reg minreg;
    for(auto it:reg_map){
        if(it.first == dontuse)
            continue;
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
    x86_instr ins = {"movq\t",to_string(location) + "(" + RBP + "), ", minreg};
    x86_code.push_back(ins);
    reg_map[minreg].push_back(arg);
    arg.second->addr_desc.reg = minreg;
    return minreg;

}
reg get_reg_res(var arg, reg dontuse1="", reg dontuse2="");
reg get_reg_res(var arg, reg dontuse1, reg dontuse2){
    // reg for argument 2
    // if(arg.second==NULL)cout << "He" << endl;
    if(arg.second->addr_desc.reg != NO_FREE_REG){
        // cout<<arg.first<<" "<<" in reg "<<arg.second->addr_desc.reg<<endl;
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
        x86_instr ins = {"movq\t",to_string(location) + "(" + RBP + "), ", freereg};
        x86_code.push_back(ins);
        return freereg;
    }
    int mincount = INT_MAX;
    reg minreg;
    for(auto it:reg_map){
        if(it.first == dontuse1 || it.first == dontuse2)
            continue;
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
    x86_instr ins = {"movq\t",to_string(location) + "(" + RBP + "), ", minreg};
    x86_code.push_back(ins);
    return minreg;
}

void bin_op(quad instr){
    cout << instr.arg1.first << " " << instr.op.first << " " << instr.arg2.first << " " << instr.res.first << endl;
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        // both are constants
        int res = 0;
        if(instr.op.first[0]=='+') res = stoi(instr.arg1.first) + stoi(instr.arg2.first);
        else if(instr.op.first[0]=='-') res = stoi(instr.arg1.first) - stoi(instr.arg2.first);
        else if(instr.op.first[0]=='*') res = stoi(instr.arg1.first) * stoi(instr.arg2.first);
        else if(instr.op.first[0]=='^') res = stoi(instr.arg1.first) ^ stoi(instr.arg2.first);
        else if(instr.op.first[0]=='|') res = stoi(instr.arg1.first) | stoi(instr.arg2.first);
        else if(instr.op.first[0]=='&') res = stoi(instr.arg1.first) & stoi(instr.arg2.first);
        
        string reg = get_reg_res(instr.res, "", "");
        cout << to_string(res) << endl;
        cout << res << endl;
        x86_instr ins = {"movq\t", "$" + to_string(res)+", ", reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        reg_map[reg].push_back(instr.res);
        return;
    }
    swap(instr.arg1, instr.arg2);
    if(is_int(instr.arg2.first)){
        var temp;
        temp = instr.arg1;
        instr.arg1 = instr.arg2;
        instr.arg2 = temp;
    }
    string reg1, reg2;

    if(is_int(instr.arg1.first)) reg1 = "$" + instr.arg1.first;
    else reg1 = get_reg_arg(instr.arg1,"");

    if(is_int(instr.arg2.first)){
        reg2 = "$" + instr.arg2.first;
    }
    else reg2 = get_reg_res(instr.arg2,reg1,"");
    if(instr.op.first == "[+]")x86_code[x86_code.size()-1][0] = "leaq\t";

    instr.res.second->addr_desc.reg = reg2;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg2].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first[0]=='+') ins = {"addq\t", reg1+", ", reg2};
    else if(instr.op.first=="[+]"){
        ins = {"addq\t", reg1+", ", reg2};
        instr.res.second->is_array = 1;
        cout << "HEY" << endl;
        // x86_code.push_back(ins);
        // ins = {"movq\t", "("+reg2+")"+", ", reg2};
    }
    else if(instr.op.first[0]=='-') ins = {"subq\t", reg1+", ", reg2};
    else if(instr.op.first[0]=='*') ins = {"imul\t", reg1+", ", reg2};
    else if(instr.op.first[0]=='^') ins = {"xor\t", reg1+", ", reg2};
    else if(instr.op.first[0]=='|') ins = {"or\t", reg1+", ", reg2};
    else if(instr.op.first[0]=='&') ins = {"and\t", reg1+", ", reg2};    

    x86_code.push_back(ins);
    return;
}

void un_op(quad instr){
    string reg1;

    reg1 = get_reg_res(instr.arg2,"","");

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first[0]=='-') ins = {"neg\t", reg1};
    if(instr.op.first[0]=='!') ins = {"not\t", reg1};

    x86_code.push_back(ins);
    return;
}

//Assigning a value to a variable
void assign(quad instr){
    cout << instr.arg1.first << " " << instr.arg2.first << " " << instr.res.first << endl;
    cout << "HEY@" << endl;
    string reg1, reg2;
    if(is_int(instr.arg1.first)){
        reg1 = '$' + instr.arg1.first;
        reg2 = get_reg_res(instr.res,"","");
        instr.res.second->addr_desc.reg = reg2;
        instr.res.second->addr_desc.in_mem = false;
        reg_map[reg2].push_back(instr.res);
        if(instr.res.second->is_array!=0){
            reg2 = "("+reg2+")";
        }
    }
    else if(instr.arg1.first == "%rbp" || instr.arg1.first == "%rsp"){
        reg1 = instr.arg1.first;
        reg2 = instr.res.first;
    }
    else{
        reg1 = get_reg_arg(instr.arg1,"");
        x86_instr ins;
        if(instr.arg1.second->is_array!=0){
            cout<<"is array "<<instr.arg1.first<<endl;
            reg2 = get_reg_res(instr.res,reg1,"");
            instr.res.second->addr_desc.reg = reg2;
            instr.res.second->addr_desc.in_mem = false;
            reg_map[reg2].push_back(instr.res);
            ins = {"movq\t", "("+reg1+")"+", ", reg2};
            x86_code.push_back(ins);
        }
        else if(instr.res.second->is_array!=0){
            reg2 = get_reg_res(instr.res,reg1,"");
            instr.res.second->addr_desc.reg = reg2;
            instr.res.second->addr_desc.in_mem = false;
            reg_map[reg2].push_back(instr.res);
            ins = {"movq\t", reg1+", ", "("+reg2+")"};
            x86_code.push_back(ins);
        }
        // cout<<reg1<<" "<<instr.arg1.first << " "<<instr.arg2.first<<" "<<instr.res.first<<endl;
        else {
            if(instr.res.second->addr_desc.reg != NO_FREE_REG){
                // remove instr.res from reg_map
                reg2 = instr.res.second->addr_desc.reg;
                reg_map[reg2].erase(remove(reg_map[reg2].begin(), reg_map[reg2].end(), instr.res), reg_map[reg2].end());
            }
            instr.res.second->addr_desc.reg = reg1;
            instr.res.second->addr_desc.in_mem = false;
            reg_map[reg1].push_back(instr.res);
        }
        return;
    }
    x86_instr ins;
    ins = {"movq\t", reg1+", ", reg2};
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

        string reg = get_reg_res(instr.res,"","");
        x86_instr ins = {"movq\t", "$" + to_string(res)+", ", reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        return;
    }

    reg2 = get_reg_res(instr.arg1,"","");
    instr.res.second->addr_desc.reg = reg2;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg2].push_back(instr.res);

    x86_instr ins;

    if(instr.op.first=="<<") ins = {"shl\t", reg1+", ", reg2};
    if(instr.op.first==">>") ins = {"shr\t", reg1+", ", reg2};
    x86_code.push_back(ins);

    return;
}

void array_access(quad instr){
    // cout<<instr.arg1.first<<" "<<instr.arg2.first<<" "<<instr.res.first<<" "<<instr.op.first<<endl;
    //     string reg = get_reg_arg(code[j].arg1);
    //     string reg1 = get_reg_arg(code[j].arg2);
    //     free_reg(RAX);
    //     x86_instr ins = {"movq\t", reg + ",", RAX};
    //     x86_code.push_back(ins);
    //     ins = {"movq\t", reg1 + ",", RDI};
    //     x86_code.push_back(ins);
    //     ins = {"movq\t", "8(" + RAX + "), ", RAX};
    //     x86_code.push_back(ins);
    //     ins = {"movq\t", "8(" + RAX + ", " + RDI + ", 8), ", RAX};
    //     x86_code.push_back(ins);
    //     code[j].res.second->addr_desc.reg = RAX;
    //     code[j].res.second->addr_desc.in_mem = false;
    //     reg_map[RAX].push_back(code[j].res);
    instr.op.first = "+";
    bin_op(instr);
    string reg1, reg2, reg3;
    reg1 = get_reg_arg(instr.arg1,"");
    reg2 = get_reg_arg(instr.arg2,reg1);
    reg3 = get_reg_res(instr.res,reg1, reg2);
    x86_instr ins = {"movq\t", reg1+", ", reg3};
    x86_code.push_back(ins);
    ins = {"movq\t", reg2+", ", "%rax"};
    x86_code.push_back(ins);
    ins = {"imulq\t", "$8, ", "%rax"};
    x86_code.push_back(ins);
    ins = {"addq\t", "%rax, ", reg3};
    x86_code.push_back(ins);
    instr.res.second->addr_desc.reg = reg3;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg3].push_back(instr.res);
    return;
}

void new_op(quad instr){
    string reg = get_reg_arg(instr.arg1,"");
    free_reg(RAX);
    x86_instr ins = {"movq\t", reg + ",", RAX};
    x86_code.push_back(ins);
    ins = {"movq\t", "$8, ", RDI};
    x86_code.push_back(ins);
    ins = {"call\t", "malloc@PLT"};
    x86_code.push_back(ins);
    ins = {"movq\t", "$0, ", "8(%rax)"};
    x86_code.push_back(ins);
    ins = {"movq\t", "%rax, ", instr.res.second->addr_desc.reg};
    x86_code.push_back(ins);
    
    instr.res.second->addr_desc.in_mem = false;
    reg_map[instr.res.second->addr_desc.reg].push_back(instr.res);
}

void div_op(quad instr){
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        int res;
        if(instr.op.first[0]=='/') res = stoi(instr.arg1.first) / stoi(instr.arg2.first);
        else res = stoi(instr.arg1.first) % stoi(instr.arg2.first);
        string reg = get_reg_res(instr.res,"","");
        x86_instr ins = {"movq\t", "$" + to_string(res)+", ", reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        return;
    }
    string reg1;
    if(is_int(instr.arg1.first)){ 
        free_reg(RAX);
        free_reg(RDX);
        reg1 = get_reg_arg(instr.arg2,"");
        // if(reg1 != RDX){
        //     x86_instr ins = {"movq\t", reg1+", ", RDX};
        //     // reg1 = RDX;
        //     x86_code.push_back(ins);
        // }
        x86_instr ins = {"movq\t", "$" + instr.arg1.first+", ", RAX};
        x86_code.push_back(ins);
    } 
    else if(is_int(instr.arg2.first)){
        free_reg(RAX);
        free_reg(RDX);
        string res2 = get_reg_arg(instr.arg1,"");
        if(res2 != RAX){
            x86_instr ins = {"movq\t", res2+", ", RAX};
            x86_code.push_back(ins);
        }
        free_reg(R10);
        reg1 = R10;
        x86_instr ins = {"movq\t", "$" + instr.arg2.first+", ", R10};
        x86_code.push_back(ins);
    }
    else{
        free_reg(RAX);
        free_reg(RDX);
        string res2 = get_reg_arg(instr.arg1,"");
        if(res2 != RAX){
            x86_instr ins = {"movq\t", res2+", ", RAX};
            x86_code.push_back(ins);
        }
        reg1 = get_reg_arg(instr.arg2,"");
    }



    x86_instr ins = {"cqo"};
    x86_code.push_back(ins);
    ins = {"idivq\t", reg1};
    x86_code.push_back(ins);
    
    if(instr.op.first[0]=='/') reg1 = RAX;
    else reg1 = RDX;

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);
    return;
}

void comp_op(quad instr){
    swap(instr.arg1, instr.arg2);
    if(is_int(instr.arg1.first) && is_int(instr.arg2.first)){
        int res=0;
        if(instr.op.first=="<") res = stoi(instr.arg1.first) < stoi(instr.arg2.first);
        else if(instr.op.first==">") res = stoi(instr.arg1.first) > stoi(instr.arg2.first);
        else if(instr.op.first=="==") res = stoi(instr.arg1.first) == stoi(instr.arg2.first);
        else if(instr.op.first == "!=") res = stoi(instr.arg1.first) != stoi(instr.arg2.first);
        else if(instr.op.first == "<=") res = stoi(instr.arg1.first) <= stoi(instr.arg2.first);
        else if(instr.op.first == ">=") res = stoi(instr.arg1.first) >= stoi(instr.arg2.first);

        string reg = get_reg_res(instr.res,"","");
        x86_instr ins = {"movq\t", "$" + to_string(res)+", ", reg};
        x86_code.push_back(ins);
        instr.res.second->addr_desc.reg = reg;
        instr.res.second->addr_desc.in_mem = false;
        return;
    }

    string reg1, reg2;

    if(is_int(instr.arg1.first)) reg1 = "$" + instr.arg1.first;
    else reg1 = get_reg_arg(instr.arg1,"");

    if(is_int(instr.arg2.first)) reg2 = "$" + instr.arg2.first;
    else reg2 = get_reg_arg(instr.arg2,reg1);

    x86_instr ins = {"cmp\t", reg1+", ", reg2};
    x86_code.push_back(ins);

    string op;

    if(instr.op.first=="<") op = "setl\t";
    else if(instr.op.first==">") op = "setg\t";
    else if(instr.op.first=="==") op = "sete\t";
    else if(instr.op.first == "!=") op = "setne\t";
    else if(instr.op.first == "<=") op = "setle\t";
    else if(instr.op.first == ">=") op = "setge\t";

    reg1 = get_reg_res(instr.res,reg1, reg2);
    // if(instr.res.first[0]=='#'){
    // }
    ins = {"movq", "\t$0, ", reg1};
    x86_code.push_back(ins);
    ins = {op, reg1+"b"};
    x86_code.push_back(ins);

    instr.res.second->addr_desc.reg = reg1;
    instr.res.second->addr_desc.in_mem = false;
    reg_map[reg1].push_back(instr.res);
    return;
}

void jmp_instr(quad instr){
    if(instr.op.first == "goto"){
        if(mark==0){
            for(auto it:reg_map){
                free_reg(it.first);
            }
            mark=1;
        }
        
        x86_instr ins = {"jmp\t", ".L" + to_string(find(leaders.begin(), leaders.end(), instr.idx)-leaders.begin())};
        x86_code.push_back(ins);
        return;
    }
    if(instr.op.first == "ifFalse"){
        if(mark==0){
            for(auto it:reg_map){
                free_reg(it.first);
            }
            mark=1;
        }
        
        string reg1 = get_reg_arg(instr.arg1, "");
        x86_instr ins = {"cmp\t", "$0, ", reg1};
        x86_code.push_back(ins);
        ins = {"je\t", ".L" + to_string(find(leaders.begin(), leaders.end(), instr.idx)-leaders.begin())};
        x86_code.push_back(ins);
        return;
    }
}

void gen_x86_code(){
    x86_code.clear();
    init_reg_map();
    basicBlock();

    
    for(int i=0;i<leaders.size();i++){
        mark=0;
        // if(leaders[i]==-1) continue;
        int start = leaders[i];
        // cout<<"i "<<leaders[i]<<endl;
        x86_instr ins = {".L"+to_string(i)+":"};
        x86_code.push_back(ins);
        int end = (i+1 < leaders.size()) ? leaders[i+1] : code.size();
        // cout<<"end "<<end<<endl;
        for(int j=start;j<end;j++){
            // cout<<"k "<<j<<code[j].op.first<<endl;
            if(code[j].op.first == "print"){
                int off = stoi(code[j].arg2.first);
                if(off%16!=0)
                off+=8;
                if(is_int(code[j].arg1.first)){
                    free_reg(RSI);
                    x86_instr ins = {"movq\t", "$" + code[j].arg1.first + ",", RSI};
                    x86_code.push_back(ins);
                }
                else{
                    free_reg(RSI);
                    string reg = get_reg_arg(code[j].arg1,"");
                    if(reg!=RSI){
                        x86_instr ins;
                        if(code[j].arg1.second->is_array==0) ins = {"movq\t", reg + ",", RSI};
                        else ins = {"movq\t", "(" + reg + "), ", RSI};
                        x86_code.push_back(ins);
                    }
                }
                free_reg(RDI);
                x86_instr ins = {"leaq","\t.LC0(%rip), ", RDI};
                x86_code.push_back(ins);
                x86_code.push_back({"sub\t", "$"+to_string(off)+", %rsp"});
                for(auto it:reg_map){
                    free_reg(it.first);
                }
                ins = {"call","\tprintf@PLT"};
                x86_code.push_back(ins);
                x86_code.push_back({"add\t", "$"+to_string(off)+", %rsp"});
            }
            else if(code[j].op.first == "func"){
                x86_instr ins = {code[j].arg1.first + ":"};
                x86_code.insert(x86_code.begin() + x86_code.size()-1,ins);

            }
            // else if(code [j].op.first[code[j].op.first.length()-1] == ']'){
            
            //     array_access(code[j]);
            // }
            // }
            // else if(code[j].op.first.find("new", 0, code[j].op.first.length()) != 0){
            //     new_op(code[j]);
            // }
            // else if(code[j].op.first == "[]="){
            //     string reg = get_reg_arg(code[j].arg1);
            //     string reg1 = get_reg_arg(code[j].arg2);
            //     string reg2 = get_reg_arg(code[j].res);
            //     free_reg(RAX);
            //     x86_instr ins = {"movq\t", reg + ",", RAX};
            //     x86_code.push_back(ins);
            //     ins = {"movq\t", reg1 + ",", RDI};
            //     x86_code.push_back(ins);
            //     ins = {"movq\t", "8(" + RAX + "), ", RAX};
            //     x86_code.push_back(ins);
            //     ins = {"movq\t", reg2 + ",", "8(" + RAX + ", " + RDI + ", 8)"};
            //     x86_code.push_back(ins);
            // }
            else if(code[j].op.first == "funcend"){
                // x86_instr ins = {"ret"};
                // x86_code.push_back(ins);
            }
            
            else if(code[j].op.first == "call"){
                // push all registers to stack;
                for(auto it:reg_map){
                    free_reg(it.first);
                }
                x86_instr ins = {"call\t", code[j].arg1.first};
                x86_code.push_back(ins);
                if(code[j].res.first != ""){
                    code[j].res.second->addr_desc.reg = RAX;
                    code[j].res.second->addr_desc.in_mem = false;
                    reg_map[RAX].push_back(code[j].res);
                }

            }
            else if(code[j].op.first == "RET"){
                if(code[j].arg1.first != ""){
                    reg reg1;
                    if(is_int(code[j].arg1.first)){
                        reg1 = RAX;
                        x86_instr ins = {"movq\t", "$" + code[j].arg1.first + ",", reg1};
                        x86_code.push_back(ins);
                    }
                    else{
                        reg1 = get_reg_arg(code[j].arg1,"");
                        if(reg1!=RAX){
                            x86_instr ins = {"movq\t", reg1 + ",", RAX};
                            x86_code.push_back(ins);
                        }
                    }
                }
                x86_code.push_back({"popq\t", "%rbp"});
                x86_instr ins = {"ret\t"};
                x86_code.push_back(ins);
            }
            else if(code[j].op.first == "push"){
                reg r;
                // cout<<"here"<<endl;
                if(code[j].arg1.first == "%rbp")
                r = "%rbp";
                else if(is_int(code[j].arg1.first)){
                    free_reg(RAX);
                    r = RAX;
                    x86_instr ins = {"movq\t", "$" + code[j].arg1.first + ",", r};
                    x86_code.push_back(ins);
                }
                else
                r = get_reg_arg(code[j].arg1,"");
                x86_instr ins = {"pushq\t", r};
                x86_code.push_back(ins);
            }
            else if(code[j].op.first == "pop"){
                
                reg r;
                if(code[j].arg1.first == "%rbp"){
                    r = "%rbp";
                    if(mark==0){
                        for(auto it:reg_map){
                            free_reg(it.first);
                        }
                        mark=1;
                    }
                    
                }
                else{
                    r = get_reg_arg(code[j].arg1,"");
                    x86_instr ins = {"pop\t", r};
                    x86_code.push_back(ins);
                }

            }
            else if(code[j].op.first == "label"){
                x86_instr ins = {"label\t", code[j].arg1.first};
                x86_code.push_back(ins);
            }
            else if(code[j].op.first == "goto" | code[j].op.first == "ifFalse"){

                jmp_instr(code[j]);
            }
            else if(code[j].op.first[0] == '+' | code[j].op.first[0] == '-' | code[j].op.first[0] == '*' | code[j].op.first[0] == '^' | code[j].op.first[0] == '|' | code[j].op.first[0] == '&' ){
                // cout<<j<<" op: "<<code[j].op.first<<endl;
                if(code[j].res.first == "%rsp"){
                    if(code[j].op.first == "+"){
                        x86_instr ins = {"add\t", "$" + code[j].arg2.first+", ", code[j].res.first};
                        x86_code.push_back(ins);
                    }
                    else if(code[j].op.first == "-"){
                        x86_instr ins = {"sub\t", "$" + code[j].arg2.first+", ", code[j].res.first};
                        x86_code.push_back(ins);
                    }
                }
                else bin_op(code[j]);
            }
            else if(code[j].op.first == "[+]")bin_op(code[j]);
            else if(code[j].op.first[0] == '/' | code[j].op.first[0] == '%'){
                div_op(code[j]);
                continue;
            }
            else if(code[j].op.first == "<" | code[j].op.first == ">" | code[j].op.first == "==" | code[j].op.first == "!=" | code[j].op.first == "<=" | code[j].op.first == ">="){
                comp_op(code[j]);
            }
            else if(code[j].op.first == "" || code[j].op.first.find("TO")!=code[j].op.first.npos){
                // cout << code[j].res.first << " " << code[j].arg1.first << " " << code[j].arg2.first << endl;
                assign(code[j]);
            }
            else if (code[j].op.first == "<<" || code[j].op.first == ">>"){
                // cout<<"jo\n";
                shift_op(code[j]);
            }
            else if(code[j].op.first == "!" || code[j].op.first == "-"){
                un_op(code[j]);
            }


            if(code[j].arg1.first[0]=='#'){
                // cout<<"temp: "<<code[j].arg1.first<<endl;
                code[j].arg1.second->addr_desc.temp_free = 1;
            }
            if(code[j].arg2.first[0]=='#'){
                // cout<<"temp: "<<code[j].arg2.first<<endl;
                code[j].arg2.second->addr_desc.temp_free = 1;
            }
        }
        if(mark==0){
            for(auto it:reg_map){
                free_reg(it.first);
            }
        }
    }

    cout << ".section" << "\t" << ".rodata" << endl;
    cout << ".LC0:" << endl;
    cout << "\t.string\t\"%d\\n\"" << endl;
    cout << "\t.text" << endl;
    cout << "\t.globl\tmain" << endl;

    for(auto it:x86_code){
        if(it[0][it[0].size()-1]!=':')cout << "\t";
        for(auto ir:it){
            cout<<ir<<" ";
        }
        cout << endl;
    }

    fstream f;
    f.open("./x86_code.s", ios::out);
    f << ".section" << "\t" << ".rodata" << endl;
    f << ".LC0:" << endl;
    f << "\t.string\t\"%d\\n\"" << endl;
    f << "\t.text" << endl;
    f << "\t.globl\tmain" << endl;
    // f << "\t.type\tmain, @function" << endl;
    for(auto it:x86_code){
        if(it[0][it[0].size()-1]!=':') f << "\t";
        for(auto ir:it){
            f<<ir<<" ";
        }
        f << endl;
    }
    return;
}
            