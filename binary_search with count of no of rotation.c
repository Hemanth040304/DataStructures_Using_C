#include<stdio.h>'
int binary_search(int *arr,int n,int se,int l,int h,int m)
{
	int static x=0;
	if(l>h)
	return 0;
	if(se==arr[m]){
		printf("%d ",x);
		return 1;
	}
	if(se>arr[m]){
		l=m+1;
		m=(l+h)/2;
	}
	if(se<arr[m]){
		h=m-1;
		m=(l+h)/2;
	}
	x++;
	binary_search(arr,n,se,l,h,m);
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
	int se,l=0,h=n-1,m=(l+h)/2;
	scanf("%d",&se);
	if(binary_search(arr,n,se,l,h,m))
	printf("True");
	else
	printf("Fasle");
}
