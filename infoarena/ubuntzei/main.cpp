#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define pb push_back

using namespace std;

const int MAXN = 2001;
const int MAXK = 16;
const uint64_t INF = 0x3f3f3f3f;

int n, m, k;

uint64_t d[MAXN][MAXN] = {};

int main()
{
    ifstream cin("ubuntzei.in");
    ofstream cout("ubuntzei.out");

    cin >> n >> m >> k;

    // initializare
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }

    vector<int> c(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; ++i) {
        uint64_t x, y, z;
        cin >> x >> y >> z;

        d[x][y] = d[y][x] = z;
    }
    for (int t = 1; t <= n; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
            }
        }
    }

    if (k > 0) {
        uint64_t minlen = ~0;
        uint64_t perm[MAXK];

        for (int i = 1; i <= k; ++i) {
            perm[i] = i;
        }

        do {;
            uint64_t len = 0;

            len += d[1][c[perm[1]]];
            for (int i = 1; i <= k - 1; ++i) {
                len += d[c[perm[i]]][c[perm[i + 1]]];
            }
            len += d[c[perm[k]]][n];

            minlen = min(minlen, len);
        } while (next_permutation(perm + 1, perm + 1 + k));

        cout << minlen;
    } else {
        cout << d[1][n];
    }

    return 0;
}
