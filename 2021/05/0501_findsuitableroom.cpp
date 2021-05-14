#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
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

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    vector<int>ans;
    sort(rooms.begin(),rooms.end());
    for(int i=0;i<queries.size();i++){
        cout<<queries[i][0]<<endl;
        int pre=queries[i][0]-1,next=queries[i][0]-1;
        if(pre>queries[rooms.size()-1][0])
            pre=queries[rooms.size()-1][0];
        if(next<queries[0][0])
            next=queries[0][0];
        for(;pre>=0||next<rooms.size();){
            cout<<pre<<" "<<next<<endl;
            if(pre>=0&&rooms[pre][1]>=queries[i][1]){
                ans.emplace_back(pre+1);
                break;
            }
            if(next<=rooms.size()-1&&rooms[next][1]>=queries[i][1]){
                ans.emplace_back(next+1);
                break;
            }
            if(pre>=0)
                pre--;
            if(next<=rooms.size()-1)
                next++;
        }
        if(pre<0&&next>=rooms.size()){
            ans.emplace_back(-1);
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    vector<vector<int>> rooms={{2,2},{1,2},{3,2}};
    vector<vector<int>> queries={{3,1},{3,3},{5,2}};
    vector<int> ans=closestRoom(rooms,queries);
    return 0;
}
