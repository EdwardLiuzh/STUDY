#include<iostream>
using namespace std;
struct jex
{
    int code;
    int password;
    jex *next;
};
int main()
{
    jex *head,*p,*q;
    int boys,m,i;
    cout<<"input boy's number:  ";
    cin>>boys;
    cout<<"intput password: "<<endl;
    head=new jex;
    cin>>m;
    head->code=1;
    head->password=m;
    q=head;
    for(i=2;i<=boys;i++)
    {
        p=new jex;
        cin>>m;
        p->code=i;
        p->password=m;
        q->next=p;
        q=p;
    }
    q->next=head;//循环链表构成！
    cout<<"input first limiting number: ";
    cin>>m;
    cout<<"the out order is:"<<endl;
    p=head;
    while(p->next!=p)
    {
        i=1;
        while(i<m)
        {
            i++;
            q=p;
            p=p->next;
        }
        q->next=p->next;
        cout<<p->code<<" ";
        m=p->password;
        delete p;
        p=q->next;
    }
    cout<<p->code<<endl;
    i=p->code;
    delete p;
    cout<<"the winner is: "<<i<<endl;
    return 0;
}