#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
int KdiffPairs(vector<int>&nums,int k){
    int ans=0;
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    for (auto it=m.begin();it!=m.end();it++){
        if(k==0){
            if((*it).second>=2)
                ans++;
        }else{
            if(m.count((*it).first+k))
                ans++;
        }
    }
    return ans;
}
*/
int KdiffPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;

        if(k < 0)//好坑不止有-1 还有-157
            return 0;

        if(k == 0) {
        //当k=0时，其实就是找数组中有没有重复元素 且重复元素个数大于等于2时 我们都视为只有1组K-diff
            for(int i = 0; i < nums.size(); i++) {
            ++map[nums[i]];
            if(map[nums[i]] == 2)
                count++;
            }
            return count;
        }
        //k为其他数字时，先构建hash表，将value初始化为0.
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = 0;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(nums[i] - k) != map.end()) {
            //若nums[i]-k存在于数组中。注：nums[i]-k必然小于nums[i] diff数对为{num[i], nums[i]-k}
                if(map[nums[i]] == 0 ) {//已经存在的diff数对中还没有出现过nums[i]为第一个数
                    count++;//数对数量+1
                    map[nums[i]] = 1;//给nums[i]标记，表示已经有nums[i]开头的数对了，后面不再考虑
                }
            }
        }
        return count;
    }

int main(int argc, char const *argv[]) {
    std::vector<int> v={1,1,2,3,4,1,5};
    cout<<KdiffPairs(v,0)<<endl;
    return 0;
}
