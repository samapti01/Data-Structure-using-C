/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement stack using linked list
Program no: 001
Date :  2021.12.21
**************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*top=NULL;

void push(int n)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	if(top==NULL)
	{	
		top=tmp;
		tmp->next=NULL;
	}
	else
	{
			tmp->next=top;
			top=tmp;
	}
}
void pop()
{
		struct node *tmp;
		if(top==NULL)
		{
			printf("stack is empty");
			return;
		}
		tmp=top;
		top=top->next;
		free(tmp);
}
void show()
{
	struct node *i=top;
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
        printf("\n 1.push \n2.pop \n0. exit");
        printf("\n Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:exit(0);
                   break;
            case 1:printf("Enter a value");
                   scanf("%d",&n);
                   push(n);
                   show();
                   break;
            case 2:pop();
                   show();
                   break;
            default:printf("\n Wrong input");
        }
    }
}
