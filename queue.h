#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode {
    int ticketId;
    char serviceType[30]; // "Fee Payment", "Registration", etc.
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, int ticketId, const char* serviceType);
int dequeue(Queue* q, char* serviceOut);
int peek(Queue* q, char* serviceOut);
void displayQueue(Queue* q);
void freeQueue(Queue* q);

#endif