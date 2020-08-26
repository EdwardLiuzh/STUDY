#include<iostream>
using namespace std;
const int N=8;
int c[N][N];
unsigned int mincost=65535;
int task[N],temp[N],worker[N];

void plan(int k,unsigned int cost)
{
    int i;
    if(k==N&&cost<mincost)
    {
        mincost=cost;
        for(i=0;i<N;i++)
            temp[i]=task[i];
    }
    else
    {
        for(i=0;i<N;i++)
            if(worker[i]==0&&cost+c[k][i]<mincost)
            {
                worker[i]=1;
                task[k]=i;
                plan(k+1,cost+c[k][i]);
                worker[i]=0;
                task[k]=0;
            }
    }
    
}

int main()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        worker[i]=0;
        temp[i]=0;
        task[i]=0;
        for(j=0;j<N;j++)
            cin>>c[i][j];
    }
    plan(0,0);
    cout<<"minist cost is:  "<<mincost<<endl;
    for(i=0;i<N;i++)
        cout<<i<<"is assigned to Worker "<<temp[i]<<endl;
    return 0;
}