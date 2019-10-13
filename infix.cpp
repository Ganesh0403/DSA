#include<iostream>
using namespace std;
class post
{
    char exp[50],out[50],stack[15];
    int stack1[15],top=-1,j=0;
public:
    void getdata()
    {
        cout<<"\nEnter Infix Expression : ";
        cin>>exp;
    }
    void push(char a)
    {
        stack[++top]=a;
    }
    int pop()
    {
        return stack[top--];
    }
    int sempty()
    {
        if(top==-1)
            return 1;
        else 
            return 0;
    }
    int getprecedance(char a)
    {
        if(a=='+'||a=='-')
            return 1;
        else if(a=='*'||a=='/')
            return 2;
        else return 0;
    }
    void convert()
    {
        int i=0;
        while(exp[i]!='\0')
        {
            if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
                push(exp[i]);
            else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
            {
                if(exp[i]==')')
                {
                    while(stack[top]!='(')
                    {
                        out[j++]=pop();
                    }
                }
                else if(exp[i]==']')
                {
                    while(stack[top]!='[')
                    {
                        out[j++]=pop();
                    }
                }
                else if(exp[i]=='}')
                {
                    while(stack[top]!='{')
                    {
                        out[j++]=pop();
                    }
                }
                int temp=pop();
            }
            else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
            {
                if(getprecedance(exp[i])<getprecedance(stack[top]))
                {
                    out[j++]=pop();
                    push(exp[i]);
                }
                else
                {
                    push(exp[i]);
                }
            }
            else
            {
                out[j++]=exp[i];
            }
            i++;
        }
        if(top!=-1)
        {
            while(top>=-1)
            {
                out[j++]=pop();
            }
        }
        out[j]='\0';
        cout<<"\nPostFix Expression is : ";
        cout<<out;
    }
    void push_int(int a)
    {
        stack1[++top]=a;
    }
    int pop_int()
    {
        return stack1[top--];
    }
    void evaluate()
    {
        int i=0;
        int op1,op2;
        while(out[i]!='\0')
        {
            if(out[i]=='+')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1+op2);

            }
            else if(out[i]=='-')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1-op2);
            }
            else if(out[i]=='*')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1*op2);
            }
            else if(out[i]=='/')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1/op2);
            }
            else
                push_int(int(out[i])-48);
            i++;
        }
        cout<<"\nEvaluation : "<<pop_int()<<"\n";
    }
};
int main()
{
    post p;
    p.getdata();
    p.convert();
    p.evaluate();
    return 0;
}