#include <iostream>

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);

    int n, a[1001], x = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            x = 1;
        }
    }

    if (x == 1) {
        cout << "-1";
    } else {
        cout << "1";
    }

    return 0;
}
