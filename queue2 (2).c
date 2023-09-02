/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement circular queue using array
Program no: 001
Date :  2021.12.21
*********************/
#include<stdio.h>
#define size 3
int rear=-1,front=-1;
int arr[size];
void insert(int value)
{
    if(front==0&&rear==size-1||rear+1==front)
    {
        printf("overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    if(rear==size-1&& front!=0)
        rear=0;
    else rear++;
    arr[rear]=value;
}
int delete(){
    if(front==-1)
    {
        printf("Queue is empty");
        return 0;
    }
    int value=arr[front];
    if(front==rear)
        rear=front=-1;
    else if(front==size-1)
            front=0;
         else front++;
    return value;
}
void show()
{
    printf("check status:\t");
    int i;
    if(front<=rear)
		{
			for(i=front;i<=rear;i++)
				printf("\t %d", a[i]);
		}
		else
		{
			for(i=front;i<size;i++)
				printf("\t %d", a[i]);
			for(i=0;i<=rear;i++)
				printf("\t %d", a[i]);
		}

}
int main()
{
    int n,ch;
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
            case 2:n=delete();
            printf("\n Deleted item:%d\n",n);
                  show();
                   break;
            default:printf("\n Wrong input");
        }
    }
}
