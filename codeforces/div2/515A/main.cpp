#include <iostream>

int abs(int x) {
    return x < 0 ? -x : x;
}

using namespace std;

int a, b, s;

int main()
{
    cin >> a >> b >> s;
    if ((abs(a) + abs(b)) % 2 == s % 2 && s >= abs(a) + abs(b))
        cout << "Yes";
    else cout << "No";
    return 0;
}
