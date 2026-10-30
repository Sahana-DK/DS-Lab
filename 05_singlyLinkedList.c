#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

int count()
{
    struct node *temp;
    int i = 0;

    temp = head;

    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

struct node *create(int value)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = value;
    temp->next = NULL;

    return temp;
}

void insert_begin(int value)
{
    struct node *newnode;

    newnode = create(value);

    
    
    newnode->next = head;
    head = newnode;
}

void insert_end(int value)
{
    struct node *newnode, *temp;

    newnode = create(value);

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}



void insert_pos(int value, int pos)
{
    struct node *newnode, *temp;
    int i, c;

    i = count();

    if (pos < 1 || pos > i + 1)
    {
        printf("Insertion is not possible\n");
        return;
    }

    if (pos == 1)
    {
        insert_begin(value);
        return;
    }

    newnode = create(value);
    temp = head;
    c = 1;

    while (c < pos - 1)
    {
        temp = temp->next;
        c++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int ch, pos, value;

    do
    {
        printf("\n1. Insert begin\n");
        printf("2. Insert end\n");
        printf("3. Insert position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_pos(value, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                break;

            default:
                printf("Your choice is wrong!\n");
        }

    } while (ch != 5);

    return 0;
}
