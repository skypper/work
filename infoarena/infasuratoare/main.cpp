#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>

#define x first
#define y second

using namespace std;

typedef pair<double, double> point;

vector<point> pts;
int n;

class my_stack : public stack<int> {
public:
    int top_second() {
        int x = top();
        pop();
        int result = top();
        push(x);
        return result;
    }
} hull;

double cross_product(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main()
{
#ifdef LOCAL
    freopen("input", "r", stdin);
#else
    ifstream cin("infasuratoare.in");
    ofstream cout("infasuratoare.out");
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    iter_swap(pts.begin(), min_element(pts.begin(), pts.end()));

    sort(pts.begin() + 1, pts.end(), [&O = pts[0]](const point &A, const point &B) {
        return cross_product(O, A, B) < 0;
    });

    hull.push(0);
    hull.push(1);

    for (int i = 2; i < n; ++i) {
        while (hull.size() >= 2 && cross_product(pts[hull.top_second()], pts[hull.top()], pts[i]) > 0) {
            hull.pop();
        }
        hull.push(i);
    }

    cout << hull.size() << '\n' << setprecision(6) << fixed;
    while (!hull.empty()) {
        cout << pts[hull.top()].x << ' ' << pts[hull.top()].y << '\n';
        hull.pop();
    }

    return 0;
}
