#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int age;
    char* name;
    char* surname;
    char* gender;
    char* group;
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
    struct Student* next;
};

struct List {
    struct Student* head;
    struct Student* tail;
    int size;

    void* (*append)(void*);
	void* (*print)(void*);
	void* (*printStudent)(void*);
};

struct Node
{
	struct List* list;
	struct Student* stud;
};

void* l_append(void*);
void* l_printList(void*);
void* l_print(void*);

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
}


struct List* init() {
    struct List* list = malloc(sizeof(struct List));
    list->append = l_append;
	list->print = l_print;
	list->printStudent = l_printList;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

struct Student* s_init(char** args) {
    struct Student* student = malloc(sizeof(struct Student));
    student->next = NULL;
    student->age = atoi(args[2]);
    student->name = args[1];
    student->surname = args[0];
    student->gender = args[3];
    student->group = args[4];
    student->mathGrade = atoi(args[5]);
    student->physicGrade = atoi(args[6]);
    student->chemistryGrade = atoi(args[7]);
    return student;
}

void* l_printList(void* args) {
	struct Node* node = (struct Node*)args;
    struct Student* current = node->list->head;
    while (current != NULL) {
        if (current->mathGrade != 2 && current->physicGrade != 2 && current->chemistryGrade != 2)
        {
             printf("%s %s %s - %d, %d, %d\n", current->surname, current->name, current->group, current->mathGrade, current->physicGrade, current->chemistryGrade);
        }
        current = current->next;
    }
}

void* l_print(void* args)
{
	struct Node* node = (struct Node*)args;
	struct Student* stud = node->list->head;
	for (int i = 0; i < node->list->size; i++)
	{
		printf("%s %s %s %s %d: %d %d %d\n", stud->surname, stud->name, stud->gender, stud->group, stud->age, stud->chemistryGrade, stud->mathGrade, stud->physicGrade);
		stud = stud->next;
	}
}


int main() {
    struct List* StudentList = init();
    
	char* student[][8] = {
		 {"Петров","Иван","12","м","401","2","3","2"},
        {"Терешков","Иван","12","м","401","5","3","2"},
        {"Иванов","Иван","12","м","401","3","3","5"},
        {"Туркменов","Иван","12","м","401","5","3","2"},
        {"Грешков","Иван","12","м","401","5","3","4"},
        {"Гнильцов","Иван","12","м","401","5","3","2"}
	};
	struct Node* node = malloc(sizeof(struct Node));
	node->list=StudentList;
	for (int i = 0; i < sizeof(student)/sizeof(student[0]); i++)
	{
		node->stud = s_init(student[i]);
		StudentList->append(node);
	}
	StudentList->printStudent(node);
    return 0;
}
