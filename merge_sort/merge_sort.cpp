/*
 * Author: Vaibhav Kushwaha
 * Code: Merge Sort
 */
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; ++i)
        L[i] = arr[i+l];
    for(int i = 0; i < n2; ++i)
        R[i] = arr[m+1+i];
    int k = l, i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}
void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right-left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void print_array(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<' ';
    cout<<endl;
}
int main()
{
    int arr[] = {4, 2, 3, 12, 14, -1, 0, 19, 88, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sorting:\n";
    print_array(arr, n);
    merge_sort(arr, 0, n-1);
    cout<<"Array after sorting:\n";
    print_array(arr, n);
    return 0;
}