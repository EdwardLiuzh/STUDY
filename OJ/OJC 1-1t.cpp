#include<stdio.h> 
unsigned long long mult_mod(unsigned long long a,unsigned long long b,unsigned long long c)
{
    a%=c;
    b%=c;
    unsigned long long ret=0;//ret记录最终的结果
    while(b)//判断不是不是为0了
    {
        if(b&1)//如果b的二进制中的最后一位为1 那么加上a
		{
			ret+=a;ret%=c;
		}
        a<<=1;a%=c;//a随着b中二进制位数而扩大每次扩大两倍。
        b>>=1;//b来缩小两倍 去掉最后一位 因为当前最后一位我们用完了，
    }
    return ret;
}
int main(){
	unsigned long long A=0,B=0,P=1000000007;
	scanf("%llu %llu",&A,&B);
	printf("%llu\t",P);
	printf("%llu\n",mult_mod(A,B,P));
	return 0;
}
