#include<iostream>

using namespace std;

pair<long long,long long> findp(long long a[],long long b[],int n){
    if(!a[n]&&!b[n]){
        pair<long long,long long> v=findp(a,b,n-1);
        a[n]=v.first+v.second;
        b[n]=v.first;
    }
    pair<long long,long long> p =make_pair(a[n],b[n]);
    return p;
};

int main(){
    int T;
    static long long p1[90]={0};      //A
    static long long p2[90]={0};      //B
    p1[0]=1;                    //A[0]=1
    p2[0]=0;                    //B[0]=0
    p1[1]=2;
    p2[1]=1;
    cin>>T;
    while(T--){
        long long n,A,B;
        cin>>n;
        pair<long long,long long>u=findp(p1,p2,n);
        A=u.first;
        B=u.second;
        cout<<A+B<<endl;
    }
    return 0;
}
