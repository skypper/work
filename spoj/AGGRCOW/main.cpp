#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100001;
const int MAXA = 1000000001;
int t, n, c, a[MAXN];

bool func(int num) {
    int m = 0, x = a[1];
    for (int i = 1; i <= n; ++i) {
        ++m;
        if (m == c) {
            return 1;
        }
        x = a[i] + num - 1;

        while (i <= n && a[i] <= x) {
            ++i;
        }
        --i;
    }

    return 0;
}

int main()
{
    //freopen("input", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> c;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int ans = 0, lo = 1, hi = MAXA;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (func(mid)) {
                lo = mid + 1;
                ans = max(ans, mid);
            } else {
                hi = mid;
            }
        }
        cout << ans << ' ';
    }

    return 0;
}
