#include<bits/stdc++.h>
using namespace std;
void printar(int arr[], int n)
{
    for(int i = 0; i < pow(2, n); ++i)
    {
        for(int j = 0; j < n; ++j)
            if((i & (1 << j)) != 0)
                cout<<arr[j]<<' ';
        cout<<"\n";
    }
}
int main()
{
    int ar[] = {1, 2, 3, 4};
    printar(ar, 4);
    return 0;
}