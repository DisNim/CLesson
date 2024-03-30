#include <stdio.h>
#include "liststudent.h"
#include "student.h"
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

void* l_append(void*, void*);
int l_get(void*, void*);
char* l_get_data(void*, int);

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
    result->get_data = l_get_data;
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


char* l_get_data(void* list, int index)
{
    ListStudent* l = (ListStudent*)list;
    if (index >= 0 && index < l->size)
    {
        char* str = malloc(0);
        Student* tmp = l->head;
        for (int i = 0; i < l->size; i++)
        {
            if (i == index)
            {
                int required_size = snprintf(NULL, 0, "%s %s %s %s %d %d %d %d",
                                             tmp->surname, tmp->name, tmp->gender, tmp->group,
                                             tmp->age, tmp->asses_math, tmp->asses_chemistry, tmp->asses_phisic) + 1;
                str = realloc(str, required_size);
                sprintf(str, "%s %s %s %s %d %d %d %d",
                    tmp->surname, tmp->name, tmp->gender, tmp->group,
                    tmp->age, tmp->asses_math, tmp->asses_chemistry, tmp->asses_phisic);
                return str;
            }
            else
            tmp = tmp->next;
        }
    }
}


int l_get(void* list, void* index)
{
    ListStudent* l = (ListStudent*)list;
    int _index = *(int*)index;
    if (_index >= 0 && _index < l->size)
    {
        Student* tmp = l->head;
        for (int i = 0; i < l->size; i++)
        {
            if (i == _index)
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


int saveFile(char* path, ListStudent* student_list)
{
    FILE* file;
    file = fopen(path, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Файл не существует!\n");
        exit(-1);
    }
    for (int i = 0; i < student_list->size; i++)
    {
        char* data = student_list->get_data(student_list, i);
        if (data != NULL)
        {
            fprintf(file, "%s\n", data);
            free(data); 
        }
    }
    fclose(file);
    return 0;
}


ListStudent* loadFile(char* path)
{
    ListStudent* list = l_init();
    FILE* file;
    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Файл не существует!\n");
        exit(-1);
    }
    char* str[8];
    for (int i = 0; i < 8; i++) {
        str[i] = (char *)malloc(100 * sizeof(char));
    }
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%s", str[i]);
        i++;
        if (i >= 8)
        {
            list->append(list, s_init(str));
            i = 0;
        }
    }
    fclose(file);
    return list;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Никита", "Поликанов", "м", "ИСП-205", "17", "5", "5", "5"};
    char* student1_args[] = {"Виктор", "Гнильцов", "м", "ИСП-205", "17", "5", "4", "2"};
    ListStudent* student_list = l_init();
    student_list->append(student_list, s_init(student_args));
    student_list->append(student_list, s_init(student1_args));
    saveFile("test.txt", student_list);
    student_list = loadFile("test.txt");
    for (int i = 0; i < student_list->size; i++)
		student_list->get(student_list, &i);
    return 0;
}
