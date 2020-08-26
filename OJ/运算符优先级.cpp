 #include<iostream>
 using namespace std;
 int main()
 {
     int a,b,c,d;
     a=10;
     b=a++;
     c=++a;
     d=10*a++;
     cout<<a<<","<<b<<","<<c<<","<<d<<endl;
     return 0;
 }