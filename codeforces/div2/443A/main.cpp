#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    set<char> letters;

    char c;
    while (cin >> c) {
        if (isalpha(c)) {
            letters.insert(c);
        }
    }

    cout << letters.size();
    return 0;
}
