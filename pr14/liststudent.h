#ifndef LIST_STUDENT_H
#define LIST_STUDENT_H
#include "student.h"
#include <malloc.h>

#define ListInit l_init()

void* l_get(void*);
void* l_append(void*);

typedef struct ListStudent 
{
    struct Student* head;
	struct Student* tail;
	int size;

	void* (*append)(void*);
	void* (*get)(void*);
} ListStudent;

typedef struct Node
{
	Student* stud;
	ListStudent* list;
	int index;
} Node;

ListStudent* l_init()
{
	ListStudent* list = malloc(sizeof(ListStudent));
	list->append = l_append;
	list->get=l_get;
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
};

void* l_append(void* node)
{
	Node* newNode = (Node*)node;
    ListStudent* l = newNode->list;
    Student* s = newNode->stud;
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
void* l_get(void* node)
{
	Node* newNode = (Node*)node;
    ListStudent* l = newNode->list;
    Student* tmp = l->head;
    int index = newNode->index;
    for (int i = 0; i < l->size; i++)
    {      
        if (index == i)
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
};

#endif //LIST_STUDENT_H