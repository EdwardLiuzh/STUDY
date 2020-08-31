#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printVectorV(vector<vector<int>>nums){
    vector<vector<int>>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"**************"<<endl;
}
/*
void MergeIntervals(vector<vector<int>>&nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>::iterator it;
    for(it=nums.begin();it+1!=nums.end();){
        if((*it)[1]>=(*(it+1))[0]){
            vector<int>tmp={(*it)[0],(*(it+1))[1]};
            nums.erase(it,it+2);
            nums.insert(it,tmp);
        }
        else{
            it++;
        }
        printVectorV(nums);
    }
}
vector<vector<int>> MergeIntervals(vector<vector<int>>nums){
    vector<vector<int>> res;
    if(nums.size()!=0){
        sort(nums.begin(),nums.end());
        int L=nums[0][0],R=nums[0][1],n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n-1&&R<nums[i+1][0]){
                res.push_back({L,R});
                L=nums[i+1][0];
                R=nums[i+1][1];
            }
            else if(i==n-1){
                res.push_back({L,R});
            }
            else if(R>=nums[i+1][0]&&R<=nums[i+1][1]){
                R=nums[i+1][1];
            }
        }
    }
    return res;
}
*/
vector<vector<int>> MergeIntervals(vector<vector<int>>intervals) {
    if (intervals.size() == 0) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({L, R});
        }
        else {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}

int main(int argc, char const *argv[]) {
    vector<vector<int>>nums={{1,2},{3,5},{4,8},{6,9},{10,15}};
    vector<vector<int>>ans=MergeIntervals(nums);
    printVectorV(ans);
    return 0;
}
