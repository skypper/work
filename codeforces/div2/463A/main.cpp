#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, x[110], y[110], p[110];

bool comp(int a, int b) {
    return y[a] > y[b];
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        if (y[i] > 0) {
            ++x[i];
        }
        y[i] = (100 - y[i]) % 100;
        p[i] = i;
    }

    sort(p + 1, p + 1 + n, comp);

    for (int i = 1; i <= n; ++i) {
        if (x[p[i]] <= s) {
            cout << y[p[i]];
            return 0;
        }
    }

    cout << -1;


    return 0;
}
