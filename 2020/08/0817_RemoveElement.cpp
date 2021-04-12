#include<iostream>
#include<vector>
using namespace std;
int RemoveElement(vector<int>& nums,int target){
    int n=0,len=nums.size();
    if(len==0)
        return 0;
    for(int i=0;i<len;i++){
        if(nums[i]!=target){
            nums[n++]=nums[i];
        }
    }
    return n;
}

int main(){
    int target;
    vector<int>array={3,2,2,3};
    cin>>target;
    cout<<RemoveElement(array,target)<<endl;
    vector<int>::iterator it;
    for(it=array.begin();it!=array.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
