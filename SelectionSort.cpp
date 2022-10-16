#include<iostream>
#include<vector>
using namespace std;
vector<int> selectionsort(vector<int> arr)
{
    int size=arr.size();
    int min;
    for(int i=0;i<size-1;i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min==i)
        {
            continue;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    return arr;
}
int main()
{
    int a;
    cout<<"Enter the number of elements in the array\n";
    cin>>a;
    vector<int> arr;
    cout<<"Enter an array\n";
    for(int i=0;i<a;i++)
    {
        int n;
        cout<<"Enter an element\n";
        cin>>n;
        arr.push_back(n);
    }
    arr.resize(a);
    system("cls");
    cout<<"The sorted array is\n";
    vector<int> sorted=selectionsort(arr);
    for(int i=0;i<a;i++)
    {
        cout<<sorted[i]<<" ";
    }
    return 0;
}