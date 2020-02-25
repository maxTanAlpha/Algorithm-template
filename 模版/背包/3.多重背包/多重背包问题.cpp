#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3;
int n, weight;
int v[maxn], w[maxn], s[maxn], dp[maxn];
int main() {
    cin >> n >> weight;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = weight; j >= w[i]; j--) {
            for (int h = 1; h <= s[i] && j >= w[i]*h; h++) {
                dp[j] = max (dp[j], dp[j-w[i]*h]+v[i]*h);
            }
        }
    }
    cout << dp[weight] << endl;
    return 0;
}