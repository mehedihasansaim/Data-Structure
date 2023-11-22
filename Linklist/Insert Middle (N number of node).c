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
void insertMid();

int main(){

        int n;
        printf("Enter your number you want to create node : ");
        scanf("%d", &n);
        createNode(n);
        display();

        insertMid();
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

void insertMid(){

            int i, pos;
            node *newNode, *temp, *current, *prev;
            newNode = (node*) malloc (sizeof(node));

            printf("Enter position where you want to insert node: ");
            scanf("%d", &pos);
            printf("Inserting data at the Middle position...\n");
            printf("Enter data for newNode: ");
            scanf("%d", &newNode->data);

            temp = head;
            for(i=1; i<pos; i++){
                prev = temp ;
                current = temp->next;
                temp = temp->next;
            }
            newNode->next = current;
            prev->next = newNode;

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

