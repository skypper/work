#include <iostream>

using namespace std;

int64_t ships(int64_t a, int64_t b) {
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return ships(b, a % b) + a / b;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int64_t a, b;
    cin >> a >> b;

    cout << ships(a, b);

    return 0;
}
