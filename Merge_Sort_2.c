#include<stdio.h>
int res[100];
void merge_sort_2(int *arr,int n)
{
	int i=0,j=n/2,x=0;
	while(i<n/2 && j<n)
	{
		if(arr[i]>arr[j])
		{
			res[x++]=arr[j++];
		}
		else{
			res[x++]=arr[i++];
		}
	}
	if(i==n/2)
	{
		while(x<n)
		{
			res[x++]=arr[j++];
		}
	}
	if(j==n)
	{
		while(x<n)
		{
			res[x++]=arr[i++];
		}
	}
}
void main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort_2(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",res[i]);
	}
}
/*
8
1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7
*/
