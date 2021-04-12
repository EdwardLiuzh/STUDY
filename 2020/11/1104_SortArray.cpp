#include<iostream>
#include<vector>
using namespace std;
vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> ans(A.size());
    int j=1,o=0;
    for(int i=0;i<A.size();i++){
        if(A[i]%2==0){
            ans[o]=A[i];
            o+=2;
        }
        else{
            ans[j]=A[i];
            j+=2;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> a={4,2,5,7};
    vector<int> ans=sortArrayByParityII(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
