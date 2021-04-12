#include<iostream>
#include<vector>
using namespace std;
int maxprofit(vector<int>&nums,int fee){
    if(nums.size()<2)
        return 0;
    int ans=0;
    int in_hand=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]<in_hand)
            in_hand=nums[i];
        else if(nums[i]-fee>in_hand){
            ans+=nums[i]-in_hand-fee;
            in_hand=nums[i]-fee;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int>nums={1, 3, 2, 8, 4, 9};
    cout<<maxprofit(nums,2)<<endl;
    return 0;
}
