#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n, k, a[40], ans;
map<int, int> m1, m2;
// m1��ʾ��������m2��ʾż����
int main() {
    cin >> n;
    k = n >> 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ma = 1 << k;
    for (int i = 1; i < ma; i++) {
        int sum = 0, cnt = 0;
        //״̬ѹ��
        for (int j = 0; j < k; j++)
            if ((i >> j) & 1)
                cnt++, sum += a[j];
        //����jλ��ĩλ��1˵����ѡ������a[j]
        // a[]���±�Ҫ��0��ʼ������0λ��������ͬ���˺�
        if (cnt & 1)
            m1[sum]++;  //��������Ϊsum��������һ
        else {
            m2[sum]++;  //ż������Ϊsum��������һ
            if (!sum)
                ans++;  //���������
        }
    }
    ma = 1 << (n - k);
    for (int i = 1; i < ma; i++) {
        int sum = 0, cnt = 0;
        for (int j = 0; j < n - k; j++)
            if ((i >> j) & 1)
                cnt++, sum += a[j + k];
        if (cnt & 1)
            ans = ans + m1[-sum];  //�������������ϣ�-sum��֤��Ϊ0
        else {
            ans = ans + m2[-sum];
            if (!sum)
                ans++;
        }
    }
    cout << ans;
    return 0;
}

