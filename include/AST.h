#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include "TAC.h"
using namespace std;


typedef struct treeNode{
	int node_id;
	string node_name;
	string lexeme;
	int dim;
	string type;
	qel_t addr;
	vector<string> typevec;
	vector<treeNode*> children;
	vector<string> arr_dims;
	int dims_count_1;
	int dims_count_2;
	int dims_count_3;

	int first_instr;
	int last_instr;

	int falselist;
	int truelist;
}treeNode;

void beginAST();
void endAST();

void insertAttr(vector<treeNode*>&v, treeNode*nod , string s , int flag );
treeNode *makeleaf(string);
treeNode *makenode(string , vector<treeNode*>&);

#endif