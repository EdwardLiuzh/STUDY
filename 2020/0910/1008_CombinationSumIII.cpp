#include<iostream>
#include<vector>
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
vector<vector<int>> FindCombinationSum(int k,int n){
    int nums[9] = { 1,2,3,4,5,6,7,8,9 };
       vector<vector<int> > res;
       vector<int> temp;
       int cnt, sum;
       for (int i = 1; i < (1 << 9); i++) {
           sum = 0;
           cnt = 0;
           for (int j = 0; j < 9; j++) {
               if (i >> j & 1) {
                   cnt++;
                   sum += nums[j];
               }
           }
           if (sum == n && cnt == k) {
               temp.clear();
               for (int j = 0; j < 9; j++) {
                   if (i >> j & 1) temp.emplace_back(nums[j]);
               }
               res.emplace_back(temp);
           }
       }
       return res;
}

int main(int argc, char const *argv[]) {
    int k=3,n=9;
    printVectorV(FindCombinationSum(k,n));
    return 0;
}
