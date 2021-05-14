#include<iostream>
#include<vector>
using namespace std;
int movehome(vector<long>& wl,int m,long h){
    int l=wl.size(),cnt=0,left=0,right=0;
    if(l>=m){
        for(int i=0;i<l;i++){
            left=i;
            while(wl[i]<=h&&i<l){
                i++;
            }
            right=i;
            if(right-left>=m){
                cout<<left<<right<<endl;
                return left+1;
            }
        }
    }
    return -1;
}

int main(){
    int n,m;
    long h;
    cin>>n>>m>>h;
    vector<long>wl(n,0);
    for(int i=0;i<n;i++){
        cin>>wl[i];
    }
    //cout<<wl[0]<<endl;
    cout<<movehome(wl,m,h)<<endl;
    return 0;
}
