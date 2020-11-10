#include<iostream>
#include<vector>
using namespace std;
vector<int> SquaresortedAay(vector<int>& A){
    vector<int> ans(A.size(),0);
    if(A.size()){
        int i=0,j=A.size()-1,k=A.size()-1;
        while(i<=j){
            if(A[i]*A[i]>A[j]*A[j]){
                ans[k--]=A[i]*A[i];
                i++;
            }
            else{
                ans[k--]=A[j]*A[j];
                j--;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> v={-7,-3,2,3,11};
    vector<int> ans=SquaresortedAay(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
