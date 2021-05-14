#include<iostream>
#include<vector>
using namespace std;
void fun(int x,int a,int b,int k,int ans,vector<int>& s){
    if(k==0){
        s.emplace_back(ans);
    }else{
        if(x==0){
            fun(b,a,b,k-1,ans,s);
        }else{
            fun(x+b,a,b,k-1,ans,s);
        }
        if(x>a){
            fun(x-a,a,b,k-1,ans+x,s);
        }
        else{
            fun(0,a,b,k-1,ans+x,s);
        }
    }
}

int maxfun(int x,int a,int b, int n){
    vector<int>res;
    int ans;
    fun(x,a,b,n,0,res);
    if(res.size()!=0){
        ans=res[0];
        for(int i=1;i<res.size();i++)
            if(ans<res[i])
                ans=res[i];
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int t=0;
    cin>>t;
    vector<int>x(t,0);
    vector<int>a(t,0);
    vector<int>b(t,0);
    vector<int>n(t,0);
    for(int i=0;i<t;i++)
        cin>>x[i]>>a[i]>>b[i]>>n[i];
    for(int i=0;i<t;i++)
        cout<<maxfun(x[i],a[i],b[i],n[i])<<endl;
    return 0;
}
