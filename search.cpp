#include<iostream>
using namespace std;
class ssearch
{
    int a[10];
    int n;
    public:
    void getdata()
    {
        cout<<"\nEnter no. of terms in array : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void binary()
    {
        int mid;
        int low=0;
        int high=n-1;
        int key,flag=1;
        cout<<"\nEnter Element to be searched : ";
        cin>>key;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(a[mid]==key)
            {
                flag=0;
                cout<<"\nElement is Found in the list!..\n";
                break;
            }
            else if(key<a[mid])
            {
                high=mid-1;
            }
            else if(key>a[mid])
            {
                low=mid+1;
            }
        }
        if(flag==1)
        {
            cout<<"\nElement not found...\n";
        }
    }
    int fibo_series(int n)
    {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else
            return (fibo_series(n-1)+fibo_series(n-2));
    }
    void fibo_search()
    {
        int key,f,a1,b;
        getdata();
        cout<<"\nEnter Element to be searched : ";
        cin>>key;
        f=n-1;
        int i=1;
        while(1)
        {
            if(fibo_series(i)>n)
                break;
            b=fibo_series(i);
            a1=fibo_series(i-1);
            i++;
        }
        int t2=0,t1=0,flag=1;
        while(1)
        {
            t2=t1;
            t1=f;
            if(f==0)
            {
                if(a[f]==key)
                {
                    flag=1;
                    cout<<"\nElement is found in the the list!..\n";
                    break;
                }
                else
                {
                    flag=0;
                    break;
                }
                
            }
            else if(t2==f)
            {
                flag=0;
                break;
            }
            else if(key<a[f])
            {
                f=f-a1;
                int temp=b;
                b=a1;
                a1=temp-a1;
            }
            else if(key>a[f])
            {
                f=f+a1;
                b=b-a1;
                a1=a1-b;
            }
            else if(key==a[f])
            {
                flag=1;
                cout<<"\nElement is found in the the list!..\n";
                break;
            }
        }
        if(flag==0)
        {
            cout<<"\nElement not found...\n";
        }
    }
};
int main()
{
    ssearch s;
    //s.getdata();
    //s.binary();
    s.fibo_search();
    return 0;
}