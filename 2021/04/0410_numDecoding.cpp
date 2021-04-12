#include<iostream>
#include<string>
#include<vector>
using namespace std;
int StringnumDecoding(string s){
    int n=s.size();
    if(n==0||(n>0&&s[0]=='0'))  return 0;
    if(n==1)    return 1;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(s[i]!='0'){
            dp[i+1]=dp[i];
        }else{
            dp[i+1]=0;
        }
            if((i>0)&&((s[i-1]=='1')||(s[i-1]=='2'&&s[i]<='6'))){
                dp[i+1]+=dp[i-1];
            }
        }
    return dp[n];
}

/*
int numDecodings(string s) {
    int n=s.size();
    if(n==0||(n>0&&s[0]=='0'))  return 0;
    if(n==1)    return 1;
    int pre=1,cur=1;
    for(int i=0;i<n;i++){
        int tmp=0;
        if(s[i]!='0')   tmp=cur;
        if(i>0&&((s[i-1]=='1')||(s[i-1]=='2'&&s[i]<='6'))){
            tmp+=pre;
        }
        pre=cur;
        cur=tmp;
    }
    return cur;
}
*/
int main(int argc, char const *argv[]) {
    string s;
    while(cin>>s){
        cout<<endl<<StringnumDecoding(s)<<endl;
    }
    return 0;
}
