#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;
int numWays(string s) {
    int len=s.size(),num=0;
        for(int i=0;i<len;i++){
            if(s[i]=='1')   num++;
        }
        if(num==0){
            return ((long)(len-1)*(long)(len-2)/2)%mod;
        }
        else if(num%3==0){
            int r=num/3,k=0;
            long res=0;
            std::vector<int> v(4);
            for(int i=0;i<len;i++){
                if(s[i]=='1'){
                    k++;
                    if(k==r){
                        v[0]=i;
                    }
                    if(k==r+1){
                        v[1]=i;
                    }
                    if(k==2*r){
                        v[2]=i;
                    }
                    if(k==2*r+1){
                        v[3]=i;
                    }
                }
            }
            res=(((long long int)(v[1] - v[0]))*(long long int)(v[3] - v[2]))%mod;
            return (int)res;
        }
        else
            return 0;
}

int main(int argc, char const *argv[]) {
    string s;
    while(cin>>s){
        cout<<numWays(s)<<endl;
    }
    return 0;
}
