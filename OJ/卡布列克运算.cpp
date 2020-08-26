#include<iostream>
using namespace std;
const int N=4;
int pow10_int(int n);
void parse_sort(int each[],int num);
int Minx(int each[]);
int Maxx(int each[]);

int main()
{
    int number,max,min;
    int each[N];
    cout<<"please input a xxxx number:  ";
    cin>>number;
    while(number!=6174)
    {
        parse_sort(each,number);
        max=Maxx(each);
        min=Minx(each);
        number=max-min;
        cout<<max<<"-"<<min<<"="<<number<<endl;
    }
    cout<<" YES\n";
    return 0;
}

int pow10_int(int n)
{
    int sum=1;
    for(int i=0;i<n;i++)
    {
        sum=sum*10;
    }
    return sum;
}

void parse_sort(int each[],int num)
{
    int m,i,j,t;
    for(i=0;i<N;i++)
        each[i]=0;
    i=0;
    while(num!=0)                                  //分解NUM，存放在each中
    {
        m=num%10;
        num=num/10;
        each[i++]=m;
    }
    for(i=0;i<N-1;i++)                             //each按从小到大排列
        for(j=0;j<N-1-i;j++)
            if(each[j]>each[j+1])
            {
                t=each[j];
                each[j]=each[j+1];
                each[j+1]=t;
            }
}

int Minx(int each[])
{
    int sum=0,i;
    for(i=0;i<N;i++)
        sum+=each[i]*pow10_int(N-1-i);
    return sum;
}

int Maxx(int each[])
{
    int sum=0,i;
    for(i=0;i<N;i++)
        sum+=each[i]*pow10_int(i);
    return sum;
}