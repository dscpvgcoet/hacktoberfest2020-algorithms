#include<iostream>
using namespace std;
int main()
{
    int row;
    int coloum;
    int a[100][100];
    int t[100][100];
    cout<<"*****WELCOME*****\n";
    cout<<"please enter the no of rows\n";
    cin>>row;
    cout<<"please enter the value of coloum\n";
    cin>>coloum;

    for(int i=0;i<row;++i)
      for (int j=0;j<coloum;++j)
      {
          cout<<"please enter the elements "<<i+j<<","<<j+1<<"\n";
          cin>>a[i][j];
      }
      cout<<"your inputed matrix is \n";
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        cout<<a[i][j]<<" ";
        cout<<"\n";

    }
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < coloum; ++j) {
         t[j][i] = a[i][j];
      }
    
    cout<<"the transpose matrix is\n";
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<coloum;++j)
        cout<<t[i][j]<<" ";
        cout<<"\n";

    }

}   