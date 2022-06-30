/*
Stack
lifo / filo
Last in  First out / First in Last out
*/

#include<stdio.h>
#include<stdlib.h>

int top=-1,*st,size;

void push(int val)
{
	if(size-1==top)
	{
		printf("Stack is Full\n");
	}
	else
	{
		st[++top]=val;
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		int i;
		for(i=top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
		printf("\n");
	}
}

int pop()
{
	int val;
	if(top==-1)
	{
		return top;
	}
	val=st[top--];
	return val;
}

int main()
{
	int i,ch;
	scanf("%d",&size);
	st = (int *)calloc(size,sizeof(int));
	while(1)
	{
		int val;
		printf("1.push 2.pop 3.display 4.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			push(val);
		}
		else if(ch==2)
		{
			val=pop();
			if(val==-1)
			{
				printf("stack is empty\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
	return 0;
}
