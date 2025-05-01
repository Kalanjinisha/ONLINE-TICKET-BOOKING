#include <stdio.h>
#include <string.h>

#define SIZE 5
#define MAX_NAME_LEN 30

// Circular Queue for storing ticket requests
char queue[SIZE][MAX_NAME_LEN];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue a ticket request
void enqueue(char request[]) {
    if (isFull()) {
        printf("Request rejected! Queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    strcpy(queue[rear], request);
    printf("Request '%s' added to the queue.\n", request);
}

// Dequeue and process a ticket request
void dequeue() {
    if (isEmpty()) {
        printf("No ticket requests to process.\n");
        return;
    }

    printf("Processing request: '%s'\n", queue[front]);

    if (front == rear) {
        front = rear = -1;  // Queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display the current state of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue:\n");
    int i = front;
    while (1) {
        printf(" - %s\n", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
}

int main() {
    int choice;
    char request[MAX_NAME_LEN];

    while (1) {
        printf("\n--- Online Ticket Booking System ---\n");
        printf("1. Add Ticket Request\n");
        printf("2. Process Ticket Request\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter ticket request (name): ");
                fgets(request, MAX_NAME_LEN, stdin);
                request[strcspn(request, "\n")] = '\0'; // Remove newline
                enqueue(request);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}