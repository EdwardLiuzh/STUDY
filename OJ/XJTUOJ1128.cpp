#include<iostream>
int main(){
    int a,b,n,i=1;
    std::cin>>n>>a>>b;
    long res=0;
    for(;i<n+1;i++){
        if(i%2){
            res=res+((a&b)<<(i%5));
        }
        else{
            res=res-((a&b)<<(i%5));
        }
    }
    std::cout<<res;
    return 0;
}
