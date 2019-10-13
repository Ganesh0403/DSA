#include<iostream>
using namespace std;
class ssort
{
    int a[10];
    int n;
    public:
        void getdata()
        {
            cout<<"\nEnter number of terms in array : ";
            cin>>n;
            cout<<"Enter "<<n<<" students marks : \n";
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        }
        void bubble()
        {
            int pass,i;
            for(pass=1;pass<n;pass++)
            {
                for(i=0;i<n-pass;i++)
                {
                    if(a[i]>a[i+1])
                    {
                        int temp;
                        temp=a[i];
                        a[i]=a[i+1];
                        a[i+1]=temp;
                    }
                }
            }
        }
        void display()
        {
            cout<<"\nTop Five Scores are : \n";
            for(int i=n-1;i>=n-5;i--)
            {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        void selection()
        {
            int min,i,j;
            for(i=0;i<n-1;i++)
            {
                min=i;
                for(j=i+1;j<n;j++)
                {
                    if(a[j]<a[min])
                    {
                        min=j;
                    }
                }
                int temp;
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
        void insertion()
        {
            int i,j,temp;
            for(i=1;i<n;i++)
            {
                temp=a[i];
                j=i-1;
                while(j>=0 && a[j]>temp)
                {
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=temp;
            }
        }
};
int main()
{
    ssort s;
    s.getdata();
    //s.selection();
    //s.bubble();
    s.insertion();
    s.display();
    return 0;
}