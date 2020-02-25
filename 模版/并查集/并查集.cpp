#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e4;
int parent[maxn];
int find1(int x) { //递归
    if (x == parent[x]) {
        return x;
    }
    return find1(x);
}
int find2(int x) { //递推
    int r = x;
    while (r != parent[r]) {
        r = parent[r];
    }
    int i = x, j;
    while (i != r) {
        j = parent[i];
        parent[i] = r;
        i = j;
    }
    return r;
}
int find3(int x) { //递推第二种
    while (x != parent[x]) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void join(int x, int y) {
    int fx = find1(x), fy = find1(y);
    if (fx != fy) {
        parent[y] = fx;
    }
}
int main() {
    
    return 0;
}