#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
/*
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;
    for(string &s:strs){
        string key=s;
        sort(key.begin(),key.end());
        mp[key].emplace_back(s);
    }
    vector<vector<string>> ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.emplace_back(it->second);
    }
    return ans;
}*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res ;
    map<string, vector<string>> mp ;
    // 统计string的各字母频次,以频次为key直接加入队列
    for (auto s : strs) {
        string sts = string(26, '0') ;
        for (auto c : s)
            ++ sts[c-'a'] ;
        mp[sts].emplace_back (s) ;
    }
    for (auto e : mp)
        res.emplace_back(e.second) ;
    return res ;
}
int main(int argc, char const *argv[]) {
    vector<string> ss={ "eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<string> > ans=groupAnagrams(ss);
    for(auto it=ans.begin();it!=ans.end();it++){
        for(auto ir=(*it).begin();ir!=(*it).end();ir++){
            cout<<*ir<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
