#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Student {
    int id;
    char name[50];
    float gpa;
    struct Student* next;
} Student;

void addStudent(Student** head, int id, const char* name, float gpa);
void deleteStudent(Student** head, int id);
Student* searchStudent(Student* head, int id);
void displayStudents(Student* head);
void freeStudentList(Student* head);

#endif