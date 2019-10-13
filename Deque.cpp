#include<iostream>
#define size 10
using namespace std;
class deque
{
    struct node
    {
        int que[size];
        int front,rear;
    }q;
public:
    deque()
    {
        q.front=q.rear=-1;
    }
    void insert_rear(int);
    void insert_front(int);
    void delete_front();
    void delete_rear();
    void display();
    int qempty();
    int qfull();
};
int deque::qempty()
{
    if(q.front==-1||q.front>q.rear)
        return 1;
    else
        return 0;
}
int deque::qfull()
{
    if(q.rear>=size-1)
        return 1;
    else
        return 0;
}
void deque::insert_rear(int item)
{
    if(qempty())
    {
        q.front=q.rear=0;
    }
    else
    {
        q.rear+=1;
    }
    q.que[q.rear]=item;
    cout<<"\n"<<item<<" is inserted at rear end\n";
}
void deque::delete_front()
{
    int temp;
    if(qempty())
        cout<<"\nDeletion is not possible\n";
    else
    {
        temp=q.que[q.front];
        q.front+=1;
        cout<<"\n"<<temp<<" is deleted from front end\n";
    }
}
void deque::delete_rear()
{
    int temp;
    if(qempty())
        cout<<"\nDeletion is not possible\n";
    else
    {
        temp=q.que[q.rear];
        q.rear-=1;
        cout<<"\n"<<temp<<" is deleted from rear end\n";
    }    
}
void deque::insert_front(int item)
{
    if(qempty())
    {
        q.front=q.rear=0;
        q.que[q.front]=item;
    }
    else
    {
        int i;
        i=q.rear;
        while(i>=q.front)
        {
            q.que[i+1]=q.que[i];
            i--;
        }
        q.que[q.front]=item;
        q.rear++;
    }
    cout<<"\n"<<item<<" is inserted at front end\n";
}
void deque::display()
{
    int i;
    for(i=q.front;i<=q.rear;i++)
    {
        cout<<q.que[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    deque d;
    int ch;
    do
    {
        cout<<"\n1: Insert Rear\n2: Insert front\n3: Delete front\n4: Delete rear\n5: Display\n6: Exit\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: if(d.qfull())
                    {
                        cout<<"\nInsertion is not possible\n";
                    }
                    else
                    {
                        int j;
                        cout<<"\nEnter Element to be inserted : ";
                        cin>>j;
                        d.insert_rear(j);
                    }
                    break;
            case 2: if(d.qfull())
                    {
                        cout<<"\nInsertion is not possible\n";
                    }
                    else
                    {
                        int j;
                        cout<<"\nEnter Element to be inserted : ";
                        cin>>j;
                        d.insert_front(j);
                    }            
                    break;
            case 3: d.delete_front();
                    break;
            case 4: d.delete_rear();
                    break;
            case 5: d.display();
                    break;
            case 6: break;
        }
    }while(ch!=6);
    return 0;
}