#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    pair<int, int> sol[1009];
    set<pair<int, int> > h;

    cin >> n >> k;
    int i, a;
    for (i = 1; i <= n; i++) {
        cin >> a;
        h.insert(make_pair(a, i));
    }

    int ok = 1;
    pair<int, int> b, c;
    i = 0;
    while (k-- && ok) {
        i++;
        ok = 0;
        b = *h.begin();
        c = *(--h.end());
        if (c.first - b.first > 1) {
            ok = 1;
            sol[i].first = c.second;
            sol[i].second = b.second;
            h.erase(h.begin());
            h.erase(--h.end());
            c.first--;
            b.first++;
            h.insert(b);
            h.insert(c);
        }
    }
    if (!ok) i--;
    cout << ((--h.end())->first - h.begin()->first) << ' ' << i << '\n';
    for (a = 1; a <= i; a++) {
        cout << sol[a].first << ' ' << sol[a].second << '\n';
    }
    return 0;
}
