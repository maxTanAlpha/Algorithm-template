//求所有点到给出点的距离,题目链接https://www.luogu.com.cn/problem/P4779
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5, maxm = 5e5+10, inf = 0x7fffffff;//0x7fffffff与0x3f3f3f3f都代表无穷大等于INT_MAX
typedef pair<int, int> PII;
int head[maxn], dis[maxn], visit[maxn];//head[i]=j表示第i点,j为第j条边,而随着add的过程head[i]会记录第i个点为头的第j条边;dis[i]表示i到目标点的最小距离;visit[i]表示判断i点是否走过
struct Edge {
    int next, end, len;
} e[maxm];
int n, m, s, cnt;
void add(int a, int b, int c) {
    cnt++;
    e[cnt].end = b;//end表示另一端
    e[cnt].len = c;
    e[cnt].next = head[a];
    head[a] = cnt;
}
void dijkstra(int s) {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int x = it.second;
        if (visit[x])  continue;
        visit[x] = 1;
        for (int i = head[x]; i; i = e[i].next) {
            int j = e[i].end;
            if (dis[j] > dis[x]+e[i].len) {
                dis[j] = dis[x]+e[i].len;
                if (!visit[j])  q.push({dis[j], j});
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)    dis[i] = inf;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}
