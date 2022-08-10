#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 105;

int dis[maxn][maxn];
void solve() {
    int n, S;
    cin >> n >> S;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dis[i][j];
    int a[n + 1] = {};
    for (int i = 1; i <= n; ++i) a[i] = i;
    int ans = 0x3f3f3f3f;
    do {
        if (a[1] != S) break;
        int temp = 0;
        for (int i = 2; i <= n; ++i)
            temp += dis[a[i - 1]][a[i]];
        temp += dis[a[n]][a[1]];
        ans = min(ans, temp);
        // for (auto &e : a) cout << e << ' ';
        // cout << temp << endl;
    } while (next_permutation(a + 1, a + 1 + n));
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
         << "Runtime: " << fixed << setprecision(3) << (double)(end - start) << "ms\n";
#endif
    return 0;
}
/**
 * 5city: 1033 0ms 
 * 10city: 981 18ms
 * 20city: -- >30years
 * 50city: -- >4^56years
 */