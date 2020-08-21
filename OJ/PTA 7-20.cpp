#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;
stack<char>c;
map<char,int>rule={{'+',1},{'-',1},{'*',2},{'/',2}};

void tra(stack<char>c,char x){
    if(c.empty())
        c.push(x);
    else{
        char top;
        top=c.top();
        if(x==')'){
            while(top!='('){
                    cout<<top<<' ';
                    c.pop();
                  }
            c.pop();
        }
        else{
           if(top=='(')
                c.push(x);
            else if(rule[top]>=rule[x]){
                cout<<top<<' ';
                c.pop();
                tra(c,x);
            }
            else if(rule[top]<rule[x])
                c.push(x);
        }
    }
};

int main(){
    char t;
    int i;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++){
        if(s[i]>='0'||s[i]<='9')
            cout<<s[i]<<" ";
        else
            tra(c,s[i]);
    }
    while(c.size()>2){
        cout<<c.top()<<" ";
        c.pop();
    }
    cout<<c.top();
    return 0;
}
