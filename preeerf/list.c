#include "list.h"
#include <malloc.h>
#include "student.h"
#include <stdio.h>


List* init() {
    struct List* list = malloc(sizeof(struct List));
    list->append = l_append;
    list->print = l_print;
    list->printStudent = l_printList;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}


void* l_append(void* args) {
    struct Node* node = (struct Node*)args;
    if (node->list->size == 0) {
        node->list->head = node->stud;
        node->list->tail = node->list->head;
    } else {
        node->list->tail->next = node->stud;
        node->list->tail = node->stud;
    }
    node->list->size++;
    return 0;
}


void* l_printList(void* args) {
    struct Node* node = (struct Node*)args;
    struct StudentData* current = node->list->head;
    while (current != NULL) {
        if (current->stud->physicGrade == 5)
        {
            printf("%s %s %s - Математика: %d, Физика: %d, Химия: %d\n", current->stud->surname, current->stud->name, current->stud->group, current->stud->mathGrade, current->stud->physicGrade, current->stud->chemistryGrade);
        }
        current = current->next;
    }
    return 0;
}


void* l_print(void* args)
{
    struct Node* node = (struct Node*)args;
    struct StudentData* stud = node->list->head;
    for (int i = 0; i < node->list->size; i++)
    {
        printf("%s %s %s %s %d: %d %d %d\n", stud->stud->surname, stud->stud->name, stud->stud->gender, stud->stud->group, stud->stud->age, stud->stud->chemistryGrade, stud->stud->mathGrade, stud->stud->physicGrade);
        stud = stud->next;
    }
    return 0;
}

void* save_file(char* path, void* args)
{
    FILE* file = fopen(path, "w");
    if (file)
    {
    Node* save = (Node*)args;
    StudentData* stud_data = save->list->head;
    for (int i = 0; i < save->list->size; i++)
    {
        Student* stud = stud_data->stud;
        fprintf(file, "%s %s %d %s %s %d %d %d\n", stud->surname, stud->name, stud->age, stud->gender, stud->group, stud->chemistryGrade, stud->mathGrade, stud->physicGrade);
        stud_data = stud_data->next;
    }
    fclose(file);
    }
}


void* load_file(char* path)
{
    List* list = ListInit;
    Node* save = malloc(sizeof(Node));
    save->list = list;
    FILE* file = fopen(path, "r");
    int j = 0;
    char* str[8];
    while (!feof(file)) {
        if (j == 0) {
            for (int i = 0; i < 8; i++)
                str[i] = (char *) malloc(100 * sizeof(char));
        }
        fscanf(file, "%s", str[j]);
        j++;
        if (j == 8) {
            StudentData *stud = create_stud(s_init(str));
            save->stud = stud;
            list->append(save);
            j = 0;
        }
    }
    fclose(file);
    return list;
}