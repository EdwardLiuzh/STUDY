#include<iostream>
#include<cstring>
using namespace std;

void GetNext(const char* p,int next[]){
    int pl=strlen(p);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pl-1){
        if(k==-1 || p[k]==p[j]){
            k++;
            j++;
            if(p[k]!=p[j]){
                next[j]=k;
            }
            else{
                next[j]=next[k];
            }
        }
        else{
            k=next[k];
        }
    }
}

int FindPosition(const char* s,char x){
    int i=0,len=strlen(s),flag=-1;
    while(i<len-1){
        if(s[i]==x)
            flag=i;
        i++;
    }
    if(flag>=0)
        return len-flag;
    else
        return flag;
}

int KmpSearch(const char* s,const char* p){
        int i=0,j=0;
        int sl=strlen(s);
        int pl=strlen(p);
        int next[pl]={};
        GetNext(p,next);
        while(i<sl && j<pl){
            if(j==-1 || s[i]==p[j]){
                i++;
                j++;
            }
            else{
                j=next[j];
            }
        }
        if(j==pl)
            return i-j;
        else
            return -1;
}

int SundaySearch(const char* s,const char* p){
        int i=0,j=0;
        int sl=strlen(s);
        int pl=strlen(p);
        int flag=0;
        while(i<sl && j<pl){
            if(s[i]==p[j]){
                i++;
                j++;
            }
            else{
                int step=FindPosition(p,s[flag+pl]);
                j=0;
                if(step==-1){
                    i=flag+pl+1;
                }
                else{
                    i=flag+step;
                }
                flag=i;
            }
        }
        if(j==pl)
            return i-j;
        else
            return -1;
}

int main(){
  //cout<<"Hello"<<endl;
  const char* s1="12124325123";
  const char* s2="123";
  const char* s3="dasfasdfgasd";
  const char* s4="fga";
  cout<<KmpSearch(s1,s2)<<endl;
  cout<<SundaySearch(s3,s4)<<endl;
  cout<<SundaySearch(s1,s2)<<endl;
  return 0;
}
