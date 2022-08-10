#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 55;
int n, S;
int dis[maxn][maxn];
int vis[maxn];
int ans = 0x3f3f3f3f;

void dfs(int now, int cnt, int temp) {
    if (temp >= ans) return;  //简单优化
    if (cnt == n)
        if (accumulate(vis + 1, vis + 1 + n, 0) == n) ans = min(ans, temp + dis[now][S]);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(i, cnt + 1, temp + dis[now][i]);
        vis[i] = 0;
    }
}

void solve() {
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dis[i][j];
    vis[S] = 1;
    dfs(S, 1, 0);
    cout << ans << endl;
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
         << "Runtime: " << (double)(end - start)  << "ms\n";
#endif
    return 0;
}
/**
 * 5city: 1033 0ms
 * 10city: 981 1ms
 * 20city: 800 9017ms
 * 50city: -- >30min
 */