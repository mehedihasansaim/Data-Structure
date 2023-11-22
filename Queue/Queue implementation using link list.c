#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Function to display the queue
void display(struct Queue* queue) {
    struct Node* current = queue->front;

    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("Queue operations using linked list\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exit point\n");
                exit(0);
            default:
                printf("Please enter a valid choice (1/2/3/4)\n");
        }
    }

    return 0;
}

