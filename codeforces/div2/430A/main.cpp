#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 103;
int n, m, ans[MAXN];
pair<int, int> pts[MAXN];

int main()
{
    //freopen("input", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> pts[i].first;
        pts[i].second = i;
    }
    for (int i = 1; i <= m; ++i) {
        int a;
        cin >> a >> a;
    }

    sort(pts + 1, pts + 1 + n);

    for (int i = 1; i <= n; ++i) {
        ans[pts[i].second] = i & 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
