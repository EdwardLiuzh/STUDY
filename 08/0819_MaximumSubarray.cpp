#include<iostream>
#include<vector>
using namespace std;
int MaxSub(vector<int>nums){            //动态规划 sum[i]=max(sum[i-1]+a[i],a[i])
    int sum=0,maxn=nums[0];
    for(int i=0;i<nums.size();i++){
        sum=max(nums[i],sum+nums[i]);   //以i位置为终止的最大子序列和
        maxn=max(maxn,sum);             //迄今到i位置为止，最大子序列和
    }
    return maxn;
}
/*
int MaxSub(vector<int>nums){
    int sum=0,max=nums[0];
    for(int i=0;i<nums.size();i++){
        if(sum>0){
            sum+=nums[i];
        }
        else{               //sum小于0时，后面子序列不包括当前序列
            sum=nums[i];
        }
        if(max<sum)
            max=sum;
    }
    return max;

}
*/
int main(){
    vector<int>array={3,2,-9,-1,5,-2,1,2,3};
    vector<int>nums={-5,-4,-1,-2};
    cout<<MaxSub(array)<<endl;
    cout<<MaxSub(nums)<<endl;
    return 0;
}
