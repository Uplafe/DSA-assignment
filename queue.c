#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int ticketId, const char* serviceType) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    if (!temp) return;
    temp->ticketId = ticketId;
    strcpy(temp->serviceType, serviceType);
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q, char* serviceOut) {
    if (q->front == NULL) return 0;

    QNode* temp = q->front;
    strcpy(serviceOut, temp->serviceType);
    int id = temp->ticketId;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return id;
}

int peek(Queue* q, char* serviceOut) {
    if (q->front == NULL) return 0;
    strcpy(serviceOut, q->front->serviceType);
    return q->front->ticketId;
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Service Queue is currently empty.\n");
        return;
    }
    QNode* curr = q->front;
    printf("\n--- Current Service Waiting Line ---\n");
    while (curr != NULL) {
        printf("[Ticket #%d: %s] -> ", curr->ticketId, curr->serviceType);
        curr = curr->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue* q) {
    char dummy[30];
    while (dequeue(q, dummy));
}