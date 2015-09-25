#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    vector<int> bad(n + 1, 0);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                bad[i] = 1;
            } else if (x == 2) {
                bad[j] = 1;
            } else if (x == 3) {
                bad[i] = bad[j] = 1;
            }
        }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (bad[i] == 0) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == 1);
            cout << ans[i] << " ";
    }

    return 0;
}
