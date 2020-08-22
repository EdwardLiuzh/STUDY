#include<iostream>
#include<vector>
using namespace std;
/*
void PathCount(int& paths,int M,int N,int x,int y){ //递归
    if(x==M-1&&y==N-1)
        paths++;
    else{
        if(x+1<M){
            PathCount(paths,M,N,x+1,y);
        }
        if(y+1<N){
            PathCount(paths,M,N,x,y+1);
        }
    }
}

int UniquePath(int m,int n){
    int paths=0;
    PathCount(paths,m,n,0,0);
    return paths;
}
*/
int UniquePath(int m,int n){        //动态规划
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][1]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        if(i==0||j==0)
            dp[i][j]=1;
        else
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    return dp[m-1][n-1];
}
int main(int argc, char const *argv[]) {
    int m,n;
    cin>>m>>n;
    cout<<UniquePath(m,n)<<endl;
    return 0;
}
