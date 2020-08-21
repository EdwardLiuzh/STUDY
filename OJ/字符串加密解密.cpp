#include <iostream>
#include <string.h>
using namespace std;

string en_code(const string s,const char* da){
	int i=0;
	char *sa=new char[s.length()];
	char *sr=new char[s.length()];
	strcpy(sa, s.c_str());
	for(i=0;i<s.length();i++)
		sr[i]=da[sa[i]-'a'];
	string s_en_result(sr);
	delete[]sa;
	delete[]sr;
	return s_en_result;
}

string de_code(const string s,const char* da){
	int i=0,j=0;
	char *sa=new char[s.length()];
	char *sr=new char[s.length()];
	strcpy(sa, s.c_str());
	for(i=0;i<s.length();i++){
		for(j=0;j<26;j++)
			if(da[j]==sa[i])
				break;
		sr[i]='a'+j;	
	}
	string s_de_result(sr);
	delete[]sa;
	delete[]sr;
	return s_de_result;
}

int main() {
   string str,s0;
   int i;
   char dict[30];
   int d[30];
   cin >> str;
   cin >> s0;
   strcpy(dict, str.c_str());
   cout << en_code(s0,dict) << endl;
   cout << de_code(s0,dict) << endl;
   return 0;
 }

