
//查找图的连通块及大小

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int nmax=1010;
//遍历连通块
void DFS(vector<vector<int>>&G,vector<int>& vis,vector<int>&p,int u){
	vis[u]=1;
    p.emplace_back(u);
	for(int i=0;i<G[u].size();i++)
		if(vis[i]==0)//如果该节点未被访问，则深度遍历
			DFS(G,vis,p,i);
}

int main(int argc, char** argv) {
	int n;//点数
	int m;//边数
    vector<vector<int>> res;
    vector<int> p;
	while(cin>>n>>m){
		if(n==0){
			break;
		}
        vector<vector<int>> G(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                G[i][j]=1;
        vector<int> vis(0,n);//1已被访问 0未被访问
		int u,v;
		for(int i=0;i<m;i++){
			cin>>u>>v;
            if(u>v){
                int tmp=u;
                u=v;
                v=tmp;
            }
			G[u-1][v-1]=1;
		}
		int blk=0;
		//遍历整个图G
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				DFS(G,vis,p,i);//访问i所在的连通块
                res.emplace_back(p);
                p.clear();
				blk++;
			}
		}
		cout<<blk<<endl;
	}
	return 0;
}
