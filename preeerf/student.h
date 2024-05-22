#ifndef C_STUDENT_H
#define C_STUDENT_H

typedef struct StudentData
{
    struct Student* stud;
    struct StudentData* next;
} StudentData;

typedef struct Student {
    int age;
    char* name;
    char* surname;
    char* gender;
    char* group;
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
} Student;


StudentData* create_stud(Student*);
Student* s_init(char**);
#endif //C_STUDENT_H
