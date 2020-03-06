#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5, inf = 0x7fffffff;
int n;
int dp[maxn], a[maxn]; //dp数组存储该序列中，上升子序列长度为i的上升子序列，的最小末尾数值
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        dp[i] = inf;
        /*原因很简单，每遇到一个新的元素时，
         就跟已经记录的f数组当前所记录的最长上升子序列的末尾元素相比较：
         如果小于此元素，那么就不断向前找，直到找到一个刚好比它大的元素，替换；
         反之如果大于，么填到末尾元素的下一个q,inf就是为了方便向后替换啊！
         */
    }
    dp[1] = a[1];
    int len = 1;
    for (int i = 2; i <= n; i++) {
        int l = 0, r = 1, min;
        if (a[i] > dp[len]) {
            len++;
            dp[len] = a[i]; //如果刚好大于末尾，暂时向后顺次填充
        } else {
            while (l < r) {
                min = (l+r)>>1;
                if(dp[mid] > a[i])  r = mid;
                /*
                 如果仍然小于之前所记录的最小末尾，
                那么不断向前寻找(因为是最长上升子序列，所以f数组必然满足单调)
                 */
                else l = mid+1;
            }
            dp[l] = min(a[i], dp[l]);//更新最小末尾
        }
        
    }
    cout << len << endl;
    return 0;
}
