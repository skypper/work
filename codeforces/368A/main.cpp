#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, d, m, ans;
vector<int> a;

int main()
{
    //freopen("input", "r", stdin);

    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    sort(a.begin(), a.end());

    ans += accumulate(a.begin(), a.begin() + min(n, m), 0);
    ans -= max(0, m - n) * d;

    cout << ans;
    return 0;
}
