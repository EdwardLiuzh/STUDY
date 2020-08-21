#include<iostream>
#include<string.h>
#define M 20
using namespace std;

int main(){
	int T,tot=0,temp=0;
	cin>>T;
	while(T--){
		char s[M];
		cin>>s;
		int n=strlen(s);
		if(s[0]=='O')
			temp=tot=1;
		for(int i=1;i<n;i++){
			if(s[i]=='O'){
				if(s[i-1]=='O')
					temp++;
				else
					temp=1;
			}
			else
				temp=0;
			tot+=temp;
		}
		cout<<tot<<endl;
	}
	return 0;
}
