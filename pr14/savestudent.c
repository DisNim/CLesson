#include "savestudent.h"
#include <malloc.h>
#include <stdio.h>
#include "liststudent.h"
#include "student.h"

#include <errno.h>

void* save_file(char* path, void* args)
{
    errno_t my_error = errno;
    FILE* file = fopen(path, "w");
    if (file)
    {
    SaveStudent* save = (SaveStudent*)args;
    StudentData* stud_data = save->list->head;
    for (int i = 0; i < save->list->size; i++)
    {
        Student* stud = stud_data->stud;
        fprintf(file, "%s %s %d %s %s %d %d %d\n", stud->surname, stud->name, stud->age, stud->gender, stud->group, stud->grade_chemestry, stud->grade_math, stud->grade_phisics);
        stud_data = stud_data->next;
    }
    fclose(file);
    }
    else {
        printf("Код ошибки: %d\n", my_error);
        perror("Сохранение файла");
    }
}


void* load_file(char* path)
{
    errno_t my_error = errno;
    List* list = list_init;
    SaveStudent* save = malloc(sizeof(SaveStudent));
    save->list = list;
    FILE* file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Код ошибки: %d\n", my_error);
        perror("Загрузкаs файла");
    }
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
            StudentData *stud = save_student(studentInit(str));
            save->stud = stud;
            list->append(save);
            j = 0;
        }
    }
    fclose(file);
    return list;
}