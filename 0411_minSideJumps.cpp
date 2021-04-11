#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
const int inf=10e6;
void jump(int &res,vector<int>& obstacles,int x,int y,int cou){
    if(x==obstacles.size()-1){
        if(cou<res)
            res=cou;
    }else{
        if(obstacles[x+1]==y){
            cou+=1;
            for(int i=1;i<=3;i++){
                if(i!=obstacles[x]&&i!=y)
                    jump(res,obstacles,x,i,cou);
            }
        }else{
            jump(res,obstacles,x+1,y,cou);
        }
    }
}

int minSideJumps(vector<int>& obstacles) {
    int res=inf;
    jump(res,obstacles,0,2,0);
    return res;
}
*/
int minSideJumps(vector<int>& obstacles) {
    vector<vector<int>> dp(obstacles.size(), vector<int>(3, 1e9));
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (obstacles[i] == j + 1) continue;
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j < 3; j++) {
            if (obstacles[i] == j + 1) continue;
            int a = (j + 1) % 3;
            int b = (j + 2) % 3;
            int side = min(dp[i][a], dp[i][b]) + 1;
            dp[i][j] = min(side, dp[i][j]);
        }
    }
    return *min_element(dp.back().begin(), dp.back().end());
}

int main(int argc, char const *argv[]) {
    std::vector<int> v={0,2,1,0,3,0};
    cout<<minSideJumps(v)<<endl;
    return 0;
}
