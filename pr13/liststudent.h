#ifndef LIST_STUDENT_H
#define LIST_STUDENT_H

#define ListStudent(LStudent) l_init(LStudent)
typedef struct ListStudent 
{
    struct Student* head;
	struct Student* tail;
	int size;

	void* (*append)(void*, void*);
	int (*get)(void*, int);
} ListStudent;

struct ListStudent* l_init();
#endif //LIST_STUDENT_H