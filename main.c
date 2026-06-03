#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "queue.h"
#include "bst.h"
#include "sorting.h"

int main() {
    int choice, subChoice;
    
    // Task State Initializations
    Student* studentHead = NULL;
    Queue serviceQueue;
    initQueue(&serviceQueue);
    int ticketCounter = 101;
    BSTNode* libraryRoot = NULL;
    
    // Task 4 Hardcoded Mock Dataset
    Product catalog[5] = {
        {402, "Wireless Mouse", 25.50},
        {105, "Mechanical Keyboard", 89.99},
        {301, "Gaming Headset", 59.99},
        {220, "USB-C Hub", 19.99},
        {512, "4K Monitor", 349.00}
    };
    int catalogSize = 5;

    while (1) {
        printf("   AMITY UNIVERSITY DUBAI - DSA SYSTEMS      \n");
        printf("1. Task 1: Student Record Management System\n");
        printf("2. Task 2: Student Service Queue Counter\n");
        printf("3. Task 3: Smart Library Catalogue System\n");
        printf("4. Task 4: Online Shopping Sorting/Searching\n");
        printf("5. Exit Program\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                do {
                    printf("\n--- Task 1: Student Management ---\n");
                    printf("1. Add Student Record\n");
                    printf("2. Delete Student Record\n");
                    printf("3. Search Student\n");
                    printf("4. Display All Records\n");
                    printf("5. Back to Main Menu\n");
                    printf("Choice: ");
                    scanf("%d", &subChoice);
                    
                    int id; char name[50]; float gpa;
                    if (subChoice == 1) {
                        printf("Enter ID: "); scanf("%d", &id);
                        printf("Enter Name: "); scanf("%s", name);
                        printf("Enter GPA: "); scanf("%f", &gpa);
                        addStudent(&studentHead, id, name, gpa);
                    } else if (subChoice == 2) {
                        printf("Enter ID to Delete: "); scanf("%d", &id);
                        deleteStudent(&studentHead, id);
                    } else if (subChoice == 3) {
                        printf("Enter ID to Search: "); scanf("%d", &id);
                        Student* res = searchStudent(studentHead, id);
                        if (res) printf("Found! Name: %s, GPA: %.2f\n", res->name, res->gpa);
                        else printf("Record not found.\n");
                    } else if (subChoice == 4) {
                        displayStudents(studentHead);
                    }
                } while (subChoice != 5);
                break;

            case 2:
                do {
                    printf("\n--- Task 2: Service Queue Counter ---\n");
                    printf("1. Issue New Ticket (Enqueue)\n");
                    printf("2. Serve Next Student (Dequeue)\n");
                    printf("3. Peek Next in Line\n");
                    printf("4. View Queue Line\n");
                    printf("5. Back to Main Menu\n");
                    printf("Choice: ");
                    scanf("%d", &subChoice);

                    char svc[30];
                    if (subChoice == 1) {
                        printf("Choose Service (1: Fees, 2: Registration, 3: ID Card): ");
                        int sType; scanf("%d", &sType);
                        const char* serviceName = (sType == 1) ? "Fee Payment" : (sType == 2) ? "Registration" : "ID Renewal";
                        enqueue(&serviceQueue, ticketCounter++, serviceName);
                        printf("Ticket Issued successfully.\n");
                    } else if (subChoice == 2) {
                        int id = dequeue(&serviceQueue, svc);
                        if (id) printf("Serving Ticket #%d for [%s]\n", id, svc);
                        else printf("Queue is empty.\n");
                    } else if (subChoice == 3) {
                        int id = peek(&serviceQueue, svc);
                        if (id) printf("Next in line is Ticket #%d for [%s]\n", id, svc);
                        else printf("No one waiting.\n");
                    } else if (subChoice == 4) {
                        displayQueue(&serviceQueue);
                    }
                } while (subChoice != 5);
                break;

            case 3:
                do {
                    printf("\n--- Task 3: Smart Library Catalogue ---\n");
                    printf("1. Register New Book (BST Insertion)\n");
                    printf("2. Search & Borrow Book (BST Search)\n");
                    printf("3. Return Book\n");
                    printf("4. Display Books Alphabetical/In-Order\n");
                    printf("5. Back to Main Menu\n");
                    printf("Choice: ");
                    scanf("%d", &subChoice);

                    int bId; char title[100];
                    if (subChoice == 1) {
                        printf("Enter unique Book ID: "); scanf("%d", &bId);
                        printf("Enter Book Title: "); scanf(" %[^\n]s", title);
                        libraryRoot = insertBook(libraryRoot, bId, title);
                        printf("Book Catalogued.\n");
                    } else if (subChoice == 2) {
                        printf("Enter Book ID to Borrow: "); scanf("%d", &bId);
                        BSTNode* res = searchBook(libraryRoot, bId);
                        if (res) {
                            if (res->isBorrowed) printf("Sorry, this book is already borrowed.\n");
                            else { res->isBorrowed = 1; printf("Success! You checked out: %s\n", res->title); }
                        } else printf("Book ID not found.\n");
                    } else if (subChoice == 3) {
                        printf("Enter Book ID to Return: "); scanf("%d", &bId);
                        BSTNode* res = searchBook(libraryRoot, bId);
                        if (res && res->isBorrowed) { res->isBorrowed = 0; printf("Book returned successfully.\n"); }
                        else printf("Invalid operation or book was not borrowed.\n");
                    } else if (subChoice == 4) {
                        printf("\n--- Library Catalogue (Sorted by ID) ---\n");
                        displayBooksInOrder(libraryRoot);
                    }
                } while (subChoice != 5);
                break;

            case 4:
                do {
                    printf("\n--- Task 4: Online Shopping Sorting/Searching ---\n");
                    printf("1. View Current Catalog (Unsorted)\n");
                    printf("2. Sort Catalog via Merge Sort (O(n log n))\n");
                    printf("3. Find Product via Binary Search (O(log n))\n");
                    printf("4. Back to Main Menu\n");
                    printf("Choice: ");
                    scanf("%d", &subChoice);

                    if (subChoice == 1) {
                        for (int i = 0; i < catalogSize; i++)
                            printf("ID: %d | %-20s | $%.2f\n", catalog[i].productId, catalog[i].name, catalog[i].price);
                    } else if (subChoice == 2) {
                        mergeSort(catalog, 0, catalogSize - 1);
                        printf("Catalog sorted successfully by ID.\n");
                    } else if (subChoice == 3) {
                        int target; printf("Enter Product ID to find: "); scanf("%d", &target);
                        int index = binarySearchProducts(catalog, catalogSize, target);
                        if (index != -1) printf("Match Found! Item: %s | Price: $%.2f\n", catalog[index].name, catalog[index].price);
                        else printf("Item not found. (Note: Search requires sorting first!)\n");
                    }
                } while (subChoice != 4);
                break;

            case 5:
                // Global Cleanup
                freeStudentList(studentHead);
                freeQueue(&serviceQueue);
                freeBST(libraryRoot);
                printf("Exiting system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid configuration index.\n");
        }
    }
    return 0;
}