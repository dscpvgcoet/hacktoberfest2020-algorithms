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
