#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void addStudent(Student** head, int id, const char* name, float gpa) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->gpa = gpa;
    newStudent->next = *head;
    *head = newStudent;
    printf("Student %s added successfully.\n", name);
}

void deleteStudent(Student** head, int id) {
    Student* temp = *head;
    Student* prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Student ID %d deleted.\n", id);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student ID %d deleted.\n", id);
}

Student* searchStudent(Student* head, int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) return current;
        current = current->next;
    }
    return NULL;
}

void displayStudents(Student* head) {
    if (!head) {
        printf("No student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while (head != NULL) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", head->id, head->name, head->gpa);
        head = head->next;
    }
}

void freeStudentList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}