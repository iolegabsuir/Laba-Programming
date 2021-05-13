#include "Stack.h"

struct Node *invert_stack(struct Node **stack);

int main(){

    struct Node *Stack = (struct Node *) malloc(sizeof(struct Node));

    int i;
    printf("\nElements in stack: \n");
    for(i = 1; i <= 20; i++){
        push(&Stack, i);
        printf("%i ", peek(Stack));
    }

    Stack = invert_stack(&Stack);

    printf("\n\nInverted stack elements while poping:\n");

    for(i = 0; i < 20; i++){
        printf("%i ", pop(&Stack));
    }

    printf("\n\n");
    
    
    free(Stack);
    system("pause");
    return 0;

}


struct Node *invert_stack(struct Node **stack){

    struct Node *tempStack = (struct Node *) malloc(sizeof(struct Node));

    int x = pop(stack);
    while(x){
        push(&tempStack, x);
        x = pop(stack);
    }

    return tempStack;

}