#include<bits/stdc++.h>
// Quick sort using the middle element as the pivot
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int l = low, r = high;
    int mid = (l+r)/2;
    int piv = arr[mid];
    while(l <= r)
    {
        while(arr[l] < piv)
            l++;
        while(arr[r] > piv)
            --r;
        if(l <= r)
        {
           swap(&arr[l++], &arr[r--]);
        }
    }
    return l;
}
void quick_sort(int arr[], int low, int high)
{
    int piv_index = partition(arr, low, high);
    if(low < piv_index - 1)
        quick_sort(arr, low, piv_index-1);
    if(piv_index < high)
        quick_sort(arr, piv_index, high);
}
void print_array(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<' ';
}
int main()
{
    int arr[] = {4, 3, 2, 12, 10, 7, 1, -8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:\n";
    print_array(arr, n);
    quick_sort(arr, 0, n-1);
    cout<<"\nArray after sorting:\n";
    print_array(arr, n);
    cout<<'\n';
    return 0;
}