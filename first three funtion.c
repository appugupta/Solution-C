#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define structure
typedef struct nodetype
{
  int info;
  struct nodetype* next;
}node;
//funtion prototype
void Createmptylist(node **head);
void Traverseinorder(node * head);
void Insertatbegining(node **head, int item);

void main()
{
 node * head;
 int choice, element, after;
 Createmptylist(&head);
 while(1)
 {
   printf("operation available are \n");
   printf("1 Insertatbegining \n");
   printf("2 Traversinorder \n");
   printf("enter choice 1or 2\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1: printf("\n enter element:");
	   scanf("%d",&element);
	   Insertatbegining(&head,element);
	   break;

    case 2: if(head==NULL)
	    printf("\n listi is empty");
	   else
	    Traverseinorder(head);
	    printf("\press any key to contiue");
	       getch();
	       break;
    default: exit(0);
	      }
   }
}
void Createmptylist(node **head)
{
 *head=NULL;
}
void Insertatbegining(node **head,int item)
 {
  node *ptr;
  ptr=(node *)malloc(sizeof(node));
  ptr->info=item;
  if(*head== NULL)
  ptr->next=NULL;
  else
  ptr->next=*head;
  *head=ptr;
  }

void Traverseinorder(node *head)
{
 while(head!= NULL)
 {
   printf("\n %d",head->info);
   head= head->next;
 }
}



