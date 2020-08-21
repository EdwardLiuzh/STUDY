#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
stack<char>opt;
stack<int>opv;

int cal(const int opv1,const char op,const int opv2){
	switch(op){
		case'+':	return opv1+opv2;
		case'-':	return opv1-opv2;
		case'*':	return opv1*opv2;
		case'/':	return opv1/opv2;
		default:	break;
	}
}

int getindex(const char opt){
	int index = 0;  
    switch (opt)  
    {  
	    case '+':  index = 0;  break;  
	    case '-':  index = 1;  break;  
	    case '*':  index = 2;  break;  
	    case '/':  index = 3;  break;  
	    case '(':  index = 4;  break;  
	    case ')':  index = 5;  break;  
	    case '#':  index = 6;  
	    default:break;  
    }  
    return index; 
}

char pri(const char opt1,const char opt2){
	int index1 = getindex(opt1);  
    int index2 = getindex(opt2);
	const char priority[][7] =     //���ȼ���ϵ����  
    {  	//+   -   *   /    (   )   #	
        { '>','>','<','<','<','>','>' },  // +
        { '>','>','<','<','<','>','>' },  // -
        { '>','>','>','>','<','>','>' },  // *
        { '>','>','>','>','<','>','>' },  // /
        { '<','<','<','<','<','=','0' },  // (
        { '>','>','>','>','0','>','>' },  // )
        { '<','<','<','<','<','0','=' },  // #
    };  
    return priority[index1][index2];  
} 

int expr(const string & expstr) {
	char s[100];
	strcpy(s,expstr.c_str()); 
   	int num=0,dig=0,i=0;
   	opt.push('#');
  	while(s[i]!='\0'||opt.top()!='#'){
		if(isdigit(s[i])){
			if(num==1){
				dig=opv.top()*10+(s[i]-'0');	//��λ�������10 
				opv.pop();
				opv.push(dig);
			}
			else{
				opv.push(s[i]-'0');
				num=1;
			}
			i++;
		}
		else{
			num=0;
			if(pri(opt.top(),s[i])=='='){
				opt.pop();					//��(��)���赯��ջ����( 
				i++;
			}
			else if(pri(opt.top(),s[i])=='<'){
				opt.push(s[i]);				//���ȼ�����ջ��  ����Ҫ���㣬ֱ��ѹ�� 
				i++;
			}
			else if(pri(opt.top(),s[i])=='>'){
				char op=opt.top();			//���ȼ�����ջ��   ʹ��ջ�������� ����ջ 
				opt.pop();
				int op1=opv.top();
				opv.pop();
				int op2=opv.top();
				opv.pop();
				opv.push(cal(op2,op,op1));	//����op2 op op1 
			}
		}		   	
   }
   return opv.top();
}



int main() {
   string s;
   getline(cin, s);
   cout << expr(s) << endl;
   return 0;
 }

