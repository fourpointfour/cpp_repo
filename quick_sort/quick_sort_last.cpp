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
    int piv = arr[high], i = low - 1;
    for(int j = low; j <= high-1; ++j)
    {
        if(piv > arr[j])
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
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main()
{
    int arr[] = {1, 5, 4, 3, 2, 6, 5, 8, 10};
    for(int i = 0; i < 9; ++i)
        cout<<arr[i]<<' ';
    quick_sort(arr, 0, 8);
    cout<<"\nAfter sorting:\n";
    for(int i = 0; i < 9; ++i)
        cout<<arr[i]<<' ';
    return 0;
}