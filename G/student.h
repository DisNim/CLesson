#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[25];
    int age;
    char group_name[10];
    int mark_math;
    int mark_physic;

    void* (*print)(void* data);
};

void* printSt(void* data);
void* Student_init_(const char* name, int age, const char* group_name, int mark_math, int mark_physic);

#endif
