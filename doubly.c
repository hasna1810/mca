#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node{
int info;
struct node *left;
struct node *right;
};
 typedef struct node Node;
 Node  *nnode,*temp=NULL,*head=NULL,*t1;
int n,ch,data,i,pos;

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
	create();
	while(1)
	{
		printf("\n 1.display \n 2.ins_beg \n 3.ins_end \n 4.ins_pos \n 5.del_beg\n 6.del_end \n 7.del_pos \n 8.exit");
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
	
			case 1:display();
				break;
			case 2: ins_beg();
				break;
			case 3: ins_end();
				break;
			case 4:ins_pos();
				break;
			case 5: del_beg();
				break;
			case 6: del_end();
				break;
			case 7: del_pos();
				break;
			case 8:exit(0);
		}
	}
}

void create()
{
	
		
		printf("enter the  limit :\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			nnode=( Node *)malloc(sizeof( Node));
			printf("enter the data :\n");
			scanf("%d",&data);
			nnode->info=data;
			nnode->left=NULL;
			nnode->right=NULL;
		
		if (head==NULL)

			temp=head=nnode;
		else
		{
			temp->right=nnode;
			nnode->left=temp;
			temp=nnode;
		}}}
		

void display()
{
	
	printf("the linked list :");
	t1=head;
	while(t1!=NULL)
	{
		printf("%d-> ",t1->info);
		t1=t1->right;
	}
}

void ins_beg()
{
 	nnode=(Node *)malloc(sizeof(Node));
 	printf("enter data:");
 	scanf("%d", &data);
 	nnode->info=data;
 	nnode->left=NULL;
 	nnode->right=head;
 	head=nnode;
 	n++;
 }
 
 void ins_end()
 {
 		int data;
 		nnode=(Node *)malloc(sizeof(Node));
 		printf("enter data:");
 		scanf("%d",&data);
 		nnode->info=data;
 		nnode->left=NULL;
 		nnode->right=NULL;
 		t1=head;
 		while(t1->right!=NULL)
 			{
 			t1=t1->right;
 			}
 			t1->right=nnode;
 			nnode->left=t1;
 			
 	}
 
 void ins_pos()
 {
 	i=0;
 	nnode=(Node*)malloc(sizeof (Node));
 	printf("enter data:");
 	scanf("%d",&data);
 	nnode->info=data;
 		nnode->left=NULL;
 		nnode->right=NULL;
 		printf("enter the position to be inserted:\n");
 		scanf("%d",&pos);
 		t1=head;
 		if(pos==1)
 		{
 			nnode->right=head;
 			head->left=nnode;
 			head=nnode;
 		}
 		else 
 		{
 		while(i<pos-1){
 		temp=t1;
 		t1=t1->right;
 		i++;
 		}
 		temp->right=nnode;
 		nnode->left=temp;
 		nnode->right=t1;
 		t1->left=nnode;
 		n++;
 		}}
 		
 			
	
void del_beg()
{
	if(head==NULL)
	printf("empty list \n");
	temp=head;
		head=head->right;
		head->left=NULL;
		free(temp);
		printf("deleted");
		n--;
	}
	
void del_end()
{
	int c=0;
	t1=head;
		while(c<n-1)
		{
			
			temp=t1;
		t1=t1->right; c++;}
		temp->right =NULL;
		free(t1);
		n--;
		}
		

void del_pos()
{
	i=0;
	t1=head;
	
		printf("enter the position:");
		scanf("%d",&pos);
		
		if(pos==1)
		{
		head=head->right;
		free(t1);
		n--;
		}
		
	else	
	{
		while (i<pos-1)
		{
			temp=t1;
			t1=t1->right;
			i++;
			}
			temp->right=t1->right;
			t1->right->left=temp;
			free(t1);
			n--;
			}}
				
	
	
	
	
