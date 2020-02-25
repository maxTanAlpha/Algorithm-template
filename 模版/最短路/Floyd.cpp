#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4;
int mmap[maxn][maxn];
int n;
void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mmap[i][j] = min(mmap[i][j], mmap[i][k] + mmap[k][j]);
            }
        } 
    }
}