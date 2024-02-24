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

	void* (*append)(void*);
	int* (*get)(void*);
};

struct Arguments
{
    struct Student* stud;
    struct ListStudents* list;
};
struct ArgumentForGet
{
    struct ListStudents* list;
    int index;
};

void* l_append(void*);
int* l_get(void*);


void* l_append(void* arg)
{   
    struct Arguments* _args = arg;
	if (_args->list->size == 0)
	{
		_args->list->head = _args->stud;
		_args->list->tail = _args->list->head;
	}
	else {
		_args->list->tail->next = _args->stud;
		_args->list->tail = _args->stud;
	}
	_args->list->size++;
}


int* l_get(void* arg)
{
    struct ArgumentForGet* _args = arg;
	if (_args->index >=0 && _args->index < _args->list->size)
	{
		struct Student* tmp = _args->list->head;
		for (int i = 0; i < _args->list->size; i++)
		{
			if (i == _args->index)
			{
				if (tmp->asses_chemistry == 2 || tmp->asses_math == 2 || tmp->asses_phisic == 2 || tmp->asses_chemistry == 3 || tmp->asses_math == 3 || tmp->asses_phisic == 3)
				{
					printf("%s %s.", tmp->surname, tmp->name);
					return 0;
				}
                else    
                {
                    return 0;
                }
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
	printf("Нет такого индекса.");
	return 0;
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
	struct Student* student = st_stud_init("Никита", "Поликанов", "м", "ИСП-205", 17, 5, 2, 5);
	struct Student* student1 = st_stud_init("Виктор", "Гнильцов", "м", "ИСП-205", 17, 5, 3, 5);
	struct ListStudents* student_list = l_init();

    struct Arguments args = {student, student_list};
    struct Arguments args2 = {student1, student_list};
	student_list->append(&args);
    student_list->append(&args2);
    for (int i = 0; i < student_list->size; i++)
    {
        struct ArgumentForGet args3 = {student_list, i};
	    student_list->get(&args3);
    }
	return 0;
}
