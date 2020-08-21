#include<bits/stdc++.h>
using namespace std;
void func(string s, string str, int i, vector<string> &vec)
{
    if(i >= str.size())
    {
        vec.push_back(s);
        return;
    }
    else
    {
        // call one function including the current letter
        func(s+str[i], str, i+1, vec);

        // call another function excluding the current letter
        func(s, str, i+1 ,vec);
    }
}
int main()
{
    string S = "abc";
    vector<string> result;
    func("", S, 0, result);
    for(string st : result)
        cout<<st<<endl;
    return 0;
}