#include <iostream>

using namespace std;

const int MAXN = 101;
int n, m, a[MAXN][MAXN];

bool included(int i, int j) {
    for (int k = 1; k <= 100 && included; ++k) {
        if (a[i][k] && !a[j][k]) {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            int t;
            cin >> t;
            a[i][t] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (included(j, i)) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
