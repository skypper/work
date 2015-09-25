#include <iostream>

using namespace std;

int abs(int x) {
    return (x < 0) ? -x : x;
}

int main()
{
    int d[2][2] = {{-1, -1}, {-1, -1}};
    string str;
    cin >> str;

    for (int i = 0; i + 1 < str.length(); ++i) {
        if (str.substr(i, 2).compare("AB") == 0) {
            if (d[0][0] == -1) {
                d[0][0] = i;
            }
            d[0][1] = i;
        }
        if (str.substr(i, 2).compare("BA") == 0) {
            if (d[1][0] == -1) {
                d[1][0] = i;
            }
            d[1][1] = i;
        }
    }

    if (d[0][0] == -1 || d[1][0] == -1) {
        cout << "NO";
    } else if (d[0][0] + 1 < d[1][1] || d[1][0] + 1 < d[0][1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
