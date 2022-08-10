#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn = 20;

int c[maxn][maxn];
int dp[1 << maxn][maxn];

void solve() {
    int n, S;
    cin >> n >> S;
    memset(dp, 0x3f, sizeof dp);
    //存边
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];
    //初始化边界
    --S;
    dp[1 << S][S] = 0;
    for (int i = 0; i < (1 << n); ++i) {  //枚举状态
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {           //枚举出发点
                for (int k = 0; k < n; ++k) {  //枚举下一个点
                    if (i & (1 << k))
                        continue;
                    else
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + c[j][k]);
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;  //答案
    for (int i = 0; i < n; ++i)
        ans = min(ans, dp[(1 << n) - 1][i] + c[i][S]);
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
         << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
/**
 * 5city: 1033 0.037s
 * 10city: 981 0.044s
 * 20city: 800 0.852s
 * 50city: -- >1.5s
 */