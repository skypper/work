#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, min[4], max[4], given[4], remaining[4];

    cin >> n;
    int given_no = 0;
    for (int i = 1; i <= 3; ++i) {
        cin >> min[i] >> max[i];
        given[i] = min[i], given_no += min[i];
        remaining[i] = max[i] - min[i];
    }

    int deg = 1;
    while (given_no < n) {
        given_no += remaining[deg];
        given[deg] += remaining[deg];
        deg++;
    }

    if (deg <= 4) {
        given[deg - 1] -= given_no - n;
    }

    for (int i = 1; i <= 3; ++i) {
        cout << given[i] << " ";
    }
    return 0;
}
