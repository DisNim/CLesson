#include "liststudent.h"
#include <malloc.h>
#include "student.h"
#include <stdio.h>
#include "savestudent.h"


List* init()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->get = l_get;
    list->print = l_print;
    list->append = l_append;
    return list;
}


void* l_append(void* args)
{
    SaveStudent* save = (SaveStudent*)args;
    List* list = save->list;
    if (list->size == 0)
    {
       list->head = save->stud;
       list->tail = list->head;
    }
    else
    {
        list->tail->next = save->stud;
        list->tail = save->stud;
    }
    list->size++;
}


void* l_print(void* args)
{
    SaveStudent* save = (SaveStudent*)args;
    StudentData* stud_data = save->list->head;
    for (int i = 0; i < save->list->size; i++)
    {
        Student* stud = stud_data->stud;
        printf("%s %s %s %s %d: %d %d %d\n", stud->surname, stud->name, stud->gender, stud->group, stud->age, stud->grade_chemestry, stud->grade_math, stud->grade_phisics);
        stud_data = stud_data->next;
    }
}


void* l_get(void* args)
{
    SaveStudent* save = (SaveStudent*)args;
    StudentData* stud_data = save->list->head;
    for (int i = 0; i < save->list->size; i++)
    {
        Student* stud = stud_data->stud;
        if (stud->grade_chemestry == 2 || stud->grade_math == 2 || stud->grade_phisics == 2 ||
            stud->grade_chemestry == 3 || stud->grade_math == 3 || stud->grade_phisics == 3)
        {
            printf("%s %s %s %s %d: %d %d %d\n", stud->surname, stud->name, stud->gender, stud->group, stud->age, stud->grade_chemestry, stud->grade_math, stud->grade_phisics);
        }
        stud_data = stud_data->next;
    }
}