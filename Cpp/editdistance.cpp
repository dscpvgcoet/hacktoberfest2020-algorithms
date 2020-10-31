#include<iostream>
#include<algorithm>
using namespace std;
int minimum(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int compare(string str1, string str2, int m, int n)
{
   
    int temp[m + 1][n + 1];
 
     for (int i = 0; i <= m; i++)
     {
        for (int j = 0; j <= n; j++)
        {
           
            if (i == 0)
            {
            temp[i][j] = j;
           
            }  
            else if (j == 0)
            {
            temp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
            temp[i][j] = temp[i - 1][j - 1];
            }
            else
            {
            temp[i][j] = 1 + minimum(temp[i][j - 1], temp[i - 1][j], temp[i - 1][j - 1]);    
            }
               
        }
    }
 
    return temp[m][n];
}
 
 
int main()
{
   
    string str1,str2;
    cout<<"first string :";
    cin>>str1;
    cout<<"second string :";
    cin>>str2;
    cout << compare(str1, str2, str1.length(), str2.length());
    return 0;
}