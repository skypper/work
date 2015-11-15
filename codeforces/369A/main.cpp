#include <iostream>

using namespace std;

int main()
{
    //freopen("input", "r", stdin);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            if (m > 0) {
                --m;
            } else {
                ++ans;
            }
        } else if (a == 2) {
            if (k > 0) {
                --k;
            } else {
                if (m > 0) {
                    --m;
                } else {
                    ++ans;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
