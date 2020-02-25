#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e2+10;
int n, weight;
int dp[maxn], v[maxn], w[maxn];
int main() {
    cin >> n >> weight;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> w[j] >> v[j];
        }
        for (int j = weight; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j >= w[k])  dp[j] = max(dp[j], dp[j - w[k]] + v[k]);
            }
        }
    }
    cout << dp[weight] << endl;
    return 0;
}