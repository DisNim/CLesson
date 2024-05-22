#include "savestudent.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "liststudent.h"
#include "student.h"


void* saveFile(char* path, void* args)
{
    FILE* file = fopen(path, "wb");
    errno_t my_error = errno;
    List* list = (List*)args;
    StudentData* students = list->head;
    if (file == NULL)
    {
        printf("Код ошибки: %d\n", my_error);
        perror("Сохранение файла файла"); 
    }
    for (int i = 0; i < list->size; i++)
    {
        Student* stud = students->stud;
        fwrite(stud->surname, 2*sizeof(char*), 1, file);
        fwrite(stud->name, 2*sizeof(char*), 1, file);
        fwrite(stud->gender, 2*sizeof(char*), 1, file);
        fwrite(stud->group, 2*sizeof(char*), 1, file);
        fwrite(&stud->age, sizeof(int), 1, file);
        fwrite(&stud->grade_chemestry, sizeof(int), 1, file);
        fwrite(&stud->grade_math, sizeof(int), 1, file);
        fwrite(&stud->grade_phisics, sizeof(int), 1, file);
        students = students->next;
    }
    fclose(file);
}


void* loadFile(char* path)
{
    List* list = list_init;
    errno_t my_error = errno;
    SaveStudent* save = malloc(sizeof(SaveStudent));
    save->list = list;
    FILE* file = fopen(path, "rb");
    if (file == NULL)
    {
        printf("Код ошибки: %d\n", my_error);
        perror("Загрузкаs файла"); 
    }
    while (!feof(file))
    {
        Student* stud = malloc(sizeof(Student));
        stud->surname = malloc(sizeof(char));
        stud->name = malloc(sizeof(char));
        stud->gender = malloc(sizeof(char));
        stud->group = malloc(sizeof(char));
        fread(stud->surname, 2*sizeof(char*), 1, file);
        fread(stud->name, 2*sizeof(char*), 1, file);
        fread(stud->gender, 2*sizeof(char*), 1, file);
        fread(stud->group, 2*sizeof(char*), 1, file);
        fread(&stud->age, sizeof(int), 1, file);
        fread(&stud->grade_chemestry, sizeof(int), 1, file);
        fread(&stud->grade_phisics, sizeof(int), 1, file);
        fread(&stud->grade_math, sizeof(int), 1, file);
        stud->surname = realloc(stud->surname, strlen(stud->surname) / sizeof(char));
        stud->name = realloc(stud->name, strlen(stud->name) / sizeof(char));
        stud->gender = realloc(stud->gender, strlen(stud->gender) / sizeof(char));
        stud->group = realloc(stud->group, strlen(stud->group) / sizeof(char));
        save->stud = saveStudent(stud);
        list->append(save);
    }
    list->size--;
    fclose(file);
    return list;
}