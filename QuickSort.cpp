#include<bits/stdc++.h>
using namespace std;
int divide(int arr[], int start, int end)
{
    int pivot=arr[start];
    int pivindex=end;
    for(int i=end;i>start;i--)
    {
        if(arr[i]>pivot)
        {
            int temp=arr[i];
            arr[i]=arr[pivindex];
            arr[pivindex]=temp;
            pivindex--;
        }
    }
    int temp=arr[start];
    arr[start]=arr[pivindex];
    arr[pivindex]=temp;
    return pivindex;
}
void quicksort(int arr[], int start, int end)
{
    if(start<end)
    {
        int p=divide(arr, start, end);
        quicksort(arr, start, (p-1));
        quicksort(arr, (p+1), end);
    }
}
int main()
{
    cout<<"Enter size of array\n";
    int a;//c
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++)
    {
        cout<<"Enter an element\n";
        cin>>arr[i];
    }
    quicksort(arr, 0, (a-1));
    system("cls");
    cout<<"The sorted array is\n";
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}