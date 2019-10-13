#include<iostream>
using namespace std;
struct node
{
    int status;
    node *next;
    node *prev;
    string name;
};
class book
{
    node *header[10];
    public:
        book()
        {
            for(int i=0;i<10;i++)
                header[i] = NULL;
        }
        void create();
        void display();
        void info();
        void seat();
        void cancel();
};
void book :: create()
{
    node *nn;
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=1;j<=7;j++)
        {
            nn=new node;
            nn->status=0;
            nn->next=nn->prev=NULL;
            if(header[i]==NULL)
            {
                header[i]=nn;
                nn->prev=header[i];
                nn->next=header[i];
            }
            else
            {
                node *cn=header[i];
                while(cn->next!=header[i])
                {
                    cn=cn->next;
                }
                cn->next=nn;
                nn->next=header[i];
                nn->prev=cn;
                header[i]->prev=nn;
            }
        }
    }
}
void book::display()
{
    cout<<"\n\t1\t2\t3\t4\t5\t6\t7\n";
    int i;
    for(i=0;i<10;i++)
    {
        cout<<i+1<<"\t";
        node *t=header[i];
        do
        {
            if(t->status==0)
            {
                cout<<"A\t";
            }
            else
            {
                cout<<"B\t";
            }
            t=t->next;
        }while(t!=header[i]);
        cout<<"\n";
    }
    cout<<"\n---------------------------------------------------------\n\n";
}
void book::seat()
{
    int r,c,j;
    cout<<"\nEnter Row number : ";
    cin>>r;
    cout<<"\nEnter Column number : ";
    cin>>c;
    node *t=header[r-1];
    for(j=0;j<c-1;j++)
    {
        t=t->next;
    }
    if(t->status==0)
    {
        t->status=1;
        cout<<"\nEnter Your name : ";
        cin>>t->name;
    }
    else
    {
        cout<<"\nSeat is already Booked\n";
    }
    
}
void book::info()
{
    int r,c,j;
    cout<<"\nEnter Row number you want to search : ";
    cin>>r;
    cout<<"\nEnter Column number you want to search : ";
    cin>>c;
    node *t=header[r-1];
    for(j=0;j<c-1;j++)
    {
        t=t->next;
    }
    if(t->status==1)
    {
        cout<<"\nName : ";
        cout<<t->name<<endl;
    }
    else
    {
        cout<<"\nSeat is Available\n";
    }
    
}
void book::cancel()
{
    int r,c,j;
    cout<<"\nEnter Row number you want to delete : ";
    cin>>r;
    cout<<"\nEnter Column number you want to delete : ";
    cin>>c;
    node *t=header[r-1];
    for(j=0;j<c-1;j++)
    {
        t=t->next;
    }
    if(t->status==1)
    {
        t->status=0;
        cout<<"\nSeat Cancelled..\n";
    }
    else
    {
        cout<<"\nSeat is already Available\n";
    }    
}
int main()
{
    book b;
    b.create();
    b.seat();
    b.display();
    b.info();
    b.cancel();
    b.display();
    return 0;
}