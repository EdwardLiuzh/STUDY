#include<iostream>
#include<vector>
using namespace std;
/*
void SubsetsCore(vector<int>nums,int start,vector<vector<int>> &ans,vector<int> &tmp){
    ans.push_back(tmp);
    for(int i=start;i<nums.size();i++){
        tmp.push_back(nums[i]);
        SubsetsCore(nums,i+1,ans,tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int>nums){  //回溯
    vector<vector<int>> ans;
    vector<int> tmp;
    SubsetsCore(nums,0,ans,tmp);
    cout<<"Total:"<<ans.size()<<endl;
    return ans;
}

vector<vector<int>> Subsets(vector<int>nums){   //幂集
    vector<vector<int>> ans;
    ans.push_back({});
    vector<int>tmp;
    for(int i=0;i<nums.size();i++){
        int sz=ans.size();
        for(int j=0;j<sz;j++){
            tmp=ans[j];
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
        }
    }
    return ans;
}
*/
vector<vector<int>> Subsets(vector<int>nums){   // 位运算
    vector<vector<int>> ans;
    int sz=nums.size();
    int N=1<<sz;
    for(int i=0;i<N;i++){
        vector<int>tmp;
        for(int j=0;j<sz;j++){
            if(i&(1<<j))
            tmp.push_back(nums[j]);
        }
        ans.push_back(tmp);
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    vector<int> nums={1,2,3};
    vector<vector<int>> res=Subsets(nums);
    vector<vector<int>>::iterator it;
    for(it=res.begin();it!=res.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"**************"<<endl;
    return 0;
}
