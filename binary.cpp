#include<iostream>
using namespace std;
struct node
{
    node *next,*prev;
    int bd;
};
class bbinary
{
    node *header;
    public:
    bbinary()
    {
        header=NULL;
    }
    node *getheader()
    {
        return header;
    }
    void getdata()
    {
        int i,b;
        cout<<"\nEnter no. of bits : ";
        cin>>b;
        for(i=0;i<b;i++)
        {
            node *nn;
            nn=new node;
            nn->next = nn->prev=NULL;
            cout<<"\nEnter bit : ";
            cin>>nn->bd;
            if(header==NULL)
            {
                header=nn;
            }
            else
            {
                node *cn=header;
                while(cn->next!=NULL)
                {
                    cn=cn->next;
                }
                cn->next=nn;
                nn->prev=cn;
            }
        }
    }
    void display()
    {
        node *cn=header;
        cout<<"\nBinary Number is : \n";
        while(cn!=NULL)
        {
            cout<<cn->bd<<" ";
            cn=cn->next;
        }        
        cout<<endl;
    }
    void one()
    {
        node *cn=header;
        cout<<"\nOne's Complement of Entered Binary Number is : \n";
        while(cn!=NULL)
        {
            if(cn->bd==0)
                cout<<1<<" ";
            else
                cout<<0<<" ";
            cn=cn->next;
        }
        cout<<"\n";
    }
    void two()
    {
        node *cn=header;
        while(cn->next!=NULL)
        {
            cn=cn->next;
        }
        while(cn->bd==0)
        {
            cn=cn->prev;
        }
        node *temp=header;
        cout<<"\nTwo's Complement of Entered Binary Number is : \n";
        while(temp!=cn)
        {
            if(temp->bd==0)
                cout<<1<<" ";
            else
                cout<<0<<" ";
            temp=temp->next;
        }
        while(cn!=NULL)
        {
            cout<<cn->bd<<" ";
            cn=cn->next;
        }
        cout<<"\n";
    }
    int retsum(int a,int b,int c=0)
    {
        if(a+b+c==1 || a+b+c==3)
            return 1;
        else
            return 0;
    }
    int retcarry(int a,int b,int c=0)
    {
        if(a+b+c>1)
            return 1;
        else
            return 0;
    }
    void addition()
    {
        bbinary x,y;
        cout<<"\nEnter First Binary number : ";
        x.getdata();
        cout<<"\nEnter Second Binary number : ";
        y.getdata();
        cout<<"\nFirst Binary Number : ";
        x.display();
        cout<<"\nSecond Binary Number : ";
        y.display();
        node *nn,*cn1,*cn2;
        cn1=x.getheader();
        while(cn1->next!=NULL)
        {
            cn1=cn1->next;
        }
        cn2=y.getheader();
        while(cn2->next!=NULL)
        {
            cn2=cn2->next;
        }
        int carry=0;
        while(cn1!=NULL && cn2!=NULL)
        {
            nn=new node;
            nn->next=nn->prev=NULL;
            if(header==NULL)
                header=nn;
            else
            {
                header->prev=nn;
                nn->next=header;
                header=nn;
            }
            nn->bd=retsum(cn1->bd,cn2->bd,carry);
            carry=retcarry(cn1->bd,cn2->bd,carry);
            cn1=cn1->prev;
            cn2=cn2->prev;
        }
        while(cn1!=NULL)
        {
            nn=new node;
            nn->next=nn->prev=NULL;
            header->prev=nn;
            nn->next=header;
            header=nn;
            nn->bd=retsum(cn1->bd,carry);
            carry=retcarry(cn1->bd,carry);
            cn1=cn1->prev;           
        }
        while(cn2!=NULL)
        {
            nn=new node;
            nn->next=nn->prev=NULL;
            header->prev=nn;
            nn->next=header;
            header=nn;
            nn->bd=retsum(cn2->bd,carry);
            carry=retcarry(cn2->bd,carry);
            cn2=cn2->prev;           
        }
        if(carry==1)
        {
            nn=new node;
            nn->next=nn->prev=NULL;
            header->prev=nn;
            nn->next=header;
            header=nn;
            nn->bd=1;
            carry=0;            
        }
        cout<<"\nResult Of the Addition : \n";
        display();
    }
};
int main()
{
    bbinary b;
    //b.getdata();
    //b.display();
    //b.one();
    //b.two();
    b.addition();
    return 0;
}