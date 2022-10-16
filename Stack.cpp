#include<iostream>
#include<string>
using namespace std;
class Stack
{
private:
    int arr[5];
    int top;
public:
    Stack()
    {
        top=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if(top==4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if(isfull())
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }
    int pop()
    {
        if(isempty())
        {
            cout<<"Stack Underflow\n";
            return 0;
        }
        else
        {
            int temp=arr[top];
            arr[top]=0;
            top--;
            return temp;
        }
    }
    int cnt()
    {
        return (top+1);
    }
    int view(int pos)
    {
        if(isempty())
        {
            cout<<"Stack underflow\n";
            return 0;
        }
        else
            return arr[pos];
    }
    void change(int pos, int val)
    {
        arr[pos-1]=val;
        cout<<"Value changed at "<<pos<<endl;
    }
    void disp()
    {
        if(isempty())
        {
            cout<<"Stack Underflow\n";
        }
        else
        {
            for(int i=top;i>=0;i--)
            {
                cout<<i+1<<" -> "<<arr[i]<<endl;
            }
        }
    }
};
int main()
{
    Stack s;
    int choice, pos, val;
    do
    {
        cout<<"The Available Operations are:\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Count\n";
        cout<<"5. Change\n";
        cout<<"6. Display\n";
        cout<<"7. Clear Screen\n";
        cout<<"0. Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter a value to push in the stack\n";
            cin>>val;
            s.push(val);
            break;
        case 2:
            cout<<s.pop()<<" was popped from the stack\n";
            break;
        case 3:
            cout<<"Enter the position in the stack\n";
            cin>>pos;
            if(s.cnt()<pos)
            {
                cout<<"Position does not exist\n";
            }
            else
            {
                cout<<"The element is "<<s.view(pos)<<endl;
            }
            break;
        case 4:
            cout<<"The number of elements in the stack is "<<s.cnt()<<endl;
            break;
        case 5:
            cout<<"Enter the position of the element to be changed\n";
            cin>>pos;
            if(s.cnt()<pos)
            {
                cout<<"Position does not exist\n";
            }
            else
            {
                cout<<"Enter the new element\n";
                cin>>val;
                s.change(pos, val);
            }
            break;
        case 6:
            s.disp();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<<"Wrong input\n";
            break;
        }
    }while(choice!=0);
    return 0;
}
