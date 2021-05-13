#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int data;
    struct Node * next;
    int size;
};


void push(struct Node ** Stack, int num){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = num;
    node->next = *Stack;
    node->size ++;
    (*Stack) = node;
}


bool isEmpty(struct Node *Stack){
    return Stack == NULL;
}


int pop(struct Node ** Stack){
    if (!isEmpty(*Stack)) {
        int x = (*Stack)->data;
        (*Stack)->size --;
        struct Node *tempNode = *Stack;
        tempNode = *Stack;
        *Stack = tempNode->next;
        free(tempNode);
        return x;
    }
    else{
        //printf("Ooops, stack is empty");
        return 0;
    }
}


int peek(struct Node *Stack){
    if (!isEmpty(Stack))
        return Stack->data;
    else{
        printf("Stack is empty");
        return 0;
    }
}