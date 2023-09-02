/*/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Two dimensional dynamic array implementation
Program no: 004
Date :  2021.12.13
**************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	int i,j,r,c;
	printf("Enter the size of rows and columns");
	scanf("%d %d",&r,&c);
	int **a=(int**)calloc(r,sizeof(int*));
	for(i=0;i<r;i++)
	{
		a[i]=(int *)calloc(c,sizeof(int));
	}
	printf("Enter the numbers");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{	
			printf(" %d",a[i][j]);
		}
		printf("\n");
	}
}
