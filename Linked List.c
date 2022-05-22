#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;

NODE *Head=NULL;

void insert_end(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		temp=Head;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=NN;
	}
}

int Delete_end()
{
	int val;
	NODE *temp;
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->add==NULL)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		temp=Head;
		while(temp->add->add)
		{
			temp=temp->add;
		}
		val=temp->add->data;
		temp->add=NULL;
		return val;
	}
}

void insert_head(int data)
{
	NODE *NN;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		NN->add=Head;
		Head=NN;
	}
}

int Delete_head()
{
	int val;
	NODE *NN;
	if(Head==NULL)
	{
		return -1;
	}
	else
	{
		val=Head->data;
		NN=Head->add;
		Head->add=NULL;
		Head=NN;
		return val;
	}
}

void display()
{
	NODE *temp;
	if(Head==NULL)
	{
		printf("No Nodes\n");
	}
	else
	{
		temp=Head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->add;
		}
		printf("\n");
	}
}

void main()
{
	int ch,data;
	while(1)
	{
		printf("1.Insert at End 2.Delete at End 3.Insert at head 4.Delete at head 5.Display 6.Exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			//Insert Data
			scanf("%d",&data);
			insert_end(data);
		}
		else if(ch==2)
		{
			//Delete Data
			data=Delete_end();
			if(data==-1)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",data);
			}
		}
		else if(ch==3)
		{
			//insert at head
			scanf("%d",&data);
			insert_head(data);
		}
		else if(ch==4)
		{
			//delete at head
			data=Delete_head();
			if(data==-1)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",data);
			}
		}
		else if(ch==5)
		{
			//Display Data
			display();
		}
		else
		{
			break;
		}
	}
}
