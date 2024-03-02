#include <stdio.h>
#include "liststudent.h"
#include "student.h"
#include <malloc.h>
#include <locale.h>

void* l_append(void*, void*);
int l_get(void*, int);

Student* s_init(void* args)
{
    struct Student* list = malloc(sizeof(struct Student));
    if (!list)
        return NULL;
    
    char** params = (char**)args;
    list->name = params[0];
    list->surname = params[1];
    list->gender = params[2];
    list->group = params[3];
    list->age = atoi(params[4]);
    list->asses_chemistry = atoi(params[5]);
    list->asses_math = atoi(params[6]);
    list->asses_phisic = atoi(params[7]);
    list->next = NULL;
    return list;
}

ListStudent* l_init()
{
    struct ListStudent* result = malloc(sizeof(struct ListStudent));
    result->append = l_append;
    result->get = l_get;
    result->head = NULL;
    result->tail = NULL;
    result->size = 0;
    return result;
}


void* l_append(void* list, void* stud)
{
    ListStudent* l = (ListStudent*)list;
    Student* s = (Student*)stud;
    if (l->size == 0)
    {
        l->head = s;
        l->tail = l->head;
    }
    else {
        l->tail->next = s;
        l->tail = s;
    }
    l->size++;
}


int l_get(void* list, int index)
{
    ListStudent* l = (ListStudent*)list;
    if (index >= 0 && index < l->size)
    {
        Student* tmp = l->head;
        for (int i = 0; i < l->size; i++)
        {
            if (i == index)
            {
                if (tmp->asses_chemistry == 2 || tmp->asses_math == 2 || tmp->asses_phisic == 2 || tmp->asses_chemistry == 3 || tmp->asses_math == 3 || tmp->asses_phisic == 3)
                {
                    printf("%s %s.", tmp->surname, tmp->name);
                    return 0;
                }
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
	else
    	printf("Нет такого индекса.");
    return -1;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Никита", "Поликанов", "м", "ИСП-205", "17", "5", "5s", "5"};
    char* student1_args[] = {"Виктор", "Гнильцов", "м", "ИСП-205", "17", "5", "4", "2"};
    ListStudent* student_list = l_init();
    student_list->append(student_list, s_init(student_args));
    student_list->append(student_list, s_init(student1_args));
    for (int i = 0; i < student_list->size; i++)
		student_list->get(student_list, i);
    return 0;
}