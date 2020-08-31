#include<iostream>
#include<vector>
using namespace std;
void SubsetsIICore(vector<int>nums,int start,vector<vector<int>>& ans,vector<int>& tmp){
    ans.push_back(tmp);
    for(int i=start;i<nums.size();i++){
        if(i>start&&nums[i]==nums[i-1])
            continue;
        tmp.push_back(nums[i]);
        SubsetsIICore(nums,i+1,ans,tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> SubsetsII(vector<int>nums){
    vector<vector<int>> ans;
    vector<int>tmp;
    SubsetsIICore(nums,0,ans,tmp);
    cout<<"Total:"<<ans.size()<<endl;
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums={1,2,2};
    vector<vector<int>> res=SubsetsII(nums);
    vector<vector<int>>::iterator it;
    for(it=res.begin();it!=res.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"**************"<<endl;
    return 0;
}
