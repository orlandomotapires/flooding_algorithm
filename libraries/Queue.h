#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int capacity;
    float *data;
    int front;
    int rear;
    int itemCount;
} Queue;

/*******************
 * Function Signatures
 *******************/

void create_queue(Queue *q, int c);
void insert(Queue *q, int v);
int remove_item(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void display_queue(Queue *q);

/*******************
 * Function Implementations
*******************/

void create_queue(Queue *q, int c) {
    q->capacity = c;
    q->data = (float*) malloc(q->capacity * sizeof(float));
    q->front = 0;
    q->rear = -1;
    q->itemCount = 0;
}

void insert(Queue *q, int v) {
    if(q->rear == q->capacity - 1)
        q->rear = -1;

    q->rear++;
    q->data[q->rear] = v;
    q->itemCount++;
}

int remove_item(Queue *q) {
    int temp = q->data[q->front++];

    if(q->front == q->capacity)
        q->front = 0;

    q->itemCount--;
    return temp;
}

int is_empty(Queue *q) {
    return (q->itemCount == 0);
}

int is_full(Queue *q) {
    return (q->itemCount == q->capacity);
}

void display_queue(Queue *q) {
    int count, i;

    for(count = 0, i = q->front; count < q->itemCount; count++) {
        printf("%.2f\t", q->data[i++]);

        if(i == q->capacity)
            i = 0;
    }
    printf("\n\n");
}
