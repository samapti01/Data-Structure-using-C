//bst
#include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1;
struct node
{
	int info;
	struct node *left,*right;
};
struct node *create(struct node *root,int value)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof (struct node));
		root->info=value;
		root->right=NULL;
		root->left=NULL;
		return root;
	}
	if(value>root->info)
	root->right=create(root->right,value);
	else
	root->left=create(root->left,value);
	return root;
}
/*
void preorder(struct node *r)
{
	if(r!=NULL)
	{
		printf(" %d",r->info);
	    preorder(r->left);
		preorder(r->right);
	}
}
void inorder(struct node *r)
{
	if(r!=NULL)
	{
		
	    inorder(r->left);
	    printf(" %d",r->info);
		inorder(r->right);
	}
}*/
void preorder(struct node *ptr)
{
	struct node *stk[size];
	stk[++top]=ptr;
	while(top!=-1)
	{
		ptr=stk[top--];
		if(ptr!=NULL)
		{
			printf("%4d",ptr->info);
			stk[++top]=ptr->right;
			stk[++top]=ptr->left;
		}
	}
}

void inorder(struct node *ptr)
{
	struct node *stk[size];
	while(top!=-1 || ptr!=NULL)
	{
		if(ptr!=NULL)
		{
		stk[++top]=ptr;
		ptr=ptr->left;
		}	
		else{
		ptr=stk[top--];
		printf(" %d",ptr->info);
		ptr=ptr->right;
		
	}
	}
}

int main()
{
	int a[]={20,1,8,5,9,7,22,90,30,35,12},n=11,i;
	struct node *root=NULL;
	for(i=0;i<n;i++)
	{
		root=create(root,a[i]);
	}
	//preorder(root);
	
	inorder(root);
}
