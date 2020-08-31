#include<iostream>
#include<vector>
using namespace std;

void minipath(vector<vector<int>>nums,int x,int y,vector<int>& path,int& sum,int& mini){//回溯
    if(x==nums.size()){
        mini=min(mini,sum);
    }
    else{
        for(int i=y;i<=y+1&&i<nums[x+1].size();i++){
            path.push_back(nums[x][y]);
            sum+=nums[x][y];
            minipath(nums,x+1,i,path,sum,mini);
            sum-=nums[x][y];
            path.pop_back();
        }
    }
}

int minipathrectangle(vector<vector<int>>triangle){
    vector<int>path;
    int mini=10000,sum=0;
    minipath(triangle,0,0,path,sum,mini);
    return mini;
}
/*
int minipathrectangle(vector<vector<int>> &triangle)    //自底向上
{
    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    return triangle[0][0];
}


int minipathrectangle(vector<vector<int>>& triangle) {  //自顶向下，边界条件
        for(int i = 1; i < triangle.size(); i++){
            triangle[i][0] += triangle[i-1][0];
            triangle[i].back() += triangle[i-1].back();
            for(int j = 1; j < triangle[i].size()-1; j++){
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        return *min_element(triangle.back().begin(),triangle.back().end());
}
*/
int main(int argc, char const *argv[]) {
    vector<vector<int>>nums={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minipathrectangle(nums)<<endl;
    return 0;
}
