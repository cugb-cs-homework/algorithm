#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;

void solve() {
    int n = 50, m = 1;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << (i == j ? 0 : 1 + rand() % 500) << ' ';
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    clock_t start, end;
    return 0;
}