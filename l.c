#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void fillArray(int*, int);
void printArray(int*, int);
int* createArray(int);
void fillDArray(int**, int,int);
int** createDArray(int, int);
int findMax(int**,int,int);
int countMaxs(int*, int, int);
int findMaxInRow(int** arr, int row, int col, int max);
void pr2(int);
void freeDArray(int**, int);
void pr3(int, int);
void pr5(int size);
double multiply(double, double);
double sum(double, double);
double divide(double, double);
double substract(double, double);


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
  void (*fPrint)(int*, int) = printArray;
  if (arr != NULL)
  {
    fArray(arr, size);
    fPrint(arr, size);
  }
  return arr;
}


void fillDArray(int** dArr, int row, int col)
{
  void (*fArray)(int*, int) = fillArray;
  for (int i = 0; i < row; i++)
    fArray(dArr[i], col);
}


void printDArray(int** dArr, int row, int col)
{
    void (*fPrint)(int*, int) = printArray;
    for (int i = 0; i < row; i++)
        fPrint(dArr[i], col);

}


int** createDArray(int row, int col)
{
  int** dArr = (int**)malloc(row * sizeof(int*));
  for (int i = 0; i < row; i++)
  {
    dArr[i] = (int*)malloc(col * sizeof(int));
  }
  void (*fArray)(int**, int, int) = fillDArray;
  void (*fPrint)(int**, int, int) = printDArray;
  if (dArr != NULL)
  {
    fArray(dArr, row, col);
    fPrint(dArr, row, col);
  }
  return dArr;
}


int findMax(int** arr, int row, int col)
{
  int max = arr[0][0];
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (arr[i][j] > max)
      {
        max = arr[i][j];
      }
    }
  }
  return max;
}


int findMaxInRow(int** arr, int row, int col, int max)
{
  int countMaxInRow = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
    {
      if (arr[i][j] == max)
        countMaxInRow++;
    }
  return countMaxInRow;
}


int findMaxInCol(int** arr, int row, int col, int max)
{
  int countMaxInCol = 0;
  for (int i = 0; i < col; i++)
    for (int j = 0; j < row; j++)
    {
      if (arr[j][i] == max)
        countMaxInCol++;
    }
  return countMaxInCol;
}


void freeDArray(int** arr, int row)
{
  for (int i = 0; i < row; i++)
  {
    free(arr[i]);
  }
  free(arr);
}


void pr2(int size)
{
    int* (*cArray)(int) = createArray;
    int* arr = cArray(size);
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
        arr[j + 1] = arr[j];
        j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\n��� ��� ����� ������� �����: ");
    for (int i = 0; i < 3 && i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}


void pr3(int row, int col)
{
    int** (*cArray)(int, int) = createDArray;
    int** dArr = cArray(row, col);
    int (*fMax)(int**, int, int) = findMax;
    int (*fMaxCol)(int**, int, int, int) = findMaxInCol;
    int (*fMaxRow)(int**, int, int, int) = findMaxInRow;
    int max = fMax(dArr, row, col);
    int countMaxInRow, countMaxInCol;
    countMaxInCol = fMaxCol(dArr, row, col, max);
    countMaxInRow = fMaxRow(dArr, row, col, max);
    printf("\n���������� ���������� � ������: %d\n", countMaxInRow);
    printf("���������� ���������� � ��������: %d", countMaxInCol);
    void (*freeArray)(int**, int) = freeDArray;
    freeArray(dArr, row);
}


void pr5(int size)
{
    int* (*cArray)(int) = createArray;
    int* arr = cArray(size);
    int* res = malloc(0);
    int pos = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
        {
        res = realloc(res, (pos + 1) * sizeof(int));
        res[pos] = arr[i] * arr[i];
        pos++;
        }
    void (*pArray)(int*, int) = printArray;
    pArray(res, pos);
    free(arr);
    free(res);
}


void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    const int SIZE = 10;
    const int ROW = 10;
    const int COL = 10;
    void (*pr_pr2)(int) = pr2; 
    pr_pr2(SIZE);
    printf("\n��3\n");
    void (*pr_pr3)(int, int) = pr3; 
    pr_pr3(ROW, COL);
    printf("\n��5\n");
    void (*pr_pr5)(int) = pr5; 
    pr_pr5(SIZE);
    double a,b;
    printf("������� ������ �����: ");
    scanf("%f", &a);
    printf("������� ������ �����: ");
    scanf("%f", &b);
    double (*calc[4])(double, double) = {sum, multiply, divide, substract};
    printf("���������");
    for (int i = 0; i < 4; i++)
        printf("%f\n", calc[i](a,b));
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
