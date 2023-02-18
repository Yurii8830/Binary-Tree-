#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <iostream>

using namespace std;
typedef int datatype;

struct Node
{
    datatype key; // ≤нформац≥йне поле (ключ) вузла
    Node* parent = NULL; // ¬каз≥вник на батьк≥вський вузол
    Node* left = NULL; // ¬каз≥вник на л≥вого сина
    Node* right = NULL; // ¬каз≥вник на правого сина
};
extern Node* pNode;

void CreateTree(Node*& pNode, int n);
void ShowTree(Node*& pNode, int L);
void PrefixOrder(Node*& pNode);
void PostfixOrder(Node*& pNode);
void InfixOrder(Node*& pNode);
bool SearchNodeBST(Node* pNode, datatype key);
Node* CreateRootBST(datatype key);
Node* InsertNodeBST(Node*& root, datatype key);
Node* SuccessorNodeBST(Node* pNode);
Node* PredecessorNodeBST(Node* pNode);
Node* MinimumNodeBST(Node* pNode);
Node* MaximumNodeBST(Node* pNode);
Node* DeleteNodeBST(Node*& delNode, datatype key);
#endif // TREE_H

