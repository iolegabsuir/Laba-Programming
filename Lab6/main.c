#include <stdio.h>
#include "TripleTree.h"


int count_depth(struct Node * root);
int Max(int a, int b, int c);


int main() {

    printf("\n");

    struct Node * root = NULL;

    // Inserting items to Tree
    int i;
    int x;
    printf("Inserted items: ");
    for(i = 0; i < 10; i++){
        x = rand() % 20;
        Insert(&root, x);
        printf("%i ", x);
    }
    printf("\n");


    // Finding number of levels
    int Depth = count_depth(root);
    printf("Numbers of tree's levels is - %i\n", Depth);

    printf("\n");
    system("pause");
    return 0;
}


int Max(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}


int count_depth(struct Node * root) {
    if (!root)
        return 0;

    int left = count_depth(root->left);
    int middle = count_depth(root->middle);
    int right = count_depth(root->right);

    return Max(left, middle, right) + 1;
}