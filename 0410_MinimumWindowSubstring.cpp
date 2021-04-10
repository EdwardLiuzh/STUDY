#include<iostream>
#include<vector>
#include <string>
using namespace std;
void findIPAddressses(const string& s,int f,int count,vector<int> &l,vector<string> &res){
    if(count==4){
        if(f==s.size()){
            string tmp;
            for(int i=0;i<l.size();i++){
                tmp+=to_string(l[i]);
                if(i!=l.size()-1)
                    tmp+=".";
            }
            //cout<<tmp<<endl;
            res.push_back(move(tmp));
        }
        return ;
    }
    if(f==s.size())
        return ;
    if(s[f]=='0'){
        l[count]=0;
        findIPAddressses(s,f+1,count+1,l,res);
    }
    int add=0;
    for(int i=f;i<s.size();i++){
        add=(s[i]-'0')+10*add;
        if(add>0&&add<=255){
            l[count]=add;
            findIPAddressses(s,i+1,count+1,l,res);
        }else{
            break;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    //if(s.size()<4||s.size()>12) return null;
    std::vector<string> v;
    std::vector<int> w(4,0);
    findIPAddressses(s,0,0,w,v);
    return v;
}



int main(int argc, char const *argv[]) {
    string s;
    while(cin>>s){
        vector<string>res=restoreIpAddresses(s);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<endl;
        }
    }
    return 0;
}
