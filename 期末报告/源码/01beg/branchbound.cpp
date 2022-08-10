#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 55;

int lb, ub;
pii a[maxn];

struct node {
    int w, v, bound, step;
    bool operator<(const node &A) const {
        return this->bound > A.bound;
    }
    node(int w, int v, int bound, int step) : w(w), v(v), bound(bound), step(step) {}
};

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, [=](pii A, pii B) {
        return A.second * 1.0 / A.first > B.second * 1.0 / B.first;
    });
    int tmp = W;
    for (int i = 1; i <= n; ++i)
        if (tmp >= a[i].first) tmp -= a[i].first, lb += a[i].second;
    tmp = W;
    ub = a[1].second * 1.0 / a[1].first * tmp;
    priority_queue<node> que;
    que.push(node(0, 0, 0, 0));
    int ans = 0;
    while (que.size()) {
        auto now = que.top();
        ans = max(ans, now.v);
        que.pop();
        auto nex = now;
        nex.step = now.step + 1;
        if (now.step == n + 1) continue;
        //先考虑不装进去
        auto tmp = nex;
        if (W - now.w >= a[tmp.step].first) {
            tmp.w = tmp.w + a[tmp.step].first;
            tmp.v = tmp.v + a[tmp.step].second;
            if (tmp.step != n)
                tmp.bound = tmp.v + (W - tmp.w) * a[tmp.step + 1].second * 1.0 / a[tmp.step + 1].first;
            if (tmp.bound >= lb && tmp.bound <= ub) que.push(tmp);
        }
        tmp = nex;
        if (tmp.step != n)
            tmp.bound = tmp.v + (W - tmp.w) * a[tmp.step + 1].second * 1.0 / a[tmp.step + 1].first;
        if (tmp.bound >= lb && tmp.bound <= ub) que.push(tmp);
    }
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
 * 468 0ms
 * 505 1ms
 * 709 1ms
 * 2113 1ms
 */
