#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char sen[100];
    int coud=0,couz=0,f=0,a[26]={0},top;
    cin>>sen;
    if(sen[0])
        for(int i=0;i<strlen(sen);i++)
        {
            if(sen[i]!=' ')
            {
                couz++;
                if(sen[i]>='A'&&sen[i]<='Z')
                {
                    sen[i]=sen[i]-'A'+'a';
                    coud++;
                }
                f=sen[i]-'a';
                a[f]++;
            }
        }
    cout<<"字母个数:	"<<couz<<endl;
    cout<<"单词个数：   "<<coud<<endl;
    top=a[0];
    for(int i=0;i<26;i++)
    {
        if(top<a[i])
            top=a[i];
    }
    cout<<"最多的字母： ";
    for(int i=0;i<26;i++)
    {
        if(top==a[i])
        { 
            cout<<char(i+'a')<<'\t';
        }
    }
    cout<<endl;
    cout<<"出现的次数： "<<top<<endl;
    return 0;

}
