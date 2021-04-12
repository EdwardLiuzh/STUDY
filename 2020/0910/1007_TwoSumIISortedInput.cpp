#include<iostream>
#include<vector>
using namespace std;
vector<int> FindSum(vector<int>& array,int target){
    vector<int>ans={0,0};
    if(array.size()==0){
        return ans;
    }
    int first=0,last=array.size()-1;
    while(first<last){
        if(array[first]+array[last]<target){
            first++;
        }
        else if(array[first]+array[last]>target){
            last--;
        }
        else if(array[first]+array[last]==target){
            ans[0]=first+1;
            ans[1]=last+1;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int>s={2,7,11,15};
    int target=9;
    vector<int>ans=FindSum(s,target);
    for(int i=0;i<2;i++){
        cout<<ans[i]<<'\t';
    }
    cout<<endl;
    return 0;
}
