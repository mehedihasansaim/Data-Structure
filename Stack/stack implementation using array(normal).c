#include<stdio.h>
#define n 3
int s[n];
int top = -1;

void push(int x)
{
    if(top < n-1){
        top = top + 1;
        s[top] = x;
        printf("Successfully added item %d\n", x);
    }
    else{
        printf("Exception! No Space.\n");
    }
}


int pop()
{
    if(top >= 0){
        int temp = s[top];
        top = top -1;
        return temp;
    }
    printf("Exception from pop! Empty stack.\n");
    return -1;

}

int peek()
{
    if(top>=0)
    {
        return s[top];
    }
    printf("Exception from peek! Empty stack.\n");
    return -1;
}


int main()
{
    printf("Implementing my stack in c.\n");
    peek();
    push(10);
    push(20);
    push(30);
    printf("pop item is %d\n", pop());
    push(40);
    printf("Top of stack is %d\n", peek());

    return 0;
}
