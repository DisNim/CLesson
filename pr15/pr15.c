#include <stdio.h>
#include "liststudent.h"
#include "student.h"
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>


int saveFile(char* path, ListStudent* student_list)
{
    FILE* file;
    file = fopen(path, "wb");
    fwrite(student_list, sizeof(ListStudent), 1, file);
    fclose(file);
    return 0;
}


ListStudent* loadFile(char* path)
{
    ListStudent* list = malloc(sizeof(ListStudent));
    FILE* file;
    file = fopen(path, "rb");
    fread(list, sizeof(ListStudent), 1, file);
    fclose(file);
    return list;
}


void main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Степа", "Иванов", "м", "ИСП-205", "17", "5", "5", "5"};
    char* student1_args[] = {"Виктор", "Гнильцов", "м", "ИСП-205", "17", "5", "4", "2"};
    
    ListStudent* student_list = ListInit;
    Node* newNode = malloc(sizeof(Node));
    newNode->stud = Stud(student_args);
    newNode->list = student_list;
    student_list->append(newNode);
    newNode->stud = Stud(student1_args);
    student_list->append(newNode);

    saveFile("test.bin", student_list);
    ListStudent* new_list = loadFile("test.bin");
    for (int i = 0; i < new_list->size; i++)
        {
            newNode->index = i;
            new_list->get(newNode);
        }
}
