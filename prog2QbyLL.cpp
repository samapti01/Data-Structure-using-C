/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement queue using linked list
Program no: 001
Date :  2021.12.21
**************************/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*rear=NULL,*front=NULL;

void insert(int value)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=value;
	tmp->next=NULL;
	if(rear==NULL)
	{	
		front=rear=tmp;
	}
	else
	{
			rear->next=tmp;
			rear=tmp;
	}
}
void Delete()
{
		struct node *tmp;
		if(front==NULL)
		{
			printf("stack is empty");
			return;
		}
		tmp=front;
		front=front->next;
		free(tmp);
}
void show()
{
	struct node *i=front;
	while(i!=NULL)
	{
		printf("%4d",i->info);
		i=i->next;
	}
}
int main()
{
	int n,ch;
	while(1)
    {
        printf("\n 1.Insert \n2.delete \n0. exit");
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
            default :printf("\n Wrong input");
        }
    }
}
