#include<stdio.h>
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}
int fibi_search(int *arr,int n,int se,int *fib)
{
	int static L=-1;
	int K=n-1,m;
	if(arr[K]==se)
	{
		return 1;
	}
	if(fib[K-2]==0)
	{
		return 0;
	}
	m=min(L+fib[K-2],n-1);
	if(arr[m]==se ||arr[K]==se)
	{
		return 1;
	}
	if(se>arr[m])
	{
		L=m;
		K=K-1;
	}
	else{
		K=K-2;
	}
	return fibi_search(arr,K+1,se,fib);
}
void main()
{
	int n,i,se;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	int fib[n];
	fib[0]=0,fib[1]=1;
	for(i=2;i<n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	if(fibi_search(arr,n,se,fib))
	{
		printf("True");
	}
	else{
		printf("Fasle");
	}
}
