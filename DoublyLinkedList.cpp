#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int key;
        int data;
        Node * nex;
        Node * prev;//ch
        Node()
        {
            key=0;
            data=0;
            nex=NULL;
            prev=NULL;//ch
        }
        Node(int k, int d)
        {
            key=k;
            data=d;
        }
};
class DLinkedList
{
    public:
        Node * head;
        DLinkedList()
        {
            head=NULL;
        }
        DLinkedList(Node * n)
        {
            head=n;
        }
        Node* nodexist(int k)
        {
            Node* temp=NULL;
            Node* ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->nex;
            }
            return temp;
        }
        void append(Node *n)
        {
            if(nodexist(n->key)!=NULL)
            {
                cout<<"Node already exists\n";
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node appended\n";
                }
                else
                {
                    Node* ptr=head;
                    while(ptr->nex!=NULL)
                    {
                        ptr=ptr->nex;
                    }
                    ptr->nex=n;
                    n->prev=ptr;//ch
                    cout<<"Node appended\n";
                }
            }
        }
        void prepend(Node *n)
        {
            if(nodexist(n->key)!=NULL)
            {
                cout<<"Node already exists\n";
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    cout<<"Node prepended\n";
                }
                else
                {
                    n->nex=head;
                    head->prev=n;//ch
                    head=n;
                    cout<<"Node prepended\n";
                }
            }
        }
        void insert(int k, Node *n)
        {
            Node* ptr=nodexist(k);
            if(ptr==NULL)
            {
                cout<<"Node does not exist\n";
                return;
            }
            if(nodexist(n->key)!=NULL)
            {
                cout<<"Node already exists\n";
                return;
            }
            Node* nextptr=ptr->nex;
            if(nextptr==NULL)
            {
                ptr->nex=n;
                n->prev=ptr;
                cout<<"Node inserted\n";
                return;
            }
            n->nex=nextptr;
            nextptr->prev=n;
            ptr->nex=n;
            n->prev=ptr;
            cout<<"Node inserted\n";
        }
        void deletenode(int k)
        {
            if(nodexist(k)==NULL)
            {
                cout<<"Node does not exist\n";
                return;
            }
            if(head==NULL)
            {
                cout<<"Linked list is empty\n";
            }
            else if(head!=NULL)
            {
                if(head->nex==NULL)
                {
                    head=NULL;
                    cout<<"Node unlinked\n";
                    return;
                }
                if(head->key==k)
                {
                    head=head->nex;
                    head->prev=NULL;//ch
                    cout<<"Node unlinked\n";
                }
                else
                {
                    Node* ptr=nodexist(k);
                    Node* prevptr=ptr->prev;//ch
                    Node* nexptr=ptr->nex;//ch
                    if(nexptr==NULL)
                    {
                        prevptr->nex=NULL;
                    }
                    else
                    {
                        prevptr->nex=nexptr;
                        nexptr->prev=prevptr;
                    }
                    cout<<"Node unlinked\n";
                }
            }
        }
        void update(int k, int d)
        {
            Node* ptr=nodexist(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Node updated\n";
            }
            else
            {
                cout<<"Node does not exist\n";
            }
        }
        void display()
        {
            if(head==NULL)
            {
                cout<<"The list is empty\n";
            }
            else
            {
                cout<<"The list is:\n";
                Node* temp=head;
                while(temp->nex!=NULL)
                {
                    cout<<"Node key: "<<temp->key<<endl<<"Node data: "<<temp->data<<endl<<endl;
                    temp=temp->nex;
                }
                if(temp->nex==NULL)
                {
                    cout<<"Node key: "<<temp->key<<endl<<"Node data: "<<temp->data<<endl<<endl;
                }
            }
        }
};
int main()
{
    DLinkedList d;
    int choice, data1, key1, key2;
    do
    {
        cout<<"The available options are:\n";
        cout<<"1.Append\n";
        cout<<"2.Prepend\n";
        cout<<"3.Insert\n";
        cout<<"4.Delete\n";
        cout<<"5.Modify\n";
        cout<<"6.Display\n";
        cout<<"7.Clear Screen\n";
        cout<<"0.Exit\n";
        cin>>choice;
        Node* n1=new Node();
        switch(choice)
        {
            case 1:
                cout<<"Enter key for node\n";
                cin>>key1;
                cout<<"Enter data\n";
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.append(n1);
                break;
            case 2:
                cout<<"Enter key for node\n";
                cin>>key1;
                cout<<"Enter data\n";
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                d.prepend(n1);
                break;
            case 3:
                cout<<"Enter key of node\n";
                cin>>key1;
                cout<<"Enter data for node\n";
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                cout<<"Enter key of node to insert after\n";
                cin>>key2;
                d.insert(key2, n1);
                break;
            case 4:
                cout<<"Enter key of node to be deleted\n";
                cin>>key2;
                d.deletenode(key2);
                break;
            case 5:
                cout<<"Enter key of node to be modified\n";
                cin>>key2;
                cout<<"Enter new data\n";
                cin>>data1;
                d.update(key2, data1);
                break;
            case 6:
                d.display();
                break;
            case 7:
                system("cls");
                break;
            case 0:
                cout<<"Execution terminated\n";
                break;
            default:
                cout<<"Wrong input\n";
        }
    }while(choice!=0);
    return 0;
}