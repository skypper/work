#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int *f = new int[m + 1]();
    for (int i = 1; i <= m; ++i) {
        cin >> f[i];
    }

    sort(f + 1, f + 1 + m);
    int ans = 1 << 30;
    for (int i = 1; i <= m - n + 1; ++i) {
        int dif = f[n + i - 1] - f[i];
        ans = min(ans, dif);
    }
    cout << ans;

    return 0;
}
