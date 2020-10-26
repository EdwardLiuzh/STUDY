#include<iostream>
#include<vector>
using namespace std;
int FindtheDuplicateNumber(vector<int>&nums){
    int fast=0,slow=0;
    do{
        fast=nums[nums[fast]];
        slow=nums[slow];
    }while(fast!=slow);
    slow=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
int main(int argc, char const *argv[]) {
    vector<int> nums={1,3,4,2,2};
    cout<<FindtheDuplicateNumber(nums)<<endl;
    return 0;
}
