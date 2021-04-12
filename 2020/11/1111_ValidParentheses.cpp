#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string str){
    int i=0,flag=1,l=0;
    char t;
    stack<char>s;
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
    return flag;
}

int main(int argc, char const *argv[]) {
    string s="(())))";
    if(isValid(s)){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}
