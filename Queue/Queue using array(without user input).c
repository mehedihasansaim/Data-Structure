#include<stdio.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{

    if(rear == N-1)
    {
        printf("Overflow.\n");
    }
    else if(front == -1)
    {
        front = rear = 0;
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

    if(front==-1)
    {
        printf("Underflow.\n");
    }
    else if(front ==  rear)
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
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements is: \n");
        for(int i= front; i<=rear; i++)
        {
            printf("|%d|\n", queue[i]);
        }
    }
}

int main()
{

    printf("Implementing a queue using an array in C [max size N=5].\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();
    display();

    return 0;




}
