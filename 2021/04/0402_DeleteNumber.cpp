//有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，
//求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:
//｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
//每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。
//一行输出最后一个被删掉的数的原始下标位置。
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        int count=0;
        while(q.size()!=1)
        {
            if(count!=2)
            {
                int b=q.front();
                q.pop();
                q.push(b);
                count++;
            }
            else
            {
                q.pop();
                count=0;
            }
        }
        int c=q.front();
        cout<<c<<endl;
    }
    return 0;
}
