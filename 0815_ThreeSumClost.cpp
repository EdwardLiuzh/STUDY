#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ThreeSumClost(vector<int>& nums,int target){
    int res=0,j,k,sum,dif=1000;
    if(nums.size()>2){
        sort(nums.begin(),nums.end());
    }
    for(int i=0;i<nums.size();i++){
        for(j=i+1,k=nums.size()-1;j<k;){
            sum=nums[i]+nums[j]+nums[k];
            if(abs(sum-target)<dif){
                res=sum;
                dif=abs(sum-target);
            }
            if(sum==target)
                return res;
            else if(sum<target)
                j++;
            else if(sum>target)
                k--;
        }
    }
    return res;
}

int main(){
    int target;
    vector<int>nums={-1, 2, 1, -4};
    cin>>target;
    cout<<ThreeSumClost(nums,target)<<endl;
    return 0;
}
