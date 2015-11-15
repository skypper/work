#include <iostream>

using namespace std;

const int MAXN = 101;
int n, k, a[MAXN], ans, ones, twos;

int main()
{
    //freopen("input", "r", stdin);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        ones = twos = 0;
        for (int j = i; j <= n; j += k) {
            if (a[j] == 1) {
                ++ones;
            } else if (a[j] == 2) {
                ++twos;
            }
        }

        if (ones * twos != 0) {
            ans += min(ones, twos);
        }
    }

    cout << ans;
    return 0;
}
