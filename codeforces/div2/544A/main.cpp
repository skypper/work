#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    char c;
    int k, d[26];
    cin >> k >> s;

    set<char> ss(s.begin(), s.end());
    if (k > ss.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        for (int i = 0; i < k - 1; ++i) {
            int j = 0;
            d[s[j] - 97] = 1; // 97 - ASCII code for 'a'

            cout << s[j];
            ++j;
            while (d[s[j] - 97] == 1) {
                cout << s[j];
                ++j;
            }
            cout << endl;
            s = s.substr(j);
        }
        cout << s;
    }

    return 0;
}
