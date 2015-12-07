#include <iostream>
#include <algorithm>

using namespace std;

const int SQRTN = 32001;
int t, m, n, prime[SQRTN];

void init_sieve() {
    fill(prime + 1, prime + 32000, 1);
    prime[1] = 0;
    for (int i = 4; i < SQRTN; i += 2) {
        prime[i] = 0;
    }
    for (int i = 6; i < SQRTN; i += 3) {
        prime[i] = 0;
    }

    for (int i = 5; i < SQRTN; ++i) {
        for (int j = i * i; j < SQRTN; j += i) {
            prime[j] = 0;
        }
    }
}

bool is_prime(int x) {
    if (x < SQRTN) {
        return prime[x];
    } else {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //freopen("input", "r", stdin);

    init_sieve();

    cin >> t;
    while (t--) {
        cin >> m >> n;

        for (int i = m; i <= n; ++i) {
            if (is_prime(i)) {
                cout << i << '\n';
            }
        }

        cout << '\n';
    }
    return 0;
}
