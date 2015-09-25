#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int *dp = new int[s.length() + 1]();
    dp[0] = 0;
    for (int i = 0; i < s.length(); ++i) {
        dp[i + 1] = dp[i];
        if (s[i] == s[i + 1]) {
            ++dp[i + 1];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        cout << dp[r - 1] - dp[l - 1] << '\n';
    }

    return 0;
}
