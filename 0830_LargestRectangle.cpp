#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
int maxarea(vector<int>nums){
    int area=0;
    int sz=nums.size();
    for(int i=0;i<sz;i++){
        int w=1,h=nums[i],j=i,k=i;
        while(--j>=0&&nums[j]>=h){
            w++;
        }
        while (++k<sz&&nums[k]>=h) {
            w++;
        }
        area=max(area,h*w);
    }
    return area;
}
*/

int maxarea(vector<int>nums){
    int area=0;
    nums.push_back(0);
    stack<int> S;
    for(int i=0;i<nums.size();i++){
        while(!S.empty()&&nums[i]<nums[S.top()]){
            int curh=S.top();
            S.pop();
            int tmp=nums[curh]*(!S.empty()?(i-S.top()-1):i);
            area=max(area,tmp);
        }
        S.push(i);
    }
    return area;
}

int main(int argc, char const *argv[]) {
    vector<int>nums={2,1,5,6,2,3};
    cout<<maxarea(nums)<<endl;
    return 0;
}
