/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement singly circular link list with associated operation.
Program no: 007
Date :  2021.12.13
**************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*start=NULL;
struct node* create_tmp()
{
	int v;
	struct node *tmp;
	printf("Enter value\n");
	scanf("%d",&v);
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=v;
	tmp->next=start;
	return tmp;
}
void create()
{
	char ch;
	do{
		struct node *tmp,*i;
		tmp=create_tmp();
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
	fflush(stdin);
    printf("wanna enter more!y or n\n");
    scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
    puts("list is made");
    return;
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
void insert_at_a_position()
{
struct node *tmp,*i=start->next;
	 int p,j;
	 if(start==NULL)
	 {
	 	printf("list is empty");
	 	return;
	 }
	 else{
	 		printf("\nEnter a position to add\n");
	 		scanf("%d",&p);
	  		tmp=create_tmp();
	  		if(p==1)
     		{
     			tmp->next=start->next;
     			start->next=tmp;
     			return;
	 		}
	        else
			{	
	 		for(int j=1;j<p-1 && i!=start;j++)
	 		{
	 			i=i->next;
		 	}
		 	if(i==start)
		 	{
		 		start->next=tmp;
		 		tmp->next=start;
				start=tmp;
            }
            else
		 	{
			 	tmp->next=i->next;
		 		i->next=tmp;
		 	}
		 	return;
	    }	    
    }
}
void delete_at_a_position()
{
	struct node *i=start->next,*tmp;
	int j,p;
	if(start==NULL)
	{
	 	printf("list is empty");
	 	return;
    }
	else{	 
			printf("Enter a position\n");
			scanf("%d",&p);
			if(p==1)
			{
				tmp=start->next;
				start->next=start->next->next;
				free(tmp);
    		}
	 		else{
	 		for(int j=1;j<p-1 && i->next!=start;j++)
	 		{
	 			i=i->next;
		 	}
		 	if(i->next==start)
		 	{
		 		tmp=start;
  	        	i->next=start->next;
  	        	start=i;
  	        	free(tmp);
		 	}
		 	else
		 	{
		 		tmp=i->next;
		 		i->next=i->next->next;
		 		free(tmp);
		 	}
		 	return;
       }
    }
}
int main()
{
	int i,ch;
	while(1)
    {
	printf("\n Choose the option\n(0)exit\n(1)Create a singly circular link list\n(2)show\n(3)add at a postion\n(4)delete at a position\n");
	scanf("%d",&ch);
    switch(ch)
    {
        case 0:exit(0);
               break;
        case 1:create();
               break;
        case 2:show();
               break;
        case 3:insert_at_a_position();
               break;
        case 4:delete_at_a_position();
           	   break;
        default:printf("\n Wrong input");
    }
    }
}
