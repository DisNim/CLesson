//16. ;
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>


struct Node
{
	char name[20];
	char surname[20];
	char gender[1];
	int age;
	char group[7];
	int mark_math;
	int mark_physics;
	int mark_chemistry;
	struct Node* next;
};

struct Student 
{
	struct Node* head;
	struct Node* tail;
	int size;

	void (*append)(struct Student* list, const char name[20],
		const char surname[20], const char gender[1],
		int age, const char group[7], int mark_math, int mark_physics, int mark_chemistry);
	int (*get)(struct Student*, int index);
};

void l_s_append(struct Student*, const char name[20], const char surname[20], const char gender[1], int age, 
	const char group[7],
	int mark_math, int mark_physics, int mark_chemustry);
int l_s_get(struct Student* list, int index);


void l_s_append(struct Student* list, const char name[20], const char surname[20], const char gender[1], int age, const char group[7],
	int mark_math, int mark_physics, int mark_chemustry)
{
	struct Node* new_node = malloc(sizeof(struct Node));
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


struct Student* l_init()
{
	struct Student* list = malloc(sizeof(struct Student));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->append = l_s_append;
	list->get = l_s_get;
	return list;
}


int l_s_get(struct Student* list, int index)
{
	if (index >= 0 && index < list->size)
	{
		struct Node* tmp = list->head;
		for (int i = 0; i < list->size; i++)
		{
			if (i == index)
			{
				if (tmp->mark_chemistry == 2 || tmp->mark_math == 2 || tmp->mark_physics == 2 || tmp->mark_chemistry == 3 || tmp->mark_math == 3 || tmp->mark_physics == 3)
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
	struct Student* student_data = l_init();
	setlocale(LC_ALL, "Rus");

	student_data->append(student_data, "Поликанов", "Никита", "м", 17, "ИСП-205", 3, 2, 4);
	student_data->append(student_data, "Грешков", "Виктор", "м", 17, "ИСП-235", 5, 5, 2);
	for (int i = 0; i < student_data->size; i++)
		student_data->get(student_data, i);
	return 0;
}