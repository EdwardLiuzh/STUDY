#include<iostream>
using namespace std;
float op(float x,float y,char o){
	switch(o){
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x+y;
		case '/':
			if(y)
				return x/y;
			else
				cout<<"ERROR!"<<endl;
			return 0;
	}
}

int main(){
	float x,y,z;
	char o;
	while(1){
		cin>>x>>o>>y;
		z=op(x,y,o);
		cout<<z<<endl;
	}
	return 0;
}
