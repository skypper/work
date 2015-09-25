#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int *v = new int[n + 1];
    set<pair<int, int>, greater<pair<int, int>>> parts;
    vector<set<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        parts.insert({v[i], i});
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    int ans = 0;
    for (pair<int, int> part : parts) {
        int idx = part.second;

        for (int neighbour : adj[idx]) {
            ans += v[neighbour];

            adj[neighbour].erase(idx);
        }
    }

    cout << ans;

    return 0;
}
