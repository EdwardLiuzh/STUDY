#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MaxThree(vector<int>&nums){
    if(nums.size()==0)
        return 0;
    int ans=1;
    if(nums.size()<=3){
        for(int i=0;i<nums.size();i++)
            ans*=nums[i];
    }
    sort(nums.begin(),nums.end());
    return max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-3 ]*nums[nums.size()-2]*nums[nums.size()-1]);
}
int main(int argc, char const *argv[]) {
    vector<int>nums={9,2,6,4,5,6};
    cout<<MaxThree(nums)<<endl;
    return 0;
}
