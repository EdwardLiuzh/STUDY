#include<iostream>
#include<vector>
using namespace std;
int UniquePaths(int m,int n,int x, int y){
    vector<vector<int>> dp(m,vector<int>(n));
    int i,j;
    if(x==0&&y==0){
        return 0;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==x&&j==y){
                dp[i][j]=0;
            }
            else{
                if(i==0&&j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}


int main(int argc, char const *argv[]) {
    int m,n,x,y;
    cin>>m>>n;
    cin>>x>>y;
    cout<<UniquePaths(m,n,x,y)<<endl;
    return 0;
}
