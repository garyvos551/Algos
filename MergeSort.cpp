#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int start, int mid, int end, int size)
{
    int i=start;
    int j=mid+1;
    int k=start;
    int temp[size];
    while(i<=mid&&j<=end)
    {
        if(arr[i]<=arr[j])//c
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int a=start;a<=end;a++)//c
    {
        arr[a]=temp[a];
    }
}
void mergesort(int arr[],int start, int end, int size)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr, start, mid, size);
        mergesort(arr, mid+1, end, size);
        merge(arr, start, mid, end, size);
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
    mergesort(arr, 0, (a-1), a);
    system("cls");
    cout<<"The sorted array is\n";
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}