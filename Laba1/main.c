#include <malloc.h>
#include <stdio.h>
#include <new.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{

	int  m=-1;
	int TheBiggestDigit = 1;
	int TheBiggestDigitBin = 1;
	int n = 0;
	printf("Enter m:");
	scanf("%d", &m);
	//Находим  последнее число,которое меньше m 
	while (TheBiggestDigit <= m)
	{
		TheBiggestDigit = TheBiggestDigit * 2 + 1;
		TheBiggestDigitBin = TheBiggestDigitBin * 10 + 1;
		n++;
	}
	TheBiggestDigit = (TheBiggestDigit - 1) / 2;
	TheBiggestDigitBin = (TheBiggestDigitBin - 1) / 10;
	// Записываем в массив все числа ,меньше m
	int* digits = NULL;
	digits = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		digits[i] = TheBiggestDigit;
		TheBiggestDigit = (TheBiggestDigit - 1) / 2;
	}
	//Вывод чисел в двух системах счисления
	for (int i = 0; i < n; i++)
	{

		printf("\n%d \t %d" , digits[i],TheBiggestDigitBin);
		TheBiggestDigitBin = (TheBiggestDigitBin - 1) / 10;
	}
	
	
	free(digits);
    printf("\n");
    system("pause");
}