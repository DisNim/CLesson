#ifndef TREE_H
#define TREE_H

#include "student.h"

struct List {
    struct Student* student;
    struct Tree* tree;
};

struct Tree {
    struct List* value;
    int count;
    struct Tree* left;
    struct Tree* right;

    void* (*add_node)(void* tree, void* value);
    void* (*print)(void* tree);
    void* (*get)(void* tree);
    void (*clear)(void* tree);
};

void* tree_init(void* value);

#endif
