#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct CircularQueue {
    int front, rear, size;
    int queue[MAX_SIZE];
};

bool isFull(struct CircularQueue *cq) {
    return (cq->front == 0 && cq->rear == cq->size - 1) || (cq->front == cq->rear + 1);
}

bool isEmpty(struct CircularQueue *cq) {
    return cq->front == -1;
}

void enqueue(struct CircularQueue *cq, int data) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (cq->front == -1) {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % cq->size;
        cq->queue[cq->rear] = data;
        printf("%d enqueued successfully.\n", data);
    }
}

void dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int dequeuedData = cq->queue[cq->front];
        printf("%d dequeued successfully.\n", dequeuedData);

        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % cq->size;
        }
    }
}

void displayQueue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = cq->front;
        do {
            printf("%d ", cq->queue[i]);
            i = (i + 1) % cq->size;
        } while (i != (cq->rear + 1) % cq->size);
        printf("\n");
    }
}

int main() {
    struct CircularQueue circularQueue;
    circularQueue.front = circularQueue.rear = -1;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &circularQueue.size);

    while (1) {
        printf("1. Enqueue (Insert)  2. Dequeue (Remove)  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                int data;
                scanf("%d", &data);
                enqueue(&circularQueue, data);
                break;
            case 2:
                dequeue(&circularQueue);
                break;
            case 3:
                displayQueue(&circularQueue);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
