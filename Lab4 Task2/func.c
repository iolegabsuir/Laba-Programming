#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

int counter(FILE* f) {
    int arr[2] = {0,0};
    char string[50];
    int i;
    char c;
    int temp;
    while (!feof(f)) {
        i = 0;
        fgets(string, 50, f);
        while (string[i] != '\0') {
            if (isdigit(string[i])) {
                c = string[i];
                temp = c- '0';
                arr[0] += temp;
            }
            if (string[i] == ' ') {
                arr[1]++;
            }
            i++;
        }
        arr[1]++;
    }
    if (arr[1] == arr[0])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}