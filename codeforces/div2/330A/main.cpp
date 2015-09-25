#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int r, c, x, y;
    char cake[12][12];

    cin >> r >> c;

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> cake[i][j];

    x = r;
    y = c;

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            if (cake[i][j] == 'S') {
                --x;
                break;
            }
        }

    for (int j = 0; j < c; ++j)
        for (int i = 0; i < r; ++i) {
            if (cake[i][j] == 'S') {
                --y;
                break;
            }
        }

    int ans = x * c + y * r - x * y;
    cout << ans;


    return 0;
}
