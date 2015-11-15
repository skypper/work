#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long a, b, ans, r;

int main()
{
    //freopen("input", "r", stdin);

    cin >> a >> b;
    r = a / gcd(a, b) * b / gcd(a, b);
    while (r % 2 == 0) {
        r /= 2;
        ++ans;
    }

    while (r % 3 == 0) {
        r /= 3;
        ++ans;
    }

    while (r % 5 == 0) {
        r /= 5;
        ++ans;
    }

    if (r != 1) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
