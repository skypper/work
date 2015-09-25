#include <iostream>

using namespace std;

int n, t, ans;
double p, pr[2002][2002], exp;

int main()
{
    cin >> n >> p >> t;
    pr[0][0] = 1;
    for (int now = 1; now <= t; now++) {
        for (int persons = 0; persons <= n; persons++) {
            if (persons == n) {
                pr[now + 1][persons] = pr[now][persons];
            } else {
                pr[now][persons + 1] += pr[now - 1][persons] * p;
                pr[now][persons] += pr[now - 1][persons] * (1 - p);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        exp += pr[t][i] * i;
    }
    cout << fixed << setprecision(7) << exp;
    return 0;
}
