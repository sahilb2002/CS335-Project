#include <AST.h>
#include<iostream>

extern FILE *dotfile;

treeNode *root = NULL;

int NodeCounter = 0;
void beginAST(){
	if(dotfile)
	fprintf(dotfile, "digraph AST {\n\tordering=out;\n");
}
void endAST(){
	if(dotfile)
	fprintf(dotfile, "}\n");
}


void insertAttr(vector<treeNode*> &v, treeNode* nod, string s, int flag){
	if(flag==0){
		nod = new treeNode;
		nod->node_name = s;
		nod->node_id = ++NodeCounter;
		if(dotfile)
		if(s!="") fprintf(dotfile, "\t%d [label=\"%s\"];\n", nod->node_id, s.c_str());
	}
	v.push_back(nod);
}

treeNode *makeleaf(string str){
	//making leaf node and printing it in dot file
	treeNode *node = new treeNode;
	node->node_id = ++NodeCounter;
	
	string tmp = "";
	for(int i=0; i<str.length(); ++i){
		tmp+=str[i];
		if(str[i]=='\\') tmp+=str[i];	
	}
	node->node_name = tmp;

	if(str[0]=='"'){
		string s = tmp.substr(1,tmp.length()-2);
		if(dotfile)
		fprintf(dotfile, "\t%d [label=\"\\\"%s\\\"\" shape=box style=filled color=\"dodgerblue\" fillcolor=\"lightyellow\"];\n", node->node_id, s.c_str());
	}
	else{
		if(dotfile)
		fprintf(dotfile, "\t%d [label=\"%s\" shape=box style=filled color=\"dodgerblue\" fillcolor=\"lightyellow\"];\n", node->node_id,node->node_name.c_str() );
	}

	return node;
}

treeNode *makenode(string s, vector<treeNode*> &v){
	//making node and printing it in dot file
	treeNode *node = new treeNode;
	node->node_name = s;
	node->node_id = ++NodeCounter;

	vector<int> op_id;
	if(dotfile)
	fprintf(dotfile, "\t%d [label=\"%s\"];\n", node->node_id, node->node_name.c_str());

	int j=0;
	for(auto nod:v){
		// if string is NULL, dont print in dot 
		if( nod && nod->node_name !="" ) {
			if(dotfile)
			fprintf(dotfile, "\t%d -> %d;\n", node->node_id, nod->node_id);
			node->children.push_back(nod);
		}

	}

	return node;

}