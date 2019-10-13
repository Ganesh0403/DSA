#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

class st
{
    struct node 
    {
        char stack[MAX];
        int top;
    }s;
    public:
        void push(int);
        int pop();
        int check(char *);
        int match(char,char);
        st()
        {
            s.top=-1;
        }
};
void st::push(int item)
{
    if(s.top==MAX-1)
    {
        cout<<"\nStack is Full\n";
    }
    else
    {
        s.top++;
        s.stack[s.top]=item;
    }
}
int st::pop()
{
    return s.stack[s.top--];
}
int st::check(char exp[])
{
    int i,n;
    char temp;
    n=strlen(exp);
    for(i=0;i<n;i++)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
        {
            push(exp[i]);
        }        
        if(exp[i]==']'||exp[i]=='}'||exp[i]==')')
        {
            if(s.top==-1)
            {
                return 0;
            }
            else 
            {
                temp=pop();
                if(!match(temp,exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int st::match(char a,char b)
{
    if(a=='('&&b==')')
        return 1;
    else if(a=='['&&b==']')
        return 1;
    else if(a=='{'&&b=='}')
        return 1;
    else
        return 0;
}
int main()
{
    st sc;
    char expr[50];
    cout<<"Enter Expression : ";
    cin>>expr;
    int status;
    status=sc.check(expr);
    if(status==1)
    {
        cout<<"\nExpression is Well Paranthesized\n";
    }
    else
    {
        cout<<"\nExpression is not Well Paranthesized\n";
    }
    return 0;
}