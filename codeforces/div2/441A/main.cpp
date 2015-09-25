#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    vector<int> ans;
    string linebuffer;

    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        int k, s;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> s;
            if (v > s) {
                ans.push_back(i);
                getline(cin, linebuffer); // dismiss line
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
