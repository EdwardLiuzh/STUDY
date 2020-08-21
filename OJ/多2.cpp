#include<stdio.h>
int main(){
    int i,len=0,l=0;
    float flag=1,res=1;
    char s[1001];
    scanf("%s",s);
    if(s[0]=='-')
        flag=1.5;
    for(i=1;s[i]!='\0';i++){
        len++;
        if(s[i]=='2')
            l++;
    }
    printf("flag=%d\n",flag); 
    printf("s[i-1]=%c\n",s[i-1]); 
    if((s[i-1]-'0')%2==0)
        res=(float)l/(float)len*flag*2*100;
    else
        res=(float)l/(float)len*flag*100;
    printf("%.2f%%",res);
    return 0;
}
