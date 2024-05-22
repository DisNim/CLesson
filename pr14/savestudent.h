#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H


typedef struct SaveStudent
{
    struct List* list;
    struct StudentData* stud;
} SaveStudent;

void* save_file(char*, void*);
void* load_file(char*);
#endif //STUDENT_DATA_H