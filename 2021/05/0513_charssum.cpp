#include<iostream>
#include<stack>
using namespace std;
char* calc_sum(char* a,char* b){
    //int la=0,lb=0;
    stack<int>qa;
    stack<int>qb;
    stack<int>res;
    int i=0;
    while(a[i]!='\0'){
        qa.push(a[i]-'0');
        i++;
    }
    i=0;
    while(b[i]!='\0'){
        qb.push(b[i]-'0');
        i++;
    }
    i=0;
    while(!qa.empty()&!qb.empty()){
        if(i+qa.top()+qb.top()>=10){
            res.push((i+qa.top()+qb.top())%10);
            i=1;
        }
        else{
            res.push(i+qa.top()+qb.top());
            i=0;
        }
        qa.pop();
        qb.pop();
    }
    while(!qa.empty()){
        if(i&qa.top()+i>=10){
            res.push((qa.top()+i)%10);
            i=1;
        }
        else{
            res.push(qa.top()+i);
            i=0;
        }
        qa.pop();
    }
    while(!qb.empty()){
        if(i&qb.top()+i>=10){
            res.push((qb.top()+i)%10);
            i=1;
        }
        else{
            res.push(qb.top()+i);
            i=0;
        }
        qb.pop();
    }
    if(i){
        res.push(1);
    }
    static char r[101];
    i=0;
    while(!res.empty()){
        r[i++]=res.top()+'0';
        res.pop();
    }
    return r;
}

int main(int argc, char const *argv[]) {
    char *a="123544563546534635463542342354235342524352435312432154444444444444444444444544444441344";
    char *b="45678543255555555551231111111111114365463754765486456364564877689576876";
    char *c;
    c=calc_sum(a,b);
    for(int i=0;*(c+i)!='\0';++i)
        cout<<*(c+i)<<endl;
    /* code */
    return 0;
}
