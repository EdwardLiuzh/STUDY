#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int ans=0;
    int l=0,r=0;
    for(;r<s.size();r++){
        for(int k=l;k<r;k++){
            if(s[r]==s[k]){
                l=k+1;
                break;
            }
        }
        if(r-l+1>ans)
            ans=r-l+1;
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    string s="abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
