//方法：分情况写出上述三种背包即可
//直接使用多重背包时会超时，可用二进制优化解决
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e3+10;
struct good{
    int kind, w, v;
};
int dp[maxn];
int n, weight;
int main() {
    cin >> n >> weight;
    vector<good> goods;
    for (int i = 1; i <= n; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        if (s == -1)    goods.push_back({-1, w, v});
        else if (s == 0)    goods.push_back({0, w, v});
        else {
            for (int j = 1; j < s; j *= 2) {
                s -= j;
                goods.push_back({-1, w*j, v*j});
            }
            if (s > 0) goods.push_back({-1, w*s, v*s});
        }
    }
    for (auto it : goods) {
        if (it.kind == -1) {
            for (int j = weight; j >= it.w; j--) {
                dp[j] = max(dp[j - it.w] + it.v, dp[j]);
            }
        } else {
            for (int j = it.w; j <= weight; j++) {
                dp[j] = max(dp[j - it.w] + it.v, dp[j]);
            }
        }
    }
    cout << dp[weight] << endl;
    return 0;
}