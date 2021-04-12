#include<iostream>
#include<vector>
using namespace std;
void MoveZeros(vector<int>& nums){
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    while(j<nums.size()){
        nums[j++]=0;
    }
}
int main(int argc, char const *argv[]) {
    vector<int>a={0,1,0,3,12};
    MoveZeros(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
