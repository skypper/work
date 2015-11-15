#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

const int MAXN = 50005, MAXM = 250005;
const long long INF = 0x3f3f3f;

int n, m;
vector<pair<int, int> > G[MAXN];

int cntInQueue[MAXN];
long long d[MAXN];
bool negative_cycles;

void ReadData() {
    scanf("%d %d", &n, &m);
    int x, y, c;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &c);
        G[x].push_back(make_pair(y, c));
    }
}

void Solve() {
    for (int i = 2; i <= n; i++)
        d[i] = INF;

    queue<int> Q;
    bitset <MAXN> inQueue(false);
    Q.push(1);
    inQueue[1] = true;

    while (!Q.empty() && !negative_cycles) {
        int u = Q.front();
        Q.pop();
        inQueue[u] = false;

        for (pair<int, int> adj : G[u]) {
            int v = adj.first;
            int weight = adj.second;

            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;

                if (!inQueue[v]) {
                    if (cntInQueue[v] > n) {
                        negative_cycles = true;
                        break;
                    }
                    Q.push(v);
                    inQueue[v] = true;
                    cntInQueue[v]++;
                }
            }
        }
    }
}

void WriteData() {
    if (negative_cycles)
        printf("Ciclu negativ!");
    else
        for (int i = 2; i <= n; i++)
            printf("%lld ", d[i]);
}

int main() {
    freopen("bellmanford.in", "r", stdin);
    freopen("bellmanford.out", "w", stdout);

    ReadData();
    Solve();
    WriteData();

    return 0;
}
