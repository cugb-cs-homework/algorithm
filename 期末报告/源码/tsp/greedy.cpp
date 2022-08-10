#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 55;
int G[maxn][maxn];
bool vis[maxn];

void solve() {
    int n, S;
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> G[i][j];
    vis[1] = 1;  //起点从1出发
    int ans = 0, now = 1, node, minn;
    for (int i = 1; i < n; ++i) {
        node = now, minn = inf;
        for (int j = 1; j <= n; ++j)
            if (!vis[j] && G[now][j] < minn) minn = G[now][j], node = j;
        vis[node] = 1, now = node, ans += minn;
        // cout << '(' << minn << ")->" << node << "-";
    }
    // cout << '(' << G[now][1] << ")->" << 1 << endl;
    ans += G[node][1];
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
         << "Runtime: " << (double)(end - start) << "ms\n";
#endif
    return 0;
}
/**
 * 5city: 1033 0ms
 * 10city: 1246 0ms
 * 20city: 1761 0ms
 * 50city: 1691 2ms
 */
