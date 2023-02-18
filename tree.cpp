#include "tree.h"

void CreateTree(Node*& pNode, int n)
{
    if (pNode == NULL) return; else
    {
        pNode = new Node;
        datatype data;
        cin >> data;
        pNode->key = data;
        pNode->left = pNode->right = NULL;
        int n_left = n / 2;
        int n_right = n - n_left - 1;
        CreateTree(pNode->left, n_left);
        CreateTree(pNode->right, n_right);
    }
}

void ShowTree(Node*& pNode, int L)
{
    if (pNode == NULL) return;
    ShowTree(pNode->left, L + 1);
    for (int i = 0; i < L; i++)
    {
        cout << "    ";
    }
    cout << pNode->key << endl;
    ShowTree(pNode->right, L + 1);
}

void PrefixOrder(Node*& pNode)
{

    if (pNode == NULL) return;

    cout << pNode->key << endl;
    PrefixOrder(pNode->left);
    PrefixOrder(pNode->right);

}
void PostfixOrder(Node*& pNode)
{
    if (pNode == NULL) return;

    PostfixOrder(pNode->left);
    PostfixOrder(pNode->right);
    cout << pNode->key << endl;
}

void InfixOrder(Node*& pNode)
{
    if (pNode == NULL) return;

    InfixOrder(pNode->left);
    cout << pNode->key << endl;
    InfixOrder(pNode->right);
}

bool SearchNodeBST(Node* pNode, datatype key)
{
    if (pNode == NULL) return false;
    else if (pNode->key == key) return true;
    else if (key < pNode->key) return SearchNodeBST(pNode->left, key);
    else return SearchNodeBST(pNode->right, key);
}

Node* CreateRootBST(datatype key)
{
    Node* pNode = new Node;
    pNode->key = key;
    pNode->parent = pNode->left = pNode->right = NULL;
    return pNode;
}

Node* InsertNodeBST(Node*& root, datatype key)
{
    if (root == NULL)
    {
        root = CreateRootBST(key);
        return root;
    }
    else
        if (key <= root->key) root->left = InsertNodeBST(root->left, key); else
            root->right = InsertNodeBST(root->right, key);
    return root;
}

Node* SuccessorNodeBST(Node* pNode)
{
    Node* previous = NULL;
    if (pNode->right)
    {
        previous = pNode->right;
        while (previous->left) previous = previous->left;
    }
    else
    {
        previous = pNode->parent;
        while (previous != NULL && pNode == previous->right)
        {
            pNode = previous;
            previous = previous->parent;
        }
    }
    return previous;
}

Node* PredecessorNodeBST(Node* pNode)
{
    Node* previous = NULL;
    if (pNode->left)
    {
        previous = pNode->left;
        while (previous->right) previous = previous->right;
    }
    else
    {
        previous = pNode->parent;
        while (previous != NULL && pNode == previous->left)
        {
            pNode = previous;
            previous = previous->parent;
        }
    }
    return previous;
}

Node* MinimumNodeBST(Node* pNode)
{
    if (pNode == NULL) return NULL;
    while (pNode->left)
    {
        pNode = pNode->left;
    }
    return pNode;

}

Node* MaximumNodeBST(Node* pNode)
{
    while (pNode->right) pNode = pNode->right;
    return pNode;
}

Node* DeleteNodeBST(Node*& delNode, datatype key)
{
    if (delNode == NULL) return delNode;
    if (delNode->key > key) delNode->left = DeleteNodeBST(delNode->left, key); else
        if (delNode->key < key) delNode->right = DeleteNodeBST(delNode->right, key); else
        {
            if (delNode->left == NULL && delNode->right == NULL)
            {
                delete delNode;
                delNode = NULL;
                return delNode;
            }
            else
                if (delNode->left == NULL)
                {
                    Node* temp = delNode;
                    delNode = delNode->right;
                    delete temp;
                    return delNode;
                }
                else
                    if (delNode->right == NULL)
                    {
                        Node* temp = delNode;
                        delNode = delNode->left;
                        delete temp;
                        return delNode;
                    }
            Node* temp = MinimumNodeBST(delNode->right);
            delNode->key = temp->key;
            delNode->right = DeleteNodeBST(delNode->right, temp->key);
        }
    return delNode;
}
