#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct Comp {
    int a, b;

    bool operator<(const Comp& that) const {
        return a < that.a;
    }
} comp[100010];

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> comp[i].a >> comp[i].b;
    }

    sort(comp + 1, comp + 1 + n);

    for (int i = 2; i <= n; ++i) {
        if (comp[i - 1].b > comp[i].b) {
            cout << "Happy Alex";
            return 0;
        }
    }

    cout << "Poor Alex";

    return 0;
}
