#include<iostream>
#include<vector>
using namespace std;
void CombinationSunCore(vector<vector<int>>&ans,vector<int>&nums,int target,vector<int>&tmp,int sum,int begin){
    if(sum==target)
        ans.push_back(tmp);
    else{
        for(int i=begin;i<nums.size();i++){
            if(sum+nums[i]<=target){
                tmp.push_back(nums[i]);
                CombinationSunCore(ans,nums,target,tmp,sum+nums[i],i);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<int>> CombinationSum(vector<int> nums, int target){
    vector<vector<int>> ans;
    vector<int>tmp;
    CombinationSunCore(ans,nums,target,tmp,0,0);
    return ans;
}



int main(){
    vector<int>nums={2,3,6,7};
    int target;
    cin>>target;
    vector<vector<int>> s=CombinationSum(nums,target);
    vector<vector<int>>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
