#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool ContainsDuplicateII(vector<int>& array,int k){
    unordered_map<int,int>m;
    for(int i=0;i<array.size();i++){
        if(m.count(array[i])&&i-m[array[i]]<=k){
            return true;
        }
        m[array[i]]=i;
    }
    return false;
}
int main(int argc, char const *argv[]) {
    vector<int>s={1,2,3,1};
    if (ContainsDuplicateII(s,2)) {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
