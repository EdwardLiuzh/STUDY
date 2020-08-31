#include<iostream>
#include<string.h>
using namespace std;

char* reverse(char *a,int l) {
  char *b;
  int i=0;
  for(;*(a+i);i++)
      *(b+i)=*(a+l-i-1);
  return b;
}

int main(){
  char inputString[100];
  char *outputString;
  cin>>inputString;
  int l=strlen(inputString);
  outputString=reverse(inputString,l);
  cout<<outputString;
  return 0;
}
