//============================================================================
// Name        : Assignment2.cpp
// Author      :Ganesh Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int m[31];
void init()
{
	for(int i=0;i<31;i++)
		m[i]=0;
}

class student
{
	int rollNo;
	int marks;
	string name;
public:
	static int count,absent,max,min,sum,avg;
	void getdata();
	void printdata();
	void display();
};
int student::count;
int student::avg;
int student::absent;
int student::max;
int student::min=30;
int student::sum;

void student::getdata()
{
	cout<<"Enter Roll no. : ";
	cin>>rollNo;
	cout<<"Enter name : ";
	cin>>name;
	cout<<"Enter marks out of 30 : ";
	cin>>marks;
	if(marks<0)
		{
			absent++;
		}
		else
		{
			m[marks]++;
			if(marks>max)
			{
				max=marks;
			}
			if (marks<min)
			{
				min=marks;
			}
			sum=sum+marks;
		}
	count++;
}
void student::printdata()
{
	cout<<"Roll no : "<<rollNo<<endl;
	cout<<"Name : "<<name<<endl;
	cout<<"Marks : "<<marks<<endl<<"\n";

}
void student::display()
{
	cout<<"The count of data entries made "<<count<<endl;
	cout<<"Maximum Score : "<<max<<endl;
	cout<<"Minimum Score : "<<min<<endl;
	cout<<"Absent Count : "<<absent<<endl;
	int present;
	present=count-absent;
	avg=sum/present;
	cout<<"Average Marks of class : "<<avg<<endl;
	cout<<"Maximum number of students scoring same marks ";
	int max=0,mark=0;
	for(int i=0;i<31;i++)
	{
		if(max<m[i])
		{
			max=m[i];
			mark=i;
		}
	}
	cout<<" Count : "<<max<<"  Marks : "<<mark<<endl<<endl;
}

int main()
{
	student s[100];
	int ch,i=0;
	init();
	do
	{
		cout<<"1: Enter details for new student\n";
		cout<<"2: Print details of all students\n";
		cout<<"3: Class test details\n";
		cout<<"4: Exit\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1: s[i].getdata();
				i++;
				break;
		case 2: for(int j=0;j<i;j++)
					s[j].printdata();
				break;
		case 3: s[1].display();
				break;
		case 4:
				break;

		}
	}while(ch!=4);
	return 0;
}
