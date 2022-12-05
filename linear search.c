#include<stdio.h>
int fun(int *arr,int n,int s)
{
	// 5 8 45 57 200
	// 57
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==s)//57==57
		{
			return 1;
		}
	}
	return 0;
}
void main()
{
	int n,s,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&s);
	if(fun(arr,n,s))
	printf("True");
	else
	printf("False");
}
