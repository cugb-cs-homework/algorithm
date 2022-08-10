#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 55;

int arr[maxn];
int w[maxn], v[maxn];

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i) arr[i] = i;
    int ans = 0;
    do {
        int tempW = W, tempV = 0;
        for (int i = 1; i <= n; ++i) {
            if (tempW >= w[arr[i]])
                tempW -= w[arr[i]], tempV += v[arr[i]];
            else
                break;
        }
        ans = max(ans, tempV);
    } while (next_permutation(arr + 1, arr + 1 + n));
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
 * 5thing: 468 1ms
 * 10thing: 505 161ms
 * 20thing: -- >10min
 * 50thing: -- --
 */