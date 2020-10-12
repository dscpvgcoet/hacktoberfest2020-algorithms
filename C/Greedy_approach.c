#include<stdio.h>
#include<stdlib.h>
int l_tp[10],tp[10][10];
void merge(int a[],int i,int m,int j);
void mergeSort(int a[],int i,int j);
void greedy(int a[],int n_tp, int n_p);
int main()
{
	int n_p,n_tp,arr[20],p[10];
	printf("\nEnter the number of programs:");
	scanf("%d",&n_p);
	printf("\nEnter the number of tapes:");
	scanf("%d",&n_tp);
	for(int j=0;j<n_p;j++)
	{
		printf("Enter the size of program %d:",j+1);
		scanf("%d",&p[j]);		
	}
	mergeSort(p,0,n_p-1);
	for(int l=0;l<n_tp;l++)
	{
		l_tp[l]=0;
	}
	int l=0,k=0;
	for(int j=0;j<n_p;j++)
	{
		l=l_tp[k];
		tp[l][k]=p[j];
		l_tp[k]=l_tp[k]+1;
		k++;
		if(k==n_tp)
		{
			k=0;
		}
	}
	for(int j=0;j<n_tp;j++)
	{
		printf("Tape %d:",j+1);
		for(int i=0;i<l_tp[j];i++)
		{
			printf("%d-",tp[i][j]);
		}
		printf("\n");
	}
	greedy(p,n_tp,n_p);
}
void mergeSort(int a[],int i,int j)
{
	if(i<j)
	{
		int mid=(i+j)/2;
		mergeSort(a,i,mid);
		mergeSort(a,mid+1,j);
		merge(a,i,mid,j);
	}
}
void merge(int a[],int i,int m,int j)
{
	int temp1=i,temp2=m+1,n=0;
	int b[20];
	while(temp1<=m && temp2<=j)
	{
		if(a[temp1]>a[temp2])
		{
			b[n]=a[temp2];
			n++;
			temp2++;
		}
		if(a[temp1]<a[temp2])
		{
			b[n]=a[temp1];
			temp1++;
			n++;
		}
		if(a[temp1]==a[temp2])
		{
			b[n]=a[temp1];
			n++;
			temp1++;
			b[n]=a[temp2];
			n++;
			temp2++;
		}
	}
	while(temp1<=m)
	{
		b[n]=a[temp1];
		n++;
		temp1++;
	}
	while(temp2<=j)
	{
		b[n]=a[temp2];
		n++;
		temp2++;
	}
	for(temp1=i,n=0;temp1<=j;temp1++,n++)
	{
		a[temp1]=b[n];
	}
}
void greedy(int a[],int n_tp, int n_p)
{
	int tmrt=0;
	for(int i=0;i<n_tp;i++)
	{
		int sum=0;
		int l=1;
		while(l!=l_tp[i]+1)
		{
			for(int j=0;j<l;j++)
			{
				sum=sum+tp[j][i];
			}
			l++;
		}
		int mrt;
		mrt=sum/(l_tp[i]);
		printf("MRT for tape %d is %d \n",(i+1),mrt);
		tmrt=tmrt+mrt;
	}
	tmrt=tmrt/n_tp;
	printf("Total MRT of %d tapes is %d\n",n_tp,tmrt);
}
/*Output 

Enter the number of programs:6

Enter the number of tapes:4
Enter the size of program 1:4
Enter the size of program 2:6
Enter the size of program 3:2
Enter the size of program 4:5
Enter the size of program 5:4
Enter the size of program 6:8
Tape 1:2-6-
Tape 2:4-8-
Tape 3:4-
Tape 4:5-
MRT for tape 1 is 5 
MRT for tape 2 is 8 
MRT for tape 3 is 4 
MRT for tape 4 is 5 
Total MRT of 4 tapes is 5
*/




























































































