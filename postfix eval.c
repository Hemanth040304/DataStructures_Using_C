#include<stdio.h>
#include<string.h>

int top=-1,st[100];

int isoper(char ch)
{
	switch(ch)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 1;
		case '/': return 1;
		default: return 0;
	}
}

int eval(int op2,char oper,int op1)
{
	switch(oper)
	{
		case '+': return op2+op1;
		case '-': return op2-op1;
		case '*': return op2*op1;
		case '/': return op2/op1;
	}
}

int postfixeval(char *str)
{
	char s[100];
	int i,num,k=0,op1,op2,res;
	for(i=0;str[i]!='\0';i++)
	{
		if(isoper(str[i]))
		{
			//operator
			op1=st[top--];
			op2=st[top--];
			res=eval(op2,str[i],op1);
			st[++top]=res;
		}
		else
		{
			//operend
			if(str[i]==' ' && k!=0)
			{
				s[k++]='\0';
				num=atoi(s);
				st[++top]=num;
				k=0;
			}
			else
			{
				s[k++]=str[i];
			}
		}
	}
	return st[0];
}

void main()
{
	int res;
	char pf[100];
	scanf("%[^\n]s",pf);
	res=postfixeval(pf);
	printf("%d",res);
}
