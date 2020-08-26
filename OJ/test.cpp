#include<iostream>
using namespace std;
int main()
{
    int i,j,t,N=4;
    int each[N]={2,3,6,5};
    for(i=0;i<N-1;i++)                             //each按从大到小排列
        for(j=0;j<N-1-i;j++)
            if(each[j]>each[j+1])
            {
                t=each[j];
                each[j]=each[j+1];
                each[j+1]=t;
            }
    cout<<each[2];
    return 0;
}