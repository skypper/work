#include <iostream>

using namespace std;

const int MAXN = 2 * 10e6 + 1;
int n, t, c, ans;

int main()
{
    //freopen("input", "r", stdin);

    cin >> n >> t >> c;
    int l = 0;
    for (int i = 1; i <= n; ++i) {
        int severity;
        cin >> severity;

        if (severity <= t) {
            l++;
        } else {
            ans += max(0, l - c + 1);
            l = 0;
        }
    }

    ans += max(0, l - c + 1);

    cout << ans;

    return 0;
}
