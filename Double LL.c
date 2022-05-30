#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *Next;
	int data;
	struct Node *Previous;
};
typedef struct Node NODE;

NODE *Head=NULL;
int count=0;

void Insert_at_Head(int data)
{
	count++;
	NODE *NN;
	NN=(NODE*)malloc(sizeof(NODE));
	NN->data=data;
	NN->Previous=NULL;
	NN->Next=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		NN->Next=Head;
		Head->Previous=NN;
		Head=NN;
	}
}

void Insert_at_End(int data)
{
	count++;
	NODE *NN,*temp;
	NN=(NODE*)malloc(sizeof(NODE));
	NN->data=data;
	NN->Previous=NULL;
	NN->Next=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		temp=Head;
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=NN;
	}
}

void Insert_at_pos(int data,int pos)
{
	count++;
	int i;
	NODE *NN,*temp=Head,*Dumy;
	NN=(NODE*)malloc(sizeof(NODE));
	NN->data=data;
	NN->Previous=NULL;
	NN->Next=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else if(pos==1)
	{
		Insert_at_Head(data);
	}
	else if(pos>count)
	{
		Insert_at_End(data);
	}
	else
	{
		temp=Head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->Next;
		}
		Dumy=temp->Next;
		temp->Next=NN;
		Dumy->Previous=NN;
		NN->Previous=temp;
		NN->Next=Dumy;
	}
}

int Delete_at_Head()
{
	int val;
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->Next==NULL)
	{
		val=Head->data;
		Head=NULL;
		count--;
		return val;
	}
	else
	{
		count--;
		NODE *temp;
		temp=Head->Next;
		val=Head->data;
		Head=NULL;
		Head=temp;
		Head->Previous=NULL;
		return val;
	}
}

int Delete_at_End()
{
	int val;
	NODE *temp;
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->Next==NULL)
	{
		count--;
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		count--;
		temp=Head;
		while(temp->Next->Next!=NULL)
		{
			temp=temp->Next;
		}
		val=temp->Next->data;
		temp->Next=NULL;
		return val;
	}
}

int Delete_at_pos(int pos)
{
	int val,i;
	NODE *Dumy,*temp=Head;
	if(Head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		val=Delete_at_Head();
		count--;
		return val;
	}
	else if(pos>count)
	{
		val=Delete_at_End();
		count--;
		return val;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->Next;
		}
		val=temp->Next->data;
		temp->Next=temp->Next->Next;
		return val;
	}
}

void Display()
{
	if(Head==NULL)
	{
		printf("No Nodes\n");
	}
	NODE *temp=Head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->Next;
	}
	printf("\n");
}

void main()
{
	int ch,data,pos;
	while(1)
	{
		printf("1.Insert_at_Head 2.Insert_at_End 3.Insert_at_pos\n4.Delete_at_Head 5.Delete_at_End 6.Delete_at_pos\n7.Display 8.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&data);
			Insert_at_Head(data);
		}
		else if(ch==2)
		{
			scanf("%d",&data);
			Insert_at_End(data);
		}
		else if(ch==3)
		{
			scanf("%d%d",&data,&pos);
			Insert_at_pos(data,pos);
		}
		else if(ch==4)
		{
			data=Delete_at_Head();
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
			data=Delete_at_End();
			if(data==-1)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",data);
			}
		}
		else if(ch==6)
		{
			scanf("%d",&pos);
			data=Delete_at_pos(pos);
			if(data==-1)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",data);
			}
		}
		else if(ch==7)
		{
			Display();
		}
		else
		{
			break;
		}
	}
}
