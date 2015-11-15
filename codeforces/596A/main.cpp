#include <iostream>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> point;

int n, ans;
point pts[5];

bool diagonal(point A, point B) {
    return A.x != B.x && A.y != B.y;
}

int main()
{
    //freopen("input", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    sort(pts + 1, pts + 1 + n);

    if (n == 1) {
        cout << -1;
        return 0;
    } else if (n == 2) {
        if (!diagonal(pts[1], pts[2])) {
            cout << -1;
            return 0;
        } else {
            ans = (pts[2].x - pts[1].x) * (pts[2].y - pts[1].y);
        }
    } else if (n == 3) {
        point X1, X2;
        if (diagonal(pts[1], pts[2])) {
            X1 = pts[1];
            X2 = pts[2];
        } else if (diagonal(pts[1], pts[3])) {
            X1 = pts[1];
            X2 = pts[3];
        } else if (diagonal(pts[2], pts[3])) {
            X1 = pts[2];
            X2 = pts[3];
        }
        ans = (X1.x - X2.x) * (X1.y - X2.y);
    } else if (n == 4) {
        ans = (pts[4].x - pts[1].x) * (pts[4].y - pts[1].y);
    }
    cout << abs(ans);

    return 0;
}
