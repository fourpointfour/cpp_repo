/*
 * Author: Vaibhav Kushwaha
 * Code: Z-Algorithm
 * This algorithm is used to find the matching occurences of a pattern in string.
 * Time complexity: O(m + n)
*/
#include<bits/stdc++.h>
using namespace std;
void search(string s, string p)
{
    string str = p + "$" + s;
    int plength = p.length();
    int newlength = str.length();
    int L, R, i, k, Z[newlength];
    L = R = 0;
    // Z[0] = 0;
    for(i = 0; i < newlength; ++i)
    {
        L = R = i;
        while(R < newlength && str[R-L] == str[R])
            R++;
        Z[i] = R-L;
    }
    cout<<"String: "<<s<<endl<<"Pattern: "<<p;
    for(i = 0; i < newlength; ++i)
    {
        if(Z[i] == plength)
            cout<<"\nPattern found at: "<<i - plength - 1;
    }
    cout<<'\n';
}
int main()
{
    search("ababbaba", "aba");
    return 0;
}