#include <queue>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

const int N=20010;

struct Node{
    int index;
    int op;
    int step;
    int steps;
    };

unordered_set<string> visited;

int main(){
    int s,end;
    cin>>s>>end;
    Node temp={s,1,1,0};
    queue<Node>q;
    q.push(temp);
    int res=0;
    Node t=q.front();

    if(s==end) {cout<<res;return 0;}
    else
    while(!q.empty()){
         t=q.front();
        q.pop();
        string temp="";
        int index=t.index+t.op*t.step;
        res=t.steps+1;
        int op=t.op*(-1);
        int step=t.step*2;

        if(index==end)break;
        if(index<-20000||index>40000)continue;
        temp=to_string(index)+to_string(op)+to_string(step);
        if(visited.find(temp)==visited.end()) {q.push({index,op,step,res});
            visited.insert(temp);
        }
        temp=to_string(t.index)+to_string(11);
          if(visited.find(temp)==visited.end()) {q.push({t.index,1,1,res});
            visited.insert(temp);
          }
    }
    cout<<res<<endl;
    return 0;
}
