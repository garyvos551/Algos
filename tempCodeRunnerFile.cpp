#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<long long int> arr;
        for(long long int i=0;i<n;i++)
        {
            long long int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        long long int sum=0;
        for(long long int i=0;i<n;i+=2)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}