#include <stdio.h>
#include <malloc.h>
#include "list.h"
#include "student.h"


int main() {
    struct List* StudentList = init();

    char* student[][8] = {
            {"Гвоздев","Артем","19","м","102","3","5","2"},
            {"Усатюк","Сережа","15","м","301","2","2","2"},
            {"Поликанов","Некит","21","м","701","5","5","5"},
            {"Фадин","Славян","11","м","201","5","3","2"},
            {"Штукатурник","Теиур","51","м","201","5","3","4"},
            {"Рудометник","Маха","78","ж","001","5","5","2"}
    };
    struct Node* node = malloc(sizeof(struct Node));
    node->list=StudentList;
    for (int i = 0; i < sizeof(student)/sizeof(student[0]); i++)
    {
        node->stud = create_stud((s_init(student[i])));
        StudentList->append(node);
    }

    save_file("test.txt", node);
    printf("Весь список:\n");
    StudentList->print(node);
    // printf("Результат:\n");
    // StudentList->printStudent(node);
    List* newList = load_file("test.txt");
    node->list = newList;
    newList->printStudent(node);
    system("pause");
    return 0;
}
