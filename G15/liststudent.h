#ifndef LIST_H
#define LIST_H

#define list_init init()

typedef struct List
{
    struct StudentData* head;
    struct StudentData* tail;

    int size;

    void* (*append)(void*);
    void* (*print)(void*);
    void* (*get)(void*);
} List;

void* l_append(void*);
void* l_get(void*);
void* l_print(void*);

List* init();
#endif //LIST_H