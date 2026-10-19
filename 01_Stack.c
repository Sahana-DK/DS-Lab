#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int ele);
void pop();
void display();

int main()
{
    int ele, choice;

    while (1)
    {
        printf("\nChoose: (1. Push, 2. Pop, 3. Display, 4. Exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("YOU EXITED!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void push(int ele)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow!!\n");
    }
    else
    {
        top++;
        stack[top] = ele;
        printf("Element is pushed!!\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Element is popped: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!!\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
