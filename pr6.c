#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>


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
	int* arr = (int*) malloc(size * sizeof(int));
	if (arr != NULL)
	{
		fillArray(arr, size);
		printArray(arr, size);
	}
	return arr;
}


void fillDArray(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		fillArray(arr[i], col);
	}
}


void printDArray(int** arr, int row, int col)
{
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		printArray(arr[i], col);
	}
}


int** createDArray(int row, int col)
{
	int** dArr = (int**) malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		dArr[i] = createArray(col);
	}
	if (dArr != NULL)
	{
		fillDArray(dArr, row, col);
		printDArray(dArr, row, col);
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
	for (int i = 0; i < row; i++)
	{
		max = findMax(arr[i], col);
	}
	return max;
}


void pr2(int size)
{
	int* arr = createArray(size);
	int max = findMax(arr, size);
	int count = countMaxs(arr, size, max);
	printf("\nМаксимум: %d\nКоличество максимумов в массиве: %d", max, count);
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

	printf("Строки содержащие максимальное значение %d под номерами:", max);
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
			secondArr[pos-1] = arr[i];
			pos++;
		}
	}
	printArray(secondArr, pos-1);
	free(arr);
	free(secondArr);
}


void main()
{
	setlocale(LC_ALL, "Rus");
	srand( time(NULL) );
	const int SIZE = 10;
	const int ROW = 10, COL = 10;
	pr2(SIZE);
	printf("\n-------------------------------------\n");
	pr3(ROW, COL);
	printf("\n--------------------------------------\n");
	pr5(SIZE);
}
