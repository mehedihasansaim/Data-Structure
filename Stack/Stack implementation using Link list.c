#include<stdio.h>
#include<stdlib.h>

struct node{

        int data;
        struct node *next;
};

typedef struct node node;
node *top = NULL;

void push(){

           int x;
           node *newNode;
           newNode = (node*) malloc (sizeof(node));

           if (newNode == NULL) {
           printf("Stack Overflow\n");
           return;
           }

           printf("Enter value you want to push: ");
           scanf("%d", &x);
           newNode->data = x;
           newNode->next = top;
           top = newNode;
           printf("Pushed %d onto the stack\n",x);
}

void pop(){

           if(top == NULL){
            printf("Underflow\n");
            return;
           }

           node *temp;
           temp = top;
           printf("Popped %d from the stack\n", top->data);
           top = top->next;
           free(temp);
}

void display(){

           if(top == NULL){
            printf("Stack is empty\n");
            return;
           }

           node *temp;
           temp = top;
           printf("Stack elements: \n");
           while(temp != NULL){
            printf("|%d|\n", temp->data);
            temp = temp->next;
           }
}


int main(){

          printf("\n\nStack Operations using linked list\n");
          printf("-------------------------------------------");
          printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");

          int choice =0;
          while(choice != 4){
            printf("\nEnter the choice: ");
            scanf("%d", &choice);

            if(choice ==1 ){
                push();
            }
            else if(choice == 2){
                pop();
            }
            else if (choice == 3){
                display();
            }
            else if(choice == 4){
                printf("\nExit point\n");
            }
            else{
                printf("Please enter a valid choice.\n");
            }
          }

          return 0;

}
