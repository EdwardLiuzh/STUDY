#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<char>>& board,string &word,vector<vector<bool>> &visited,int index,int x,int y){
        //适当剪枝
    if(index >= word.size())
        return true;
        //越界或者已经访问，或者未访问但不相等，则直接结束
    if(x<0 || x>=board.size() || y<0 || y>= board[x].size() || visited[x][y] || board[x][y]!=word[index])
        return false;

        //到这里说明未访问，且相等，则可以继续在(x,y)点周围继续搜索
        //向后搜索前，先将（x,y）点处置为已经访问状态，后面不可再访问
    visited[x][y] = true;
    if(search(board,word,visited,index+1,x+1,y) || search(board,word,visited,index+1,x,y+1)
        || search(board,word,visited,index+1,x-1,y) || search(board,word,visited,index+1,x,y-1))
        return true;
        //x,y点访问结束，重新置为可访问状态
    visited[x][y] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
    bool result = false;
    string curr_str;
    int index = 0;
    for(int i = 0;i<board.size();++i){
        for(int j = 0;j<board[i].size();++j){
            result = result || search(board,word,visited,index,i,j);
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    string s="ABCCED";
    vector<vector<char>> nums={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<exist(nums,s)<<endl;
    return 0;
}
