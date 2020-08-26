#include<iostream>
using namespace std;

struct Stu
{
    char name[8];
    char code[3];
    float sa,sb,sc,sum;
};

int main()
{
    Stu s[3],t;
    for(int i=0;i<3;i++)
    {
        cout<<"Please input No."<<i+1<<"'s data:"<<endl;
        cin>>s[i].name;
        cin>>s[i].code;
        cin>>s[i].sa;
        cin>>s[i].sb;
        cin>>s[i].sc;
        s[i].sum=s[i].sa+s[i].sb+s[i].sc;
    }
    for(int i=0;i<3;i++)
        for(int j=i;j<3;j++)
            if(s[i].sum<s[j].sum)
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
    cout<<"*************ALL DATA:*************"<<endl;
    for(int i=0;i<3;i++)
        cout<<"No."<<i+1<<"   "<<s[i].code<<"   "<<s[i].name<<" "<<s[i].sa<<" "<<s[i].sb<<" "<<s[i].sc<<" "<<s[i].sum<<endl;
    return 0;
}
