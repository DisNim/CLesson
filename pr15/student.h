#ifndef STUDENT_H
#define STUDENT_H

#define studentInit(students) s_init(students)
#define saveStudent(student) save_student(student)

typedef struct StudentData
{
	struct Student* stud;
	struct StudentData* next;
} StudentData;

typedef struct Student
{
	char* name;
	char* surname;
	char* group;
	char* gender;
	int age;
	int grade_math;
	int grade_phisics;
	int grade_chemestry;
} Student;

Student* s_init(char**);
StudentData* save_student(Student*);

#endif //STUDENT_H