/*
����һ������Ϊn������List������List[i]����List[i+1]
����q��������ÿ�������������������֣�
1 p x����ʾ�ڵ�p�����ֺ������һ��Ԫ��x
2 p����ʾɾ����p�����֡�
��˳��������յ�����
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
