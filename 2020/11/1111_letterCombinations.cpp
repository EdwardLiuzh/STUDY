#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<queue>
using namespace std;
/*回溯,类似DFS
void backtrack(vector<string>&combinations,string tmp,
    const unordered_map<char, string> phoneMap,int index,
    const string digits){
    if(index==digits.size()){
        combinations.push_back(tmp);
    }else{
        char digit=digits[index];
        const string& letters=phoneMap.at(digit);
        for(const char letter:letters){
            tmp.push_back(letter);
            backtrack(combinations,tmp,phoneMap,index+1,digits);
            tmp.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.empty())
        return ans;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string tmp;
    backtrack(ans,tmp,phoneMap,0,digits);
    return ans;
}
*/
//队列的“先进先出”,类似BFS
vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.empty())
        return ans;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    queue<string>que;
    string letters_0=phoneMap.at(digits[0]);
    for(const char letter:letters_0){
        string str;
        str.push_back(letter);
        que.push(str);
    }
    string ss;
    for(int i=1;i<digits.size();i++){
        int length=que.size();
        while(length--){
            for(int j=0;j<phoneMap[digits[i]].size();j++){
                ss=que.front();
                ss=ss+phoneMap[digits[i]][j];
                que.push(ss);
            }
            que.pop();
        }
    }
    while(!que.empty()){
        ans.push_back(que.front());
        que.pop();
    }
    return ans;
}


int main(int argc, char const *argv[]) {
    string s="45";
    vector<string>ans=letterCombinations(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
