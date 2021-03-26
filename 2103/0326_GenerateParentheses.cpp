#include<iostream>
#include<vector>
using namespace std;
void func(vector<string>& v, string s, int left, int right, int n){
        if(left>n||right>n||right>left) return ;
        if(left==n && right==n){
            v.push_back(s);
            return ;
        }
        func(v,s+'(',left+1,right,n);
        func(v,s+')',left,right+1,n);
        return ;
}

vector<string> generateParenthesis(int n) {
    std::vector<string> res;
    func(res,"",0,0,n);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string> result=generateParenthesis(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
