/*************************
NAME :  SAMAPTI CHAR
PROGRAM :Two dimensional Static array implementation
Program no: 003
Date :  2021.12.13
**************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[3][2]={{55,60},{70,90},{40,95}};
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<2;j++)
	printf(" %d",a[i][j]);
	printf("\n");
}
}
