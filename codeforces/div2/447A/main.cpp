#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int p, n;
    cin >> p >> n;

    vector<bool> occ(p, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (occ[x % p] == 1) {
            cout << i;
            return 0;
        } else {
            occ[x % p] = 1;
        }
    }
    cout << "-1";

    return 0;
}
