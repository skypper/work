#include <iostream>

using namespace std;

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    int n, x = 0;
    char c;
    cin >> n;
    while (n--) {
        cin >> c;
        if (c == '0')
            --x;
        else if (c == '1')
            ++x;
    }
    cout << abs(x);
    return 0;
}
