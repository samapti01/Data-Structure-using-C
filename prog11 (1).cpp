 /*************************
NAME :  SAMAPTI CHAR
PROGRAM :Create a binary tree and search in preorder,postorder and inorder traversal
**************************/
#include<stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
}
struct node *create()
{
	struct node *tmp;
	int x;
	printf("\nEnter data(-1 for no node)");
	scanf("%d",&x);
	if(x==-1)
	return NULL;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=x;
	printf("Enter left child of %d",x);
	tmp->left=create();
	printf("Enter right child of %d",x);
	tmp->right=create();
	return tmp;
}
void preorder(struct node *ro)
{
	if(ro==NULL)
	return;
	printf("%d ",ro->info);
	preorder(ro->left);
	preorder(ro->right);
}
void inorder(struct node *ro)
{
	if(ro==NULL)
	return;
	inorder(ro->left);
	printf("%d ",ro->info);
	inorder(ro->right);
}
void postorder(struct node *ro)
{
	if(ro==NULL)
	return;
	postorder(ro->left);
	postorder(ro->right);
    printf("%d ",ro->info);
}
int main()
{
	int n,i;
	struct node *root=NULL;
	root=create();
	printf("preorder traversal \n");
    preorder(root);
    printf("inorder traversal \n");
    inorder(root);
    printf("postorder traversal \n");
    postorder(root);
}
