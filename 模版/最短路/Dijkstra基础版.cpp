//Dijkstra采用贪心思想，不从整体考虑结果，只从当前情况考虑选择最优。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5, inf = 0x7f7f7f;
int mmap[maxn][maxn], dis[maxn], visit[maxn]; // dis数组存的为起始点与每个点的最短距离,visit数组存的为0或者1，1表示已经走过这个点
int n;
void dijkstra(int start) {
    memset(visit, 0, sizeof(visit));//初始化为0，表示开始都没走过
    int pos = 1, min, sum = 0;
    for (int i = 1; i <= n; i++) {
        dis[i] = mmap[start][i]; //从起始点到第i个点的距离
    }
    visit[start] = 1;
    dis[start] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            min = inf;
            if (!visit[i] && dis[j] < min) {
                min = dis[j];
                pos = j;
            }
        }
        visit[pos] = 1;//表示这个点已经走过
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && dis[j] > dis[pos] + mmap[pos][j]) {
                dis[j] = dis[pos]+mmap[pos][j];
            }
        }
    }
}