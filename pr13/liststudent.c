#include "liststudent.h"
#include <stdio.h>
#include "student.h"
#include <malloc.h>

void l_append(void* node)
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

ListStudent* l_init()
{
	ListStudent* list = malloc(sizeof(ListStudent));
	list->append = l_append;
	list->get=l_get;
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void l_get(void* node)
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
                return;
            }
        }
        else
        {
            tmp = tmp->next;
        }
    }
}