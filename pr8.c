#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>


void fillArray(int* arr, int start, int end) 
{
	if(start < end) 
	{
		arr[start] = rand() % 21 + -10;
		fillArray(arr, start + 1, end);
	}
}


void printArray(int* arr, int start, int end)
{
	if (start < end)
	{
		printf("|%d|", arr[start]);
		printArray(arr, start + 1, end);
	}
}


int* createArray(int size) 
{
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr != NULL) 
	{
		fillArray(arr, 0, size);
		
	}
	return arr;
}


int countMax(int* arr, int size, int max) 
{
	if (size == 0) 
	{
		return 0;
	}
	if (arr[0] == max) 
	{
		return 1 + countMax(arr + 1, size - 1, max);
	}
	else 
	{
		return countMax(arr + 1, size - 1, max);
	}
}


int findMax(int* arr, int size) 
{
	if (size == 0) 
	{
		return 0;
	}
	int resMax = findMax(arr + 1, size - 1);
	return (arr[0] > resMax) ? arr[0] : resMax;
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int SIZE = 10;
	int* arr = createArray(SIZE);
	printf("Массив:\n");
	int max = findMax(arr, SIZE);
	int cMax = countMax(arr, SIZE, max);
	printArray(arr, 0, SIZE);
	printf("\nМаксимум в массиве: %d\n", max);
	printf("Количество максимумов в массиве: %d", cMax);
	free(arr);
	return 0;
}