#include <iostream>
using namespace std;
 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
 
    // val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

void createTree(int arr[],int n,struct Node *root)
{
    for(int i=0;i<n;i++)
    {
        root->data=arr[i];
        
    }
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}