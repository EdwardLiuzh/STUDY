#include<iostream>
#include<vector>
using namespace std;
void outMatrix(vector<vector<int>>Matrix){
    vector<vector<int>>::iterator it;
    for(it=Matrix.begin();it!=Matrix.end();it++){
        for(int i=0;i<(*it).size();i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
}

void rotate1(vector<vector<int>>&Matrix){    //顺时针旋转
    outMatrix(Matrix);
    cout<<"   V        "<<endl;
    for(int i=0;i<Matrix.size()/2;i++){
        swap(Matrix[i],Matrix[Matrix.size()-1-i]);
    }
    for(int i=0;i<Matrix.size();i++){
        for(int j=i+1;j<Matrix[i].size();j++){
            swap(Matrix[i][j],Matrix[j][i]);
        }
    }
    outMatrix(Matrix);
    cout<<"**************"<<endl;
}

void rotate2(vector<vector<int>>&Matrix){    //逆时针旋转
    outMatrix(Matrix);
    cout<<"   V        "<<endl;
    vector<vector<int>>::iterator it;
    for(it=Matrix.begin();it!=Matrix.end();it++){
        for(int i=0;i<(*it).size()/2;i++){
            swap((*it)[i],(*it)[(*it).size()-1-i]);
        }
    }
    for(int i=0;i<Matrix.size();i++){
        for(int j=i+1;j<Matrix[i].size();j++){
            swap(Matrix[i][j],Matrix[j][i]);
        }
    }
    outMatrix(Matrix);
    cout<<"**************"<<endl;
}

int main(){
    vector<vector<int>>m={{1,2,3,4},{5,3,1,2},{3,1,1,6},{9,6,7,3}};
    outMatrix(m);
    cout<<"**************"<<endl;
    rotate1(m);
    rotate2(m);
    return 0;
}
