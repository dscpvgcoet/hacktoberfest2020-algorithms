#include<iostream>
#include<vector>
using namespace std;
void bubblesort(int v[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(v[j]>v[j+1])
      {
        int temp=v[j];
        v[j]=v[j+1];
        v[j+1]=temp;
      }
    }
  }
}
int main()
{
  int a[]={64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(a)/sizeof(a[0]);
  bubblesort(a,n);
  cout<<"The array after sorting is\n";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<"\n";
  return 0;

}
