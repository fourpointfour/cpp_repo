/*
 * Author: Vaibhav Kushwaha
 * Code: Sieve of Eratosthenes
 * This algorithm is used to find prime numbers less than or equal to N;
 * Time complexity: O[n * log(log n)]
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> sieve_of_eratosthenes(int n)
{
    vector<int> prime_vector;
    bool isPrime[n+1];
    memset(isPrime, true, sizeof(isPrime));
    int p;
    for(p = 2; p * p <=n; ++p)
    {
        if(isPrime[p])
        {
            // SEGMENT
            prime_vector.push_back(p);
            for(int i = p*p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    // The following code is being commented because of change in SEGMENT
    /* for(p = 2; p <=n; ++p)
        if(isPrime[p])
            prime_vector.push_back(p);
    */
    return prime_vector;
}

int main()
{
    int n;
    cout<<"Enter a number... ";
    cin>>n;
    cout<<"The following are the prime numbers less than or equal to "<<n<<":\n";
    for(int val : sieve_of_eratosthenes(n))
        cout<<val<<' ';
    cout<<"\n";
    return 0;
}