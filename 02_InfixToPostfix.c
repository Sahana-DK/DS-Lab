#include <stdio.h>
#define size 5
char stack[size];
int top= -1;

int pr(char symbol){
    if(symbol=='^'){
        return (3);
    }
    else if(symbol=='*'||symbol=='/'){
        return(2);
    }
    else if(symbol=='+'||symbol=='-'){
        return(1);
    }
    else{
        return(0);
    }
}

void push(char ele){
    stack[++top]=ele;
}

char pop(){
 return(stack[top--]);
}

int main(){
    char infix[50],postfix[50],ele,ch;
    int i=0,k=0;
    printf("enter the expression:");
    scanf("%s",infix);
    push('#');

    while((ch=infix[i++])!='\0'){
        if (ch=='('){
                push(ch);
        }
        else{
            if(isalnum(ch)){
                postfix[k++]=ch;
            }
            else{
                if(ch==')'){
                    while(stack[top]!='('){
                        postfix[k++]=pop();
                    }
                    ele=pop();
                }
                else{
                    while(pr(stack[top])>pr(ch)){
                        postfix[k++]=pop();
                    }
                    push(ch);
                }
            }
        }
    }

    while(stack[top]!='#'){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("%s",postfix);
}
