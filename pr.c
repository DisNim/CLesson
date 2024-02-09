#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>


void fillArray(int*, int);
void printArray(int*, int);
int* createArray(int);
void fillDArray(int**, int,int);
int** createDArray(int, int);
int findMax(int*, int);
int countMaxs(int*, int, int);
int findMaxInDArray(int**, int, int);
void pr2(int);
void freeDArray(int**, int);
void pr3(int, int);
void pr5(int);
double multiply(double, double);
double sum(double, double);
double divide(double, double);
double substract(double, double);


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int SIZE = 10;
	const int ROW = 10, COL = 10;
	double a, b;
	void (*executePr2)(int) = pr2;
	executePr2(SIZE);
	printf("\n-------------------------------------\n");
	void (*executePr3)(int,int) = pr3;
	executePr3(ROW, COL);
	printf("\n--------------------------------------\n");
	void (*executePr5)(int) = pr5;
	executePr5(SIZE);
	printf("\n--------------------------------------\n");
	printf("Введите первое число: ");
	scanf("%lf", &a);
	printf("Введите второе число: ");
	scanf("%lf", &b);
	double(*calc[4])(double, double) = {sum, multiply, divide, substract};
	printf("Рузультат:\n");
	for (int i = 0; i < 4; i++)
	{

		printf("%lf\n", calc[i](a, b));
	}
	system("pause");
}


void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
}


void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("|%d|", arr[i]);
	}
	printf("\n");
}


int* createArray(int size)
{
	int* arr = (int*)malloc(size * sizeof(int));
	void (*fArray)(int*, int) = fillArray;
	void (*pArray)(int*, int) = printArray;
	if (arr != NULL)
	{
		fArray(arr, size);
		pArray(arr, size);
	}
	return arr;
}


void fillDArray(int** arr, int row, int col)
{
	void (*fArray)(int*, int) = fillArray;
	for (int i = 0; i < row; i++)
	{
		fArray(arr[i], col);
	}
}


void printDArray(int** arr, int row, int col)
{
	printf("\n");
	void (*pArray)(int*, int) = printArray;
	for (int i = 0; i < row; i++)
	{
		pArray(arr[i], col);
	}
}


int** createDArray(int row, int col)
{
	int** dArr = (int**)malloc(row * sizeof(int*));
	int* (*cArray)(int) = createArray;
	void (*fDArray)(int**, int, int) = fillDArray;
	void (*pDArray)(int**, int, int) = printDArray;
	for (int i = 0; i < row; i++)
	{
		dArr[i] = cArray(col);
	}
	if (dArr != NULL)
	{
		fDArray(dArr, row, col);
		pDArray(dArr, row, col);
	}
	return dArr;
}


int findMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}


int countMaxs(int* arr, int size, int max)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == max)
		{
			count++;
		}
	}
	return count;
}


int findMaxInDArray(int** arr, int row, int col)
{
	int max = 0;
	int (*fMax)(int*, int) = findMax;
	for (int i = 0; i < row; i++)
	{
		max = fMax(arr[i], col);
	}
	return max;
}


void pr2(int size)
{
	int* arr = createArray(size);
	int (*fMax)(int*, int) = findMax;
	int (*cMax)(int*, int, int) = countMaxs;
	int max = fMax(arr, size);
	int count = cMax(arr, size, max);
	printf("\nМаксимум: %d\nВстречается: %d", max, count);
	free(arr);
}


void freeDArray(int** arr, int row)
{
	for (int i = 0; i < row; i++)
	{
		free(arr[i]);
	}
	free(arr);
}


void pr3(int row, int col)
{
	int** arr = createDArray(row, col);
	int* maxs = malloc(0);
	int posMax = 0;
	int max = findMaxInDArray(arr, row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == max)
			{
				maxs = realloc(maxs, (posMax + 1) * sizeof(int));
				maxs[posMax] = i;
				posMax++;
			}
		}
	}

	printf("Максимум %d:", max);
	printArray(maxs, posMax);
	freeDArray(arr, row);
	free(maxs);
}


void pr5(int size)
{
	int* arr = createArray(size);
	int* secondArr = malloc(0);
	int pos = 1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			secondArr = realloc(secondArr, pos * sizeof(int));
			secondArr[pos - 1] = arr[i];
			pos++;
		}
	}
	printArray(secondArr, pos - 1);
	free(arr);
	free(secondArr);
}


double divide(double a, double b)
{
	return a / b;
}


double multiply(double a, double b)
{
	return a * b;
}


double sum(double a, double b)
{
	return a + b;
}


double substract(double a, double b)
{
	return a - b;
}
