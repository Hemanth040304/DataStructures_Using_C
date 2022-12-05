#include<stdio.h>
#include<string.h>

int top=-1;
char infix[100],st[100],pf[100];

int isoper(char ch)
{
	switch(ch)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '(': return -1;
		case ')': return -1;
		default: return 0;
	}
}

char *infix_to_postfix(char *infix)
{
	int i,k=0;
	char o;
	for(i=0;infix[i]!=0;i++)
	{
		if(isoper(infix[i]))
		{
			if(infix[i]==')')
			{
				while(st[top]!='(')
				{
					o=st[top--];
					pf[k++]=o;
				}
				top--;
				continue;
			}
			if(top==-1 || infix[i]=='(' || isoper(infix[i])>isoper(st[top]))
			{
				st[++top]=infix[i];
			}
			else
			{
				while(top!=-1 && isoper(infix[i])<=isoper(st[top]))
				{
					o=st[top--];
					pf[k++]=o;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
			pf[k++]=infix[i];
		}
	}
	for(i=top;i>-1;i--)
	{
		pf[k++]=st[i];
	}
	return pf;
}

void main()
{
	int i;
	scanf("%[^\n]s",infix);
	strcpy(pf,infix_to_postfix(infix));
	printf("%s",pf);
}
