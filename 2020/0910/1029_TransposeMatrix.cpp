#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> TransposeMatrix(vector<vector<int>>& ma) {
    vector<vector<int>>mb;
    if(ma.size()!=0){
        int a1=ma.size(),a2=ma[0].size();
        int count=0;
        vector<int> v;
        for(int j=0;j<a2;j++){
            for(int i=0;i<a1;i++){
                v.push_back(ma[i][j]);
                count++;
                if(count==a1){
                    mb.push_back(v);
                    v.clear();
                    count=0;
                }
            }
        }
    }
    return mb;
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
    vector<vector<int>>m={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> a=TransposeMatrix(m);
    printVectorV(a);
    return 0;
}
