#include<iostream>
#include<vector>
using namespace std;
int BestTimeBuySell(vector < int >& nums){
    int best = 0;
    if(nums.size()){
        nums.push_back(-1);
        vector < int > S;
        for(int i = 0;i < nums.size();i ++){
            while(!S.empty()&&S.back() > nums[i]){
                best = max(best,S.back()-S.front());
                S.pop_back();
            }
            S.push_back(nums[i]);
        }
    }
    return best;
}

/*
int BestTimeBuySell(vector < int >& nums){
    int best = 0;
    if(nums.size() <= 1)
        return best;

    int minb = nums[0];
    if(nums.size() > 1){
        for(int i = 1;i < nums.size();i ++){
            best = max(best,nums[i]-minb);
            minb = min(nums[i],minb);
        }
    }
    return best;
}
*/
int main(int argc, char const *argv[]) {
    vector < int > nums = {7,1,5,3,6,4};
    cout << BestTimeBuySell(nums) << endl;
    return 0;
}
