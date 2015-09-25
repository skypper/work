#include <iostream>

using namespace std;

int main()
{
    int n;
    int i, j, x;

    cin >> n;

    x = n / 2;
    for (i = 1; i <= n / 2; ++i) {
        j = 1;
        for (; j <= x; ++j) {
            cout << "*";
        }
        for (; j <= x + 2 * i - 1; ++j) {
            cout << "D";
        }
        for (; j <= n; ++j) {
            cout << "*";
        }
        --x;
        cout << "\n";
    }

    for (j = 1; j <= n; ++j) {
        cout << "D";
    }
    cout << "\n";
    ++i;

    ++x;
    for (; i <= n; ++i) {
        j = 1;
        for (; j <= x; ++j) {
            cout << "*";
        }
        for (; j <= x + 2 * (n - i) + 1; ++j) {
            cout << "D";
        }
        for (; j <= n; ++j) {
            cout << "*";
        }
        ++x;
        cout << "\n";
    }

    return 0;
}
