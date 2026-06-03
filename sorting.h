#ifndef SORTING_H
#define SORTING_H

typedef struct {
    int productId;
    char name[50];
    float price;
} Product;

void mergeSort(Product arr[], int l, int r);
int binarySearchProducts(Product arr[], int size, int targetId);

#endif