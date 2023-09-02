/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement queue using static array
Program no: 009
Date :  2022.02.11
**************************/
#include<stdio.h>
#define size 10
int rear=-1,front=0;
int arr[size];
void insert (int value)
{
    if(rear==size-1)
    {
        printf("overflow\n");
        return;
    }
    rear++;
    arr[rear]=value;
}
int delete(){
    if(rear<front)
    {
        printf("Queue is empty");
        return 0;
    }
    int value=arr[front];
    front++;
    return value;
}
void show()
{
    printf("check status:\t");
    int i;
    for(i=front;i<=rear;i++)
    printf("\t %d",arr[i]);
}
int main()
{
    int n,ch;
    while(1)
    {
        printf("\n 1.Insert \n2.Delete \n0. exit");
        printf("\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:exit(0);
                   break;
            case 1:printf("Enter a value");
                   scanf("%d",&n);
                   insert(n);
                   show();
                   break;
            case 2:n=delete();
            printf("\n Deleted item:%d\n",n);
                  show();
                   break;
            default:printf("\n Wrong input");
        }
    }
}
