#include <stdio.h>
#include <malloc.h>
#include <locale.h>


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

struct Student* st_stud_init(char* name, char* surname, char* gender, char* group, int age, int asses_chemistry,
int asses_math, int asses_phisic)
{
	struct Student* list = malloc(sizeof(struct Student));
	list->name = name;
	list->surname = surname;
	list->gender = gender;
	list->group = group;
	list->age = age;
	list->asses_chemistry = asses_chemistry;
	list->asses_math = asses_math;
	list->asses_phisic = asses_phisic;
	list->next = NULL;
	return list;
}


struct ListStudents 
{
	struct Student* head;
	struct Student* tail;
	int size;

	void (*append)(struct ListStudents*, struct Student*);
	int (*get)(struct ListStudents*, int);
};

void l_append(struct ListStudents*, struct Student*);
int l_get(struct ListStudents*, int);


void l_append(struct ListStudents* list, struct Student* stud)
{
	if (list->size == 0)
	{
		list->head = stud;
		list->tail = list->head;
	}
	else 
	{
		list->tail->next = stud;
		list->tail = stud;
	}
	list->size++;
}


int l_get(struct ListStudents* list, int index)
{
	if (index >=0 && index < list->size)
	{
		struct Student* tmp = list->head;
		for (int i = 0; i < list->size; i++)
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
	{
	printf("Нет такого индекса.");
	return -1;
	}
}


struct ListStudents* l_init()
{
	struct ListStudents* list = malloc(sizeof(struct ListStudents));
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
	struct Student* student = st_stud_init("Никита", "Поликанов", "м", "ИСП-205", 17, 5, 5, 0);
	struct Student* student1 = st_stud_init("Виктор", "Гнильцов", "м", "ИСП-205", 17, 5, 4, 0);
	struct ListStudents* student_list = l_init();
	student_list->append(student_list, student);
	student_list->append(student_list, student1);
	for (int i = 0; i < student_list->size; i++)
		student_list->get(student_list, i);
	return 0;
}
