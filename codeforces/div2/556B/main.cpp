#include <iostream>

using namespace std;

const int MAXN = 1010;
int n, a[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int steps = n - a[1];
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0 && (a[i] - steps + n) % n != (i - 1)) { // counter-clockwise
            cout << "No";
            return 0;
        } else if (i % 2 == 1 && (a[i] + steps) % n != (i - 1)) { // clockwise
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}
