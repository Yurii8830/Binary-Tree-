#include "tree.h"
Node* pNode = NULL;
int main()
{
    cout << "Input the size of tree: " << endl;
    int n;
    cin >> n;
    cout << "Input the values:" << endl;
    int key;
    int i = 0;
    while (i < n)
    {
        cin >> key;
        if (SearchNodeBST(pNode, key))
        {
            cout << "A node with such data is already exist. Please, input the other value. " << endl;
        }
        else
        {
            InsertNodeBST(pNode, key);
            i++;
        }
    }
    cout << "Tree: " << endl;
    ShowTree(pNode, 0);
    char choice;
    cout << "Menu:" << endl;
    cout << "1. Insert value;" << endl;
    cout << "2. Delete value;" << endl;
    cout << "3. Infix order;" << endl;
    cout << "4. Postfix order;" << endl;
    cout << "5. Prefix order;" << endl;
    cout << "6. Search;" << endl;
    cout << "7. Exit;" << endl;
    cout << "Input your choice: " << endl;
    cin >> choice;
    while (choice >= '1' && choice <= '6')
    {
        switch (choice) {
        case '1':
            cout << "Input the value you want to insert: ";
            cin >> key;
            cout << endl;
            InsertNodeBST(pNode, key);
            cout << "Tree: " << endl;
            ShowTree(pNode, 0);
            break;
        case '2':
            cout << "Input the value you want to delete: ";
            cin >> key;
            cout << endl;
            if (!SearchNodeBST(pNode, key)) cout << "A node with such data doesn't exist." << endl; else
            {
                DeleteNodeBST(pNode, key);
                cout << "Tree: " << endl;
                ShowTree(pNode, 0);
            }
            break;
        case '3':
            cout << endl << "Infix order:" << endl;
            InfixOrder(pNode);
            break;
        case '4':
            cout << endl << "Postfix order:" << endl;
            PostfixOrder(pNode);
            break;
        case '5':
            cout << endl << "Prefix order:" << endl;
            PrefixOrder(pNode);
            break;
        case '6':
            cout << "Search:" << endl;
            cin >> key;
            if (!SearchNodeBST(pNode, key)) cout << "A node with such data doesn't exist." << endl; else
                cout << "Element found" << endl;
            break;
        }
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Insert value;" << endl;
        cout << "2. Delete value;" << endl;
        cout << "3. Infix order;" << endl;
        cout << "4. Postfix order;" << endl;
        cout << "5. Prefix order;" << endl;
        cout << "6. Search;" << endl;
        cout << "7. Exit;" << endl;
        cout << "Input your choice: " << endl;
        cin >> choice;
    }
    return 0;
}
