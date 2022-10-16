#include<iostream>
#include<vector>
using namespace std;
vector<int> insertionsort(vector<int> arr)
{
    int size=arr.size();
    for(int i=1;i<size;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    vector<int> sorted=insertionsort(arr);
    for(int i=0;i<a;i++)
    {
        cout<<sorted[i]<<" ";
    }
    return 0;
}