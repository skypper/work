#include <iostream>
#include <fstream>
#include <cmath>

#define x first
#define y second

#define EPS 0.00001

using namespace std;

typedef pair<double, double> point;

double det(const point &a, const point &b, const point &c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - b.x * a.y - a.x * c.y;
}

double area(const point &a, const point &b, const point &c) {
    return 0.5 * abs(det(a, b, c));
}

double cross_product(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int orientation(const point &a, const point &b, const point &c) {
    double x = cross_product(a, b, c);
    if (abs(x) <= EPS) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

bool triangle_interior(const point &a, const point &b, const point &c, const point &m) {
    if (abs(area(a, b, m) + area(b, c, m) + area(c, a, m) - area(a, b, c)) <= EPS) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    ifstream cin("input");

    point m;
    cin >> m.x >> m.y;

    int n = 4, t;
    cin >> t;
    while (t--) {
        point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

        int o1 = orientation(a, b, c);
        int o2 = orientation(b, c, d);
        int o3 = orientation(c, d, a);
        int o4 = orientation(d, a, b);
        if (o1 == o2 && o2 == o3 && o3 == o4 && o4 == o1) {
            cout << "Patrulaterul ABCD este convex.";
            /*if (abs(area(a, b, m) + area(b, c, m) + area(c, d, m) + area(d, a, m) - (area(a, b, c) + area(a, c, d))) <= EPS) {
                cout << "Punctul M apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            } else {
                cout << "Punctul M nu apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
            }*/
        } else {
            cout << "Patrulaterul ABCD nu este convex.";
        }

        cout << " ";
        /// Testez daca punctul M apartine macar unui triunghi ABC, BCD, CDA, ABD.
        if (triangle_interior(a, b, c, m) || triangle_interior(b, c, d, m) || triangle_interior(c, d, a, m)|| triangle_interior(a, b, d, m)) {
            cout << "Punctul M apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
        } else {
            cout << "Punctul M nu apartine acoperirii convexe a multimii de puncte {A, B, C, D}.";
        }

        cout << "\n\n";
    }
    return 0;
}
