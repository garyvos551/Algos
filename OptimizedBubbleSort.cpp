#include<iostream>
#include<vector>
using namespace std;
vector<int> bubblesort(vector<int> arr)
{
    int size=arr.size();
    for(int i=0;i<size;i++)
    {
        bool flag=false;
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==false)
        {
            break;
        }
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
    vector<int> sorted=bubblesort(arr);
    for(int i=0;i<a;i++)
    {
        cout<<sorted[i]<<" ";
    }
    return 0;
}