#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001;
int n, marked[MAXN], f1[MAXN], f2[MAXN];
vector<int> challenged_by[MAXN];

int main()
{
    freopen("input", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        f1[i] = x;
        challenged_by[x].push_back(i);
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        int x;
        cin >> x;
        f2[i] = x;
        challenged_by[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        marked[i] = 1;
    }

    for (int i = n + 1; i <= 2 * n; ++i) {
        marked[i] = 1;
        for (int x : challenged_by[i]) {
            marked[x] = 0;
        }
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (marked[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}
