#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int bookId;
    char title[100];
    int isBorrowed; // 0 = Available, 1 = Borrowed
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* insertBook(BSTNode* root, int bookId, const char* title);
BSTNode* searchBook(BSTNode* root, int bookId);
void displayBooksInOrder(BSTNode* root);
void freeBST(BSTNode* root);

#endif