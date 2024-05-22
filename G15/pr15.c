#include "liststudent.h"
#include "student.h"
#include "savestudent.h"
#include <malloc.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    setlocale(LC_ALL, "RUS");
    List* list = list_init;
    SaveStudent* save = malloc(sizeof(SaveStudent));
    save->list = list;
    char* student[][8] = {
            {"Гвоздев","Артем","19","м","102","3","5","2"},
            {"Усатюк","Сережа","15","м","301","2","2","2"},
            {"Поликанов","Некит","21","м","701","5","5","5"},
            {"Фадин","Славян","11","м","201","5","3","2"},
            {"Штукатурник","Теиур","51","м","201","5","3","4"},
            {"Рудометник","Маха","78","ж","001","5","5","2"}
    };
    int size = sizeof(student) / sizeof(student[0]);
    for (int i = 0; i < size; i++)
    {
        StudentData* stud = save_student(studentInit(student[i]));
        save->stud = stud;
        list->append(save);
    }
    saveFile("test.bin", list);
    List* newList = (List*)loadFile("test.bin");
    save->list = newList;
    newList->print(save);
    system("pause");
    return 0;
}