#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int n=nums.size()*nums[0].size();
    vector<vector<int>>ans;
    if(n/r!=c)
        return nums;
    else{
        vector<int> list;
        int nu=1;
        for(vector<vector<int>>::iterator it=nums.begin();it!=nums.end();it++){
            for(int i=0;i<(*it).size();i++){
                list.push_back((*it)[i]);
                if(nu++/c==1){
                    ans.push_back(list);
                    list.clear();
                }
            }
            cout<<endl;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    vector<vector<int>> m={{1,2},{3,4}};
    for(vector<vector<int>>::iterator it=m.begin();it!=m.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<'\t';
        }
        cout<<endl;
    }
    vector<vector<int>> ans=matrixReshape(m,1,3);
    for(vector<vector<int>>::iterator it=ans.begin();it!=ans.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<'\t';
        }
        cout<<endl;
    }

    return 0;
}
