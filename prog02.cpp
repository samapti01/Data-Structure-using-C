#include<stdio.h>
/*************************
NAME :  SAMAPTI CHAR
PROGRAM :One dimensional Dynamic array implementation
Program no: 002
Date :  2021.12.13
**************************/
#include<stdlib.h>
int main()
{
int *a,n,i;
printf("Enter the total no. of element in the list");
scanf("%d",&n);
a=(int*)calloc(n,sizeof(int));
printf("Enter the numbers");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<n;i++)

	printf(" %d",a[i]);                                 
}

