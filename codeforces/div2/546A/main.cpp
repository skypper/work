#include <iostream>

using namespace std;

int f(int k, int n) {
    return k * n * (n + 1) / 2;
}

int main()
{
    int k, n, w;
    cin >> k >> n >> w;

    int borrow = f(k, w) - n;
    if (borrow > 0) {
        cout << borrow;
    } else {
        cout << 0;
    }

    return 0;
}
