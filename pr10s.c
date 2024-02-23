//16. ;
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>


struct Student
{
	char name[20];
	char surname[20];
	char gender[1];
	int age;
	char group[7];
	int mark_math;
	int mark_physics;
	int mark_chemistry;
	struct Student* next;
};

struct List 
{
	struct Student* head;
	struct Student* tail;
	int size;

	void (*append)(struct List* list, const char name[20],
		const char surname[20], const char gender[1],
		int age, const char group[7], int mark_math, int mark_physics, int mark_chemistry);
	int (*get)(struct List*, int index);
};

void l_s_append(struct List*, const char name[20], const char surname[20], const char gender[1], int age, 
	const char group[7],
	int mark_math, int mark_physics, int mark_chemustry);
int l_s_get(struct List* list, int index);


void l_s_append(struct List* list, const char name[20], const char surname[20], const char gender[1], int age, const char group[7],
	int mark_math, int mark_physics, int mark_chemustry)
{
	struct Student* new_node = malloc(sizeof(struct Student));
	strcpy(new_node->name, name);
	strcpy(new_node->surname, surname);
	strcpy(new_node->gender, gender);
	strcpy(new_node->group, group);
	new_node->age = age;
	new_node->mark_math = mark_math;
	new_node->mark_chemistry = mark_chemustry;
	new_node->mark_physics = mark_physics;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}
	list->size++;
}


struct List* l_init()
{
	struct List* list = malloc(sizeof(struct List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->append = l_s_append;
	list->get = l_s_get;
	return list;
}


int l_s_get(struct List* list, int index)
{
	if (index >= 0 && index < list->size)
	{
		struct Student* tmp = list->head;
		for (int i = 0; i < list->size; i++)
		{
			if (i == index)
			{
				if (tmp->mark_chemistry == 5 && strcmp(tmp->gender,"ж")==0)
				{
					printf("%s %s\n", tmp->surname, tmp->name);
					return 0;
				}
				else
					return 0;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
	printf("Нет такого индекса");
	return -1;
}


int main()
{
	struct List* student_data = l_init();
	setlocale(LC_ALL, "Rus");

	student_data->append(student_data, "Терешкова", "Светлана", "ж", 17, "ИСП-205", 5,5,5);
	student_data->append(student_data, "Купцова", "Екатерина", "ж", 17, "ИСП-235", 5, 5, 5);
	for (int i = 0; i < student_data->size; i++)
		student_data->get(student_data, i);
	return 0;
}