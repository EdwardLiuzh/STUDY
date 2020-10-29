#include<iostream>
#include<vector>
using namespace std;
int IsToeplitzMatrix(vector<vector<int>>&m){
    int i,j;
    for(i=1;i<m.size();i++){
        for(j=1;j<m[0].size();j++)
            if(m[i][j]!=m[i-1][j-1])
                return 0;
    }
    return 1;
}
int main(int argc, char const *argv[]) {
    std::vector<vector<int>> v={{1,2},{2,2}};
    cout<<IsToeplitzMatrix(v)<<endl;
    return 0;
}
