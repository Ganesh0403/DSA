#include<iostream>
#define size 10
using namespace std;
class queue
{
    struct node
    {
        int front,rear;
        int que[size];
    }q;
public:
    queue()
    {
        q.front=q.rear=-1;
    }
    int qempty();
    int qfull();
    void accecpt(int);
    void ready();
    void display();
};
int queue::qempty()
{
    if(q.front==-1)
        return 1;
    else
        return 0;
}
int queue::qfull()
{
    if(q.front==(q.rear+1)%size)
        return 1;
    else
        return 0;
}
void queue::accecpt(int item)
{   
    if(qempty())
    {
        q.rear=q.front=0;
    }
    else
    {
        q.rear=(q.rear+1)%size;
    }
    q.que[q.rear]=item;
    cout<<"\nOrder Placed\n";
}
void queue::ready()
{
    cout<<"\nThe Order number "<<q.que[q.front]<<" is on the way.\n";
    if(q.front==q.rear)
    {
        q.front=q.rear=-1;
    }
    else
    {
        q.front=(q.front+1)%size;
    }
}
void queue::display()
{
    cout<<"\nPizza Orders : \n";
    int i=q.front;
    do
    {
        cout<<q.que[i]<<" ";
        i=(i+1)%size;
    }while(i!=q.rear);
    cout<<q.que[i];
    cout<<"\n";
}
int main()
{
    queue s;
    int ch;
    cout<<"\n\t\tWelcome to Pizza Parlour...\n";
    do
    {
        cout<<"\n1: Accept Order\n2: Order Status\n3: Display\n4: Exit\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: if(s.qfull())
                    {
                        cout<<"\nFurther Orders are not taken.\n";
                    }
                    else
                    {
                        int in;
                        cout<<"\nEnter order number : ";
                        cin>>in;
                        s.accecpt(in);
                    }
                    break;
            case 2: if(s.qempty())
                    {
                        cout<<"\nThere are no Orders available to check status.\n";
                    }
                    else
                    {
                        s.ready();
                    }
                    break;
            case 3: if(s.qempty())
                    {
                        cout<<"\nQueue is empty there are no pizza orders taken.\n";
                    }
                    else
                    {
                        s.display();
                    }
                    break;
            case 4: break;
        }
    }while(ch!=4);
    cout<<"\nThankyou Visit Again\n\n";
    return 0;
}