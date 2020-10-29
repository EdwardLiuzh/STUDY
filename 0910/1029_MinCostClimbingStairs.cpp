#include<vector>
#include<iostream>
using namespace std;
int mincost(vector<int>&costs){
    int ans=0;
    vector<int>dp(costs.size());
    dp[0]=costs[0];
    dp[1]=costs[1];
    for(int i=2;i<costs.size();i++)
        dp[i]=costs[i]+min(dp[i-1],dp[i-2]);
    ans=min(dp[costs.size()-1],dp[costs.size()-2]);
    return ans;
}
int main(int argc, char const *argv[]) {
    vector<int>costs={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<mincost(costs)<<endl;
    return 0;
}
