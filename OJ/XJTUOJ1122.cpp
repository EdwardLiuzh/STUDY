/*
给出一个长度为n的链表List，其中List[i]接着List[i+1]
给出q个操作，每个操作可能是以下两种：
1 p x：表示在第p个数字后面插入一个元素x
2 p：表示删除第p个数字。
按顺序输出最终的链表
n,q<=2e3
*/
#include<iostream>
static int a[2000];
int n,q;
int main(){
    int i,t;
    std::cin>>n>>q;
    for(i=0;i<n;i++){
        std::cin>>t;
        a[i]=t;
    }
    while(q--){
        std::cin>>t;
        if(t==1){
            int f,x;
            std::cin>>f>>x;
            for(i=n;i>=f;i--)
                a[i+1]=a[i];
            a[f]=x;
            n++;
        }
        if(t==2){
            int f;
            std::cin>>f;
            for(i=f-1;i<n;i++)
                a[i]=a[i+1];
            a[n]=0;
            n--;
        }
    }
    for (i=0; i<n; i++)
        std::cout<<a[i]<<"\t";
    return 0;
}
