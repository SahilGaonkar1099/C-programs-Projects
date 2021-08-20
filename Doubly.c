#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *p,*first=NULL;
void insert()
{
	struct node *temp;
	temp=(struct node*) malloc(sizeof(struct node));
		printf("Enter the data to be inserted\n");
		scanf("%d",&temp->data);
		temp->left=temp->right=NULL;
	if(first==NULL)
	first=temp;
	else
	{
	p=first;
	while(p->right!=NULL)
	p=p->right;
	temp->left=p;
	p->right=temp;
	}
}
void display(){
	if(first==NULL){
	printf("NO NOdes to display\n");
	
}
	else
	p=first;
	printf("**************************************************************\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->right;
	}
	printf("**************************************************************\n");
}
void AscendDisplay()
{
	struct node *h1,*h2;
	int t;
	if(first==NULL){
	printf("NO NOdes to display\n");
	exit(0);
}
	else
	
	h1=first;
	h2=h1->right;
	while(h2!=NULL){
	if(h1->data<=h2->data){
		h1=h2;
		h2=h2->right;
	}
	else
	{
		
		t=h1->data;
		h1->data=h2->data;
		h2->data=t;
		
		h1=h1->right;
		h2=h2->right;
		AscendDisplay();//Recursive Approach::::
		
		}
	
}
}

void main()
{
	int ch;
	for(;;)
	{
		printf("MENU:\n1].Insert\t\t2].display\t3.AscendDisplay\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();break;
			case 2:display();break;
			case 3:AscendDisplay();break;
			default :printf("INVALID\n");
		}
	}
}
