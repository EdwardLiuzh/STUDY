#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct xuesheng{
    int xuhao;
    int l;
    int r;
};


bool cmp(xuesheng a, xuesheng b) {
    if (a.l == b.l) {
        return a.xuhao < b.xuhao;
    }
    return a.l < b.l;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<xuesheng> aaa;
        xuesheng temp;
        for (int j = 0; j < n; j++) {
            temp.xuhao = j;
            cin >> temp.l >> temp.r;
            aaa.push_back(temp);
        }
        sort(aaa.begin(), aaa.end(), cmp);
        int dangqianshike = 1;
        for (int j = 0; j < n; j++) {
            if (dangqianshike > aaa[0].r) {
                aaa.erase(aaa.begin());
                cout << 0 << " ";
            }
            else{
                cout << max(dangqianshike, aaa[0].l) << " ";
                dangqianshike = max(dangqianshike, aaa[0].l) + 1;
                aaa.erase(aaa.begin());
            }
        }
        cout << "\n";
    }
 return 0;
}
