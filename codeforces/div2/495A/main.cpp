#include <iostream>

using namespace std;

int main()
{
    int a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2}, n;
    cin >> n;
    int d1 = n / 10, d2 = n % 10;
    cout << a[d1] * a[d2];
    return 0;
}
