#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, k;
    map<int, int> m[2];

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x % k != 0) {
        } else {

            ++m[1][x];
        }
        ++m[0][x];
    }

    return 0;
}
