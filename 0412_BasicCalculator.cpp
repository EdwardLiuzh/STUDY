#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int func(string s){
    int res=0,n=0;
    char sign='+';
    stack<int>nums;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'){
            n=n*10-'0'+s[i];
        }
        if((s[i]<'0' && s[i]!= ' ')||(i==s.size()-1)){
            if(sign=='+'){
                nums.push(n);
            }
            if(sign=='-'){
                nums.push(-n);
            }
            if(sign=='*'){
                int tmp=nums.top()*n;
                nums.pop();
                nums.push(tmp);
            }
            if(sign=='/'){
                int tmp=nums.top()/n;
                nums.pop();
                nums.push(tmp);
            }
            sign=s[i];
            n=0;
        }
    }
    for(;!nums.empty();nums.pop()){
        res += nums.top();
    }
    return res;
}

int main(int argc, char const *argv[]) {
    string str1;
    while(cin>>str1){
        cout<<func(str1)<<endl;
    }
    return 0;
}
