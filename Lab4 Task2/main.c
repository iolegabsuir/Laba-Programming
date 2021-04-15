#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"


int main() {
    FILE* f = fopen("input.txt", "r");
    if(f == NULL)
    {
        printf("Error occured");
        return 1;
    }
    if(counter(f))
    {
        printf("Amount of words equal to sum of all digits");
    }
    else
    {
        printf("Amount of words not equal to sum of all digits");
    }
    fclose(f);
    return 0;
}