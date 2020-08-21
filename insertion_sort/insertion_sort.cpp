/*
 * Author: Vaibhav Kushwaha
 * Code: Insertion Sort
 */
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int *arr, int n)
{
    int i, j, temp;
    for(i = 1; i < n; ++i)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] >= temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void print_array(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<' ';
}
int main()
{
    int arr[] = {4, 3, 2, 12, 10, 1, 0, -8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting: \n";
    print_array(arr, n);
    insertionSort(arr, n);
    cout<<"\nArray after sorting:\n";
    print_array(arr, n);
    cout<<'\n';
    return 0;
}