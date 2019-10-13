#include<iostream>
using namespace std;
class sparse
{
    int arr[10][3];
    public:
        void getdata()
        {
            cout<<"\nEnter Number of rows, columns and no. of non-zero elements : ";
            cin>>arr[0][0]>>arr[0][1]>>arr[0][2];
            for(int i=1;i<=arr[0][2];i++)
            {
                cout<<"\nEnter Row number : ";
                cin>>arr[i][0];
                cout<<"\nEnter Column number : ";
                cin>>arr[i][1];
                cout<<"\nEnter non-zero element at that position : ";
                cin>>arr[i][2];
            }
        }
        void display()
        {
            cout<<"\n"<<arr[0][0]<<"\t"<<arr[0][1]<<"\t"<<arr[0][2];
            cout<<"\n----------------------\n";
            for(int i=1;i<=arr[0][2];i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<arr[i][j]<<"\t"; 
                }
                cout<<"\n";
            }
        }
        void addition(sparse a,sparse b)
        {
            int i=1,j=1,k=1;
            if(a.arr[0][0]==b.arr[0][0] && a.arr[0][1]==b.arr[0][1])
            {
                arr[0][0]=a.arr[0][0];
                arr[0][1]=a.arr[0][1];
                while(i<=a.arr[0][2] && j<=b.arr[0][2])
                {
                    if(a.arr[i][0]==b.arr[j][0])
                    {
                        if(a.arr[i][1]==b.arr[j][1])
                        {
                            arr[k][0]=a.arr[i][0];
                            arr[k][1]=a.arr[i][1];
                            arr[k][2]=a.arr[i][2] + b.arr[j][2];
                            i++;k++;j++;
                        }
                        else if(a.arr[i][1]<b.arr[j][1])
                        {
                            arr[k][0]=a.arr[i][0];
                            arr[k][1]=a.arr[i][1];
                            arr[k][2]=a.arr[i][2];
                            i++;k++;
                        }
                        else
                        {
                            arr[k][0]=b.arr[j][0];
                            arr[k][1]=b.arr[j][1];
                            arr[k][2]=b.arr[j][2];
                            k++;j++;                            
                        }
                    }
                    else if(a.arr[i][0]<b.arr[j][0])
                    {
                        arr[k][0]=a.arr[i][0];
                        arr[k][1]=a.arr[i][1];
                        arr[k][2]=a.arr[i][2];
                        i++;k++;
                    }
                    else
                    {
                        arr[k][0]=b.arr[j][0];
                        arr[k][1]=b.arr[j][1];
                        arr[k][2]=b.arr[j][2];
                        k++;j++;                         
                    }    
                }
                while(i<=a.arr[0][2])
                {
                    arr[k][0]=a.arr[i][0];
                    arr[k][1]=a.arr[i][1];
                    arr[k][2]=a.arr[i][2];
                    i++;k++;                     
                }
                while(j<=b.arr[0][2])
                {
                    arr[k][0]=b.arr[j][0];
                    arr[k][1]=b.arr[j][1];
                    arr[k][2]=b.arr[j][2];
                    j++;k++;                     
                }
                arr[0][2]=k-1;
            }
            else
            {
                cout<<"\nAddition is not possible\n";
            }
        }
        void s_transpose(sparse a)
        {
            int i,j,k=1;
            arr[0][0]=a.arr[0][1];
            arr[0][1]=a.arr[0][0];
            arr[0][2]=a.arr[0][2];
            for(i=0;i<a.arr[0][1];i++)
            {
                for(j=1;j<=a.arr[0][2];j++)
                {
                    if(i==a.arr[j][1])
                    {
                        arr[k][0]=a.arr[j][1];
                        arr[k][1]=a.arr[j][0];
                        arr[k][2]=a.arr[j][2];
                        k++;
                    }
                }
            }
        }
        void f_transpose(sparse a)
        {
            int r_term[10],r_pos[10];
            int i,k;
            arr[0][0]=a.arr[0][1];
            arr[0][1]=a.arr[0][0];
            arr[0][2]=a.arr[0][2];
            for(i=0;i<a.arr[0][1];i++)
            {
                r_term[i]=0;
            }
            for(i=1;i<=a.arr[0][1];i++)
            {
                r_term[a.arr[i][1]]++;
            }
            r_pos[0]=1;
            for(i=1;i<a.arr[0][1];i++)
            {
                r_pos[i]=r_pos[i-1]+r_term[i-1];
            }
            for(i=1;i<=a.arr[0][2];i++)
            {
                k=r_pos[a.arr[i][1]];
                arr[k][0]=a.arr[i][1];
                arr[k][1]=a.arr[i][0];
                arr[k][2]=a.arr[i][2];
                r_pos[a.arr[i][1]]=k+1;
            }
        }
};
int main()
{
    sparse s1,s2,s3;
    s1.getdata();
    s3.f_transpose(s1);
    s3.display();
    return 0;
}