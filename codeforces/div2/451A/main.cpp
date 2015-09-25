#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ((min(n, m) & 1) ? "Akshat" : "Malvika");
    return 0;
}
