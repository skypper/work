#include <iostream>

using namespace std;

int main()
{
    //freopen("input", "r", stdin);

    int r1, c1, r2, c2, ans1, ans2, ans3;
    cin >> r1 >> c1 >> r2 >> c2;

    ans1 = 2;
    if (r1 == r2 || c1 == c2) {
        ans1 = 1;
    }
    ans2 = 0;
    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        ans2 = 2;
        if (abs(r1 - r2) == abs(c1 - c2)) {
            ans2 = 1;
        }
    }
    ans3 = max(abs(r1 - r2), abs(c1 - c2));
    cout << ans1 << ' ' << ans2 << ' ' << ans3;

    return 0;
}
