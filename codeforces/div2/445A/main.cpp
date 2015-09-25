#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m, a[110][110];

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;

            if (c == '-') {
                cout << '-';
            } else if (c == '.') {
                cout << ((i + j) % 2 == 0 ? 'B' : 'W');
            }
        }
        cout << '\n';
    }

    return 0;
}
