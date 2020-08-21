#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

string stack_decode(int seq) {
   int t=0,i=1,j=0,n=0;
   stack<char>s0,s1;
   string res;
   stringstream ss;
   for(i=1;i<10;i++){
   		t=seq%10;
   		seq=seq/10;
   		if(t)
   			s0.push(t+'0');
   }
	n=s0.size();
   char *s=new char[n];
   
   for(i=0;!s0.empty();i++){
   		s[i]=s0.top();
   		s0.pop();
   }
   
   for(i=0;i<n;i++){
		if(res.find(s[i])==res.npos){
			for(t=s[i]-'0'-1;t>0;t--){
				ss<<t;
				if(res.find(ss.str())!=res.npos)
					break;
				ss.str("");
			}
			for(j=t+1;j<=s[i]-'0';j++){
				ss.str("");
				res.append("+");
				ss<<j;
				res+=ss.str();
				s1.push(j+'0');
			}	
		}
		else{
			if(s1.top()!=s[i]){
				res.append("*");
				return res;
			}
		}
		ss.str("");
		res.append("-");
		ss<<s[i];
		res+=ss.str();
		ss.str("");
		s1.pop();
	}  
	return res;		
}
  

int main() {
   int seqnum;
   cin >> seqnum;
   cout << stack_decode(seqnum) << endl;
   return 0;
 }


