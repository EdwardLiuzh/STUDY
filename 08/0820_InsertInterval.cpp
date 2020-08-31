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

vector<vector<int>> InsertIntervals(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>> merged;
    int i;
    if (intervals.size() == 0) {
        merged.push_back(newInterval);
        return merged;
    }
    for(i=0;i < intervals.size(); ++i){
        if(newInterval[0]<intervals[i][0]){
            intervals.insert(intervals.begin()+i,newInterval);
            break;
        }
    }
    for (i = 0; i < intervals.size(); ++i) {
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
    vector<vector<int>>nums={{1,3},{6,9}};
    vector<int> x={2,5};
    vector<vector<int>>ans=InsertIntervals(nums,x);
    printVectorV(ans);
    return 0;
}
