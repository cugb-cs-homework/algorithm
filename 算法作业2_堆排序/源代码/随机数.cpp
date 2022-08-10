#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll a = 1, b = 10000;  //规定生成随机数的范围

signed main(int argc, char *argv[]) {
    freopen("IO\\in.txt", "w", stdout);
    stringstream ss;
    ll seed = time(NULL);
    if (argc > 1) {  //如果传入了参数
        ss.clear();
        ss << argv[1];
        ss >> seed;  //把参数转换成整数赋值给seed
    }
    //rand_max=32767
    auto random = [] {  //加强随机数范围,生成数在[a,b]
        return a + rand() * rand() % (b - a + 1);
    };
    srand(seed);

    /**
     * @author pengpenglnag
     * 下面利用利用rand()或者自定义的random()生成随机数
     */

    int len = 10000;
    cout << len << endl;
    for (int i = 1; i <= len; ++i) {
        cout << left << setw(6) << random();
        if (i % 5 == 0) cout << endl;
    }
    cout << endl;
    return 0;
}