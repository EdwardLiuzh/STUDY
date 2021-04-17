/*
在一个01串中，每一轮，玩家都可以选择一串连续相同字符进行消除，消除之后，左右两侧剩余的字符自动拼接，重新形成一个字符串。
例如:在101001中，牛牛选择了第四个和第五个字符，它们连续且都是0,满足消除条件，而当它们消除之后，左侧剩余的101和右侧剩余的1会拼接到一起，即:消除后剩余的01串为: 1011
计分规则如下:消除了几个1就计几分,直到消成空串时游戏结束。
对于一串全新的01串，由牛妹先手进行消除，两个人都以最优策略且以得分高为目标进行消除，请问最后，哪个人的得分会比较高?
输入描述:
本题为多组测试数据，第一行输入-个正整数T(1≤T≤1000)，代表测试数据组数。对于每组测试数据，- 行输入-个长度不超过1000的01串，代表初始形态。
输出描述:
对于每组测试数据，如果牛妹得分高，则在第一行输出Niumei, 第二行输出一个分数代表牛妹比牛牛高几分;
如果牛牛得分高，则在第一行输出Niuniu,第二行输出一个分数代表牛牛比牛妹高几分;如果两个人分数相同，则只需要在一行输出Draw.
示例1:
输入输出示例仅供调试，后台判题数据一般不包含示例
输入
2
111111
111011
输出
Niumei
6
Niumei
1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findwinner(string &s){
    std::vector<int> score;
    int res[2]={0,0};
    int count=0;
    for(auto c:s){
        if(c=='1'){
            count+=1;
        }else{
            score.push_back(count);
            count=0;
        }
    }
    score.push_back(count);
    sort(score.rbegin(),score.rend());
    for(int i=0;i<score.size();i++){
        if(i%2==0){
            res[0]+=score[i];
        }else{
            res[1]+=score[i];
        }
    }
    if(res[0]>res[1]){
        cout<<"Niumei"<<endl;
        cout<<res[0]-res[1]<<endl;
    }else if(res[1]>res[0]){
        cout<<"Niuniu"<<endl;
        cout<<res[1]-res[0]<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
}

int main(int argc, char const *argv[]) {
    string str;
    int T;
    cin>>T;
    while(T--){
        cin>>str;
        findwinner(str);
    }
    return 0;
}
