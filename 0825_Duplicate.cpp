#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int i=0;
    int flag=0;
    if(nums.size()==0)
        return 0;
    else{
        for(int j=1;j<nums.size();j++){
            //if(nums[j]==nums[i]&&)
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
                flag=0;
            }
            else if(nums[j]==nums[i]&&flag<1){
                i++;
                nums[i]=nums[j];
                flag++;
            }
        }
    }
    return i+1;
}

int main(){
    vector<int>nums={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
    vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
