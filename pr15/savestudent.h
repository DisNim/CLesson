#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H


typedef struct SaveStudent
{
    struct List* list;
    struct StudentData* stud;
} SaveStudent;

void* saveFile(char*, void*);
void* loadFile(char*);
#endif //STUDENT_DATA_H