//Create a singly linked list and display it
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
}*start=NULL;

void create(int v)
{
	struct node *tmp,*i; 
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=v;
	tmp->next=NULL;
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
}
void avg()
{
	int sum=0,avg,count=0;
    struct node *i=start;
	while(i!=NULL)
	{
		sum+=i->info;
		count++;
		i=i->next;
		
	}
	avg=sum/count;
	printf("\navg=%d",avg);
}
void add_beg(int n)
{
  struct node *tmp;
  tmp=(struct node *)malloc(sizeof(struct node));
  tmp->info=n;
  tmp->next=start;
  start=tmp;
}
void add_end(int n)
{
  struct node *tmp,*i=start;
  tmp=(struct node *)malloc(sizeof(struct node));
  tmp->info=n;
  tmp->next=NULL;
  while(i->next!=NULL)
	{
		i=i->next;
	}
	i->next=tmp;
}
void insert(int p,int n)
{
	 struct node *tmp,*i=start;
	 tmp=(struct node *)malloc(sizeof(struct node));
     tmp->info=n;
     tmp->next=NULL;
     if(p==1)
     {
     	tmp->next=start;
     	start=tmp;
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
	 }
}
void addafterdata(int data ,int n)
{
	struct node *tmp,*ptr;
	ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->info==data)
			{
				
  				tmp=(struct node *)malloc(sizeof(struct node));
  				tmp->info=n;
  				tmp->next=ptr->next;
  				ptr->next=tmp;
  				return;
			}
			ptr=ptr->next;	
		}	
		printf("%d not present in the list\n",data);
		return;
		
}
void addbeforedata(int data,int n)//
{
	struct node *tmp,*ptr;
	ptr=start;
		while(ptr->next!=NULL)
		{
			if(ptr->next->info==data)
			{
				
  				tmp=(struct node *)malloc(sizeof(struct node));
  				tmp->info=n;
  				tmp->next=ptr->next;
  				ptr->next=tmp;
  				return;
			}
			ptr=ptr->next;	
		}	
		printf("%d not present in the list\n",data);
		return;
}
void deletefirst()
{
	struct node *tmp;
	tmp=start;
	start=start->next;
	free(tmp);
}
void deletelast()//
{
	struct node *tmp,*ptr;
    tmp->next=NULL;
	ptr=start;
	while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;	
		}
	tmp=ptr->next;
  	ptr->next=NULL;
  	free(tmp);
  	return;	
}
void deletedata(int data)//
{
	struct node *tmp,*ptr;
    tmp->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		{
			if(ptr->next->info==data)
			{
  				tmp=ptr->next;
  				ptr->next=tmp->next;
  				free(tmp);
  				return;
			}
			ptr=ptr->next;	
		}	
		printf("%d not present in the list\n",data);
}
void reverselist()//
{
	struct node *ptr=start,*next,*prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
}
int GetNth( int index)
{
 
    struct Node* ptr = start;
 
    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (ptr != NULL) {
        if (count == index)
            return (ptr->data);
        count++;
        ptr = ptr->next;
    }
void printNthFromLast(int n)
{
    int len = 0, i;
    struct Node* temp = start;
  
    // count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
  
    // check if value of n is not
    // more than length of the linked list
    if (len < n)
        return;
  
    temp = start;
  
    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
  
    printf("%d",&temp->data);
  
    return;
}
int getCount()
{
    // Base Case
    if (start == NULL) {
        return 0;
    }
    // Count this node plus the rest of the list
    else {
        return 1 + getCount(start->next);
    }
}
void count_no_of_key(int search_for)
{
    struct Node* ptr=start;
    int count = 0;
    while (ptr != NULL) {
        if (ptr->data == search_for)
            count++;
        ptr=ptr->next;
    }
    printf("%d",count);
}
boolean checkpalindrome() 
{
 	struct node	*slow=start;
 	struct node	*fast=start;
 	
 	while(fast!=NULL and fast->next!=NULL)
 	{
 		slow=slow->next;
 		fast=fast->next->next;
	 }
	 struct node *prev=NULL;
	  struct node *next;
	  struct node cur=slow;
	  while(cur!=NULL)
	  {
	  	next=cur->next;
	  	cur->next=prev;
	  	prev=cur;
	  	cur=next;
	  }
	  fast=start;
	  while(prev!=NULL)
	  {
	  	if(fast->info!=prev->info)
			return false;
		fast=fast->next;
		prev=prev->next;
	  }
	 return true;
}	
node remove_duplicates_from_sortedlist()
{
	struct node *root=start;
	if(!root)return NULL;
	while(root->next!=NULL)
	{
		if(root->info==root->next->info)
		{
			root->next=root->next->next;
		}
		else root=root->next;
	}
	return head;
}
void remove_duplicates_from_unsortedlist()
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data) {
                /* sequence of steps is important here */
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void swapnodeswithoutswappingdata(struct Node** start, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
 
    // Search for x (keep track of prevX and CurrX
    struct Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    struct Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;
 
    // Swap next pointers
    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
 
struct Node *createlist()
{
    struct Node *ptr=NULL;
    struct Node *current=NULL;
    struct Node *head=NULL;
    puts("We are creating a list now\n");
    char ch;
    do{
        ptr=(struct Node*)malloc(sizeof(struct Node));
        if(ptr==NULL)
        {
            printf("memory not available");
            return ptr;
        }
            puts("Enter data");
            scanf("%d",&ptr->data);
            ptr->next=NULL;
        if(head==NULL)
        {
            head=ptr;
            current=ptr;
        }
        else{
            current->next=ptr;
            current=ptr;
        }
        fflush(stdin);
        printf("wanna enter more!y or n\n");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    puts("list is made");
    return head;
}
	/*avg();
	add_beg(5);
	show();
	add_end(6);
	show();*/
	insert(5,101);
	show();
	addafterdata(10,11);
	show();
	addbeforedata(10,11);
	show();
	deletefirst();
	show();
	deletelast();
	show();
	deletedata(20);
	show();
	GetNth(6);
	printNthFromLast(5);
	printf ("%d",getCount());
	 count_no_of_key(10);
	checkpalindrome();
	remove_duplicates_from_sortedlist();
	remove_duplicates_from_unsortedlist();
	swapnodeswithoutswappingdata();
	pairwise_swap_elements();
	movelasttofront();
	intersectn_two_sortedlist();
	intersectn_two_linkedlist();
	quicksort();
	segregateeven_odd();
	show();*/
	reverselist();
	show();
}
