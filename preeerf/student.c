#include "student.h"
#include <malloc.h>
#include <stdlib.h>

StudentData* create_stud(struct Student* stud)
{
    struct StudentData* student = malloc(sizeof(struct StudentData));
    student->stud = stud;
    student->next = NULL;
    return student;
}


Student* s_init(char** args) {
    struct Student* student = malloc(sizeof(struct Student));
    student->age = atoi(args[2]);
    student->name = args[1];
    student->surname = args[0];
    student->gender = args[3];
    student->group = args[4];
    student->mathGrade = atoi(args[5]);
    student->physicGrade = atoi(args[6]);
    student->chemistryGrade = atoi(args[7]);
    return student;
}
