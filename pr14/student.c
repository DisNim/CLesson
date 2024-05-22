#include "student.h"
#include <malloc.h>
#include <stdio.h>


Student* s_init(char** args)
{
    Student* stud = malloc(sizeof(Student));
    stud->surname = args[0];
    stud->name = args[1];
    stud->gender = args[3];
    stud->group = args[4];
    stud->age = atoi(args[2]);
    stud->grade_chemestry = atoi(args[5]);
    stud->grade_math = atoi(args[6]);
    stud->grade_phisics = atoi(args[7]);
    return stud;
}


StudentData* save_student(Student* args)
{
    StudentData* save_student = malloc(sizeof(StudentData));
    save_student->stud = args;
    save_student->next = NULL;
    return save_student;
}