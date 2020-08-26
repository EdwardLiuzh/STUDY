#include<iostream>
using namespace std;
int main()
{
    int x[8]={0};
    int PresentRowNo,PresentColNo,i,num=0;
    bool flag;
    PresentRowNo=0;
    PresentColNo=-1;
    while(PresentRowNo>=0)
    {
        do{
            PresentColNo++;
            flag=true;
            for(i=0;i<PresentRowNo&&flag;i++)
                if(PresentColNo==x[i]||(x[i]-i)==(PresentColNo-PresentRowNo)||(x[i]+i)==(PresentColNo+PresentRowNo))
                    flag=false;
        }while(PresentColNo<7&&!flag);
        if(flag)
        {
            x[PresentRowNo]=PresentColNo;
            PresentRowNo++;
            PresentColNo=-1;
            if(PresentRowNo==8)
            {
                num++;
                cout<<num<<"-->  ";
                for(i=0;i<8;i++)
                    cout<<"("<<i<<"):"<<x[i]<<" ";
                cout<<endl;
                PresentRowNo--;
                if(PresentRowNo>=0)
                {
                    PresentColNo=x[PresentRowNo];
                    x[PresentRowNo]=0;
                }
                if(PresentColNo=7)
                {
                    PresentRowNo--;
                    if(PresentRowNo>=0)
                    {
                        PresentColNo=x[PresentRowNo];
                        x[PresentRowNo]=0;
                    }
                }
            }
        }
        else
        {
            PresentRowNo--;
            if(PresentRowNo>=0)
            {
                PresentColNo=x[PresentRowNo];
                x[PresentRowNo]=0;
            }
            if(PresentColNo==7)
            {
                PresentColNo--;
                if (PresentRowNo>=0) 
                {
                    PresentColNo=x[PresentRowNo];
                    x[PresentRowNo]=0;
                }
                
            }
        }
        
    }
    return 0;
}