#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25;  //顶点数

int n, m;
int dis[maxn], pre[maxn];
int graph[maxn][maxn];
vector<string> path[maxn];

void dp_path() {
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0;
    path[0].push_back("0");
    for (int i = 1; i < n; ++i) {
        cout << "------- " << i << " ------" << endl;
        for (int j = 0; j <= i - 1; ++j) {
            if (dis[i] == dis[j] + graph[j][i]) {
                for (auto &e : path[j]) path[i].push_back(e + "->" + to_string(i));
                cout << "find another transit point: " << j << endl;
            }
            if (dis[i] > dis[j] + graph[j][i]) {
                dis[i] = dis[j] + graph[j][i], path[i].clear();
                for (auto &e : path[j]) path[i].push_back(e + "->" + to_string(i));
                cout << "find a better transit point: " << j << endl;
            }
        }

        cout << "dis[" << i << "]: " << dis[i] << '\t';
        for (auto &e : path[i])
            cout << e << '\t';
        cout << endl;
        cout << endl;
    }
}

void solve() {
    cin >> n >> m;
    memset(graph, 0x3f, sizeof graph);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    dp_path();
    cout << "------- ans ------" << endl;
    cout << dis[n - 1] << endl;
    for (auto &e : path[n - 1]) cout << e << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    solve();
    return 0;
}