#include<iostream>
using namespace std;
class quick
{
    public:
    int a[10];
    int n;
    void getdata()
    {
        cout<<"\nEnter No. of terms in array : ";
        cin>>n;
        cout<<"\nEnter "<<n<<" Students marks : \n";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void display()
    {
        cout<<"\nTop Five Scores are : \n";
        for(int i=n-1;i>n-6;i--)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    void sort(int a,int b)
    {
        int j;
        if(a<b)
        {
            j=partition(a,b+1);
            sort(a,j-1);
            sort(j+1,b);
        }
    }
    int partition(int m,int n)
    {
        int i=m,j=n;
        float pivot=a[m];
        do
        {
            do
            {
                i++;
            } while (a[i]<pivot);
            do
            {
                j--;
            } while (a[j]>pivot);
            if(i<j)
            {
                swap(i,j);
            }
        }while(i<j);
        swap(m,j);
        return j;
    }
    void swap(int i,int j)
    {
        int temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
};
int main()
{
    quick q;
    q.getdata();
    q.sort(0,q.n-1);
    q.display();
    return 0;
}