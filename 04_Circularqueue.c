#include<stdio.h>
#define size 5
int i;
int front=-1;
int rear=-1;
int cqueue[size];

void insert(int ele){
    if(front==0 && rear==size-1)
        printf("full");
    else{
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        cqueue[rear]=ele;

    }
}

void deleted(){
    if(front==-1)
        printf("empty");
    else{
        printf("%d is deleted",cqueue[front]);
        front=(front+1)%size;
    }
}

void display(){
    if(front==-1)
        printf("empty");
    else{
        for(int i=front;i!=rear;i=(i+1)%size){
            printf("%d",cqueue[i]);
        }
        printf("\n");
        printf("%d",cqueue[rear]);

    }
}

int main()
{
    int n,ele;
    while(1){
        printf("\n 1.insert,2.delete,3.display,4.exit:");
        scanf("%d",&n);
        switch(n){
            case 1:printf("add ele:");
                   scanf("%d",&ele);
                   insert(ele);
                   break;
            case 2: deleted();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default:printf("wrong option!");
        }
    }
}
