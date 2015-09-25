#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;

    if (s.length() % k != 0) {
        cout << "NO";
    } else {
        int l = s.length() / k;
        for (int i = 0; i < s.length(); i += l) {
            string fax = s.substr(i, l);
            string ifax(fax);
            reverse(fax.begin(), fax.end());

            if (fax.compare(ifax) != 0) {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }

    return 0;
}
