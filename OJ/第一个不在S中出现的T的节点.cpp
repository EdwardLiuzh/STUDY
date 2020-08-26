#include<iostream>
using namespace std;

struct Linkstring
{
    char data;
    struct Linkstring *next;   /* data */
};
char SearchNoin(Linkstring *s,Linkstring *t);
Linkstring *creatList();

int main()
{
    Linkstring *s,*t;
    s=creatList();
    t=creatList();
    cout<<SearchNoin(s,t)<<endl;
    return 0;
}

Linkstring *creatList()
{
    Linkstring *head,*s,*r;
    char c;
    head=NULL;
    cout<<"Please input words ending with #:";
    cin>>c;
    while(c!='#')
    {
        s=new Linkstring;
        s->data=c;
        s->next=NULL;
        if(head==NULL)
            head=s;
        else
            r->next=s;
        r=s;
        cin>>c;
    }
    return head;
}

char SearchNoin(Linkstring *s,Linkstring *t)
{
    Linkstring *p,*q;
    p=s;
    q=t;
    while(p)
    {
        while(q&&p->data!=q->data)
            q=q->next;
        if(q==NULL)
            return p->data; //未在q中找到该节点,是目标节点
        q=t;
        p=p->next;
    }
    cout<<"there's no such character!";
    return NULL;
}
