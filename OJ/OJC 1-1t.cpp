#include<stdio.h> 
unsigned long long mult_mod(unsigned long long a,unsigned long long b,unsigned long long c)
{
    a%=c;
    b%=c;
    unsigned long long ret=0;//ret��¼���յĽ��
    while(b)//�жϲ��ǲ���Ϊ0��
    {
        if(b&1)//���b�Ķ������е����һλΪ1 ��ô����a
		{
			ret+=a;ret%=c;
		}
        a<<=1;a%=c;//a����b�ж�����λ��������ÿ������������
        b>>=1;//b����С���� ȥ�����һλ ��Ϊ��ǰ���һλ���������ˣ�
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
