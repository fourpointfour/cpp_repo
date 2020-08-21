/*
 * Author: Vaibhav Kushwaha
 * Code: Wilson's Theorem
 * This theorem is used to check whether a number is prime or not.
 * It states that a number n is a prime iff
 * (n-1)! congruent to -1 (mod n)
 * OR
 * (n-1)! congruent to (n-1) mod n
*/
#include<bits/stdc++.h>
using namespace std;
long int factorial(int n)
{
    if(n <= 1)
        return 1;
    else
    {
        return n * factorial(n-1);
    }
}
bool isPrime(int n)
{
    long int fac = factorial(n-1);
    if((fac % n == -1 % n) || (fac % n == (n - 1) % n))
        return true;
    else
        return false;
    
}
int main()
{
    int num;
    cout<<"Enter a number... ";
    cin>>num;
    if(isPrime(num))
        cout<<"It is a prime number!";
    else
    {
        cout<<"It is NOT a prime number!";
    }
    cout<<'\n';
    return 0;
}