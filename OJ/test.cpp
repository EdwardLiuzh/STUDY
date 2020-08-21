#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
using namespace std;

int htoi(char s[])
{
	int i;
	int n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else
		i = 0;
	for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'); ++i)
	{
		if (tolower(s[i]) > '9')
			n = 16 * n + (10 + tolower(s[i]) - 'a');
		else
			n = 16 * n + (tolower(s[i]) - '0');
	}
	return n;
}

struct amm{
    int sts;
    int add;
};

int Search_data(int target, vector<amm>cd){ //在Kernel_cache中搜索地址为target的数据块
    int flag=0;
    if(cd.size()){
        for(;flag<cd.size();flag++){
            if(cd[flag].add==target){
                //cout<<cd[flag].add<<"\t\t\t"<<target<<endl;
                return flag;
            }
        }
        cout<<flag<<endl;
        if(flag==cd.size()-1)
            return -1;
    }
    else
        return -1;
}

int main(){
    ifstream infile;
    string cm[40];
    int x[40];
    int i=0;
    /*
    infile.open("WbCache.cpp");
    if(infile.is_open()){   //若失败,则输出错误消息,并终止程序运行
        while(getline(infile,cm[i++])){
            cout<<cm[i-1]<<endl;
        }
    }
    i=0;
    string s="1 0000aabc";
    char buf[10];
    strcpy(buf, s.c_str()+2);
    cout<<hex<<htoi(buf)<<endl;
    cout<<s[0]-'0';
    */
    vector<amm>v={{12,12},{13,13},{16,16}};
    int t=14;
    //cout<<Search_data(t,v)<<endl;
    string s="0 0000aabc";
    cout<<s.c_str()[0]-'0'<<endl;
    cout<<int('a'-'b')<<endl;
    return 0;
}
