#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n, k, a[40], ans;
map<int, int> m1, m2;
// m1表示奇数个，m2表示偶数个
int main() {
    cin >> n;
    k = n >> 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ma = 1 << k;
    for (int i = 1; i < ma; i++) {
        int sum = 0, cnt = 0;
        //状态压缩
        for (int j = 0; j < k; j++)
            if ((i >> j) & 1)
                cnt++, sum += a[j];
        //右移j位若末位是1说明该选择中有a[j]
        // a[]的下标要从0开始，右移0位就是自身，同理退后
        if (cnt & 1)
            m1[sum]++;  //奇数个和为sum的数量加一
        else {
            m2[sum]++;  //偶数个和为sum的数量加一
            if (!sum)
                ans++;  //符合题意的
        }
    }
    ma = 1 << (n - k);
    for (int i = 1; i < ma; i++) {
        int sum = 0, cnt = 0;
        for (int j = 0; j < n - k; j++)
            if ((i >> j) & 1)
                cnt++, sum += a[j + k];
        if (cnt & 1)
            ans = ans + m1[-sum];  //两个奇数个集合，-sum保证和为0
        else {
            ans = ans + m2[-sum];
            if (!sum)
                ans++;
        }
    }
    cout << ans;
    return 0;
}

