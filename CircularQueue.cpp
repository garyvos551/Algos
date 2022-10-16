#include<bits/stdc++.h>
using namespace std;
class Queue
{
    private:
    int arr[5];
    int front, rear, num;
    public:
    Queue()
    {
        rear=-1;
        front=-1;
        num=0;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isfull()
    {
        if((rear+1)%5==front)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if(front==-1&&rear==-1)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if(isfull())
        {
            cout<<"Queue is full\n";
            return;
        }
        else if(isempty())
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%5;
        }
        arr[rear]=val;
        num++;
    }
    int dequeue()
    {
        int x;
        if(isempty())
        {
            cout<<"Queue is already empty\n";
            return 0;
        }
        else if(front==rear)
        {
            x=arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;
        }
        num--;
        return x;
    }
    int cnt()
    {
        if(isempty())
        {
            cout<<"The queue is empty";
            return 0;
        }
        else
        {
            return num;
        }
    }
    void disp()
    {
        if(isempty())
        {
            cout<<"The queue is empty\n";
            return;
        }
        else
        {
            for(int i=0;i<5;i++)
            {
                cout<<i+1<<" -> "<<arr[i]<<endl;
            }
        }
    }
};
int main()
{
    Queue q;
    int choice, val;
    do
    {
        cout<<"The Available Operations are:\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. IsFull\n";
        cout<<"4. IsEmpty\n";
        cout<<"5. Display\n";
        cout<<"6. Count\n";
        cout<<"7. Clear Screen\n";
        cout<<"0. Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter a value to enqueue\n";
            cin>>val;
            q.enqueue(val);
            break;
        case 2:
            cout<<q.dequeue()<<" was dequeued\n";
            break;
        case 3:
            if(q.isfull())
            {
                cout<<"The queue is full\n";
            }
            else
            {
                cout<<"The queue is not full\n";
            }
            break;
        case 4:
            if(q.isempty())
            {
                cout<<"The queue is empty\n";
            }
            else
            {
                cout<<"The queue is not empty\n";
            }
            break;
        case 5:
            cout<<"The queue is:\n";
            q.disp();
            break;
        case 6:
            cout<<"The number of elements are: "<<q.cnt()<<endl;
            break;
        case 7:
            system("cls");
            break;
        case 0:
            cout<<"Execution Terminated\n";
            break;
        default:
            cout<<"Wrong input\n";
            break;
        }
    }while(choice!=0);
    return 0;
}