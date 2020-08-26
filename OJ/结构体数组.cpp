#include<iostream>
#include<string.h>
using namespace std;
struct Merchandising
{
    char code[5];
    char name[11];
    float price;
    int quantity;
    float amount;
};

int main()
{
    Merchandising sell[10],temp;
    int i,j;
    for(i=0;i<20;i++)
    {
        cout<<"Please input No."<<i+1<<" selling record"<<endl;
        cout<<"Product code:    ";
        cin>>sell[i].code;
        cout<<"Product name:    ";
        cin>>sell[i].name;
        cout<<"Product price:   ";
        cin>>sell[i].price;
        cout<<"Selling amount:  ";
        cin>>sell[i].quantity;
        sell[i].amount=sell[i].price*sell[i].quantity;
    }
    for(i=0;i<20-1;i++)
        for(j=i+1;j<20;j++)
            if(sell[i].amount>sell[j].amount||sell[i].amount==sell[j].amount&&strcmp(sell[i].code,sell[j].code)>0)
                {
                    temp=sell[i];
                    sell[i]=sell[j];
                    sell[j]=temp;
                }
    cout<<"code\tname\tprice\tquantity\tamount"<<endl;
    for(i=0;i<20;i++)
    {
        cout<<sell[i].code<<" ";
        cout<<sell[i].name<<" ";
        cout<<sell[i].price<<" ";
        cout<<sell[i].quantity<<" ";
        cout<<sell[i].amount<<endl;
    }
    return 0;
}