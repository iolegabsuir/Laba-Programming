#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#include <assert.h>

int main() {
    FILE* f = fopen("input.txt", "r");
    FILE* file = fopen("test.txt", "r");
    if(f == NULL)
    {
        printf("Error occured");
        return 1;
    }
    assert(counter(f) == 0);
    fclose(f);
    if(file == NULL)
    {
        printf("Error occured");
        return 1;
    }
    assert(counter(file) == 1);
    fclose(file);
    printf("Tests passed");
    return 0;
}