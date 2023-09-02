/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement circular queue using linked list
Program no: 001
Date :  2021.12.21
*********************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*rear=NULL,*front=NULL;

void insert (int value)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=value;
	tmp->next=NULL;
	if((rear==NULL)&&(front==NULL))
	{	
		front=rear=tmp;
		rear->next=front;
    }
    else
    {
    	rear->next=tmp;
    	rear=tmp;
    	tmp->next=front;
	
	}
	
}
void Delete(){
	struct node*tmp;
	tmp=front;
    if((front==NULL)&&(rear==NULL))
    {
        printf("Queue is empty");
        return;
    }
    if(front==rear)
        {	
		rear=front=NULL;
        free(tmp);
        return ;
    }
         else 
		 {
		 	front=front->next;
		 	rear->next=front;
		 	free(tmp);
		 	return ;
		 }
}
void show()
{
	struct node *i=front;
    printf("check status:\t");
    do{
		printf("%4d",i->info);
		i=i->next;
	}
    while( i!=front);
   	
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
            case 2:Delete();
                  show();
                   break;
            default:printf("\n Wrong input");
        }
    }
}
