#include<iostream>
#include<vector>
using namespace std;
void bubblesort(int v[],int n)
{
  int temp;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(v[j]>v[j+1])
      {
        temp=v[j];
        v[j]=v[j+1];
        v[j+1]=temp;
      }
    }
  }
}
void display_array(int v[],int n)
{
   
	for(int i=0;i<n;i++)
	{
	   cout<<v[i]<<"\t";
	}
}
int main()
{
  int a[]={78,64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"elements of array before sorting:\n";
  display_array(a,n);
  bubblesort(a,n);
  cout<<"\nelements of array after sorting:\n";
  display_array(a,n);
  cout<<"\n";
  return 0;

}