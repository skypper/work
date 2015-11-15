#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 200001;
int n, a[MAXN];
ll ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ans += abs(a[1]);
    for (int i = 1; i <= n - 1; i++) {
        ans += abs(a[i + 1] - a[i]);
    }

    cout << ans;

    return 0;
}
