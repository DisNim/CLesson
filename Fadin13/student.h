#ifndef STUDENT_H
#define STUDENT_H

#define Student() s_init();

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

struct Student* s_init(void*);
#endif //STUDENT_H