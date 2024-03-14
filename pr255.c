#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[20];
    int age;
};

int main() {
    struct Student* my_student;
    strcpy(my_student->name, "Andrey");
    my_student->age = 45;

    FILE* random_name_file = fopen("my_file.bin", "wb");
    fwrite(&my_student, sizeof(struct Student), 2, random_name_file);
    fclose(random_name_file);

    struct Student* my_new_student;
    random_name_file = fopen("my_file.bin", "rb");
    fread(&my_new_student, sizeof(struct Student), 1, random_name_file);
    fclose(random_name_file);

    printf("%s, %d\n", my_new_student->name, my_new_student->age);

    return 0;
}