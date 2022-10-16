#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> arr, int searchval)
{
    int lower=0;
    int upper=arr.size();
    while(upper>=lower)
    {
        int mid=(upper+lower)/2;
        if(searchval==arr[mid])
        {
            return mid+1;
        }
        else if(searchval>arr[mid])
        {
            lower=mid+1;
        }
        else
        {
            upper=mid-1;
        }
    }
    return 0;
}
int main()
{
    int a;
    cout<<"Enter the number of elements in the array\n";
    cin>>a;
    vector<int> arr;
    cout<<"Enter a sorted array\n";
    for(int i=0;i<a;i++)
    {
        int n;
        cout<<"Enter a larger element\n";
        cin>>n;
        arr.push_back(n);
    }
    arr.resize(a);
    system("cls");
    int searchval;
    cout<<"Enter a value to search in the array\n";
    cin>>searchval;
    int pos=binarysearch(arr, searchval);
    if(pos==0)
    {
        cout<<"Element not found\n";
    }
    else
    {
        cout<<"Element found at position number "<<pos<<endl;
    }
    return 0;
}