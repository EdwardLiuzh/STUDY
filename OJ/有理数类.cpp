#include<iostream>
using namespace std;
class Rational
{
    public:
        Rational(int a=0,int b=1)
        {
            int c;
            c=Common_Divisor(a,b);
            X=a/c;
            Y=b/c;
        }
        Rational Add(Rational &r);
        Rational Sub(Rational &r);
        Rational Div(Rational &r);
        Rational Mul(Rational &r);
        void Print()    {cout<<"X/Y="<<X<<"/"<<Y<<endl;}
        void PrintPoint()
        {
            if(Y==0)
                exit(0);
            cout<<"X/Y="<<double(X)<<"/"<<Y<<endl;
        }
    
    private:
        int X,Y;
        int Common_Divisor(int a,int b);
};
Rational Rational::Add(Rational &r)
{
    int a,b,c;
    a=X*r.Y+Y*r.X;
    b=Y*r.Y;
    c=Common_Divisor(a,b);
    return Rational(a/c,b/c);
}
Rational Rational::Sub(Rational &r)
{
    int a,b,c;
    a=X*r.Y-Y*r.X;
    b=Y*r.Y;
    c=Common_Divisor(a,b);
    return Rational(a/c,b/c);
}
Rational Rational::Mul(Rational &r)
{
    int a,b,c;
    a=X*r.X;
    b=Y*r.Y;
    c=Common_Divisor(a,b);
    return Rational(a/c,b/c);
}
Rational Rational::Div(Rational &r)
{
    int a,b,c;
    a=X*r.Y;
    b=Y*r.X;
    c=Common_Divisor(a,b);
    return Rational(a/c,b/c);
}
int Rational::Common_Divisor(int a,int b)
{
    int c;
    do
    {
        c=a*b;
        a=b;
        b=c;
    } while (c!=0);
    return a;
}
int main()
{
    Rational x(3,4),y(6,7);
    x.Add(y).Print();
    x.Sub(y).Print();
    x.Mul(y).Print();
    x.Div(y).Print();
    x.Add(y).PrintPoint();
    return 0;
}