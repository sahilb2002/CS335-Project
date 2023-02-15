#include "common.h"

int ind;
string text;
int errcode;
map<string, vector<int>> csvmap;                            // lexeme: (count, token_id, index)
vector<pair<string,pair<int,int>>> errors;                               // (error lexeme, (line_no, error_code))

vector<string> tokens = {
    "Operator",
    "Seperator",
    "Keyword",
    "Identifier",
    "String Literal",
    "Literal",
    "Bool Literal",
    "Null Literal",
    "Floating Point",
    "Character Literal",
    "Text Block",
    "ERROR",
};

vector<string> err_msgs = {
    "Expected new line after \"\"\"",
    "got unexpected character",
    "Only single character allowed in character literal",
    "got unexpected literal",
    "Expected 'p'/'P' for exponent in hexadecimal float literal",
    "EOF detected before closing comment",
    "EOF detected before closing text block",
};

bool comp_pair(pair<string, vector<int>>& p1, pair<string, vector<int>>& p2){
    return p1.second[2] < p2.second[2];
}

void init(){
    ind = 0;
    text.clear();
    csvmap.clear();
    
}

int check_token(set<string>& keywords) {
    text = yytext;
    if (keywords.find(text) != keywords.end()) {
        return KEY;
    }
    else if (text=="true" || text=="false"){
        return BOOL;
    }
    else if (text=="null"){
        return NULL_LIT;
    }
    return ID;
}

void add_lexeme(int tok){
    text = yytext;
    if ( csvmap.find(text) == csvmap.end() ){
        vector<int> v = {1, tok, ind};
        csvmap[text] = v;
        ind++;
    }
    else{
        csvmap[text][0] += 1;
    }
    if (tok == ERR){
        errors.push_back(make_pair(text, make_pair(yylineno, errcode)));
    }
}

void dump_data(char* file_name){
    string fname = file_name;
    vector<pair<string, vector<int>>> data;
    for (auto tup :csvmap){
        data.push_back(make_pair(tup.first, tup.second));
    }
    sort(data.begin(),data.end(),comp_pair);
    ofstream fid(file_name);
    if(!fid.is_open()){
        cout << "ERROR: cannot open output file: "<<fname<<endl;
        return ;
    }

    fid <<  "LEXEME | TOKEN | COUNT"<<endl;
    
    for(auto tup : data){
        fid << tup.first << ", " << tokens[tup.second[1]] << ", " << tup.second[0] << endl;
    }

}

int __main(int argc, char** argv){
    if(argc!=3){
        cout<<"Usage:\n"<<"./a.out path/to/input.335(java) path/to/output.csv"<<endl;
        return -1;
    }
    string infile = argv[1];
    yyin = fopen(argv[1],"r");
    if(yyin == NULL){
        cout << "ERROR: Cannot open input file:"<<infile<<endl;
        return -1;
    }
    init();
    yylex();
    dump_data(argv[2]);

    // print errors:
    if (errors.size())
    cout<< "The following errors were found in the input file:"<<endl<<endl;
    for(auto tup : errors){
        cout << infile << ": " << tup.second.first << ":  " << RED << "error:  " << RESET << err_msgs[tup.second.second] <<endl;
        cout << "Line No: "<<tup.second.first<<" |     " <<RED <<tup.first << RESET <<endl;
        // cout << RED << "ERROR: " << RESET << "["<<tup.second<<"] "<<tup.first<<endl;
    }
    return 1;
}