#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int piv = arr[low], i = high+1;
    for(int j = high; j >= low; --j)
    {
        if(piv < arr[j])
        {
            i--;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i-1]);
    return (i-1);
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
    int arr[] = {2, 1, 3, 4, 5, 2, 4, 1, 222, 9};
    cout<<"Array before sorting:\n";
    for(int val : arr)
        cout<<val<<' ';
    quick_sort(arr, 0, 9);
    cout<<"\nArray after sorting:\n";
    for(int val : arr)
        cout<<val<<' ';
    cout<<endl;
    return 0;
}