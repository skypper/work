#include <iostream>

using namespace std;

int main()
{
    int a[6];

    for (int i = 0; i < 6; ++i)
        cin >> a[i];

    cout << (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];

    return 0;
}
