#include <iostream>

using namespace std;

string lex_minimal(string s) {
    if (s.length() % 2 == 1) {
        return s;
    } else {
        string s1 = lex_minimal(s.substr(0, s.length() / 2));
        string s2 = lex_minimal(s.substr(s.length() / 2));

        if (s1 < s2) {
            return s1 + s2;
        } else {
            return s2 + s1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    string a, b;
    cin >> a >> b;

    cout << (lex_minimal(a) == lex_minimal(b) ? "YES" : "NO");

    return 0;
}
