#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100001;

int main()
{
    ifstream cin("darb.in");
    ofstream cout("darb.out");

    int ans = 0, n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, 0);

    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int last;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u]) {
            if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        last = u;
    }

    for (int i = 1; i <= n; ++i) {
        dist[i] = 0;
    }
    Q.push(last);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u]) {
            if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                Q.push(v);
                ans = max(ans, dist[v]);
            }
        }
    }

    cout << ans + 1;
    cin.close();
    cout.close();

    return 0;
}
