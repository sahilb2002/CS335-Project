#pragma once

#include <bits/stdc++.h>
using namespace std;


typedef struct{
	int node_id;
	string node_name;
}treeNode;

typedef struct{
	treeNode* node;
	string str;
	bool is_node;
}data;

void beginAST();
void endAST();

void insertAttr(vector<data>&, treeNode* , string , int );
treeNode *makeleaf(string);
treeNode *makenode(string , vector<data>&);