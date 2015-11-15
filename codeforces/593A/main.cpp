#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt[26], cnt2[26][26], ans;

int main()
{
    //freopen("input", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        fill(cnt, cnt + 26, 0);

        int distinct = 0;
        for (char x : s) {
            if (cnt[x - 'a'] == 0) {
                ++distinct;
            }
            ++cnt[x - 'a'];
        }
        if (distinct <= 2) {
            if (distinct == 1) {
                int k = s[0] - 'a';
                for (int j = 0; j < 26; ++j) {
                    cnt2[k][j] += s.size();
                    cnt2[j][k] += s.size();
                }
            }
            if (distinct == 2) {
                for (int j = 0; j < 26 - 1; ++j) {
                    for (int k = j + 1; k < 26; ++k) {
                        if (s.find(j + 'a') != string::npos && s.find(k + 'a') != string::npos) {
                            cnt2[j][k] += s.size();
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 26 - 1; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            ans = max(ans, cnt2[i][j]);
        }
    }
    cout << ans;

    return 0;
}
