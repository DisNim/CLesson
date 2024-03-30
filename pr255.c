#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char surname[50];
    char name[50];
    char gender;
    int age;
    char group[50];
    float math_grade;
    float physics_grade;
    float chemistry_grade;
};

struct Derevo
{
    struct Student data;
    struct Derevo* left;
    struct Derevo* right;

    void (*CreatDerevo)(struct Student student);
    void (*PrintDerevo)(struct Derevo* root);
    void (*AddDerevoByChemistry)(struct Derevo* root, struct Student student);

};

struct Derevo* CreatDerevo(struct Student student) {
    struct Derevo* newDerevo = (struct Derevo*)malloc(sizeof(struct Derevo));
    newDerevo->data = student;
    newDerevo->left = NULL;
    newDerevo->right = NULL;
    return newDerevo;
}

struct Derevo* AddDerevoByChemistry(struct Derevo* root, struct Student student) {
    if (root == NULL) {
        return CreatDerevo(student);
    }

    if (student.chemistry_grade < root->data.chemistry_grade) {
        root->left = AddDerevoByChemistry(root->left, student);
    }
    else {
        root->right = AddDerevoByChemistry(root->right, student);
    }

    return root;
}


void PrintDerevo(struct Derevo* root) {
    if (root != NULL) {
        PrintDerevo(root->left);
        printf("%s %s %c %d %s %.1f %.1f %.1f\n", root->data.surname, root->data.name, root->data.gender, root->data.age, root->data.group, root->data.math_grade, root->data.physics_grade, root->data.chemistry_grade);
        PrintDerevo(root->right);
    }
}

int main() {
    struct Student student1 = { "Иванов", "Иван", 'М', 20, "Группа1", 4.5, 4.0, 4.8 };
    struct Student student2 = { "Петров", "Петр", 'М', 21, "Группа2", 3.8, 4.2, 4.5 };
    struct Student student3 = { "Сидорова", "Мария", 'Ж', 19, "Группа1", 4.2, 3.9, 4.9 };

    struct Derevo* rootByChemistry = NULL;
    rootByChemistry = AddDerevoByChemistry(rootByChemistry, student1);
    rootByChemistry = AddDerevoByChemistry(rootByChemistry, student2);
    rootByChemistry = AddDerevoByChemistry(rootByChemistry, student3);

    printf("Структура со студентами, отсортированными по оценке по химии:\n");
    PrintDerevo(rootByChemistry);

    return 0;
}
