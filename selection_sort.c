/* Selection sort */
// At the bottom of the page there is an sample input

#include<stdio.h>
// The below function is to find the maximum element in the array
int max(int *arr,int n)
{
	int i,max=0,po;
	for(i=0;i<n;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			po=i;
		}
	}
	return po;
}

// The below function is to replace the last element and maximum element
void selection_sort(int *arr,int n)
{
	int i,po,last=n-1;//6 5 4 3
	while(last!=0)
	{
		po=max(arr,last+1);
		if(arr[po]>arr[last])
		{
			int temp=arr[po];
			arr[po]=arr[last];
			arr[last]=temp;
		}
		last--;
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
	selection_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

/*

8  -->number of elements in the array

66 44 22 77 88 43 11 10
0  1  2  3  4  5  6  7

66 44 22 77 10 43 11 88  --> 88 replaces in 10's position and 10 in 88's position
0  1  2  3  4  5  6  7

66 44 22 11 10 43 77 88  --> 77 replaces in 11's position and 11 in 77's position
0  1  2  3  4  5  6  7

43 44 22 11 10 66 77 88  --> 66 replaces in 43's position and 43 in 66's position
0  1  2  3  4  5  6  7

43 10 22 11 44 66 77 88  --> 44 replaces in 10's position and 10 in 44's position
0  1  2  3  4  5  6  7

11 10 22 43 44 66 77 88  --> 43 replaces in 11's position and 11 in 43's position
0  1  2  3  4  5  6  7

11 10 22 43 44 66 77 88  -->here 22 replaces itself
0  1  2  3  4  5  6  7

10 11 22 43 44 66 77 88  --> 10 replaces in 11's position and 11 in 10's position
0  1  2  3  4  5  6  7
*/
