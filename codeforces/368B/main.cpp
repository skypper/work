#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
vector<int> a, distinct;
unordered_set<int> x;

int main()
{
    //freopen("input", "r", stdin);

    cin >> n >> m;
    a.resize(n);
    distinct.resize(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    distinct[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        distinct[i] = distinct[i + 1];
        if (x.find(a[i]) == x.end()) {
            x.insert(a[i]);
            ++distinct[i];
        }
    }

    for (int i = 1; i <= m; ++i) {
        int l;
        cin >> l;
        cout << distinct[l - 1] << '\n';
    }

    return 0;
}
