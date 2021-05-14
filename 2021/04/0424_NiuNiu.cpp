/*
在新的一年，牛牛想跳得更高。牛牛本身可以跳高{h}h米。同时牛牛有{n}n颗跳高弹，使用第{i}i颗跳高弹可以使牛牛跳高高度增加a_ia
i米，且跳高弹的效果是可以叠加的，也就是说如果牛牛使用多颗跳高弹，那么他的跳高高度将会增加这些跳高弹单个效果的和。
每颗跳高弹只能使用一次。
请问牛牛最少需要使用多少个跳高弹，才能让牛牛的高度至少是{u}u米高呢？
第一行三个整数{n},{h},{u}n,h,u。(1\leq n\leq 5*10^5, 1\leq h, u\leq 10^9)(1≤n≤5∗10^5,1≤h,u≤10^9)。
第二行n个整数a_1,...,a_n(1≤a_i≤10^9)
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,h,u;
    cin>>n>>h>>u;
    int ans=0;
    if(n){
        vector<int>hn(n,0);
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            hn[i]=tmp;
        }
        if(h<u){
            int sum=h;
            sort(hn.begin(),hn.end());
            for(int i=n-1;i>=0;i--){
                ans+=1;
                sum+=hn[i];
                if(sum>=u)
                    break;
                }
        }
    }
    cout<<ans<<endl;
    return 0;
}
