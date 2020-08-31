#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int> &nums){         //三指针
    int r=nums.size()-1,l=0,i=0,tmp;
    while(i<=r){
        if(nums[i]==0){
            tmp=nums[i];
            nums[i]=nums[l];
            nums[l]=tmp;
            l++;
            i++;
        }
        else if(nums[i]==2){
            tmp=nums[i];
            nums[i]=nums[r];
            nums[r]=tmp;
            r--;
        }
        else
            i++;
    }
}
int main(int argc, char const *argv[]) {
    vector<int>nums={0,0,1,2,1,2,1,0,0,0,1,2};
    sortcolors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    return 0;
}
