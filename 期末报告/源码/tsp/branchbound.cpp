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

struct node {
    bool vis[maxn];                        //标记走过的点
    int start, end;                        //第一个点、最后一个点
    int k, sum, lb;                        //走过的点数、路径距离、目标函数值
    bool operator<(const node &A) const {  //lb小的先出队
        return lb < A.lb;
    }
    node() = default;
    node(int start, int end, int k) : start(start), end(end), k(k) { memset(vis, 0, sizeof vis); }
};

priority_queue<node> que;  //创建一个优先队列
int low, up;               //下界和上界
bool dfs_vis[maxn];        //在dfs中搜索过

int dfs(int now, int nex, int len) {
    if (nex == n + 1) return len + dis[now][S];
    int minlen = 0x3f3f3f3f, p;
    for (int i = 1; i <= n; ++i)
        if (!dfs_vis[i] && minlen > dis[now][i])
            minlen = dis[now][i], p = i;
    dfs_vis[p] = true;
    return dfs(p, nex + 1, len + minlen);
}

void getup() {  //贪心法确定上界
    dfs_vis[S] = true;
    up = dfs(S, 2, 0);
}

void getlow() {  //确定下界
    double temp = 0;
    int tempdis[maxn];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            tempdis[j] = dis[i][j];
        sort(tempdis + 1, tempdis + 1 + n);
        temp += tempdis[2] + tempdis[3];
    }
    cout << temp << endl;
    low = ceil(temp * 1.0 / 2);
}

int getlb(node p) {
    int temp = p.sum * 2, minn = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        if (i == p.start) continue;
        minn = min(minn, dis[p.start][i]);
    }
    temp += minn;
    for (int i = 1; i <= n; ++i) {
        if (i == p.end) continue;
        minn = min(minn, dis[p.end][i]);
    }
    temp += minn;
    for (int i = 1; i <= n; ++i) {
        if (!p.vis[i]) {
            int tempdis[maxn];
            for (int j = 1; j <= n; ++j)
                tempdis[j] = dis[i][j];
            sort(tempdis + 1, tempdis + 1 + n);
            temp += tempdis[1] + tempdis[2];
        }
    }
    return ceil(temp * 1.0 / 2);
}

void solve() {
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dis[i][j];
    getup(), getlow();
    node st(S, S, 1);                           //起点终点走过的点
    st.vis[S] = true, st.sum = 0, st.lb = low;  //初始化标记
    cout << low << ' ' << up << endl;
    int ans = up;  //最终答案
    que.push(st);  //放入队列
    while (que.size()) {
        node now = que.top();
        que.pop();
        if (now.k == n) {  //走过了n个点更新答案
            ans = min(ans, now.sum + dis[now.end][now.start]);
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            if (now.vis[i]) continue;
            node nex;
            nex.start = now.start;
            nex.sum = now.sum + dis[now.end][i];
            nex.end = i;
            nex.k = now.k + 1;
            for (int j = 1; j <= n; ++j) nex.vis[j] = now.vis[j];
            nex.vis[i] = 1;
            nex.lb = getlb(nex);
            if (nex.lb > up) continue;  //剪枝
            que.push(nex);
        }
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
 * 5city: 1033 2ms
 * 10city: 981 45ms
 * 20city: -- >1h
 * 50city: -- --
 */