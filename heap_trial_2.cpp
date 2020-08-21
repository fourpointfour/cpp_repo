#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {14, 22, 4, 3, 5, 77, 6, 88, 99, 1000};
    make_heap(begin(v), end(v));
    v.push_back(3300);
    push_heap(v.begin(), v.end());
    int i = 0;
    while(i < v.size())
    {
        pop_heap(v.begin(), v.end()-i);
        ++i;
    }
    cout<<"\nThe sorted heap is:\n";
    for(int x : v)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}