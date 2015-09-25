#include <iostream>
#include <vector>

using namespace std;

#define maxn 102
#define x first
#define y second
pair<int, int> p[maxn];
vector<int> g[maxn];

int comp, viz[maxn];

void dfs(int x) {
    viz[x] = 1;
    for (int nb : g[x]) {
        if (!viz[nb]) dfs(nb);
    }
}

int main()
{
    int n, i, j, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (p[i].x == p[j].x || p[i].y == p[j].y) {
                g[i].push_back(j);
                g[j].push_back(i);
            }

    for (i = 1; i <= n; i++) {
        if (!viz[i]) dfs(i), comp++;
    }
    ans = comp - 1;
    cout << ans;
    return 0;
}
