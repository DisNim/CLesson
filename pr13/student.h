#ifndef STUDENT_H
#define STUDENT_H
#include <malloc.h>
//#ifdef 

#define Stud(students) init(students);
#define say printf
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

Student* init(void* args);

#endif //STUDENT_H