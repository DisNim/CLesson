#ifndef STUDENT_H
#define STUDENT_H
#include <malloc.h>

#define Stud(students) init(students);
typedef struct Student
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
} Student;

Student* init(void* args)
{
	Student* list = malloc(sizeof(Student));
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
};
#endif //STUDENT_H