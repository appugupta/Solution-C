#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct poly
{
int degree;
int coeff;
};

void main()
{
struct poly poly1[10],poly2[10],product[100];
int noOfTerms1,noOfTerms2,count=-1;
int i,j;

printf("\nEnter Number Of Terms Of 1st Polynomial: ");
scanf("%d",&noOfTerms1);
for(i=0;i< noOfTerms1;i++)
{
printf("\nEnter Degree: ");
scanf("%d",&poly1[i].degree);
printf("\nEnter Coefficient: ");
scanf("%d",&poly1[i].coeff);
}/*End of i for loop*/
printf("\nEnter Number Of Terms Of 2nd Polynomial: ");
scanf("%d",&noOfTerms2);
for(i=0;i< noOfTerms2;i++)
{
printf("\nEnter Degree: ");
scanf("%d",&poly2[i].degree);
printf("\nEnter Coefficient: ");
scanf("%d",&poly2[i].coeff);
}/*End of i for loop*/
for(i=0;i< noOfTerms1;i++)
{
for (j=0;j< noOfTerms2;j++)
{
product[++count].degree=poly1[i].degree+poly2[j].degree;
product[count].coeff=poly1[i].coeff*poly2[j].coeff;
}
}
printf("\nThe Product Of Two Polynomials Is: \n");
for(i=0;i<=count;i++)
{
if(product[i].degree==0)
printf("%d ",product[i].coeff);
else if(product[i].degree==1)
printf("%dx ",product[i].coeff);
else
{
printf("%dx^%d ",product[i].coeff,product[i].degree);
}
if(i!=count)
printf("+ ");
}
getch();
}