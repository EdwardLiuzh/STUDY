#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="",s2="";
        for(int i=0;i<word1.size();i++){
            s1+=word1[i];
        }
        for(int i=0;i<word2.size();i++){
            s2+=word2[i];
        }
        if(s1==s2)
            return true;
        return false;
}

int main(int argc, char const *argv[]) {
    std::vector<string> w1={"ab", "c"};
    std::vector<string> w2={"a","bc"};
    cout<<arrayStringsAreEqual(w1,w2)<<endl;
    return 0;
}
