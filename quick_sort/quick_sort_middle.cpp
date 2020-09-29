#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void partition(int arr[], int low, int high)
{
    if(low >= high)
        return;
    int mid = low + (high-low)/2;
    int piv = arr[mid];
    int i = low, j = high;
    while(i <= j)
    {
        while(arr[i] < piv)
            i++;
        while(arr[j] > piv)
            j--;
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    
    partition(arr, low, j);
    partition(arr, i, high);
}

// void quick_sort(int arr[], int low, int high)
// {
//     if(low < high)
//     {
//         int pi = partition(arr, low, high);

//         quick_sort(arr, low, pi-1);
//         quick_sort(arr, pi + 1, high);
//     }
// }

int main()
{
    int arr[] = {3, 4, 2, 1, 4, 9, 100};
    for(int i = 0; i < 7; ++i)
        cout<<arr[i]<<' ';
    partition(arr, 0, 6);
    cout<<"\nAfter sorting:\n";
    for(int i = 0; i < 7; ++i)
        cout<<arr[i]<<' ';
    return 0;
}