/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement queue using dynamic array
Program no: 002
Date :  2021.12.14
**************************/
#include<stdio.h>
#include<stdlib.h>
int *arr;
int size;
int rear=-1,front=0;
void insert (int value)
{
    if(rear==size-1)
    {
        printf ("overflow\n");
        return;
    }
    rear++;
    arr[rear]=value;
}
int Delete(){
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
    printf("\nEnter the total no. of element in the list\n");
    scanf("%d",&size);
    arr=(int*)calloc(size,sizeof(int));
    while(1)
    {
        printf("\n 1.Insert \n2.Delete \n0. exit");
        printf("\n Enter your choice");
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
            case 2:n=Delete();
            printf("\n Deleted item:%d\n",n);
                  show();
                   break;
            default:printf("\n Wrong input");
        }
    }
}
