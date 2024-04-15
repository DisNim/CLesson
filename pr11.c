#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>


struct Student
{
	char *name;
	char *surname;
	char *group;
	char *gender;
	int age;
	int mark_math;
	int mark_phisic;
	int mark_chemistry;
	int count;
	struct Student* left;
	struct Student* right;

	void (*add_node)(struct Student*, struct Student*);
	void (*print)(struct Student*);
	void (*get)(struct Student*);
	void (*clear)(struct Student*);

};


void tree_add_node(struct Student*, struct Student*);
void tree_print(struct Student*);
void tree_get(struct Student*);
void tree_clear(struct Student*);


struct Student* s_init(char* name, char* surname, char* gender, char* group, int age, int mark_math,
int mark_chemistry, int mark_phisic)
{
	struct Student* result = malloc(sizeof(struct Student));
	result->name = name;
	result->surname = surname;
	result->gender = gender;
	result->group = group;
	result->age = age;
	result->mark_chemistry = mark_chemistry;
	result->mark_math = mark_math;
	result->mark_phisic = mark_phisic;
	result->count=1;
	result->left = NULL;
	result->right = NULL;
	result->print = tree_print;
	result->add_node = tree_add_node;
	result->get = tree_get;
	result->clear = tree_clear;
	return result;
}


void tree_add_node(struct Student* tree, struct Student* stud)
{
	if (strcmp(tree->surname, stud->surname)==0)
	{
		tree->count++;
		return;
	}
	if (strcmp(tree->surname, stud->surname) < 0)
	{
		if (tree->left == NULL)
			tree->left = s_init(stud->name, stud->surname, stud->gender, 
								stud->group, stud->age, stud->mark_math, 
								stud->mark_chemistry, stud->mark_phisic);
		tree_add_node(tree->left, stud);
	}
	if (strcmp(tree->surname, stud->surname) > 0)
	{
		if (tree->right == NULL)
			tree->right = s_init(stud->name, stud->surname, stud->gender, 
								 stud->group, stud->age, stud->mark_math, 
								 stud->mark_chemistry, stud->mark_phisic);
		tree_add_node(tree->right, stud);
	}
}


void tree_print(struct Student* tree)
{
	if (tree == NULL)
	{
		return;
	}
	tree_print(tree->right);
	printf("%s %s.\n", tree->surname, tree->name);
	tree_print(tree->left);
}


void tree_get(struct Student* tree)
{
	if (tree == NULL)
		return;
	if (tree->count == 0)
			printf("Элемент не найден");
	if (tree->mark_chemistry == 2 || tree->mark_math == 2 || tree->mark_phisic == 2 ||
			tree->mark_chemistry == 3 || tree->mark_math == 3 || tree->mark_phisic == 3)
		{
			tree->count--;
			printf("%s %s\n", tree->surname, tree->name);
			tree_get(tree->left);
		}
    else 
    {
        tree_get(tree->right);
    }
}


void tree_clear(struct Student* tree){
    if(tree == NULL)
        return;
    tree_clear(tree->left);
    tree_clear(tree->right);
    free(tree);
}


int main()
{
	setlocale(LC_ALL, "Rus");
	struct Student* root = s_init("Петр", "Петров", "м", "ИСП-205", 17, 5, 5, 5);
	root->add_node(root, s_init("Виктор", "Степанович", "м", "ИСП-205", 17, 5, 4, 5));
	root->add_node(root, s_init("Иван", "Иванов", "м", "ИСП-205", 17, 5, 4, 5));
	root->add_node(root, s_init("Светлана", "Викторовна", "м", "ИСП-205", 17, 2, 4, 5));
	printf("Все дерево:\n");
	root->print(root);
	printf("Результат:\n");
	root->get(root);
	return 0;
}