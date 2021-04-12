#include<iostream>
#include<vector>
using namespace std;
int MiniSum(vector<vector<int>> nums){
    int ms=nums[0][0],m=nums.size(),n=nums[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(i==0&&j==0)
                dp[i][j]=nums[i][j];
            else if(i==0)
                dp[i][j]=nums[i][j]+dp[i][j-1];
            else if(j==0)
                dp[i][j]=nums[i][j]+dp[i-1][j];
            else
                dp[i][j]=nums[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    return dp[m-1][n-1];
}
int main(int argc, char const *argv[]) {
    vector<vector<int>>nums={{1,3,1},{1,5,1},{4,2,1}};
    cout<<MiniSum(nums)<<endl;
    return 0;
}
