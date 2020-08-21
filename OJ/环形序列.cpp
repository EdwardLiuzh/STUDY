#include<iostream>
#include<string.h>
#define A 100

using namespace std; 
int l_ess(const char* s,int p,int q){
	int n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[(p+i)%n]!=s[(q+i)%n])
			return s[(p+i)%n]<s[(q+i)%n];
		else
			return 0;
}

int main(){
		int T;
		char s[A];
		cin>>T;
		while(T--){
			cin>>s;
			int ans=0,n=strlen(s);
			for(int i=0;i<n;i++)
				if(l_ess(s,i,ans))
					ans=i;
			for(int i=0;i<n;i++)
				cout<<s[(ans+i)%n];
			cout<<endl;
		}
		return 0;
}
