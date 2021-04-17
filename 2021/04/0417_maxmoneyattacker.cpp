/*
西部世界中有n个赏金猎人，每个赏金猎人都有两个属性战斗力和所拥有金钱。(attack[i, money[i]分别表示第i个赏金猎人的战斗力和所拥有金钱，
保证每个赏金猎人的战斗力不相同)。每一个赏金猎人只有k发子弹，
这意味着他最多可以击败k个战斗力比他小的赏金猎人并获取他们的金钱。
你能输出每一一个赏金猎人最多拥有多少金钱?
输入描述:
第一行包含两个整数n,k(1<n≤10^5,0≤k≤min(n-1,10))。
第二行包含n个整数attack[i(1≤attack[i]≤10^9)。
第三行包含n个整数money[i](1≤money[i]≤10^9)。
输出描述:
输出一行包含n个整数，第i个整数表示第i个赏金猎人最多拥有金钱数。
示例:
输入
3 1
1 8 3
1 8 5
输出
1 13 6

以{attack,money}为二元组进行排序，money为第一关键字降序，attack为第二关键字升序。最后求结果
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> attack(n),money(n);
    vector<vector<int>> mh(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>mh[i][1];
        attack[i] = mh[i][1];
    }
    for(int i=0;i<n;i++){
        cin>>mh[i][2];
        money[i] = mh[i][2];
    }
    sort(mh.begin(),mh.end(),[](vector<int> &m1,vector<int> &m2){
        return m1[2]>m2[2]||m1[2]==m2[2]&&m1[1]>m2[1];
    });
    for(int i=0;i<n;i++){
        int j=0,t=0;
        long long sum=0;
        while(j<n&&attack[i]<=mh[j][1])
            j++;
        while(t<k&&j<n){
            if(attack[i]>mh[j][1]){
                sum+=mh[j][2];
                t++;
            }
            j++;
        }
        sum+=money[i];
        if(i!=n-1)
            cout<<sum<<" ";
        else
            cout<<sum<<endl;
    }
    return 0;
}
