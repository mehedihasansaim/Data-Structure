#include <stdio.h>
#define MAX_SIZE 5

int top = -1;
int stack[MAX_SIZE];

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
        printf("Pushed %d onto the stack\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped %d from the stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++) {
            printf("| %d |\n", stack[i]);
        }
    }
}

int main() {
    int x;
    printf("\nStack operations using array");
    printf("\n---------------------------------------");
    printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");

    int choice = 0;
    while (choice != 4) {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a value to push: ");
            scanf("%d", &x);
            push(x);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            printf("\nExit point\n");
        } else {
            printf("\nPlease enter a valid choice (1/2/3/4)\n");
        }
    }
    return 0;
}
