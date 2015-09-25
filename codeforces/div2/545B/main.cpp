#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    string s, t, p;
    cin >> s >> t;

    int x = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == t[i]) {
            p.push_back('0');
        } else {
            if (x % 2 == 0) {
                p.push_back(s[i]);
            } else if (x % 2 == 1) {
                p.push_back(t[i]);
            }
            x++;
        }
    }

    if (x % 2 == 0) {
        cout << p;
    } else {
        cout << "impossible";
    }

    return 0;
}
