#include <stdio.h>
#include <malloc.h>
#include "student.h"
#include "stack.h"


void s_append(void*, void*);
void s_get(void*);
void s_sort(void*);

Student* s_init(void* args)
{
    struct Student* stud = malloc(sizeof(struct Student));
    char** str = (char**)args;
    stud->surname = str[0];
    stud->name = str[1];
    stud->gender = str[2];
    stud->group = str[3];
    stud->age = atoi(str[4]);
    stud->asses_chemistry = atoi(str[5]);
    stud->asses_math = atoi(str[6]);
    stud->asses_phisic = atoi(str[7]);
    stud->next = NULL;
    return stud;
}


Stack* init()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->append = s_append;
    stack->get = s_get;
    stack->head = NULL;
    stack->size = 0;
    stack->sort = s_sort;
    return stack;
}

void s_sort(void* st)
{
    Stack* stack = (Stack*)st;
    int size = stack->size;
    while (size > 0)
    {
        if (stack->head->asses_chemistry > stack->head->next->asses_chemistry)
        {
            struct Student* tmp = stack->head;
            stack->head = stack->head->next;
            stack->head->next = tmp;
        }
        size--;
    }
}
void s_append(void* st, void* str)
{
    Student* stud = (Student*)str;
    Stack* stack = (Stack*)st;
    stud->next = stack->head;
    stack->head = stud;
    stack->size++;
}

void s_get(void* st)
{
    Stack* stack = (Stack*)st;
    if (stack->size == 0)
    {
        printf("Размер стака равен 0");
        return;
    }
    char* surname = stack->head->surname;
    char* name = stack->head->name;
    char* gender = stack->head->gender;
    char* group = stack->head->group;
    struct Student* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    printf("\n%s %s %s %s", surname,name,gender,group);
    return;
}


void main()
{
    struct Stack* stack = init();
    char* student[] = {"Фадин", "Саятослав", "м", "ИСП-205", "17", "5", "3","3"};
    char* student2[] = {"Гренков", "Генадий", "м", "ИСП-205", "17", "4", "4","3"};
    stack->append(stack, s_init(student));
    stack->append(stack, s_init(student2));
    printf("После сортировки");

    stack->sort(stack);
    while (stack->size > 0)
        stack->get(stack);
}