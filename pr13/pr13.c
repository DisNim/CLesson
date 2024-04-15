#include <stdio.h>
#include "liststudent.h"
#include "student.h"
#include <malloc.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Никита", "Поликанов", "м", "ИСП-205", "17", "4", "5", "5"};
    char* student1_args[] = {"Виктор", "Гнильцов", "м", "ИСП-205", "17", "5", "4", "2"};
    ListStudent* student_list = ListInit;
    Node* newNode = malloc(sizeof(Node));
    newNode->list = student_list;
    newNode->stud = Stud(student_args);
    student_list->append(newNode);
    newNode->stud = Stud(student1_args);
    student_list->append(newNode);
    for (int i = 0; i < student_list->size; i++)
    {
        newNode->index = i;
	    student_list->get(newNode);
    }
    system("pause");
    return 0;
}