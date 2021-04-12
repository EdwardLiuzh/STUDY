#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {     //动态法，每一位查找左最大与右最大的最小值减去本值为该位可存储的雨水量
    int res=0,n=height.size();
    vector<int>MaxL(n),MaxR(n);
    MaxL[0]=height[0];
    MaxR[n-1]=height[n-1];
    for(int i=1;i<n;i++){
        MaxL[i]=max(height[i],MaxL[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        MaxR[i]=max(height[i],MaxR[i+1]);
    }
    for(int i=0;i<n;i++){
        res+=min(MaxL[i],MaxR[i])-height[i];
    }
    return res;
}
/*
int trap(vector<int>& height) {      //双指针法
    int res=0,MaxL=0,MaxR=0,left=0,right=height.size()-1;
    while(left<right){
        if(height[left]<=height[right]){       //左边决定
            if(height[left]<=MaxL){
                res+=MaxL-height[left];
            }
            else{
                MaxL=height[left];
            }
            left++;
        }
        else{                                   //右边决定
            if(height[right]<=MaxR){
                res+=MaxR-height[right];
            }
            else{
                MaxR=height[right];
            }
            right--;
        }
    }
    return res;
}
*/
int main(){
    vector<int>nums={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(nums)<<endl;
    return 0;
}
