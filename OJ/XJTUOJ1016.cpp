#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,i,j,t;
	cin>>n;
	vector<int>a;
	vector<int>a1;
	vector<int>a2;
	for(i=0;i<n;i++){
		cin>>t;
		if(t%2!=0){
			a1.push_back(t);
			a.push_back(1);
		}
		else{
			a2.push_back(t);
			a.push_back(0);
		}
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	i=0;
	j=0;
	vector<int>::iterator it = a.begin();
	for (; it < a.end(); it++)
    {
        if(*it==1){
        	*it=a1[i++];
		}
		else{
			*it=a2[j++];
		}
    }
    for (it = a.begin(); it < a.end()-1; it++)
    {
        cout << *it << " ";
    }
    cout<<*it;
    return 0;
}
