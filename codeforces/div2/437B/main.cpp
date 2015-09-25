#include <iostream>
#include <vector>
#include <set>

using namespace std;

inline int lsb(int x) {
    return (-x & x);
}

int main()
{
    int sum, limit;
    cin >> sum >> limit;

    vector<int> ans;

    if (limit >= sum) {
        for (int i = 1; i <= sum; i <<= 1) {
            if (i & sum) {
                ans.push_back(i);
            }
        }
    } else {
        set<pair<int, int>, greater<pair<int, int>>> gr;
        for (int i = 1; i <= limit; ++i) {
            gr.insert({lsb(i), i});
        }

        int s = 0;
        for (pair<int, int> x : gr) {
            int l = x.first;
            int t = x.second;

            if (s + l <= sum) {
                s += l;

                ans.push_back(t);
            }
        }

        if (s != sum) {
            cout << -1;
            return 0;
        }
    }

    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}
