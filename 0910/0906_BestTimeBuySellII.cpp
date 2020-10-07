#include<iostream>
#include<vector>
using namespace std;
/*
int BestTimeBuySellII(vector<int>& nums){   //贪心
    int best=0;
    if(nums.size()){
        for(int i=1;i<nums.size();i++){
            best+=max(0,nums[i]-nums[i-1]);
        }
    }
    return best;
}
*/

int BestTimeBuySellII(vector<int>& nums){   //动态规划
    int best=0;
    if(nums.size()){
        int buy=(-nums[0]);
        int prebuy=buy,presell=best;
        for(int i=1;i<nums.size();i++){
            best=max(presell,prebuy+nums[i]);
            buy=max(prebuy,presell-nums[i]);
            prebuy=buy;
            presell=best;
        }
    }
    return best;
}

int main(int argc, char const *argv[]) {
    vector<int>nums={7,1,5,3,6,4};
    cout<<BestTimeBuySellII(nums)<<endl;
    return 0;
}
