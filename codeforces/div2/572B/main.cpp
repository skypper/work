#include <fstream>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    //ifstream cin("input");

    int n, s, min_psell = int(10e5 + 1), max_pbuy = -1;
    cin >> n >> s;

    map<int, int, greater<int>> m;
    for (int i = 1; i <= n; ++i) {
        char d;
        int p, q;
        cin >> d >> p >> q;

        if (d == 'S') {
            min_psell = min(min_psell, p);
        } else if (d == 'B') {
            max_pbuy = max(max_pbuy, p);
        }
        m[p] += q;
    }

    auto it_sep = m.upper_bound(min_psell);
    auto it = m.begin();
    if (distance(m.begin(), it_sep) > s) {
        advance(it, distance(m.begin(), it_sep) - s);
    }
    for (int i = 0; i < s && it != it_sep; ++i, ++it) {
        cout << "S " << it->first << ' ' << it->second << '\n';
    }
    it = m.lower_bound(max_pbuy);
    for (int i = 0; i < s && it != m.end(); ++i, ++it) {
        cout << "B " << it->first << ' ' << it->second << '\n';
    }

    return 0;
}
