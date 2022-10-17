#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cout << "Enter the number of elements in the array\n";
    cin >> a;
    vector<int> arr;
    for (int i = 0; i < a; i++)
    {
        int n;
        cout << "Enter an element\n";
        cin >> n;
        arr.push_back(n);
    }
    arr.resize(a);
    system("cls");
    int searchval;
    cout << "Enter a value to search in the array\n";
    cin >> searchval;
    int flag = 0;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == searchval)
        {
            cout << "The element was found at position number " << i + 1 << endl;
            flag++;
            break;
        }
    }
    if (flag == 0)
        cout << "The element was not found\n";
    return 0;
}