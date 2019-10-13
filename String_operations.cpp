//============================================================================
// Name        : Assignment3.cpp
// Author      : Ganesh Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class string_operation
{
	char name[100],p[100];
	int i;
public:
    int str_len();
	void str_cpy();
	void str_cat();
	void str_rev();
	int str_cmp();
	void sub_str();

};
int string_operation::str_len()
{
	cout<<"Enter string : ";
	cin>>name;
	for(i=0;name[i]!='\0';i++);
	return(i);
}
void string_operation::str_cpy()
{
	cout<<"Enter string : ";
	cin>>name;
	for(i=0;name[i]!='\0';i++)
	{
		p[i]=name[i];
	}
	p[i]='\0';
	cout<<"\nThe copied string is : "<<p<<endl;
}
void string_operation::str_cat()
{
		cout<<"Enter string : ";
		cin>>name;
		cout<<"Enter string to concatenate : ";
		cin>>p;
		for(i=0;name[i]!='\0';i++);
		for(int j=0;p[j]!='\0';j++,i++)
		{
			name[i]=p[j];
		}
		name[i]='\0';
		cout<<"\nString Concatenation : "<<name<<endl;
}
void string_operation::str_rev()
{
	int j,temp,r;
	r=str_len();
	j=r-1;
	for(i=0;i<j;i++,j--)
	{
		temp=name[i];
		name[i]=name[j];
		name[j]=temp;
	}
	cout<<"\nReverse of String : "<<name<<endl;
}
int string_operation::str_cmp()
{
	int j,flag=0,la,lb;
	cout<<"Enter String 1 : ";
	cin>>name;
	cout<<"Enter String 2 : ";
	cin>>p;
	for(i=0;name[i]!='\0';i++);
	int m=i;
	for(int j=0;p[j]!='\0';j++);
	int n=j;
	if(m==n)
	{
		for(int k=0;k<m;k++)
		{
			if(name[k]==p[k])
			{
				flag=1;
			}
			else
			{
			    flag=0;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"\nTwo Strings are equal"<<endl;
		}
		else
		{
			cout<<"\nTwo Strings are not equal"<<endl;
		}
	}
	else
	{
		cout<<"\nTwo Strings are not equal"<<endl;
	}
	return 0;
}
void string_operation::sub_str()
{
    int m,n,flag=0,j;
    cout<<"Enter String : ";
    cin>>name;
    cout<<"Enter substring : ";
    cin>>p;
	for(i=0;name[i]!='\0';i++);
	n=i;
	for(j=0;p[j]!='\0';j++);
	m=j;
	j=0;
	for(i=0;i<n;i++)
	{
		 if(name[i]==p[j])
		 {
			 j++;
		     if(p[j]=='\0')
             {
                flag=1;
                cout<<"\nThe substring found at "<<(i+2-m)<<"th position.\n";
                j=0;
             }
		 }
	}
	if(flag==0)
		cout<<"\nThe substring is not present"<<endl;
}
int main()
{
	string_operation s;
	int ch;
	do
	{
		cout<<"\nProgram for string Operations\n";
		cout<<"1 : Length"<<endl;
		cout<<"2 : Copy"<<endl;
		cout<<"3 : Concatenation"<<endl;
		cout<<"4 : Reverse"<<endl;
		cout<<"5 : Compare"<<endl;
		cout<<"6 : Substring"<<endl;
		cout<<"7 : Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<"\nLength = "<<s.str_len()<<endl;
				break;
		case 2: s.str_cpy();
				break;
		case 3: s.str_cat();
				break;
		case 4: s.str_rev();
				break;
		case 5: s.str_cmp();
				break;
        case 6: s.sub_str();
                break;
        case 7: break;
        default:
                cout<<"\nYou entered Wrong choice \n ";
		}
	}while(ch!=7);
	return 0;
}
