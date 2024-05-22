#ifndef C_LIST_H
#define C_LIST_H

#define ListInit init();

typedef struct List {
    struct StudentData* head;
    struct StudentData* tail;
    int size;

    void* (*append)(void*);
    void* (*print)(void*);
    void* (*printStudent)(void*);
} List;

typedef struct Node
{
    struct List* list;
    struct StudentData* stud;
} Node;

void* l_append(void*);
void* l_printList(void*);
void* l_print(void*);
void* save_file(char*, void*);
void* load_file(char*);

List* init();
#endif //C_LIST_H
