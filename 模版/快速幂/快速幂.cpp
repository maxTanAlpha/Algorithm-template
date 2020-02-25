#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int pow1(int a, int b) { //a的b次幂
    int ans = 1, base = a; // ans：幂的结果；base：底数a
    while (b) {
        if (b&1)    ans = ans * base;
        base *= base;
        b = b >> 1;
    }
    return ans;
}
int pow2(int a, int b, int c) { //每次取模
    int ans = 1, base = a;
    base = base % c;
    while (b) {
        if (b&1)    ans = (ans * base) % c;
        b = b >> 1;// 右移一位，相当于除2
        base = (base * base) % c; 
    }
    return ans;
}