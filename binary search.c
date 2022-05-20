#include<stdio.h>
int binary_search(int *arr,int n,int s)
{
	int l=0,h=n-1,m=(l+h)/2;
	while(l<=h)
	{
		if(s==arr[m])
		{
			return 1;
		}
		if(s>arr[m])
		{
			l=m+1;
			m=(l+h)/2;
		}
		if(s<arr[m])
		{
			h=m-1;
			m=(l+h)/2;
		}
	}
	return 0;
}
void main()
{
	int n,i,s;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&s);
	if(binary_search(arr,n,s))
	printf("True");
	else
	printf("False");
}
/*
binary 
7
10 15 20 55 65 70 85
0  1  2  3  4  5  6 
L		 M	      H

se==arr[M]-->55==55 if it is true  returm 1;
se>arr[M]--> 70>55  if it is true-->L=M+1
se<arr[M]--> 15<55 if it is true-->H=M-1





M=(L+H)/2
se=15


*/
