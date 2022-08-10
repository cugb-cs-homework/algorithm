#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int v[maxn], w[maxn], dp[maxn][maxn];  //维护的是从第i个物品到第n个物品在剩余容量为j的情况下能得到的最大价值

void solve() {
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    for (int i = n; i >= 1; --i) {
        cout << "----- " << i << " ----" << endl;
        for (int j = 0; j <= V; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i] && dp[i + 1][j - v[i]] + w[i] > dp[i][j]) {
                dp[i][j] = dp[i + 1][j - v[i]] + w[i];
                cout << dp[i][j] << '\t' << "when volumn is " << j << " choose " << i << endl;
                continue;
            }
            cout << dp[i][j] << '\t' << "when volumn is " << j << " do not choose " << i << endl;
        }
        cout << endl;
    }
    cout << "---- ans ----" << endl;
    cout << dp[1][V] << endl;
    int p = V;
    for (int i = 1; i <= n; ++i) {
        if (p == 0)  //背包满了直接退出
            break;
        else if (i == n && p >= v[i]) {  //特判最后一个物品需不需要装进背包
            cout << i << ' ';
            break;
        } else if (p >= v[i] && dp[i][p] == dp[i + 1][p - v[i]] + w[i]) {  //说明可以装下这个物品且装下后满足最优
            cout << i << ' ';
            p -= v[i];
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    solve();
    return 0;
}