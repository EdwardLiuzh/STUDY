#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> Spiral(int n){
    vector<vector<int>> res;
    if(n>0){
        vector<int>tmp;
        for(int i=0;i<n;i++)
            tmp.push_back(0);
        for(int i=0;i<n;i++)
            res.push_back(tmp);
        int top=0,left=0,down=n-1,right=n-1,count=0;
        while(count<n*n){
            for(int i=left;i<=right;i++)
                res[top][i]=++count;
            top++;
            for(int i=top;i<=down;i++)
                res[i][right]=++count;
            right--;
            for(int i=right;i>=left;i--)
                res[down][i]=++count;
            down--;
            for(int i=down;i>=top;i--)
                res[i][left]=++count;
            left++;
        }
    }
    return res;
}

void printVectorV(vector<vector<int>>nums){
    vector<vector<int>>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"**************"<<endl;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    printVectorV(Spiral(n));
    return 0;
}
