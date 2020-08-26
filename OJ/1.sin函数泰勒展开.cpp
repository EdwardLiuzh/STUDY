#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.1415926
double sinx(double x)
{
    double sum=0,t=1,u=x;
    int i=1,s=1,f=1;
    while(t>1e-7)
    {
        sum+=s*t*u;
        i+=2;
        s*=-1;
        u*=x*x;
        f*=(i+1)*(i+2);
        t=1.0/f;
        //cout<<sum<<endl;
    }
    return sum;
}
int main()
{
    cout<<sinx(56.0/180*pi)<<endl;
    cout<<sin(56.0/180*pi)<<endl;
    return 0;
}