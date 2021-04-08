#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>



int main()
{
    
    int digits1[4] = { 1, 2, 3, 4 };
    int digits2[4] = { 3, 4, 1, 2 };
    int* p;

    int rows, cols;
    int i, j, k;

    printf("Enter rows: ");
    
    while (scanf("%d", &rows) != 1) 
        {
            if (scanf("%d", &rows) != 1) 
            {
                printf("Incorrect input, try again!");  
                printf("\nrows = ");
                while(getchar() != '\n') {}
            }
        }
    printf("Enter cols: ");
   
    while (scanf("%d", &cols) != 1) 
        {
            if (scanf("%d", &cols) != 1) 
            {
                printf("Incorrect input, try again!");  
                printf("\ncols = ");
                while(getchar() != '\n') {}
            }
        }
    int** A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        A[i] = (int*)malloc(cols * sizeof(int));
    }


    for (int i = 0; i < rows; ++i)
    {
        k = 0;
        p = i % 2 ? digits2 : digits1;

        for (int j = 0; j < cols; ++j)
        {
            A[i][j] = p[k++];

            if (k > 3)
                k = 0;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf( " %d ", A[i][j]);
        }
       printf( "\n");
    }

    for (int i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);
    system("pause");
    return 0;
}