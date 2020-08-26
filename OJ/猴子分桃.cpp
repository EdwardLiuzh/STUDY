#include<iostream> 
using namespace std;
int main()
{
    int res,pre,pea,cou;//residual present peachnumber count
    for(res=4;res<10000;res+=4)
    {
        cou=0;
        pre=res;
        while(cou<=4)
        {
            pea=pre/4*5+1;
            cou++;
            pre=pea;
            if(pre%4!=0) break;
        }
        if(cou==5)
        {
            cout<<pea<<endl;
            break;
        }
    }
    return 0;
}