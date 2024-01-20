#ifndef STUDENT_H
#define STUDENT_H
typedef struct student_t Student;

struct student_t
{
    char nis[12];
    char name[40];
    int grade;
    char major[5];
    char teacher[40];
    char activity[40];
    Student *next;
};

Student *add_student(Student **nodeRef, char *_nis, char *_name, int _grade, char *_major, char *_teacher, char *_activity);
int check_digit(char *str);
int check_alpha(char *str);
int check_empty(Student *s);
void search_student(Student *nodeRef, char *_nis);
void print_condition(Student *s, char *keyword);
void print_all(Student *s);
#endif