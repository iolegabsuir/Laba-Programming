#include <stdlib.h>
#include <stdbool.h>

struct Node{
    struct Node * left;
    struct Node * middle;
    struct Node * right;
    int data;
};


struct Node * GetNewNode(int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;

    return newNode;
}


struct Node * InsertNode(struct Node * root, int data){
    if (!root){
        root = GetNewNode(data);
    }
    else if(root->data > data)
        root->left = InsertNode(root->left, data);
    else if (root->data < data)
        root->right = InsertNode(root->right, data);
    else if (root->data == data)
        root->middle = InsertNode(root->middle, data);

    return root;
}


void Insert(struct Node ** root, int data){
    *root = InsertNode(*root, data);
}


