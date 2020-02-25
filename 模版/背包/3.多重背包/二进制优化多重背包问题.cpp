#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct good {
    int w, v;
};
const int maxn = 2e3+10;
int n, weight;
int dp[maxn];
int main() {
    cin >> n >> weight;
    vector<good> goods;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> w >> v >> s;
        for (int j = 1; j <= s; j*=2) { //拆成log2(s)份
            s -= j;
            goods.push_back({w*j, v*j});
        }
        if (s > 0) {
            goods.push_back({w*s, v*s});
        }
    }
    for (auto it : goods) {
        for (int j = weight; j >= it.w; j--) {
            dp[j] = max(dp[j], dp[j-it.w]+it.v);
        }
    }
    cout << dp[weight] << endl;
    return 0;
}