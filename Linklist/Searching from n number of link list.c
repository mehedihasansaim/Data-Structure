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

void search();

int main(){

        int n;
        printf("Enter your number you want to create node : ");
        scanf("%d", &n);
        createNode(n);
        display();

        search();

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
            printf("Enter data for node %d : ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;

            temp->next = newNode;
            temp = temp->next;
        }
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



void search(){
           int key, count=0;
           node *temp;
           temp = head;

           printf("Enter key you want to search: ");
           scanf("%d", &key);

           while(temp != NULL){

            if(temp->data == key){
                printf("Data is found\n");
                count++;
                return;
            }
            temp = temp->next;
           }
           if(count==0){
            printf("Data is not found\n");
           }
}

