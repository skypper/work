#include <iostream>
#include <algorithm>

using namespace std;

int n, a[2010], p[2010], r[2010];

bool comp(int i, int j) {
    return a[i] > a[j];
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = i;
    }

    sort(p + 1, p + n + 1, comp);

    int rating = 1;
    for (int i = 1; i <= n; ++i) {
        r[p[i]] = rating;
        int x = rating;
        ++rating;

        int y = a[p[i]];
        while (i + 1 <= n && a[p[i + 1]] == y) {
            r[p[i + 1]] = x;
            ++rating;
            ++i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << r[i] << " ";
    }

    return 0;
}
