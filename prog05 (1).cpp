/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Implement singly linear linked list with associated operation.
Program no: 005
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
	tmp->next=NULL;
	return tmp;
}
void create()
{
	char ch;
	do{
		struct node *tmp,*i;
		tmp=create_tmp(); 
		if(start==NULL)
		start=tmp;
		else{
		i=start;
		while(i->next!=NULL)
		{
			i=i->next;
		}
		i->next=tmp;
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
	struct node *i=start;
	while(i!=NULL)
	{
		printf("%4d",i->info);
		i=i->next;
	}
	printf("\n\n");
	return;
}
void insert_at_a_position()
{
	
	 struct node *tmp,*i=start;
	 int p,j;
	 if(start==NULL)
	 {
	 	printf("list is empty");
	 	return;
	 }
	 else{
	 		printf("Enter a position to add");
	 		scanf("%d",&p);
	  		tmp=create_tmp();
     		if(p==1)
     		{
     			tmp->next=start;
     			start=tmp;
     			return;
	 		}
	 		else{
	 				for(int j=1;j<p-1 && i->next!=NULL;j++)
	 				{
	 					i=i->next;
		 			}
		 			if(i->next==NULL)
		 			{			
		 				i->next=tmp;
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
void addafterdata()
{
	struct node *tmp,*ptr;
	int data;
	if(start==NULL)
	{
	 	printf("\nlist is empty\n");
	 	return;
	}
   else
	{
		ptr=start;
		printf("Enter data to insert a node after it ");
		scanf("%d",&data);
		while(ptr!=NULL)
		{
			if(ptr->info==data)
			{
  				tmp=create_tmp();
  				tmp->next=ptr->next;
  				ptr->next=tmp;
  				return;
			}
			ptr=ptr->next;	
		}	
		printf("%d not present in the list\n",data);
		return;
	}
}
void addbeforedata()
{
	struct node *tmp,*ptr;
	int data;
	if(start==NULL)
	 {
	 	printf("list is empty");
	 	return;
	 }
	 else{
	ptr=start;
	printf("Enter data to insert a node before it ");
	scanf("%d",&data);
		while(ptr->next!=NULL)
		{
			if(ptr->next->info==data)
			{
				tmp=create_tmp();
  				tmp->next=ptr->next;
  				ptr->next=tmp;
  				return;
			}
			ptr=ptr->next;	
		}	
		printf("%d not present in the list\n",data);
		return;
	}
}
void delete_at_a_position()
{
	struct node *tmp,*i=start;
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
     	tmp=start;
		start=start->next;
     	free(tmp);
     	return;
	 }
	 else{
	 	for(int j=1;j<p-1 && i->next->next!=NULL;j++)
	 	{
	 		i=i->next;
		}
		 if(i->next->next==NULL)
		 {
		 	tmp=i->next->next;
  	        i->next=NULL;
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
void deletedata()
{
	struct node *tmp,*i;
	int data;
	if(start==NULL)
	 {
	 	printf("list is empty");
	 	return;
	 }
	 else{
    tmp->next=NULL;
    printf("Enter data to delete from the list apart from first and last element");
	scanf("%d",&data);
	i=start;
	while(i->next!=NULL)
		{
			if(i->next->info==data)
			{
  				tmp=i->next;
  				i->next=tmp->next;
  				free(tmp);
  				return;
			}
			i=i->next;	
		}	
		printf("%d not present in the list\n",data);
		return;
	}
}
void reverselist()
{
	struct node *i=start,*next,*prev=NULL;
	if(start==NULL)
	 {
	 	printf("list is empty");
	 	return;
	 }
	 else{
	while(i!=NULL)
	{
		next=i->next;
		i->next=prev;
		prev=i;
		i=next;
	}
	start=prev;
}
}
int main()
{
	int i,ch;
	while(1)
    {
	printf("\nChoose the option\n(0)exit\n(1)Create a singly linked list\n(2)show\n(3)add at a postion\n(4)add after a node\n(5)add before a node\n(6)delete at a position\n(7)delete a node\n(8)Reverse a linked list\n");
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
            case 4:addafterdata();
            	   break;
            case 5:addbeforedata();
            	   break;
            case 6:delete_at_a_position();
            	   break;
            case 7:deletedata();
            	   break;
            case 8:reverselist();
            	   break;
            default:printf("\n Wrong input");
        }
    }
}
