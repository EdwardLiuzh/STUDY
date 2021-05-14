#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

vector<int> findlost(vector<int>&n,const int k){
    vector<int>ans;
    bitset<101> b;
    for(int i=0;i<n.size();i++)
        b.set(n[i]);
    for(int i=1;i<k+1;i++){
        if(!b.test(i)){
            cout<<i<<endl;
            ans.emplace_back(i);
        }

    }
}

int main(int argc, char const *argv[]) {
    vector<int>nums={1,2,4,5,6,7,9,10,13};
    int m=nums.back();
    vector<int>ans=findlost(nums,m);
    return 0;
}
