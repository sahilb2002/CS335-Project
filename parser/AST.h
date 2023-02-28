#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
using namespace std;


typedef struct treeNode{
	int node_id;
	string node_name;
}treeNode;

typedef struct data{
	treeNode* node;
	string str;
	bool is_node;
}data;

void beginAST();
void endAST();

void insertAttr(vector<data>&v, treeNode*nod , string s , int flag );
treeNode *makeleaf(string);
treeNode *makenode(string , vector<data>&);

#endif