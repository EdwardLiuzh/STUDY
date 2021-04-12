#include<iostream>
#include<vector>
using namespace std;
int LessThankK(vector<int>& nums,int k){
    if(nums.size()==0)
        return 0;
    int ans=0;
    int i=0;
    while(i<=nums.size()-1){
        int tmp=1;
        int j=i;
        for(;j<=nums.size()-1;j++){
            tmp*=nums[j];
            if(tmp<k){
                ans++;
            }else{
                i++;
                break;
            }
            if(j==nums.size()-1)
                i++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int>nums={10,5,2,6};
    cout<<LessThankK(nums,100)<<endl;
    return 0;
}
