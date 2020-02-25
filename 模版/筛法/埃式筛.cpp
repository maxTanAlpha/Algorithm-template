#include <iostream>
#include <cstring>
#include <algorithm>
const int maxn = 1e5;
int prime[maxn];
void make_prime(int n) {  //埃式筛
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = 0;
        }
    }
}