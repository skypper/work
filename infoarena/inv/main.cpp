#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MOD 9917

using namespace std;

int *aux;
int count_inv(int lo, int hi, vector<int> &v) {
    if (lo == hi) {
        return 0;
    } else {
        int inv = 0, mid = lo + (hi - lo) / 2;
        int inv1 = count_inv(lo, mid, v);
        int inv2 = count_inv(mid + 1, hi, v);

        int i = lo, j = mid + 1, k = 0;
        while (i <= mid && j <= hi) {
            if (v[i] <= v[j]) {
                aux[k] = v[i];
                ++i;
                ++k;
            } else {
                aux[k] = v[j];
                ++j;
                ++k;
                inv += mid - i + 1;
            }
        }
        if (i <= mid) {
            while (i <= mid) {
                aux[k] = v[i];
                ++i;
                ++k;
            }
        }
        if (j <= hi) {
            while (j <= hi) {
                aux[k] = v[j];
                ++j;
                ++k;
            }
        }

        for (i = lo; i <= hi; ++i) {
            v[i] = aux[i - lo];
        }

        inv = (inv + (inv1 + inv2) % MOD) % MOD;

        return inv;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input", "r", stdin);
#else
    ifstream cin("inv.in");
    ofstream cout("inv.out");
#endif // LOCAL

    int n;
    cin >> n;
    vector<int> v(n);
    aux = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << count_inv(0, n - 1, v);
    delete [] aux;

    return 0;
}
