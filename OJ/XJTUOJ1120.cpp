#include<stdio.h>
#include<algorithm>
#include<vector>

bool cmp(char &a,char &b){
	int c,d;
	if(a>=65&&a<=90)
		c=a+100;
	else
		c=a;
	if(b>=65&&b<=90)
		d=b+100;
	else
		d=b;
	return c<d;
}
int main(){
	char str[100000];
	std::vector<char>s;
	int i=0;
	scanf("%s",str);
	while(str[i]!='\0'){
		s.push_back(str[i++]);
	}
	std::sort(s.begin(),s.end(),cmp);
	for(std::vector<char>::iterator it=s.begin();it<s.end();it++){
		printf("%c",*it);
	}
	return 0;
}
