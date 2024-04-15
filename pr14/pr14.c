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
    file = fopen(path, "w");
    fwrite(student_list, sizeof(ListStudent), 1, file);
    fclose(file);
    return 0;
}


// ListStudent* loadFile(char* path)
// {
//     ListStudent* list = l_init();
//     FILE* file;
//     file = fopen(path, "r");
//     if (file == NULL)
//     {
//         printf("Файл не существует!\n");
//         exit(-1);
//     }
//     char* str[8];
//     for (int i = 0; i < 8; i++) {
//         str[i] = (char *)malloc(100 * sizeof(char));
//     }
//     int i = 0;
//     while (!feof(file))
//     {
//         fscanf(file, "%s", str[i]);
//         i++;
//         if (i >= 8)
//         {
//             list->append(list, Stud(str));
//             i = 0;
//         }
//     }
//     fclose(file);
//     return list;
// }


void main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Никита", "Поликанов", "м", "ИСП-205", "17", "5", "5", "5"};
    char* student1_args[] = {"Виктор", "Гнильцов", "м", "ИСП-205", "17", "5", "4", "2"};
    ListStudent* student_list = ListInit;
    Node* newNode = malloc(sizeof(Node));
    newNode->stud = Stud(student_args);
    newNode->list = student_list;
    student_list->append(newNode);
    newNode->stud = Stud(student1_args);
    student_list->append(newNode);

    saveFile("test.txt", student_list);
    // ListStudent* new_list = loadFile("test.bin");
    for (int i = 0; i < student_list->size; i++)
        {
            newNode->index = i;
            student_list->get(newNode);
        }
}
