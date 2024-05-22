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
};

struct Tree
{
    struct Student* stud;
    struct Tree* left;
  struct Tree* right;
    int count;

  void (*add_node)(struct Tree*, struct Student*);
  void (*print)(struct Tree*);
  void (*get)(struct Tree*);
  void (*clear)(struct Tree*);
};


void tree_add_node(struct Tree*, struct Student*);
void tree_print(struct Tree*);
void tree_get(struct Tree*);
void tree_clear(struct Tree*);


struct Student* s_init(char** args)
{
  struct Student* result = malloc(sizeof(struct Student));
  result->name = args[0];
  result->surname = args[1];
  result->gender = args[2];
  result->group = args[3];
  result->age = atoi(args[4]);
  result->mark_chemistry = atoi(args[5]);
  result->mark_math = atoi(args[6]);
  result->mark_phisic = atoi(args[7]);
  return result;
}

struct Tree* tree_init(struct Student* stud)
{
    struct Tree* result = malloc(sizeof(struct Tree));
    result->stud = stud;
    result->count=1;
  result->left = NULL;
  result->right = NULL;
  result->print = tree_print;
  result->add_node = tree_add_node;
  result->get = tree_get;
  result->clear = tree_clear;
    return result;
}

void tree_add_node(struct Tree* tree, struct Student* stud)
{
  if (tree->stud == stud)
  {
    tree->count++;
    return;
  }
  if (tree->stud < stud)
  {
    if (tree->left == NULL)
      tree->left = tree_init(stud);
    tree_add_node(tree->left, stud);
  }
  if (tree->stud > stud)
  {
    if (tree->right == NULL)
      tree->right = tree_init(stud);;
    tree_add_node(tree->right, stud);
  }
}


void tree_print(struct Tree* tree)
{
  if (tree == NULL)
  {
    return;
  }
  tree_print(tree->right);
  printf("%s %s.\n", tree->stud->surname, tree->stud->name);
  tree_print(tree->left);
}


void tree_get(struct Tree* tree)
{
  if (tree == NULL)
    return;
  if (tree->stud->mark_chemistry != 2 && tree->stud->mark_math != 2 && tree->stud->mark_phisic != 2)
    {
    if (tree->count == 0)
        printf("Элемент не найден");
    else
    {
      tree->count--;
      printf("%s %s\n", tree->stud->surname, tree->stud->name);
    }
  }
  tree_get(tree->left);
  tree_get(tree->right);
}


void tree_clear(struct Tree* tree){
    if(tree == NULL)
        return;
    tree_clear(tree->left);
    tree_clear(tree->right);
    free(tree);
}


int main()
{
  setlocale(LC_ALL, "Rus");

    char* student[][8] = {
    {"Петров","Иван","12","м","401","2","3","2"},
        {"Терешков","Иван","12","м","401","5","3","2"},
        {"Иванов","Иван","12","м","401","3","3","5"},
        {"Туркменов","Иван","12","м","401","5","3","5"},
        {"Грешков","Иван","12","м","401","5","3","4"},
        {"Гнильцов","Иван","12","м","401","5","3","2"}
  };

  struct Tree* root = tree_init(s_init(student[0]));
    for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++)
      root->add_node(root, s_init(student[i]));
  printf("Все дерево:\n");
  root->print(root);
  printf("Результат:\n");
  root->get(root);
    root->clear(root);
  return 0;
}
