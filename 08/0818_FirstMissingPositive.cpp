#include<iostream>
#include<vector>
using namespace std;
void adjust(vector<int>& nums, int i){
    if(nums[i]>=1 && nums[i]<nums.size() && nums[nums[i]-1]!=nums[i])
        swap(nums[i],nums[nums[i]-1]);
}
int firstMissingPositive(vector<int>& nums) {
    for(int i=0;i<nums.size();i++)
        adjust(nums,i);
    for(int i=0;i<nums.size();i++){
        if(nums[i]-1!=i){
            return i+1;
        }
    }
    return nums.size()+1;
}
int main(){
    vector<int>nums={7,8,9,11,12};
    cout<<firstMissingPositive(nums)<<endl;
    return 0;
}
