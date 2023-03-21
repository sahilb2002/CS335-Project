#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
using namespace std;


typedef struct treeNode{
	int node_id;
	string node_name;
	string lexeme;
	int dim;
	string type;
	vector<string> typevec;
	vector<treeNode*> children;
}treeNode;

void beginAST();
void endAST();

void insertAttr(vector<treeNode*>&v, treeNode*nod , string s , int flag );
treeNode *makeleaf(string);
treeNode *makenode(string , vector<treeNode*>&);

#endif