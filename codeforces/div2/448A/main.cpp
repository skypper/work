#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int a[4], b[4], n, x, y;
    x = y = 0;

    for (int i = 1; i <= 3; ++i) {
        cin >> a[i];
        x += a[i];
    }
    for (int i = 1; i <= 3; ++i) {
        cin >> b[i];
        y += b[i];
    }
    cin >> n;

    int z = (x + 5 - 1) / 5 + (y + 10 - 1) / 10;
    if (z <= n) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}
