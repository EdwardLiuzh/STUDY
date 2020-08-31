#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> FourSum(vector<int>nums,int target){
    vector<vector<int>> ans;
    int len=nums.size();
    if(len<4)
        return ans;
    int a,b;
    sort(nums.begin(),nums.end());
    for(a=0;a<len-4;a++){
        if(nums[a]>target)
            break;
        if(a>0&&nums[a]==nums[a-1])
            continue;
        for(b=a+1;b<len-3;b++){
            if(b>a+1&&nums[b]==nums[b-1])
                continue;
            int i=b+1,j=len-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[a]+nums[b]==target){
                    ans.push_back({nums[a],nums[b],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[i+1])
                        i++;
                    while(i<j&&nums[j]==nums[j-1])
                        j--;
                    i++;
                    j--;
                }
                else if(nums[i]+nums[j]+nums[a]+nums[b]>target)
                    j--;
                else if(nums[i]+nums[j]+nums[a]+nums[b]<target)
                    i++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int>nums={-1, 0, 1, 2, -1, -4, 2};
    int target;
    cin>>target;
    vector<vector<int>> s=FourSum(nums,target);
    vector<vector<int>>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
