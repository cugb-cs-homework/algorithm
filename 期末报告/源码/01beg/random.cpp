#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;

void solve() {
    srand(time(NULL));
    int n = 50;
    cout << n << ' ' << rand()%200 << endl;
    for (int i = 1; i <= n; ++i)
        cout << 1 + rand() % 50 << ' ' << 1 + rand() % 200 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    solve();
    return 0;
}