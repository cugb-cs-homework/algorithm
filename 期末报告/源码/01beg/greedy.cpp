#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 55;

struct thing {
    int weight, value, id;
} beg[maxn];

bool sortByValue(thing A, thing B) {  //物品价值大的优先
    return A.value > B.value;
}

bool sortByWeight(thing A, thing B) {  //物品重量轻的优先
    return A.weight < B.weight;
}

bool sortByRate(thing A, thing B) {  //物品价值重量比大的优先
    return A.value * 1.0 / A.weight > B.value * 1.0 / B.weight;
}

void solve() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        cin >> beg[i].weight;
    for (int i = 1; i <= n; ++i)
        cin >> beg[i].value, beg[i].id = i;

    int ans = 0;
    sort(beg + 1, beg + n + 1, sortByValue);
    int tempW = W, tempV = 0;
    for (int i = 1; i <= n; ++i) {
        if (beg[i].weight <= tempW)
            tempW -= beg[i].weight, tempV += beg[i].value;
    }
    ans = max(ans, tempV);

    tempW = W, tempV = 0;
    sort(beg + 1, beg + n + 1, sortByWeight);
    for (int i = 1; i <= n; ++i) {
        if (beg[i].weight <= tempW)
            tempW -= beg[i].weight, tempV += beg[i].value;
    }
    ans = max(ans, tempV);

    tempW = W, tempV = 0;
    sort(beg + 1, beg + n + 1, sortByRate);
    for (int i = 1; i <= n; ++i) {
        if (beg[i].weight <= tempW)
            tempW -= beg[i].weight, tempV += beg[i].value;
    }
    ans = max(ans, tempV);
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
 * 5thing: 269 0ms
 * 10thing: 147 0ms
 * 20thing: 326 0ms
 * 50thing: 822 0ms
 */
