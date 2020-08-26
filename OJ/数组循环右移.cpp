#include<iostream>
using namespace std;
int main()
{
    int N,a[10]={0,1,2,3,4,5,6,7,8,9},pre,n,tem;
    cin>>N;
    if(10%N==0)
    {
        for(int i=0;i<N;i++)
        {
            pre=a[i];
            tem=0; 
            n=i;
            for(int j=0;j<10/N;j++)
            {
                tem=pre;
                pre=a[(n+N)%10];
                a[(n+N)%10]=tem;
                n=(n+N)%10;
            }
        }

    }
    else
    {
    	tem=0;
    	n=0;
        pre=a[0];
        for(int i=0;i<10;i++)
        {
            tem=pre;
            pre=a[(n+N)%10];
            a[(n+N)%10]=tem;
            n=(n+N)%10;
        }
    }
    for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
    return 0;
}
