#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500
#include <string.h>

struct Node
{
    int price;
    char data[100]; // Assuming a maximum string length of 100 characters
    struct Node *next;
};

typedef struct Node menu;
menu *head;

void createNode();
void display();
void insertBeg();
void insertMid();
void insertEnd();

struct node
{
    int table_number; // New field for table number
    int data;
    struct node *next;
};


typedef struct node node;
node *top = NULL;

void push()
{
    int num;
    while(num != -1)
    {
        int x, table_num;
        node *newNode;
        newNode = (node *)malloc(sizeof(node));

        if (newNode == NULL)
        {
            printf("Stack Overflow\n");
            return;
        }

        printf("\nThis is our menu. All is available for your order.\n\n");
        printf("1. Pizza - 120 tk\n");
        printf("2. Burger - 80 tk\n");
        printf("3. Chicken - 100 tk\n");
        printf("For exit press -1 in table number\n");

        printf("\nEnter table number: ");
        scanf("%d", &table_num);
        if(table_num == -1)
        {
            break;
        }
        newNode->table_number = table_num; // Store the table number
        printf("Enter item number you want to order: ");
        scanf("%d", &x);
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        printf("\nAdd item-%d in your order list for table %d\n", x, table_num);
        printf("-----------------------------------------------------\n");
        num = table_num;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Underflow\n");
        return;
    }

    node *temp;
    temp = top;
    printf("Remove item-%d from your order for table %d\n", top->data, top->table_number);
    top = top->next;
    free(temp);
}

void C_display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *temp;
    temp = top;
    printf("Stack elements: \n");
    while (temp != NULL)
    {
        printf("\n\t|| Table %d | Item no. %d ||\n", temp->table_number, temp->data);
        temp = temp->next;
    }
}
/*------------------------------------------------------ End of stack --------------------------------------------*/
/*------------------------------------------------------ Starts of Queue --------------------------------------------*/

int rear = -1;
int front = -1;
int queue[MAX_SIZE];

void enqueue(int x)
{

    if(rear == MAX_SIZE-1)
    {
        printf("Order limit is full. Please try again latter.\n");
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
        printf("No order yet.\n");
    }
    else if(front == rear)
    {
        printf("%d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Delivered order is : %d\n", queue[front]);
        front++;
    }
}



void M_display()
{
    if(front == -1 && rear == -1)
    {
        printf("No order yet.\n");
    }
    else
    {
        printf("Customers orders : \n");
        for(int i=front; i<= rear; i++)
        {
            printf("|%d| \n", queue[i]);
        }
    }
}


/*------------------------------------------------------ Ends of Queue --------------------------------------------*/



/*------------------------------------------------------ Starts of main function --------------------------------------------*/
int main()
{
    while(1)
    {

        int id;
        printf(" \t\t\t\t For customer press 1\n \t\t\t\t For management press any integer number\n\n \t\t\t\t Press:");
        scanf("%d",&id);

        if(id == 1)
        {
            printf("\n \t\t\t\t\tWelcome to our restaurent\n\n");

            int choice = 0;
            while (choice != 4)
            {
                printf("-----------------------------------------------------\n");
                printf("1. Add your order\n");
                printf("2. Remove order from list\n");
                printf("3. Show your order\n");
                printf("4. Submit your order\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    push();
                }
                else if (choice == 2)
                {
                    pop();
                }
                else if (choice == 3)
                {
                    C_display();
                }
                else if (choice == 4)
                {
                    printf("Your order is accepted.\n\n");
                }
                else
                {
                    printf("Please enter a valid choice.\n");
                }
            }
        }




        else
        {
            printf("\n\t\t\t\t\tWelcome to our management system\n\n");
            int key;
            printf("Select your option: \n\n1. Deliver your customer order. \n2. Edit Your Menu. \nPress: ");
            scanf("%d", &key);

            if(key == 1)
            {
                /*============================================  Queue starts here ================================================================= */
                int x;
                if (top == NULL)
                {
                    printf("\n >>\tNo order Yet!!\n");

                }

                printf("\n---------------------------------------");
                printf("\n 1.Add all of customers order \n 2.Delivered order \n 3.Show order list \n 4.Exit\n");

                int choice = 0;
                while(choice!= 4)
                {

                    printf("\nEnter the choice: ");
                    scanf("%d", &choice);

                    if(choice == 1)
                    {
                        node *temp;
                        temp = top;
                        int count;

                        while (temp != NULL)
                        {
                            temp = temp->next;
                            count++;
                        }

                        int array[count];
                        temp = top;
                        int i;

                        while (temp != NULL)
                        {
                            array[i] = temp->data;
                            i++;
                            temp = temp->next;
                        }

                        for(i=count; i>=0; i--)
                        {
                            enqueue(array[i]);
                        }
                        printf("Successfully stored all customers order.\n");

                    }
                    else if(choice == 2)
                    {
                        dequeue();
                    }
                    else if (choice == 3)
                    {
                        M_display();

                    }
                    else if(choice == 4)
                    {
                        printf("\nExit point\n");
                        printf("-----------------------------------------------------\n");
                    }
                    else
                    {
                        printf("\n Please enter a valid choice(1/2/3/4)");
                    }
                }
            }
            /*============================================  Link list starts here ================================================================= */
            else if(key == 2)
            {
                int n;
                printf("\nEnter the number of items you want to add: ");
                scanf("%d", &n);

                createNode(n);
                display();

                insertBeg();
                display();

                insertMid();
                display();

                insertEnd();
                display();

            }
        }

    }




    return 0;
}











void createNode(int n)
{
    head = (menu *)malloc(sizeof(menu));

    printf("Enter item 1: ");
    scanf("%s", head->data);
    printf("Enter price for item 1: ");
    scanf("%d", &head->price);
    head->next = NULL;
    printf("\n\n");

    int i;
    menu *temp, *newNode;
    temp = head;

    for (i = 2; i <= n; i++)
    {
        newNode = (menu *)malloc(sizeof(menu));

        printf("Enter item %d: ", i);
        scanf("%s", newNode->data);
        printf("Enter price for item %d: ", i);
        scanf("%d", &newNode->price);
        newNode->next = NULL;
        printf("\n\n");

        temp->next = newNode;
        temp = temp->next;
    }
}

void insertBeg()
{
    menu *newNode;
    newNode = (menu *)malloc(sizeof(menu));
    printf("Inserting item at the Start position...\n");

    printf("Enter item for start position: ");
    scanf("%s", newNode->data);
    printf("Enter price for item: ");
    scanf("%d", &newNode->price);
    newNode->next = head;
    head = newNode;
}

void insertMid()
{
    int i, pos;
    menu *newNode, *temp, *current, *prev;
    newNode = (menu *)malloc(sizeof(menu));

    printf("Enter position where you want to insert your item: ");
    scanf("%d", &pos);

    printf("Enter item for %d position: ",pos);
    scanf("%s", newNode->data);

    printf("Enter price for item: ");
    scanf("%d", &newNode->price);

    temp = head;
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        current = temp->next;
        temp = temp->next;
    }
    newNode->next = current;
    prev->next = newNode;
}

void insertEnd()
{
    menu *temp, *newNode;
    newNode = (menu *)malloc(sizeof(menu));
    printf("Inserting item at the End position...\n");

    printf("Enter item for End position: ");
    scanf("%s", newNode->data);
    printf("Enter price for item: ");
    scanf("%d", &newNode->price);

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void display()
{
    menu *temp;
    temp = head;
    printf("\nYour Items here: \n");
    int i = 1;
    while (temp != NULL)
    {
        printf("%d. %s - %d\n", i, temp->data, temp->price);
        temp = temp->next;
        i++;
    }
    printf("\n\n");
}

