#include<stdio.h>
#include<stdlib.h>
#define  N 5
int front=-1,rear=-1;
int queue[N];
int c=0;

void insert()
{
 	int item;
	printf("enter the item to be inserted");
	scanf("%d",&item);
	if((rear+1)%N==front)
 		printf("the queue is full\n");
 		else if (front==-1 && rear==-1)
 		{
 		front=rear=0;
 		queue[rear]=item;
 		c++;
 		}
 		else
 		{
 		rear=(rear+1)%N;
 		queue[rear]=item;
 		c++;
 		}
 	
 	}
 void del()
 {
 		if(front==-1 && rear==-1)
 		 printf("the queue is empty\n");
 		  else if(front==rear)
 		  {
 		  printf("the deleted element is %d\n",queue[front]);
 		  front=rear=-1;
 		  c--;
 		  }
 		  else
 		  {
 		  printf("the deleted element is %d\n",queue[front]);
 		  front=(front+1)%N;
 		  c--;
 		  }
 		 }
 void display()
 {
 	int i=front;
 	if(front==-1 && rear==-1)
 	 printf("the queue is empty\n");
 	 else
 	 {
 	 printf("the queue is");
 	 while(i!=rear)
 	 {
 	 printf("%d",queue[i]);
 	 i=(i+1)%N;
 	 }
  printf("%d\n",queue[i]);
  
  }
  printf("\t count:%d\n",c);
 }
 int main()
 {
 	int choice;
 	while(1)
 	{
 	 printf("1.insertion\n 2.deletion\n 3.display\n 4.exit\n");
 	 printf("enter your choice\n");
 	 scanf("%d",&choice);
 	 switch(choice)
 	 {
 	 case 1:insert();
 	     	break;
 	 case 2:del();
 		 break;
 	 case 3:display();
 	 	break;
 	 case 4:exit(0);
 	 default:printf("invalid choice\n");
 	 }
 	 }
 	 }
 	 
 	
 	 
 
 		
