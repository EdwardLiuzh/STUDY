#include<iostream>
#include<vector>
using namespace std;
int MaximumSub(vector<int>& array){
    if(array.size()==0){
        return 0;
    }
    int maxa=array[0];
    int mina=array[0];
    int ans=array[0];
    for(int i=1;i<array.size();i++){
        /*
        if(array[i]<0){
            swap(maxa,mina);
        }
        maxa=max(array[i],maxa*array[i]);
        mina=min(array[i],mina*array[i]);
        */
        maxa=max(array[i],max(maxa*array[i],mina*array[i]));
        mina=min(array[i],min(maxa*array[i],mina*array[i]));
        ans=max(ans,maxa);
    }
    return ans;
}
int main(){
    vector<int> a={2,3,-2,4};
    cout<<MaximumSub(a)<<endl;
    return 0;
}
