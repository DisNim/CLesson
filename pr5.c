#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>
//���� ������ : ������������ ������.
//������ ��������� ������ ����������� ������������ ������ �����, ��� ������ ���������� � ��� ������ ������ �� �����.
//������� ���������� ������ � ������ �������.��������� ��� ���� ���������� ������, ������� ����� ��������� ������ ... �� ��������� ������� :
//18. ������������������ �� �������� �����.
void main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int SIZE = 10;
	int pos = 0;
	int* arr = (int*)malloc(sizeof(int) * SIZE);

	int* resArr = malloc(0);
	printf("�������� ������:\n");
	for (int i = 0; i < SIZE; i++) {
		*(arr+i) = rand() % 10 + 1;
		printf("|%d|", arr[i]);
	}
	printf("\n���������:\n");
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