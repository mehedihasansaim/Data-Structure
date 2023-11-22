#include<stdio.h>
#define MAX_SIZE 5

int rear = -1;
int front = -1;
int queue[MAX_SIZE];


void enqueue(int x)
{

    if(rear == MAX_SIZE-1)
    {
        printf("Overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front = 0;
        rear = 0;

        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}




void dequeue()
{

    if(front == -1 && rear == -1)
    {
        printf("Underflow.\n");
    }
    else if(front == rear)
    {
        printf("%d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequeue element is : %d\n", queue[front]);
        front++;
    }
}



void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements : \n");
        for(int i=front; i<= rear; i++)
        {
            printf("|%d| \n", queue[i]);
        }
    }
}


int main()
{
    int x;

    printf("\nQueue operations using array");
    printf("\n---------------------------------------");
    printf("\n 1.Enqueue\n 2.Dequeue \n 3.Display\n 4.Exit\n");

    int choice = 0;
    while(choice!= 4)
    {

        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter a value to enqueue: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if(choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();

        }
        else if(choice == 4)
        {
            printf("\n Exit point");
        }
        else
        {
            printf("\n Please enter a valid choice(1/2/3/4)");
        }
    }
    return 0;
}
