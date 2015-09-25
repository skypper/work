#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m, a[110], maxi, maxval = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = (a[i] - 1) / m;
        if (maxval <= a[i]) {
            maxval = a[i];
            maxi = i;
        }
    }
    cout << maxi;
    return 0;
}
