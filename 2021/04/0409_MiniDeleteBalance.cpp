#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
int minimumDeletions(string s){
//遍历字符串，统计前面有'b'的'a'的数目
    stack<char> char_stack;
    int cnt=0;
    for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                char_stack.push(s[i]);
            }
            else{
                if(!char_stack.empty()){
                    cnt++;
                    char_stack.pop();
                }
            }
    }
    return cnt;
}
*/
int minimumDeletions(string s){
//动态规划，如果当前s[i]为'b'，只需0~i-1平衡即可，若s[i]为'a',则选择删除前面所有的'b'，或者删除当前'a'
        int n=s.size(),cou=0;
        //std::vector<int> dp(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                //dp[i+1]=dp[i];
                cou++;
            }
            else{
                //dp[i+1]=min(dp[i]+1,cou);
                ans=min(ans+1,cou);
            }
        }
        //return dp[n];
        return ans;
}

int main(int argc, char const *argv[]) {
    string s;
    while(cin>>s){
        cout<<minimumDeletions(s)<<endl;
    }
    return 0;
}
