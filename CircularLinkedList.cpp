#include<iostream>
using namespace std;
class Node
{
    public:
        int key;
        int data;
        Node* nex;
        Node()
        {
            key=0;
            data=0;
            nex=NULL;
        }
        Node(int k, int d)
        {
            key=k;
            data=d;
        }
};
class CLinkedList
{
    public:
        Node* head;
        CLinkedList()
        {
            head=NULL;
        }
        Node* nodexist(int k)
        {
            Node* ptr=head;
            Node* temp=NULL;
            if(ptr==NULL)
            {
                return temp;
            }
            do
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->nex;
            }while(ptr!=head);
            return temp;
        }
        void append(Node* n)
        {
            if(nodexist(n->key)!=NULL)
            {
                cout<<"Node already exists\n";
                return;
            }
            else
            {
                if(head==NULL)
                {
                    head=n;
                    n->nex=head;
                    cout<<"Node appended\n";
                }
                else
                {
                    Node* ptr=head;
                    while(ptr->nex!=head)
                    {
                        ptr=ptr->nex;
                    }
                    ptr->nex=n;
                    n->nex=head;
                    cout<<"Node appended\n";
                }
            }
        }
        void prepend(Node* n)
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
                    n->nex=head;
                    cout<<"Node prepended\n";
                }
                else
                {
                    Node* ptr=head;
                    while(ptr->nex!=head)
                    {
                        ptr=ptr->nex;
                    }
                    ptr->nex=n;
                    n->nex=head;
                    head=n;
                    cout<<"Node prepended\n";
                }
            }
        }
        void insert(int k, Node* n)
        {
            Node* ptr=nodexist(k);
            if(ptr==NULL)
            {
                cout<<"Node does not exist\n";
                return;
            }
            if(nodexist(n->key)!=NULL)
            {
                cout<<"Node with key value already exists\n";
            }
            else
            {
                if(ptr->nex==head)
                {
                    n->nex=head;
                    ptr->nex=n;
                    cout<<"Node inserted\n";
                    return;
                }
                n->nex=ptr->nex;
                ptr->nex=n;
                cout<<"Node inserted\n";
            }
        }
        void deletenode(int k)
        {
            Node* ptr=nodexist(k);
            if(ptr==NULL)
            {
                cout<<"Node does not exist\n";
            }
            else
            {
                if(ptr==head)
                {
                    if(head->nex==head)
                    {
                        head=NULL;
                        cout<<"Node unlinked\n";
                    }
                    else
                    {
                        Node* temp=head;
                        while(temp->nex!=head)
                        {
                            temp=temp->nex;
                        }
                        temp->nex=head->nex;
                        head=head->nex;
                        cout<<"Node unlinked\n";
                    }
                }
                else
                {
                    Node* temp=NULL;
                    Node* prevptr=head;
                    Node* currentptr=head->nex;
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else
                        {
                            prevptr=prevptr->nex;
                            currentptr=currentptr->nex;
                        }
                    }
                    prevptr->nex=temp->nex;
                    cout<<"Node unlinked\n";
                }
            }
        }
        void update(int k, int d)
        {
            Node* ptr=nodexist(k);
            if(ptr==NULL)
            {
                cout<<"Node does not exist\n";
            }
            else
            {
                ptr->data=d;
                cout<<"Node updated\n";
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
                do
                {
                    cout<<"Node key: "<<temp->key<<endl<<"Node data: "<<temp->data<<endl<<endl;
                    temp=temp->nex;
                }while(temp!=head);
            }
        }
};
int main()
{
    CLinkedList c;
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
                c.append(n1);
                break;
            case 2:
                cout<<"Enter key for node\n";
                cin>>key1;
                cout<<"Enter data\n";
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                c.prepend(n1);
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
                c.insert(key2, n1);
                break;
            case 4:
                cout<<"Enter key of node to be deleted\n";
                cin>>key2;
                c.deletenode(key2);
                break;
            case 5:
                cout<<"Enter key of node to be modified\n";
                cin>>key2;
                cout<<"Enter new data\n";
                cin>>data1;
                c.update(key2, data1);
                break;
            case 6:
                c.display();
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