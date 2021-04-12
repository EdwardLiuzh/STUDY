#include<iostream>
#include<vector>
using namespace std;
void getNext(int* next, const string& s) {  //KMP
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

int strStr2(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
}

int strStr1(string haystack, string needle){    //暴力
    int i=0,j=0;
    if(needle=="")  return j;
    while(i<haystack.size()){
        cout<<haystack[i]<<'\t'<<needle[j]<<endl;
        if(haystack[i]==needle[j]){
            if(j==needle.size()-1){
                return i-j;
            }
            else
                j++;
            i++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    return -1;
}
int main(){
    string haystack = "mississippi", needle = "issip";
    cout<<strStr2(haystack,needle)<<endl;
    return 0;
}
