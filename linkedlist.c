#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node{
int data;
struct node *next;
};
 
 struct node  *head=NULL,*temp,*newnode;

void create();
void display();
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
 
int main(){
	int choice;
	while(1)
	{
		printf("1.create \n 2.display \n 3.ins_beg \n 4.ins_end \n 5.ins_pos \n 6.del_beg\n 7.del_end \n 8.del_pos \n 9.exit");
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create();
				break;
			case 2:display();
				break;
			case 3: ins_beg();
				break;
			case 4: ins_end();
				break;
			case 5:ins_pos();
				break;
			case 6: del_beg();
				break;
			case 7: del_end();
				break;
			case 8: del_pos();
				break;
			case 9:exit(0);
		}
	}
}

void create()
{
	int choice=1;
	
	while(choice)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if (head==NULL)
		{
			head=newnode;
			temp=head;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		count++;
		printf("do you want to continue (1 for YES, 0 for NO):");
		scanf("%d",&choice);
	}
}

void display()
{
	temp=head;
	if(temp==NULL)
	{
		printf("the list is empty \n");
		return;
	}
	printf("the linked list is:");
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
		temp=temp->next;
	}
	printf("NULL \n");
}

void ins_beg()
{
 	newnode=(struct node *)malloc(sizeof(struct node));
 	printf("enter data:");
 	scanf("%d", &newnode->data);
 	newnode->next=head;
 	head=newnode;
 	count++;
 }
 
 void ins_end()
 {
 	if(count!=0)
 	{
 		newnode=(struct node *)malloc(sizeof(struct node));
 		printf("enter data:");
 		scanf("%d",&newnode->data);
 		newnode->next=0;
 		temp=head;
 		while(temp->next!=0)
 			{
 			temp=temp->next;
 			}
 			temp->next=newnode;
 			count++;
 	}
 	else
 		printf("empty list \n");
 }
 
 void ins_pos()
 {
 	if(count!=0)
 	{
 		int pos,i=1;
 		printf("enter the position");
 		scanf("%d",&pos);
 		if(pos>count)
 		{
 			printf("invalid position \n");
 		}
 		else if(pos==1)
 		{
 			ins_beg();
 		}
 		else
 		{	
			newnode=(struct node *)malloc(sizeof(struct node));
			temp=head;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			printf("enter the data:");
			scanf("%d",&newnode->data);
			newnode->next=temp->next;
			temp->next=newnode;
			count++;
		}}
	else
	printf("empty list \n");
	}
	
void del_beg()
{
	if(count!=0)
	{
		temp=head;
		head=head->next;
		free(temp);
		count--;
	}
	else
	printf("empty list \n");
	}
	
void del_end()
{
	if(count!=0)
	{
		struct node *prevnode;
		temp=head;
		while(temp->next!=0)
		{
			prevnode=temp;
			temp=temp->next;
		}
		if(temp==head)
			{
			prevnode->next=0;
			}
			free(temp);
			count--;
		}
		else 
		printf("empty list \n");
	}

void del_pos()
{
	if(count!=0)
	{
		struct node *nextnode;
		int pos,i=1;
		printf("enter the position:");
		scanf("%d",&pos);
		
		if(pos==1)
		{
			del_beg();
		}
		
	else	
	{
		temp=head;
		while (i<pos-1)
		{
			temp=temp->next;
			i++;
			}
			nextnode=temp->next;
			
			if(nextnode->next==NULL)
			{
				temp->next=NULL;
			}
			else
			{
				temp->next=nextnode->next;
			}
			free(nextnode);
		}
		count --;
		}
		else 
		printf("empty list");
}
				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
			
