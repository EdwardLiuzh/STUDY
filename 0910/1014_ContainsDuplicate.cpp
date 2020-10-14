#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int ContainDuplicate(vector<int> nums){
    unordered_set<int> u;
    for (int i=0;i<nums.size();i++)
        u.insert(nums[i]);

    if(nums.size() == u.size())
        return false;
    else
        return true;
}

int main(int argc, char const *argv[]) {
    vector<int>a={1,2,3,4,1};
    cout<<ContainDuplicate(a)<<endl;
    return 0;
}
