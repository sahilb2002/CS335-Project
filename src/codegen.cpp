#include <codegen.h>

extern vector<quad>code;

vector<int>leaders;
void basicBlock(){
    for(int i=0; i<code.size(); i++){
        if(i==0){
            leaders.push_back(i);
        }
        else if(code[i].op == GOTO){
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op == IFFALSE){
            leaders.push_back(code[i].idx);
            leaders.push_back(i+1);
        }
        else if(code[i].op == "func"){
            leaders.push_back(i);
        }
    }
}