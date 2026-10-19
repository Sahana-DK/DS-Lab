#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void insert(int ele){
    if(rear==MAX-1){
        printf("Full!!!");
    }
    else{
        if(front==-1){
            front++;
        }
        rear++;
        queue[rear]=ele;
    }
}

void deleted(){
    if(front==-1){
        printf("empty!!");
    }
    else{
        printf("ele deleted: %d",queue[front]);
        front++;
    }
}

void display(){
        for (int i=front;i<=rear;i++){
            printf("%d",queue[i]);
            printf("\n");
        }
}

int main(){
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
