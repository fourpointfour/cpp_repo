// This version of quick sort uses the last element as the pivot element
#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int piv = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; ++j)
    {
        if(arr[j] < piv)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int piv_index = partition(arr, low, high);

        if(low < piv_index - 1)
            quick_sort(arr, low, piv_index-1);
        if(piv_index+1 < high)
            quick_sort(arr, piv_index+1, high);
    }
}
void print_array(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<' ';
    cout<<'\n';
}
int main()
{
    int arr[] = {4, 2, 8, 12, 13, -4, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:\n";
    print_array(arr, n);
    quick_sort(arr, 0, n-1);
    cout<<"Array after sorting:\n";
    print_array(arr, n);
    return 0;
}