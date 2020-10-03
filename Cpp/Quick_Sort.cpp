#include<iostream>
using namespace std;
void swap(float *m, float *n)
{
	float temp;
	temp = *m ;
	*m = *n ;
	*n = temp;
}

int part(float *a, int l, int h)
{
	int i = l-1;
	int p = a[h];
	for(int j = l; j<=h; j++)
	{
		if(a[j] < p)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[h]);
	return (i+1);
}

void quickSort(float *a, int l, int h)
{
	if(l<h)
	{
		int p = part(a, l, h);
		quickSort(a, l, p-1);
		quickSort(a, p+1, h);
	}
}

int main()
{
	float nums[10];
	cout<<"Enter 10 numbers: \n";
	for(int i=0;i<10;i++)
	{
		cin>>nums[i];
	}
	
	quickSort(nums, 0, 9);
	cout<<"\nSorted array:\n";
	for(int i=0;i<10;i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<"\n";

	return 0;
}
