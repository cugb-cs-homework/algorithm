#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, x, y) for (auto i = (x); i != (y + 1); ++i)
#define dep(i, x, y) for (auto i = (x); i != (y - 1); --i)
#ifdef LOCAL
#define de(...) cout << '[' << #__VA_ARGS__ << "] = " << __VA_ARGS__ << endl;
#else
#define de(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 55;

int n, W;
int w[maxn], v[maxn];

int dfs(int now, int tempW, int tempV) {
    if (now == n + 1) return 0;
    int ans = tempV;
    if (w[now] <= tempW) ans = max(ans, dfs(now + 1, tempW - w[now], tempV + v[now]));
    ans = max(ans, dfs(now + 1, tempW, tempV));
    return ans;
}

void solve() {
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    cout << dfs(1, W, 0) << endl;
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
 * 5thing: 468 1ms
 * 10thing: 505 1ms
 * 20thing: 709 2ms
 * 50thing: 2113 15075ms
 */