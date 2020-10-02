#include<bits/stdc++.h>

#define ll long long
#define FOR(i,j,k) for(i = j;i <= k;i++)

using namespace std;

void Prime_Sieve(int N,bool isPrime[]){
    int i,j;
    isPrime[1] = false;
    
    for(i = 2; i < N; i++)
        isPrime[i] = true;

    for(i = 2;i < N;i++){
        if(isPrime[i]){
            for(j = i*i;j < N;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    int N = 1e3;
    bool isPrime[N];
    Prime_Sieve(N,isPrime);
    while(1){
      int x;
      cout<<"Enter a number : ";
      cin>>x;
      cout<<x<<"is "<<(isPrime[x] ? "a prime":"not a prime")<<endl;
    }
    return 0;
}
/*
 * Time Compexity  : O(n)
 * Space Compexity : O(n)
*/

