#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 200001;
int n, a[MAXN];

ll BIT[MAXN], ans;
void update(ll x, ll val)
{
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
ll query(ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
ll query_single(ll x) {
    return query(n) - query(x);
}

int main()
{
    //freopen("input", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int val = a[i] - query_single(n - i + 1);
        if (val != 0) {
            ans += abs(val);
            update(n - i + 1, val);
        }
    }

    cout << ans;

    return 0;
}
