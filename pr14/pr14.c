#include "liststudent.h"
#include "student.h"
#include "savestudent.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void main()
{
    List* list = list_init;
    char* students[][8] = {
        {"Петров","Иван","15","м","401","2","3","2"},
        {"Терешков","Иван","12","м","401","5","3","2"},
        {"Иванов","Иван","20","м","405","3","3","5"},
        {"Туркменов","Иван","14","м","403","5","5","4"},
        {"Грешков","Иван","15","м","404","5","5","4"},
        {"Гнильцов","Иван","17","м","402","5","5","5"}
    };

    int size = sizeof(students) / sizeof(students[0]);
    SaveStudent* save = malloc(sizeof(SaveStudent));
    save->list = list;
     for (int i = 0; i < size; i++)
     {
         StudentData* student_data = saveStudent(studentInit(students[i]));
         save->stud = student_data;
         list->append(save);
     }
     save_file("\rtrttest.rtrtxt", save);
     printf("Весь список студентов\n");
     list->print(save);
     printf("\nРезультат\n");
     list->get(save);
     List* newList = (List*)load_file("tes34t.txt");
     save->list = newList;
     printf("\nРезультат после загрузки\n");
     newList->get(save);
     system("pause");
}