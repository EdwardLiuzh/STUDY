#include<iostream>
#include<map>
#include<vector>
using namespace std;

void Find(vector<int>& num,int target){
    map<int,int>hash;
    vector<int>res;
    int i;
    for(i=0;i<num.size();i++)
        hash[num[i]]=i;
    for(i=0;i<num.size();i++){
        int e=target-num[i];
        if(hash.end()!=hash.find(e)&&hash[e]!=i){
            res.push_back(i);
            res.push_back(hash[e]);
            break;
        }
    }
    vector<int>::iterator it;
    for(it=res.begin();it!=res.end();it++)
        cout<<*it<<endl;
}

int main(){
    vector<int>num={8,12,32,43,54,23,72,54,122,654,124,65,2};
    int x=10;
    Find(num,x);
    return 0;
}
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res;
        map<int,int> hash_list;
        for(int i=0;i<nums.size();++i)
           hash_list[nums[i]]=i;

        map<int,int>::iterator it;

        for(int i=0;i<nums.size();++i)
        {
            int e=target-nums[i];
            if(hash_list.end()!=hash_list.find(e)&&hash_list[e]!=i)
            {
                res.push_back(i);
                res.push_back(hash_list[e]);
                break;
            }
        }
        return res;
    }
};
int main(){
    vector<int>num={8,12,32,43,54,23,72,54,122,654,124,65,2};
    int x=10;
    Solution f;
    vector<int>res=f.twoSum(num,x);
    vector<int>::iterator it;
    for(it=res.begin();it!=res.end();it++)
        cout<<*it<<endl;
}
*/
