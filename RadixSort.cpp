#include<iostream>
using namespace std;
void countingsort(int arr[], int a, int div)
{
    int count[10]={0};
    for(int i=0;i<a;i++)
    {
        count[(arr[i]/div)%10]++;
    }
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    int oparr[a];
    for(int i=a-1;i>=0;i--)
    {
        oparr[count[(arr[i]/div)%10]-1]=arr[i];
        count[(arr[i]/div)%10]--;
    }
    for(int i=0;i<a;i++)
    {
        arr[i]=oparr[i];
    }
}
void radixsort(int arr[], int a)
{
    int max=arr[0];
    for(int i=1;i<a;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    for(int div=1;max/div>0;div*=10)
    {
        countingsort(arr, a, div);
    }
}
int main()
{
    int a;
    cout<<"Enter number of elements\n";
    cin>>a;
    system("cls");
    int inparr[a];
    cout<<"Enter the elements\n";
    for(int i=0;i<a;i++)
    {
        cin>>inparr[i];
    }
    radixsort(inparr, a);
    cout<<"The sorted array is:\n";
    for(int i=0;i<a;i++)
    {
        cout<<inparr[i]<<" ";
    }
    cout<<endl;
    return 0;
}