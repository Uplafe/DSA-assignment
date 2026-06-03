#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BSTNode* insertBook(BSTNode* root, int bookId, const char* title) {
    if (root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->bookId = bookId;
        strcpy(newNode->title, title);
        newNode->isBorrowed = 0;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (bookId < root->bookId)
        root->left = insertBook(root->left, bookId, title);
    else if (bookId > root->bookId)
        root->right = insertBook(root->right, bookId, title);
    return root;
}

BSTNode* searchBook(BSTNode* root, int bookId) {
    if (root == NULL || root->bookId == bookId)
        return root;
    if (bookId < root->bookId)
        return searchBook(root->left, bookId);
    return searchBook(root->right, bookId);
}

void displayBooksInOrder(BSTNode* root) {
    if (root != NULL) {
        displayBooksInOrder(root->left);
        printf("Book ID: %d | Title: %s | Status: %s\n", 
               root->bookId, root->title, root->isBorrowed ? "Borrowed" : "Available");
        displayBooksInOrder(root->right);
    }
}

void freeBST(BSTNode* root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}