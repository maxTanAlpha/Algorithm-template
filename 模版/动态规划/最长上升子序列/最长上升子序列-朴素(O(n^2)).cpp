#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
int n;
int dp[maxn], data[maxn], from[maxn]; //from记录前趋,用于判断输出取到的数
void output(int x) {
    if (!x)  return;
    output(from[x]);
    cout << data[x] << " ";
    //迭代输出
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;from[i] = 0;
        for (int j = 1; j < i; j++) {
            if (data[j] < data[i]) {
                if (dp[i] < dp[j]+1) {
                    from[i] = j;
                }
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = dp[1], pos = 1;
    for (int i = 1; i <= n; i++){
        if(ans < dp[i]) {
            ans = dp[i];
            pos = i;
            //由于需要递归输出所以要记录最长上升子序列的最后一个元素
            //需要来不断回溯出路径来
        }
    }
    cout << ans << endl;
    output(pos);
    return 0;
}
