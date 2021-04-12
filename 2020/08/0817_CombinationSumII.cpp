#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void CombinationSunCore(vector<vector<int>>&ans,vector<int>&nums,int target,vector<int>&tmp,int sum,int begin){
    if(sum==target)
        ans.push_back(tmp);
    else{
        for(int i=begin;i<nums.size();i++){
            if(sum+nums[i]<=target){
                if(i!=begin&&nums[i]==nums[i-1])
                    continue;
                tmp.push_back(nums[i]);
                CombinationSunCore(ans,nums,target,tmp,sum+nums[i],i+1);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<int>> CombinationSum(vector<int> nums, int target){
    vector<vector<int>> ans;
    vector<int>tmp;
    sort(nums.begin(),nums.end());
    CombinationSunCore(ans,nums,target,tmp,0,0);
    return ans;
}



int main(){
    vector<int>nums={10,1,2,7,6,1,5};
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
