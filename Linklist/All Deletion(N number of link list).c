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
void delete_first();
void delete_middle();
void delete_last();

int main(){

        int n;
        printf("Enter your number you want to create node : ");
        scanf("%d", &n);
        createNode(n);
        display();

        delete_first();
        display();
        delete_middle();
        display();
        delete_last();
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


void delete_first()
{
             node *temp;
             temp=head;
             head=temp->next;
             free(temp);
             printf("After deleting the first node from the link list.");
}

void delete_middle()
{
            int pos,i;
            node *current, *temp, *prev;
            printf("\nEnter the position of the node you want to delete: ");
            scanf("%d",&pos);

            temp=head;
            for(i=1;i<pos;i++){

                prev=temp;
                current=temp->next;
                temp=temp->next;
            }
            prev->next=current->next;
            free(current);
}

void delete_last(){

         node *temp, *prev;
         temp=head;
         while(temp->next!=NULL){

             prev=temp;
             temp=temp->next;
         }
         prev->next=NULL;
         free(temp);
         printf("After deleting the last node from the link list.");
}
