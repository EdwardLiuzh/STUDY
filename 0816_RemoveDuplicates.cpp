#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int i=0;
    if(nums.size()==0)
        return 0;
    else{
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
    }
    return i+1;
}
/*
int removeDuplicates(vector<int>& nums){
    vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();){
        if(it+1!=nums.end()&&(*it==*(it+1)))
            nums.erase(it+1);
        else
            it++;
    }
    return nums.size();
}
*/
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
