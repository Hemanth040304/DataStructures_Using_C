#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;

NODE *Head=NULL;
int count=0;

void insert_end(int a)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=a;
	NN->add=NULL;
	count++;
	if(Head==NULL)
	{
		Head=NN;
		Head->add=Head;
	}
	else
	{
		temp=Head;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		temp->add=NN;
		NN->add=Head;
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
	else if(Head->add==Head)
	{
		val=Head->data;
		Head=NULL;
		count--;
		return val;
	}
	else
	{
		temp=Head;
		while(temp->add->add!=Head)
		{
			temp=temp->add;
		}
		val=temp->add->data;
		temp->add=Head;
		count--;
		return val;
	}
}

void insert_head(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NN;
	count++;
	if(Head==NULL)
	{
		Head=NN;
		Head->add=Head;
	}
	else
	{
		temp=Head;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		NN->add=Head;
		Head=NN;
		temp->add=Head;
	}
}

int Delete_head()
{
	int val;
	NODE *NN,*temp;
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->add==Head)
	{
		val=Head->data;
		Head=NULL;
		count--;
		return val;
	}
	else
	{
		temp=Head;
		count--;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		val=Head->data;
		Head=Head->add;
		temp->add=Head;
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
		while(temp->add!=Head)
		{
			printf("%d ",temp->data);
			temp=temp->add;
		}
		printf("%d ",temp->data);
		printf("\n");
	}
}

void insert_pos(int val,int pos)
{
	NODE *NN,*temp;
	int i;
	count++;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else if(pos==1)
	{
		insert_head(val);
	}
	else if(pos>count)
	{
		insert_end(val);
	}
	else
	{
		temp=Head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->add;
		}
		NN->add=temp->add;
		temp->add=NN;
	}
}

int delete_pos(int pos)
{
	int val = 0,i;
	NODE *temp2,*temp=Head;
	if(Head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		val=Delete_head();
		count--;
		return val;
	}
	else if(pos>count)
	{
		val=Delete_end();
		count--;
		return val;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->add;
		}
		val=temp->add->data;
		temp2=temp->add->add;
		temp->add=NULL;
		temp->add=temp2;
		count--;
		return val;
	}
}

void main()
{
	int ch,data,pos;
	while(1)
	{
		printf("1.Insert at End\n2.Delete at End\n3.Insert at head\n4.Delete at head\n5.Display\n6.Insert at position\n7.delete at position\n8.Exit\n");
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
		else if(ch==6)
		{
			//insert_pos
			scanf("%d%d",&data,&pos);
			insert_pos(data,pos);
		}
		else if(ch==7)
		{
			//delete_pos
			scanf("%d",&pos);
			data=delete_pos(pos);
			printf("%d\n",data);
		}
		else
		{
			break;
		}
	}
}
