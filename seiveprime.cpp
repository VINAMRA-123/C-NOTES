// Sieve of Eratosthenes
// Algorithm: We start from 2, and on each encounter of a prime number, we mark
// its multiples as composite.
// Time Complexity: O(n log log n)
// Space Complexity: O(n)
// its multiples as composite.
#include<iostream>
using namespace std;
void primeseive(int n){
    int prime[100] = {0};
    for(int i = 2; i < n; i++)
    {
        if(prime[i] == 0){
            for ( int j = i*i; j <=n; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if (prime[i] == 0)
        {
            cout<<i<<" ";
        }
    }cout<<endl;
    
}
int main(){
    primeseive(30);
}
// PROBLEM 2 - PRIME FACTORIZATION USING SEIVE
/*Explanation:
while( num ! = 1 ):

We keep on dividing it with its smallest prime factor.

The smallest prime factor is pre-calculated using a slightly modified prime sieve.
Since we start from 2 and go on, we mark the first multiple as the spf.
Preprocessing for Sieve: O(n log log n)
Time Complexity for factorization: O(log n)
Space Complexity: O(n)*/
void primefactor(int n){
    int spf[100] ={0};
    for (int  i = 2; i <=n; i++)
    {
        spf[i] =i;
    }
    
    for (int  i = 2; i <=n; i++)
    {
        if(spf[i] ==i){
            for (int j = i*i; j<=n; j+=i)
            {
                if (spf[j] == j)
                {
                    spf[j] =i;
                }   
            }    
        }
    }
    while (n!=1)
    {
        cout<<spf[n]<<endl;
        n = n/spf[n];
    }
    
    
}
// TOPIC -INCLUSION EXCLUSION 
// problem - FIND HCF or HCF
int gcd(int a,int b){

    while (b!=0)
    {
        int rem = a%b;
        a = b;
        b = rem;
    }return a; 
    


}