#include <iostream>

using namespace std;

typedef long long ll;

ll t, n, ans;

ll lsb(ll x) {
    return x & -x;
}

int main()
{
    //

    cin >> t;
    while (t--) {
        cin >> n;
        ans = n * (n + 1) / 2;
        for (ll i = 1; i <= n; i <<= 1) {
            ans -= 2 * i;
        }
        cout << ans << '\n';
    }

    return 0;
}
