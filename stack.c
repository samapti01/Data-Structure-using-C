/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement stack using array
Program no: 001
Date :  2021.12.14
**************************/
#include<stdio.h>
#define size 5
int stk[size];
int top=-1;
void push(int value)
{
    if(top==size-1)
    {
        printf("\nstack overflow");
        return;
    }
    top++;
    stk[top]=value;
}
int pop()
{
    if(top==-1)
     {
        printf("\n stack underflow");
        return -1;
     }
     int value=stk[top];
     top--;
     return value;
}
void show()
{
    int i;
    printf("\n stack status:");
    for(i=0;i<=top;i++)
    {
        printf("\t %4d",stk[i]);
    }
}
int main()
{
    int n,ch;
    int ch=1;
    while(1)
    {
        printf("\n 1.push \n2.pop \n0. exit");
        printf("\n Enter your choice");
        //scanf("%d",&ch);
        switch(ch)
        {
            case 0:exit(0);
                   break;
            case 1:printf("Enter a value");
                   scanf("%d",&n);
                   push(n);
                   show();
                   break;
            case 2:n=pop();
                   show();
            printf("\n popped item:%d",n);
                   break;
            default:printf("\n Wrong input");
        }
    }
}
