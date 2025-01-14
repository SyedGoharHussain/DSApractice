#include<iostream>
using namespace std;

void selsort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		int  j=i-1;
		for(j=i;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		
		if(i!=min)
		{
			swap(arr[i],arr[min]);
		}
	}
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[6]={4,2,5,3,1,8};
	
	selsort(arr,6);
}

