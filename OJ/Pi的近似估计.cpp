#include<iostream>
using namespace std;
int main()
{
    long int i;
    double pi,t;
    int s;
    pi=0;
    t=1;
    i=1;
    s=1;
    while(t>1e-6)
    {
        pi+=s*t;
        i=i+2;
        s=-s;
        t=1.0/i;
        cout<<t<<endl;
    }
    pi=pi*4;
    cout<<"Pi= "<<pi<<endl;
    return 0;
}