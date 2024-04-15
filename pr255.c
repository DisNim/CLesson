#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int age;
    char name[50];
    char surname[50];
    char gender[10];
    char group[50];
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
    struct Student* next;
};

struct List {
    struct Student* head;
    struct Student* tail;
    int size;

    void (*append)(struct List*, struct Student*);
    void (*get)(struct List*);
};

void l_append(struct List* list, struct Student* student);
void l_get(struct List*);
void printList(struct List*);

void l_append(struct List* list, struct Student* student) {
    if (list->size == 0) {
        list->head = student;
        list->tail = list->head;
    } else {
        list->tail->next = student;
        list->tail = student;
    }
    list->size++;
}

void l_get(struct List* list) {
    struct Student *current, *prev = NULL, *nextNode;
    int swapped;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        current = list->head;

        while (current->next != NULL) {
            nextNode = current->next;
            if (current->age > nextNode->age) {
                if (prev != NULL) {
                    prev->next = nextNode;
                } else {
                    list->head = nextNode;
                }
                current->next = nextNode->next;
                nextNode->next = current;
                prev = nextNode;
                swapped = 1;
            } else {
                prev = current;
                current = current->next;
            }
        }
        list->tail = prev;
    } while (swapped);
}

struct List* init() {
    struct List* list = malloc(sizeof(struct List));
    list->append = l_append;
    list->get = l_get;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

struct Student* s_init(int age, const char* name, const char* surname, const char* gender, const char* group, int mathGrade, int physicGrade, int chemistryGrade) {
    struct Student* student = malloc(sizeof(struct Student));
    student->next = NULL;
    student->age = age;
    strcpy(student->name, name);
    strcpy(student->surname, surname);
    strcpy(student->gender, gender);
    strcpy(student->group, group);
    student->mathGrade = mathGrade;
    student->physicGrade = physicGrade;
    student->chemistryGrade = chemistryGrade;
    return student;
}

void printList(struct List* list) {
    struct Student* current = list->head;
    while (current != NULL) {
        if (current->mathGrade != 2 || current->physicGrade != 2 || current->chemistryGrade != 2)
        {
             printf("%s %s %s - %d, %d, %d: ", current->surname, current->name, current->group, current->mathGrade, current->physicGrade, current->chemistryGrade);
             break;
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct List* StudentList = init();
    StudentList->append(StudentList, s_init(23, "Ivan", "Nikita", "муж", "Artem", 4, 4,4));
    StudentList->append(StudentList, s_init(14, "Чурка", "Egor", "муж", "Sergey", 2, 2, 2));
    StudentList->get(StudentList);
    printList(StudentList);
    return 0;
}