#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void* l_append(void*);
int l_get(void*);


struct Node
{
    struct Student* stud;
    struct ListStudents* list;
    int i;
};


struct Student
{
    char* name;
    char* surname;
    char* gender;
    char* group;
    int age;
    int asses_chemistry;
    int asses_math;
    int asses_phisic;
    struct Student* next;
};

struct Student* st_stud_init(void* args)
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

struct ListStudents 
{
    struct Student* head;
    struct Student* tail;
    int size;

    void* (*append)(void*);
    int (*get)(void*);
};

void* l_append(void* list)
{
    struct Node* node = (struct Node*)list;
    struct Student* s = node->stud;
    struct ListStudents* l = node->list;
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
    return NULL;
}


int l_get(void* node)
{
    struct Node* newNode = (struct Node*)node;
    int index =  newNode->i;
    struct ListStudents* l = newNode->list;
    if (index >= 0 && index < l->size)
    {
        struct Student* tmp = l->head;
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

void* l_init()
{
    struct ListStudents* list = malloc(sizeof(struct ListStudents));
    if (!list)
        return NULL;
    
    list->append = l_append;
    list->get = l_get;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    char* student_args[] = {"Попов", "Петр", "м", "ИСП-205", "17", "3", "5", "5"};
    char* student1_args[] = {"Гнельцов", "Виктор", "м", "ИСП-205", "17", "5", "4", "2"};
    struct ListStudents* student_list = (struct ListStudents*)l_init();
    struct Node* node = malloc(sizeof(struct Node));
    node->list = student_list;
    node->stud = st_stud_init(student_args);
    student_list->append(node);
    node->stud = st_stud_init(student1_args);
    student_list->append(node);
    for (int i = 0; i < student_list->size; i++)
    {
        node->i = i;
		student_list->get(node);
    }
    return 0;
}
