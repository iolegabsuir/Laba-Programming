#include <stdio.h>
#include <math.h>
int Ax, Ay, Bx, By, Cx, Cy;
float AB, AC, BC;
float P, S;
float r, R;
int isFull=0;
void DetermineTypeOfTriangle()
{
	int isArbitrary = 1;
	FindSides();
	 
	if (pow(AB, 2) == pow(AC, 2) + pow(BC, 2) || pow(BC, 2) == pow(AC, 2) + pow(AB, 2) || pow(AC, 2) == pow(AB, 2) + pow(BC, 2)) 
	{
		printf("\nTriangle is right");
		isArbitrary = 0;
	}
	if (AB == BC || AC == AB || BC == AC) {
		printf("\nTriangle is isosceles");
		isArbitrary = 0;
	}

	if (AB == BC == AC) {
		printf("\nTriangle is equilateral");
		isArbitrary = 0;
	}
	if (isArbitrary == 1) printf("Triangle is arbitrary");
}

void FindRadius()
{
	FindArea();
	FindPerimeter();
	r = S / P / 2;
	R = (AB * AC * BC) / S / 4;
}

void FindArea()
{
	FindSides();
	S = sqrt(P / 2 * ((P / 2 - AB) * (P / 2 - AC) * (P / 2 - BC)));
}

void FindPerimeter()
{

	FindSides();
	P = AB + AC + BC;

}

void FindSides()
{
	AB = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
	AC = sqrt(pow(Cx - Ax, 2) + pow(Cy - Ay, 2));
	BC = sqrt(pow(Cx - Bx, 2) + pow(Cy - By, 2));
}

void EnterTheCoordinats()
{
	printf("Enter coordinats:");
	printf("\nA(x):"); scanf_s("%d", &Ax);
	printf("\nA(y):"); scanf_s("%d", &Ay);
	printf("\nB(x):"); scanf_s("%d", &Bx);
	printf("\nB(y):"); scanf_s("%d", &By);
	printf("\nC(x):"); scanf_s("%d", &Cx);
	printf("\nC(y):"); scanf_s("%d", &Cy);
	isFull = 1;
}

int main() 
{
	int isRunning = 1;
	
	int userChoice=0;
	while (isRunning == 1) 
	{
		printf("\nMenu:");
		printf("\n1:Enter the coordinats");
		printf("\n2:Determine the type of triangle");
		printf("\n3:Find a perimetr");
		printf("\n4:Find area");
		printf("\n5:Find radius");
		printf("\n6:Credits");
		printf("\n7:Exit");
		scanf_s("\n%d", &userChoice);
		switch (userChoice)
		{
		case 1:
			EnterTheCoordinats();
			break;
		case 2:
			if (isFull == 0) {
				
				printf("Firstly enter the coordinats");
				break;
			}
			DetermineTypeOfTriangle();
			break;
		case 3:
			if (isFull == 0) {
				printf("Firstly enter the coordinats");
				break;
			}
			FindPerimeter();
			printf("\nP = %f", P);
			break;
		case 4:
			if (isFull == 0) {
				printf("Firstly enter the coordinats");
				break;
			}
			FindArea();
			printf("\nS = %f", S);
			break;
		case 5:
			if (isFull == 0) {
				printf("Firstly enter the coordinats");
				break;
			}
			FindRadius();
			printf("\nr = %f", r);
			printf("\nR = %f", R);
			break;
		case 6:
			printf("Developer: Oleg Krivenkov \n Version:  1.0");
			break;
		case 7:
			isRunning = 0;
			break;


		default:
			printf("Something go wrong .Enter again");
			break;
		}
		
		
		
	}

	

}

