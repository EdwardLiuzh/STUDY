#include<iostream>
#include<string.h>
using namespace std;
char *dele(char *str,char *s,int l1,int l2)
{
	int i=0,f=0,j=0;
	char* res=NULL;
	while(*(str+i+j))
	{
        cout<<"start no."<<i+1<<endl;
		if(*(str+i)==*s)
		{
            for(j=0;j<l2;)
            	if(*(str+i+j)==*(s+j))
            		j++;
				else
					break;
		}
		if(j==l2)
			i+=l2;
		else
		{
			*(res+f)=*(str+i);
			i++;
			f++;
		}
        j=0;
	}
	if(*res)
		return res;
	else
		return NULL;
}
int main()
{
	char str[100]={"dddlsfsdf"},s[100]={"dd"},*r;
	r=dele(str,s,strlen(str),strlen(s));
    if(*r)
	    for(int i=0;i<strlen(r);i++) 
		    cout<<*(r+i)<<endl;
    else
        cout<<"NONE DATA!!!"<<endl;
	return 0;
}
    
