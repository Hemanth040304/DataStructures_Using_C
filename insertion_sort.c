#include<stdio.h>
void insertion_sort(int *arr,int n)
{
	int i,temp,j;
	for(i=1;i<n;i++)
	{
		j=i-1;
		while(arr[i]<arr[j])
		{
			temp=arr[i];	
			while(temp<arr[j])
			{
				arr[j+1]=arr[j];
				arr[j]=temp;
				j--;
			}
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
	insertion_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}


/*
4
22 33 44 55  ---> inserting -->    32
after insretion 
22 32 33 44 55 

ex:- 44 33 22 66 77 32 88 65 55 34
     0  1  2  3  4  5  6  7  8  9 
        i
        
    33 44 22 66 77 32 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
          i
          
    22 33 44 66 77 32 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
             i
             
    22 33 44 66 77 32 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
                i
                
    22 33 44 66 77 32 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
                j  i
                   
i=32,j=77   j should stat from i-1 to 0 if i<j-->32<77
                   
    22 32 33 44 66 77 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
                     i             
					   
	22 32 33 44 66 77 88 65 55 34
    0  1  2  3  4  5  6  7  8  9 
                      j  i 
						 
temp=65
temp<88 -->arr[j+1]=arr[j]
until temp is greater j
	
	22 32 33 44 65 66 77 88 55 34
    0  1  2  3  4  5  6  7  8  9 
                         j  i 
                         
temp=55
temp<88-->arr[j+1]=arr[j]                        
until temp is greater j

    22 32 33 44 55 65 66 77 88 34
    0  1  2  3  4  5  6  7  8  9 
                            j  i

temp=34
temp<88-->arr[j+1]=arr[j]                        
until temp is greater j

	22 32 33 34 44 55 65 66 77 88
    0  1  2  3  4  5  6  7  8  9 
                            j  i
        
*/
