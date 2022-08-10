#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int arr[maxn];

void HeapAdjust(int s, int m) {  //s是堆的第一个元素，m是堆的最后一个元素
    arr[0] = arr[s];             //将堆的第一个值赋给哨兵位置
    for (int j = 2 * s; j <= m; j *= 2) {
        if (j < m && arr[j] < arr[j + 1]) j++;  //找出孩子中最大的
        if (arr[0] >= arr[j]) break;            //符合大顶推退出调整
        arr[s] = arr[j];                        //把较大的字节点往上移动替换它的父节点
        s = j;                                  //更新当前要移动的点要放的位置
    }
    arr[s] = arr[0];  //交换
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = n / 2; i > 0; --i)  //建堆从第n/2个位置依次往上调整
        HeapAdjust(i, n);
    for (int i = n; i > 1; --i) {  //交换堆顶和堆底，执行n-1次
        swap(arr[1], arr[i]);
        HeapAdjust(1, i - 1);  //堆调整从第一个位置调整
    }
    for (int i = 1; i <= n; ++i) {
        cout << left << setw(6) << arr[i];
        if (i % 5 == 0) cout << endl;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("IO\\in.txt", "r", stdin);
    freopen("IO\\out.txt", "w", stdout);
    clock_t start, end;
    start = clock();
    solve();
    end = clock();
    cout << endl
         << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";  //看下时间
    return 0;
}
