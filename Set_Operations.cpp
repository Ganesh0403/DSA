//============================================================================
// Name        : Assignment1.cpp
// Author      : Ganesh Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sports
{
	int m,roll[30];
public:
	void getdata();
	void display();
	void sunion(sports,sports);
	void sintersection(sports,sports);
	void difference(sports,sports);
};
void sports::getdata()
{
	cout<<"Enter no. of students : ";
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cout<<"Enter Roll no. : ";
		cin>>roll[i];
	}
}
void sports::display()
{
	cout<<" count is "<<m;
	cout<<"\n{";
	for(int i=0;i<m;i++)
	{
		cout<<roll[i];
		if(i!=m-1)
		{
			cout<<",";
		}
	}
	cout<<"}\n";
}
void sports::sunion(sports a,sports b)
{
	int flag,i,x=0;
	for(i=0;i<a.m;i++)
	{
		roll[i]=a.roll[i];
		x++;
	}
	for(i=0;i<b.m;i++)
	{
	    flag=0;
		for(int j=0;j<a.m;j++)
		{
			if(b.roll[i]==a.roll[j])
			{
				flag=1;
				break;
			}
		}
        if(flag==0)
        {
            roll[x]=b.roll[i];
            x++;
        }
	}

	m=x;
}
void sports::sintersection(sports a,sports b)
{
	int x=0,flag;
	for(int i=0;i<b.m;i++)
	{
		int flag=0;
		for(int j=0;j<a.m;j++)
		{
			if(b.roll[i]==a.roll[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
        {
            roll[x]=b.roll[i];
            x++;
        }
	}
    m=x;
}
void sports::difference(sports a,sports b)
{
	int x=0,flag;
		for(int i=0;i<a.m;i++)
		{
			int flag=0;
			for(int j=0;j<b.m;j++)
			{
				if(a.roll[i]==b.roll[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
            {
                roll[x]=a.roll[i];
                x++;
            }
		}
		m=x;
}
int main()
{
	sports total,ct,bm,uni,intr,diff,dn;
	int ch;

	do
	{
		cout<<"\nSelect operation\n";
		cout<<"1 : Take a input\n";
		cout<<"2 : To display set details\n";
		cout<<"3 : Union\n";
		cout<<"4 : Intersection\n";
		cout<<"5 : Difference\n";
		cout<<"6 : Don't play\n";
		cout<<"7 : Exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			cout<<"Enter total no. of students \n";
			total.getdata();

			cout<<"Enter no. of students who play cricket \n";
			ct.getdata();

			cout<<"Enter no.of students who play badminton \n";
			bm.getdata();

			break;
		}
		case 2:
		{
			cout<<"Set of total no. of students : ";
			total.display();

			cout<<"\nSet of students playing cricket : ";
			ct.display();

			cout<<"\nSet of students playing badminton : ";
			bm.display();

			break;
		}
		case 3:
		{
			uni.sunion(ct,bm);
			cout<<"Set of students who play either cricket or badminton or both : ";
			uni.display();
			break;
		}
		case 4:
		{
			intr.sintersection(ct,bm);
			cout<<"Set of students who play both cricket and badminton : ";
			intr.display();
			break;
		}
		case 5:
        {
            diff.difference(ct,bm);
            cout<<"Set of students who play only cricket : ";
            diff.display();

            diff.difference(bm,ct);
            cout<<"Set of students who play only badminton : ";
            diff.display();

            break;
        }
        case 6:
        {
            dn.difference(total,uni);
            cout<<"Set of students who do not play anything : ";
            dn.display();
            break;
        }
        default :
        {
            cout<<"Enter  correct choice/operation : ";
            break;
        }

		}
	}while(ch!=7);
 return 0;
}
