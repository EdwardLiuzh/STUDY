#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    int maxline=1;
    vector<int>line(T,0);
    for(int i=0;i<T;i++){
        cin>>line[i];
        if(line[i]>maxline)
            maxline=line[i];
    }
    vector<int>A(maxline+1,0);
    A[1]=0;
    if(maxline>1){
        for(int i=2;i<maxline+1;i++){
            A[i]=A[i-floor(i/2)]+1;
        }
    }
    for(int i=0;i<T;i++){
        cout<<A[line[i]]+1<<endl;
    }
    return 0;
}
