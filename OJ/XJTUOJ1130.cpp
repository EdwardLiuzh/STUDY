#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    int n,t,l1=0,l2=0;
    std::vector<int>a1;
    std::vector<int>a2;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>t;
        if(t%2){
            a1.push_back(t);
            l1++;
        }
        else{
            a2.push_back(t);
            l2++;
        }
    }
	std::sort(a1.begin(), a1.end());
	std::sort(a2.begin(), a2.end());
	n=0;
	if(l1>l2){
        for(std::vector<int>::iterator it = a1.begin();it<a1.begin()+l1-l2-1;it++)
            n+=*it;
	}
	if(l2>l1){
        for(std::vector<int>::iterator it = a2.begin();it<a2.begin()+l2-l1-1;it++)
            n+=*it;
	}
	std::cout<<n;
	return 0;
}
