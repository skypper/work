#include <iostream>
#include <vector>
#include <stack>

#define MAXN 100010

using namespace std;

int N, M;
vector<int> adj[MAXN], con, idx, lowlink, in_stack;
vector<vector<int>> C;
stack<int> S;
int index = 0;

void tarjan(int n) {
    idx[n] = lowlink[n] = index;
    index++;
    S.push(n), in_stack[n] = 1;

    for (int v : adj[n]) {
        if (idx[v] == -1) {
            tarjan(v);
            lowlink[n] = min(lowlink[n], lowlink[v]);
        } else if (in_stack[v]) {
            lowlink[n] = min(lowlink[n], lowlink[v]);
        }
    }

    if (idx[n] == lowlink[n]) {
        con.clear();
        int node;
        do {
            node = S.top();
            con.push_back(node);
            S.pop();
            in_stack[node] = 0;
        } while (node != n);
        C.push_back(con);
    }
}

int main() {
    iostream::sync_with_stdio(false);
    freopen("ctc.in", "r", stdin);
    freopen("ctc.out", "w", stdout);

    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }

    idx.resize(N), lowlink.resize(N), in_stack.resize(N);
    idx.assign(N, -1), in_stack.assign(N, 0);

    for (int i = 0; i < N; ++i) {
        if (idx[i] == -1) {
            tarjan(i);
        }
    }

    cout << C.size() << "\n";
    for (const vector<int> &x : C) {
        for (int y : x) {
            cout << y + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
