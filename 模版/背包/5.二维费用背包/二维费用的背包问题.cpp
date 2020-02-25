#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e4;
int n, weight, volume;
int v[maxn], w[maxn], m[maxn], dp[maxn][maxn];
int main() {
    cin >> n >> weight >> volume;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> m[maxn];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = weight; j >= w[i]; j--) {
            for (int h = volume; h >= m[i]; h--) {
                dp[j][h] = max(dp[j][h], dp[j-w[i]][h-m[i]]+v[i]);
            }
            
        }
    }
    cout << dp[weight][volume] << endl;
    return 0;
}