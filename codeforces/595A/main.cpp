#include <iostream>

using namespace std;

int main()
{
    //freopen("input", "r", stdin);

    int n, m, x, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i) {
        int a, b;
        cin >> a >> b;
        ans += max(a, b);
    }

    cout << ans;

    return 0;
}
