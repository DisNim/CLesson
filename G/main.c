#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "tree.h"
#define SUM (a,b) {(a)+b}

void* printSt(void* data) {
    struct Student* student = (struct Student*)data;
    printf("Name: %s, age: %d, group: %s, Math: %d, Physics: %d.\n", student->name, student->age, student->group_name, student->mark_math, student->mark_physic);
    return NULL;
}

void* Student_init_(const char* name, int age, const char* group_name, int mark_math, int mark_physic) {
    struct Student* student = malloc(sizeof(struct Student));
    strncpy(student->name, name, sizeof(student->name) - 1);
    student->age = age;
    strncpy(student->group_name, group_name, sizeof(student->group_name) - 1);
    student->mark_math = mark_math;
    student->mark_physic = mark_physic;
    student->print = printSt;
    return student;
}


void* tree_add_node(void* tree, void* value);
void* tree_print(void* tree);
void* tree_get(void* tree);
void tree_clear(void* tree);

void* tree_init(void* value){
    struct Tree* result = malloc(sizeof(struct Tree));
    result->value = malloc(sizeof(struct List));
    result->value->student = value;
    result->value->tree = result;
    result->count = 1;
    result->left = NULL;
    result->right = NULL;
    result->add_node = tree_add_node;
    result->print = tree_print;
    result->get = tree_get;
    result->clear = tree_clear;
    return result;
}

void* tree_add_node(void* tree, void* value){
    struct Tree* t = (struct Tree*)tree;
    struct Student* val = (struct Student*)value;
    if(t->value->student == val){
        t->count++;
        return NULL;
    }
    if(((struct Student*)(t->value->student))->mark_physic < val->mark_physic){
        if(t->left == NULL){
            t->left = tree_init(value);
        }
        t->add_node(t->left, value);
    }
    if(((struct Student*)(t->value->student))->mark_physic == val->mark_physic){
        if(t->right == NULL){
            t->right = tree_init(value);
        }
        t->add_node(t->right, value);
    }
    return NULL;
}

void* tree_print(void* tree){
    struct Tree* t = (struct Tree*)tree;
    if (t == NULL)
        return NULL;
    t->print(t->left);
    ((struct Student*)(t->value->student))->print(t->value->student);
    t->print(t->right);
    return NULL;
}

void* tree_get(void* tree){
    struct Tree* t = (struct Tree*)tree;
    if(t == NULL) {
        printf("Element not found\n");
        return NULL;
    }
    if(((struct Student*)(t->value->student))->mark_physic == 5) {
        if(t->count == 0){
            printf("Element not found\n");
            return NULL;
        }
        t->count--;
        t->print(t);
        t->get(t->left);
    }
    if(((struct Student*)(t->value->student))->mark_physic > 5){
        t->get(t->right);
    }
    return NULL;
}

void tree_clear(void* tree){
    struct Tree* t = (struct Tree*)tree;
    if(t == NULL)
        return;
    t->clear(t->left);
    t->clear(t->right);
    free(t);
}
const char names[10][20] = {
        "MiHaHaHa", "Dasha","SerGo","Artem",
        "Den","Ann","Sasha", "Kate", "Vitek","Sonya"
};

const char groups[5][10] = {
        "SIS-2","ISP-3","ZIO-1","ISP-5","SIS-6"
};
int main() {
    system("chcp 65001");
    srand(time(NULL));
    struct Tree* tree = tree_init(Student_init_(names[rand() % 10], rand() % 100, groups[(rand() % 10) / 2], rand() % 5 + 1,
                                                5));
    for (int i = 1; i < 10; i++) {
        struct Student* value = Student_init_(names[rand() % 10], rand() % 100, groups[(rand() % 10) / 2],
                                              rand() % 5 + 1, 5);
        tree ->add_node(tree, Student_init_(names[rand() % 10], rand() % 100, groups[(rand() % 10) / 2],
                                            rand() % 5 + 1, 5));
    }
    tree->get(tree);
    tree_clear(tree);
    system("pause");
    return 0;
}
