#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    //ifstream cin("input");

    int na, nb, k, m;
    cin >> na >> nb >> k >> m;
    vector<int> a(na + 1), b(nb + 1);
    for (int i = 1; i <= na; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= nb; ++i) {
        cin >> b[i];
    }

    if (a[k] < b[nb - m + 1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
