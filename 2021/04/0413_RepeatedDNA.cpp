#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    if(s.size()<10) return {};
    std::vector<string> r;
    map<string,int>mp;
    for(int i=0;i<=s.size()-10;i++){
        mp[s.substr(i,10)]++;
    }
    for(auto it:mp)
        if(it.second>1)
            r.emplace_back(it.first);
    return r;
}

int main(int argc, char const *argv[]) {
    string s;
    while(cin>>s){
        vector<string>ans=findRepeatedDnaSequences(s);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
