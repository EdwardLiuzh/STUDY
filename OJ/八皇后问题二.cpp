#include<iostream>
using namespace std;
void show_chess();
int check(int n);
void put_chess(int n);
int chess[8];

int main()
{
    cout<<"All results are:"<<endl;
    put_chess(0);
    return 0;
}

void put_chess(int n)
{
    int i;
    if(n<8)
    {
        for(i=0;i<8;i++)
        {
            chess[n]=i;
            if(check(n)==1)
            {
                if(n==7)
                    show_chess();
                else
                    put_chess(n+1);
            }
        }
    }
}

int check(int n)
{
    int i;
    for(i=0;i<=n-1;i++)
        if((chess[n]==chess[i]+(n-1))||(chess[n]==chess[i]-(n-i))||(chess[n]==chess[i]))
            return 0;
    return 1;
}

void show_chess()
{
    static int count=0;
    cout<<"***************No."<<++count<<"**************"<<endl;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            if(j==chess[i])
                cout<<"1 ";
            else
                cout<<"0 ";
        cout<<endl;
    }
}