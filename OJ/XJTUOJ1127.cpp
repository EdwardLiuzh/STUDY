#include<iostream>
int main(){
    unsigned long long A,B,C=0;
    static unsigned long long P=1000000007;
    std::cin>>A>>B;
    A=A%P;
    B=B%P;
    while(B){
        if(B&1){
            C=C+A;
            C=C%P;
        }
        B>>=1;
        A<<=1;
        if(A>P)
            A=A%P;
    }
    std::cout<<C;
    return 0;
}
