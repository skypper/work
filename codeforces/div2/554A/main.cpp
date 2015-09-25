#include <iostream>
#include <set>

using namespace std;

int main()
{
    string booklet;
    getline(cin, booklet);

    set<char> booklet_s(booklet.begin(), booklet.end());
    int distinct = booklet_s.size();

    int ans = 0;
    for (int i = 0; i <= booklet.size(); ++i) {
        ans += 26;
        if (i == 0) {
            continue;
        } else if (0 < i && i < booklet.size()) {
            ans--;
        } else if (i == booklet.size()) {
            ans--;
        }
    }
    cout << ans;

    return 0;
}
