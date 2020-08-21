#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	unsigned int n,m,cas;
	n=m=cas=0;
	cin>>n>>m;
	while(n||m){
		long double a=0,t=0;
		long int i;
		for(i=n;i<=m;i++){
			t=1.0/i/i;
			a+=t;
		}
		cout<<"Case "<<++cas<<": "<<setiosflags(ios::fixed)<<setprecision(5)<<a<<endl;
		cin>>n>>m;
	}
	return 0;
}
