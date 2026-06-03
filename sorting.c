#include "sorting.h"
#include <string.h>
#include <stdlib.h>

void merge(Product arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Product* L = (Product*)malloc(n1 * sizeof(Product));
    Product* R = (Product*)malloc(n2 * sizeof(Product));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].productId <= R[j].productId) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Product arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int binarySearchProducts(Product arr[], int size, int targetId) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].productId == targetId) return mid;
        if (arr[mid].productId < targetId) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
