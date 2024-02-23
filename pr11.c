#include <stdio.h>
#include <locale.h>
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

	void (*append)(struct List*, struct Student* );
	int (*get)(struct List*, int );
};


void l_s_append(struct Student*, char name[20],char surname[20],char gender[1],int age,char group[7],
                int mark_math, int mark_physics, int mark_chemistry);
int l_s_get(struct List*, int);


void l_s_append(struct Student*, char name[20],char surname[20],char gender[1],int age,char group[7],
                int mark_math, int mark_physics, int mark_chemistry)
{
    
}
void main()
{
    setlocale(LC_ALL, "Rus");

}