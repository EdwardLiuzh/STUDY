#include<iostream>
using namespace std;

const int length=8;

bool Check(int matrix[], int row){ 
    int i=0; 
    for (i=0;i<=row-1;i++){ 
        if (matrix[i]==matrix[row] || row-i==matrix[row]-matrix[i] ||i-row==matrix[row]-matrix[i]) 
            return false; 
    } 
    return true; 
}

void EightQueen(int matrix[], int row){ 
    int i=0,j=0; 
    for (i=0;i<length;i++){ 
        matrix[row]=i+1; 
        if (Check(matrix,row) && row<=length-1){ 
            if (row==length-1){ 
                for (j=0;j<length;j++) 
                    cout<<matrix[j]; 
                cout<<endl; 
            } 
            else 
                EightQueen(matrix,row+1); 
        } 
    } 
}

int main() { 
    int first=0,matrix[length]={0};
	cin>>first;
	if(first>=1&&first<=8){
		matrix[0]=first;
		EightQueen(matrix,1);
	}
	    
    return 0; 
}
