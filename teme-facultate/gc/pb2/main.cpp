#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>

#define x first
#define y second

#define EPS 0.00001

using namespace std;

typedef pair<double, double> point;

double det(const point &a, const point &b, const point &c) {
    return a.x * b.y + a.y * c.x + b.y * c.y - c.x * b.y - a.x * c.y - b.x * a.y;
}

double area(const point &a, const point &b, const point &c) {
    return 0.5 * abs(det(a, b, c));
}

class my_stack : public stack<int> {
public:
    int top_second() {
        int x = top();
        pop();
        int result = top();
        push(x);
        return result;
    }
};

double cross_product(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main()
{
    ifstream cin("input");

    point m;
    cin >> m.x >> m.y;

    int n = 4, t;
    cin >> t;
    while (t--) {
        vector<point> pts(n);
        for (int i = 0; i < n; ++i) {
            cin >> pts[i].x >> pts[i].y;
        }

        iter_swap(pts.begin(), min_element(pts.begin(), pts.end()));
        sort(pts.begin() + 1, pts.end(), [&O = pts[0]](const point &A, const point &B) {
            return cross_product(O, A, B) < 0;
        });

        my_stack hull;
        hull.push(0);
        hull.push(1);

        for (int i = 2; i < n; ++i) {
            while (hull.size() >= 2 && cross_product(pts[hull.top_second()], pts[hull.top()], pts[i]) > 0) {
                hull.pop();
            }
            hull.push(i);
        }

        // Verific daca exista trei puncte coliniare
        bool three_point = false;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (cross_product(pts[i], pts[j], pts[k]) == 0) {
                        three_point = true;
                    }
                }
            }
        }
        if (hull.size() == 4 || (three_point && hull.size() == 3)) {
            cout << "Patrulaterul ABCD este convex.\n";
        } else {
            cout << "Patrulaterul ABCD nu este convex.\n";
        }

        bool four_point = false;
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                for (int k = j + 1; k < n - 1; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        if (cross_product(pts[i], pts[j], pts[k]) == 0 && cross_product(pts[i], pts[j], pts[l]) == 0) {
                            four_point = true;
                        }
                    }
                }
            }
        }

        if (hull.size() == 4) {
            point a = pts[hull.top()];
            hull.pop();
            point b = pts[hull.top()];
            hull.pop();
            point c = pts[hull.top()];
            hull.pop();
            point d = pts[hull.top()];

            if (!four_point && abs(area(a, b, m) + area(b, c, m) + area(c, d, m) + area(d, a, m) - (area(a, b, c) + area(a, c, d))) <= EPS) {
                cout << "Punctul M apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            } else {
                cout << "Punctul M nu apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            }
        } else if (hull.size() == 3) {
            point a = pts[hull.top()];
            hull.pop();
            point b = pts[hull.top()];
            hull.pop();
            point c = pts[hull.top()];

            if (abs(area(a, b, m) + area(b, c, m) + area(c, a, m) - area(a, b, c)) <= EPS) {
                cout << "Punctul M apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            } else {
                cout << "Punctul M nu apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            }
        }

        cout << "\n\n";
    }
    return 0;
}
