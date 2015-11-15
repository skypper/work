#include <iostream>
#include <vector>

using namespace std;

const int MAXN = (int) 1e5 + 1;
int n, marked[MAXN], white[MAXN], dp[MAXN];
vector<int> g[MAXN], ans;

void dfs(int u, int prev = -1) {
    marked[u] = 1;

    dp[u] = white[u];

    for (int v : g[u]) {
        if (v == prev) {
            continue;
        }
        dfs(v, u);
        dp[u] += dp[v];
    }
}

int main()
{
    //freopen("input", "r", stdin);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x, y, t;
        cin >> x >> y >> t;

        g[x].push_back(y);
        g[y].push_back(x);

        if (t == 2) {
            white[x] = 1;
            white[y] = 1;
        }
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        if (white[i] == 1 && dp[i] == 1) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}
