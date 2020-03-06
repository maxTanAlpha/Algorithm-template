/*
 当前的 A1[i]和A2[j]相同（即是有新的公共元素）
 那么 dp[i][j]=max(dp[i][j],dp[i−1][j−1]+1);
 如果不相同，即无法更新公共元素，考虑继承:
 dp[i][j]=max(dp[i−1][j],dp[i][j−1])
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3+10, inf = 0x7fffffff;
int n, m;
int dp[maxn][maxn], a1[maxn*2], a2[maxn*2]; //dp[i][j]来表示第一个串的前i位，第二个串的前j位的LCS的长度
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a1[i];
    for (int i = 1; i <= m; i++) cin >> a2[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          if(a1[i] == a2[j])
          dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
          //因为更新，所以++；
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
