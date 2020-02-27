//例题：https://www.acwing.com/problem/content/175/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 1010;
int n, m;
char g[maxn][maxn];
int dis[maxn][maxn];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
void bfs() {
    memset(dis, -1, sizeof(dis));
    queue<PII> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '1') {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a > 0 && a <= n && b > 0 && b <= m && dis[a][b] == -1) {
                dis[a][b] = dis[x][y] + 1;
                q.push({a, b});
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
