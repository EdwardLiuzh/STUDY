#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int i=0,flag=1,l=0;
    char t;
    stack<char>s;
    string str;
    cin>>str;
    if(str.length()%2==0){
        while(i<str.length()){
            t=str.c_str()[i];
            if(t=='{'||t=='['||t=='('){
               s.push(t);
            }
            else if(!s.empty()&&t=='}'&&s.top()=='{'){
                s.pop();
            }
            else if(!s.empty()&&t==')'&&s.top()=='('){
                s.pop();
            }
            else if(!s.empty()&&t==']'&&s.top()=='['){
                s.pop();
            }
            else{
                flag=0;
                break;
            }
            i++;
        }
    }
    else{
        flag=0;
    }
    if(!s.empty()){
        flag=0;
    }
    if(flag){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
