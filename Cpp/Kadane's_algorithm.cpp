/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int Kadanesalgo(int array[],int size)
{
    int local_sum,global_sum;
    local_sum=array[0];
    global_sum=array[0];
    for(int i=1;i<size;i++)
    {
        local_sum=max(array[i],(local_sum+array[i]));
        if(local_sum>global_sum)
        {
            global_sum=local_sum;
        }
    }
    return global_sum;
}
int main()
{
    int n;
    cout<<"size of array:";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<Kadanesalgo(array,n);
}
