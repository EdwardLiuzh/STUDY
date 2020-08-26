#include<iostream>
using namespace std;
int main()
{
    int i,j,k=0,n;
    cin>>n;
    for(i=5;i<=n;i=i+5)
    {
        j=i;
        while(j%5==0)
        {
            k++;
            j=j/5;
        }
    }
    cout<<k<<endl;
    return 0;
}
