#include <iostream>

using namespace std;

bool ff(string s, string t) {
    for (int i = 0; i < s.length(); ++i) {
        if (t[i] != '.' && t[i] != s[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

    int l;
    string cw;
    cin >> l >> cw;
    for (int i = 0; i < 8; ++i) {
        if (s[i].size() == l && ff(s[i], cw)) {
            cout << s[i] << '\n';
        }
    }

    return 0;
}
