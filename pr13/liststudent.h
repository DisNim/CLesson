#ifndef LIST_STUDENT_H
#define LIST_STUDENT_H

#define ListInit l_init()

void l_get(void*);
void l_append(void*);


typedef struct ListStudent 
{
    struct Student* head;
	struct Student* tail;
	int size;

	void (*append)(void*);
	void (*get)(void*);
} ListStudent;

typedef struct Node
{
	struct Student* stud;
	struct ListStudent* list;
	int index;
} Node;

ListStudent* l_init();
#endif //LIST_STUDENT_H