#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>
//Тема работы : Динамическая память.
//Каждая программа должна освобождать динамическую память сразу, как только хранящиеся в ней данные больше не нужны.
//Создать одномерный массив с целыми числами.Составить еще один одномерный массив, который будет содержать только ... из исходного массива :
//18. Последовательности из нечётных чисел.
void main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int SIZE = 10;
	int pos = 0;
	int* arr = (int*)malloc(sizeof(int) * SIZE);

	int* resArr = malloc(0);
	printf("Исходный массив:\n");
	for (int i = 0; i < SIZE; i++) {
		*(arr+i) = rand() % 10 + 1;
		printf("|%d|", arr[i]);
	}
	printf("\nРезультат:\n");
	for (int i = 0; i < SIZE; i++) {
		if (*(arr + i) % 2 != 0) {
			*(resArr + pos) = *(arr + i);
			pos++;

		}
	}
	resArr = realloc(resArr, pos * sizeof(int));
	for (int i = 0; i < pos; i++) {
		printf("|%d|", resArr[i]);
	}
	free(arr);
	free(resArr);
}