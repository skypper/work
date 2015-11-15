#include <iostream>

using namespace std;

int main()
{
    long long a, b, ans = 0;
    cin >> a >> b;

    while (a > 0 && b > 0) {
        if (a > b) {
            ans += a / b;
            a %= b;
        } else {
            ans += b / a;
            b %= a;
        }
    }

    cout << ans;
    return 0;
}
