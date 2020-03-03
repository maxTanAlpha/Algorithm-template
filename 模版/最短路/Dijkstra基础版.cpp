//Dijkstra采用贪心思想，不从整体考虑结果，只从当前情况考虑选择最优。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5, inf = 0x7fffffff;
int mmap[maxn][maxn], dis[maxn], visit[maxn]; // dis数组存的为起始点与每个点的最短距离,visit数组存的为0或者1，1表示已经走过这个点
int n;
int dijkstra(int start, int end) { //从start到end的最短路
    int minn = inf;
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++)
        dis[i] = mmap[start][i];//从起始点到第i个点的距离
    dis[start] = 0;
    visit[start] = 1;
    while (!visit[end]) {
        minn = inf;
        visit[start] = 1;
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && dis[i] > dis[start]+mmap[start][i]) {
                dis[i] = dis[start]+mmap[start][i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if(!visit[i] && minn >= dis[i]) {
                minn = dis[i];
                start = i;
            }
        }
    }
    return dis[end];
}
