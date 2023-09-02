//circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*start=NULL;
void create(int n)
{
	struct node* tmp,*i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=n;
	if(start==NULL)
	{
		start=tmp;
		tmp->next=start;
    }
    else{
		tmp->next=start->next;
		start->next=tmp;
		start=tmp;
    } 
}
void show()
{
	struct node *i=start->next;
	while(i!=start)
	{
		printf("%4d",i->info);
		i=i->next;
	}
	printf("%4d",i->info);
	printf("\n\n");
}
struct node *createtmp(int n)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=n;
	return tmp;
}
void add_at_desired_location(int pos,int value)
{
	struct node *i,*tmp;
	tmp=createtmp(value);
	if(pos==1)
	{
		start->next=tmp;
	}
	struct node* i=start;
	while(i->next!=NULL)
	{
		i=i->next;
	}
		i->next=tmp;
		start=tmp;
}
void delete_at_desired_location(int pos)
{
	struct node *i,*tmp;
	if(pos==1)
	{
	tmp=start->next;
	start->next=start->next->next;
	free(tmp);
    }
	else{
    while(i->next!=start)
    {
    	i=i->next;	 
	}
	tmp=i->next;
	i->next=NULL;
	free(tmp);
    }
}
int main()
{
	int i;
	for(i=10;i<=100;i=i+10)
	{
		create(i);
	}
	show();
	add_at_desired_location(5,5);
	show();
    delete_at_desired_location(1);
	show();
}
