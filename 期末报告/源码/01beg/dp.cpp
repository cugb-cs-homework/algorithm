#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define debug(x) cout << "debug: " << x << endl;
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;

int v[maxn], w[maxn], dp[maxn], sum[maxn];

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i], sum[i] = sum[i - 1] + v[i];
    for (int i = 1; i <= n; ++i) {
        int bound = max(w[i], W - (sum[n] - sum[i]));  //前缀和处理
        for (int j = W; j >= bound; --j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    cout << dp[W] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
#ifdef LOCAL
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    clock_t start, end;
    start = clock();
#endif
    solve();
#ifdef LOCAL
    end = clock();
    cout << endl
         << "Runtime: " << (double)(end - start) << "ms\n";
#endif
    return 0;
}
/**
 * 5thing: 468 0ms
 * 10thing: 505 0ms
 * 20thing: 709 0ms
 * 50thing: 2113 0ms
 */