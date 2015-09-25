#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, d, a[110], s = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }

    // check the feasibility of the solution
    if (s + (n - 1) * 10 <= d) {
        cout << (d - s) / 5;
    } else {
        cout << -1;
    }


    return 0;
}
