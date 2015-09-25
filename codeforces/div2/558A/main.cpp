#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> t_l, t_r;

int n;
long long ans;

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x, a;
        cin >> x >> a;

        pair<int, int> q = {x, a};
        if (x < 0) {
            t_l.push_back(q);
        } else if (x > 0) {
            t_r.push_back(q);
        }
    }

    sort(t_l.begin(), t_l.end(), greater<pair<int, int>>());
    sort(t_r.begin(), t_r.end());

    if (t_l.empty()) {
        ans += t_r[0].second;
    } else if(t_r.empty()) {
        ans = t_l[0].second;
    } else {
        int c = min(t_l.size(), t_r.size());

        for (int i = 0; i < c; ++i) {
            ans += t_l[i].second + t_r[i].second;
        }
        if (t_l.size() < t_r.size()) {
            if (c < t_r.size()) {
                ans += t_r[c].second;
            }
        } else if (t_l.size() == t_r.size()) {
            if (c < t_l.size() && c < t_r.size()) {
                ans += max(t_l[c].second, t_r[c].second);
            }
        } else if (t_l.size() > t_r.size()) {
            if (c < t_l.size()) {
                ans += t_l[c].second;
            }
        }
    }
    cout << ans;

    return 0;
}
