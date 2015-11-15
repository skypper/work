#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXLEN = 100001;

int main()
{
#ifdef LOCAL
    freopen("input", "r", stdin);
#else
    ifstream cin("parantezare.in");
    ofstream cout("parantezare.out");
#endif // LOCAL

    string s;
    cin >> s;

    int m;
    cin >> m;

    vector<int> st;
    vector<pair<int, int>> q(m);
    vector<int> ans(m);

    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        q[i] = {x, i};
    }

    sort(q.begin(), q.end());

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push_back(i);
        } else if (s[i] == ')') {
            int u = st.back();

            int lo = 0, hi = m, pos = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (q[mid].first == u) {
                    pos = mid;
                    break;
                } else if (q[mid].first < u) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (pos != -1) {
                ans[q[pos].second] = i;
            }

            st.pop_back();
        }
    }
    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}
