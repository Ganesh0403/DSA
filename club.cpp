#include<iostream>
using namespace std;
struct node
{
    string name;
    char info;
    int prn;
    node *next;
};
class cclub
{
    int i;
    char s_info,p_info;
public:
    node *header;
    node *nn;
    cclub()
    {
        header=NULL;
        s_info=1;
        p_info=1;
        i=1;
    }
    void insert_p()
    {
        if(p_info==1)
        {
            p_info=0;
            nn=new node;
            nn->next=NULL;
            cout<<"\nEnter PRN no. : ";
            cin>>nn->prn;
            cout<<"\nEnter Name : ";
            cin>>nn->name;
            nn->info='p';
            nn->next=header;
            header=nn;
        }
        else
        {
            cout<<"\nPresident Already Exist\n";
        }
    }
    void insert_s()
    {
        if(s_info==1)
        {
            s_info=0;
            nn=new node;
            nn->next=NULL;
            nn->info='s';
            cout<<"\nEnter PRN no. : ";
            cin>>nn->prn;
            cout<<"\nEnter Name : ";
            cin>>nn->name;
            if(header==NULL)
                header=nn;
            else
            {
                node *cn=header;
                while(cn->next!=NULL)
                {
                    cn=cn->next;
                }
                cn->next=nn;
            }
        }
        else
        {
            cout<<"\nSecretary Already Exist\n";
        }        
    }
    void insert_m()
    {
        int flag=0;
        nn=new node;
        nn->next=NULL;
        nn->info='m';
        cout<<"\nEnter PRN no. : ";
        cin>>nn->prn;
        cout<<"\nEnter Name : ";
        cin>>nn->name;
        node *cn=header;
        while(cn->next!=NULL)
        {
            if(nn->prn==cn->prn)
            {
                flag=1;
                cout<<"\nPRn no. Already Exist\n";
                break;
            }
            cn=cn->next;
        }
        if(flag==0)
        {
            node *cn=header;
            int count=0;
            while(cn!=NULL)
            {
                cn=cn->next;
                count++;
            }
            if(count==0||count==1)
            {
                cout<<"\nFirst Enter President and Secretary information\n";
            }
            else if(count==2)
            {
                nn->next=header->next;
                header->next=nn;
            }
            else
            {
                node *temp=header;
                cn=header->next;
                int count2=1;
                while((nn->prn>cn->prn)&&count2!=count-1)
                {
                    temp=cn;
                    cn=cn->next;
                    count2++;
                }
                nn->next=temp->next;
                temp->next=nn;
            }
        }
    }
    void display()
    {
        node *cn=header;
        while(cn!=NULL)
        {
            if(cn->info=='p')
            {
                cout<<"\nPresident information : \n";
                i=1;
            }
            else if(cn->info=='s')
                cout<<"\nSecretary information : \n";
            else if(cn->info=='m' && i==1)
            {
                i=0;
                cout<<"\nMember information : \n";
            }
            cout<<"Name : "<<cn->name<<"\t"<<"PRN no. : "<<cn->prn<<endl;
            cn=cn->next;
        }
        cout<<"\n";
    }
    void exchange_p()
    {
        if(p_info==0)
        {
            p_info=1;
            node *temp=header;
            header=header->next;
            delete temp;
            cout<<"\nEnter new president info : \n";
            insert_p();
        }
        else
        {
            cout<<"\nPresident does not exist\n";
        }
    }
    void exchange_s()
    {
        if(s_info==0)
        {
            s_info=1;
            if(header->next==NULL)
            {
                delete header;
                header=NULL;
            }
            else
            {
                node *temp=header;
                node *cn;
                while(temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                cn=temp->next;
                temp->next=NULL;
                delete cn;
            }
            cout<<"\nEnter new secretary info : \n";
            insert_s();
        }
        else
        {
            cout<<"\nSecretary does not exist\n";
        }
    }
    void delete_m()
    {
        int t,flag=0;
        cout<<"\nEnter PRN no. to be deleted : ";
        cin>>t;
        node *dn,*cn;
        cn=header;
        while(cn!=NULL)
        {
            if(cn->prn==t)
            {
                dn=cn;
                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
            cn=cn->next;
        }
        if(flag==1)
        {
            node *cn=header;
            while(cn->next!=dn)
            {
                cn=cn->next;
            }
            cn->next=cn->next->next;
            delete dn;
            cout<<"\nMember Deleted..\n";
        }
        else
        {
            cout<<"\nMember Of prn no. does not exist\n";
        }
        
    }
    void reverse(node *a)
    {
        if(a->next!=NULL)
        {
            reverse(a->next);
        }
        if(a->info=='p')
        {
            cout<<"\nPresident information : \n";
        }
        else if(a->info=='s')
        {
            cout<<"\nSecretary information : \n";
            i=1;
        }
        else if(a->info=='m' && i==1)
        {
            i=0;
            cout<<"\nMember information : \n";
        }
        cout<<"Name : "<<a->name<<"\t"<<"PRN no. : "<<a->prn<<endl;
    }
    void concat(node *a)
    {
        node *cn=header;
        while(cn->next!=NULL)
        {
            cn=cn->next;
        }
        cn->next=a;
        cn=header;
        while(cn!=NULL)
        {
            if(cn->info=='p')
            {
                cout<<"\nPresident information : \n";
                i=1;
            }
            else if(cn->info=='s')
                cout<<"\nSecretary information : \n";
            else if(cn->info=='m' && i==1)
            {
                i=0;
                cout<<"\nMember information : \n";
            }
            cout<<"Name : "<<cn->name<<"\t"<<"PRN no. : "<<cn->prn<<endl;
            cn=cn->next;
        }
        cout<<"\n";
    }
};
int main()
{
    int ch;
    cclub c,c1;
    do{
        cout<<"\n\nFor Class A\n";
        cout<<"\n1: Insert President\n2: Insert Secretary\n3: Insert Member\n4: Display\n5: Exchange President\n6: Exchange Secretary\n7: Delete member\n8: Reverse display";
        cout<<"\n\nFor Class B\n";
        cout<<"\n9: Insert President\n10: Insert Secretary\n11: Insert Member\n12: Display\n13: Exchange President\n14: Exchange Secretary\n15: Delete member\n16: Reverse display\n17: Concatenate\n18: Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: c.insert_p();
                    break;
            case 2: c.insert_s();
                    break;
            case 3: c.insert_m();
                    break;
            case 4: c.display();
                    break;
            case 5: c.exchange_p();
                    break;
            case 6: c.exchange_s();
                    break;
            case 7: c.delete_m();
                    break;
            case 8: c.reverse(c.header);
                    break;
            case 9: c1.insert_p();
                     break;
            case 10: c1.insert_s();
                     break;
            case 11: c1.insert_m();
                     break;
            case 12: c1.display();
                     break;
            case 13: c1.exchange_p();
                     break;
            case 14: c1.exchange_s();
                    break;
            case 15: c1.delete_m();
                     break;
            case 16: c1.reverse(c1.header);
                     break;
            case 17: c.concat(c1.header);
                     break;
            case 18: break;
        }
    }while(ch!=18);
    return 0;
}