#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char num[10];
    cin>>num;
    int s=0,l,t,b=1;
    l=strlen(num);
    for(int i=l-1;i>1;i--)
    {
    	if(num[i]>='A'&&num[i]<='F')
    		t=10+num[i]-'A';
    	else
    		t=num[i]-'0';
    	s=s+t*b;
    	b=b*16;
	}
	cout<<s<<endl;
    return 0;
}
