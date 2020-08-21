/*
 * Just as a reminder, countig sort is used only when the range
 * of the elements is comparable to the length of the array.
 * Otherwise it would become too difficult to handle an array
 * if the size would be in the range of 1000 or 10000
*/
#include<bits/stdc++.h>
using namespace std;
void count_sort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> output(arr.size()), count(range);
    // Counting the occurences of an element
    for(int i = 0; i < arr.size(); ++i)
        ++count[arr[i] - min];

    // Modifying the count array
    for(int i = 1; i < arr.size(); ++i)
        count[i] += count[i-1];

    // Filling values in the output array
    for(int i = 0; i < arr.size(); ++i)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        --count[arr[i] - min];
    }
    for(int i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}
int main()
{
    vector<int> ar = {1, 4, -3, -1, 5, 9, 6, 2, 3, 1, 1};
    count_sort(ar);
    for(int val : ar)
        cout<<val<<' ';
    cout<<'\n';
    return 0;
}