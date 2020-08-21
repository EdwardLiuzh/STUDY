#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(int *s,int n){
	if(n>2){
		stack<int>s1;
		int s2[n+1]={0};
		for(int i=0;i<n;i++){
			for(int j=1;j<=s[i];j++){
				if(s2[j]==0){
					s1.push(j);
					s2[j]=1;
				}
			}
			if(s[i]==s1.top()){
				s1.pop();
				s2[s[i]]=2;
			}
			else
				return false;
		}
	}
	return true;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void recurPermutation(int *arr, int n, int i)
{
    if(i==n-1) {
    	if(check(arr,n)){
    		for(int x=0;x<n;x++)
        		cout<<arr[x];
        cout<<',';
		}
    }
    for(int j=i; j<n; j++) {
        swap(arr[i], arr[j]);
        recurPermutation(arr, n, i+1);
        swap(arr[i], arr[j]);
    }
}

int main()
{
	int i,num,p[9];
	cin>>num;
	for(i=0;i<num;i++){
		p[i]=i+1;
	}
	recurPermutation(p,num,0);
	return 0;
}
