#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> pancakeSort(vector<int>& A){
    int len = A.size();
        if (!len || len==1)
            return {};
        int a[105];
        for (int i = 0; i < len; ++i)
            a[A[i]] = i+1; //初始化饼的位置
        int max_v = len;
        vector<int> ans;
        while (max_v) {
            int max_ind = a[max_v];
            ans.push_back(max_ind); //从最大饼位置翻转一次
            ans.push_back(max_v); //从底部翻转一次
            for (int i = 0; i < len; ++i) {
                if (A[i] > max_v)
                    continue; //这些饼已经在底部排好，不用管
                if (a[A[i]] > max_ind)
                    a[A[i]] = max_v-a[A[i]]+1; //最大饼下面的饼位置更新
                else
                    a[A[i]] = max_v-max_ind+a[A[i]]; //最大饼上面的饼位置更新
            }
            max_v--;
        }
        return ans;
}

int main(int argc, char const *argv[]) {
    std::vector<int> v={3,2,4,1};
    std::vector<int> ans=pancakeSort(v);
    for(int i=0;i<v.size();i++){
        cout<<ans[i]<<'\t';
    }
    cout<<endl;
    return 0;
}
