#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 2) {
        cout << "1\n1";
    } else if (n == 3) {
        cout << "2\n1 3";
    } else if (n == 4) {
        cout << "4\n3 1 4 2";
    } else if (n == 5) {
        cout << "5\n5 3 1 4 2";
    } else {
        int *v = new int[n];
        for (int i = 0; i < n / 2; ++i) {
            v[2 * i] = i + 1;
        }
        for (int i = 0; i < n / 2; ++i) {
            v[2 * i + 1] = n / 2 + 1 + i;
        }

        if (n % 2 == 1) {
            v[0] = n;
            v[n - 1] = 1;
        }

        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << v[i] << ' ';
        }
    }
    return 0;
}
