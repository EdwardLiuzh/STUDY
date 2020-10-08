#include<iostream>
#include<vector>
using namespace std;
int FindMiniSizeSub(vector<int>& nums,int s){
    if(nums.size()==0)
        return 0;
    else if(nums.size()==1){
        if(nums[0]>=s)
            return 1;
        else
            return 0;
    }
    int a=0,b=0,flag=0,ans=nums.size(),tmp=0;
    while(b<nums.size()){
        tmp+=nums[b];
        while(tmp>=s){
            ans=min(ans,b-a+1);
            flag=1;
            tmp-=nums[a++];
        }
        b++;
    }
    if(flag)
        return ans;
    else
        return 0;
}

int main(int argc, char const *argv[]) {
    vector<int>a={2,3,1,2,4,3};
    int s=7;
    cout<<FindMiniSizeSub(a,s)<<endl;
    return 0;
}
