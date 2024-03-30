#ifndef STACK_H
#define STACK_H

#define Stack() init();
typedef struct Stack
{
    struct Student* head;
    int size;

    void (*append)(void*, void*);
    void (*get)(void*);
    void (*sort)(void*);
} Stack;

struct Stack* init();
#endif //STACK_H