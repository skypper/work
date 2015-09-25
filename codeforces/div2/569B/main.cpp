#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100001;
int n, a[MAXN], fq[MAXN];

int main()
{
    ifstream cin("input");

    cin >> n;
    vector<int> res(n + 1);
    multimap<int, int> duplicate;
    set<int> non_occupied;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        fq[a[i]]++;
        if (fq[a[i]] >= 2) {
            duplicate.emplace(a[i], i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (fq[i] == 0) {
            non_occupied.insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] > n) {
            int val = *non_occupied.begin();
            non_occupied.erase(non_occupied.begin());
            res[i] = val;
        } else if (fq[a[i]] == 1) {
            /// for unique elements just fix the element where it was
            res[i] = a[i];
        } else if (fq[a[i]] >= 2) {
            /// for duplicate elements fix one duplicate in its position
            res[i] = a[i];

            /// and then try to fix the other duplicates in the non-occupied positions
            /// with a not taken id
            auto it = duplicate.lower_bound(a[i]);
            auto it2 = duplicate.upper_bound(a[i]);
            while (it != it2) {
                int val = *non_occupied.begin();
                non_occupied.erase(non_occupied.begin());

                int idx = it->second;

                res[idx] = val;
                it++;
            }
        }

        fq[a[i]] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}
