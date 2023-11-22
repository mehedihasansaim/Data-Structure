#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};

typedef struct node node;
node *head;
void createNode();
void display();
void insertEnd();

int main(){

        int n;
        printf("Enter your number you want to create node : ");
        scanf("%d", &n);
        createNode(n);
        display();

        insertEnd();
        display();

        return 0;
}


void createNode(int n){

        head = (node*) malloc (sizeof(node));
        printf("Enter data for node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;

        int i;
        node *temp, *newNode;
        temp = head;

        for(i=2; i<=n; i++){
            newNode = (node*) malloc (sizeof(node));
            printf("Enter data for node %d : ",i);
            scanf("%d", &newNode->data);
            newNode->next = NULL;

            temp->next = newNode;
            temp = temp->next;
        }
}


void insertEnd(){

            node *temp, *newNode;
            newNode = (node*) malloc(sizeof(node));
            printf("Inserting data at the End position...\n");
            printf("Enter data for newNode: ");
            scanf("%d", &newNode->data);

            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
}

void display(){

            node *temp;
            temp = head;
            printf("\n\nYour Link List is : \n");
            while(temp!= NULL){
                printf("|%d|-> ", temp->data);
                temp = temp->next;
            }
            printf("\n\n");
}

