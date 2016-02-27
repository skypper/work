#include <iostream>
#include <fstream>
#include <cmath>

#define x first
#define y second

#define PI 3.14159265
#define EPS 0.0000001

using namespace std;

typedef pair<double, double> point;

double sq(double x) {
    return x * x;
}
double dot_product(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}
double magnitude(const point &a) {
    return sqrt(sq(a.x) + sq(a.y));
}
double dist(const point &a, const point &b) {
    return magnitude({a.x - b.x, a.y - b.y});
}

int main()
{
    ifstream cin("input");

    int t;
    cin >> t;
    while (t--) {
        point a, b, c, d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

        point ba = {a.x - b.x, a.y - b.y}, bc = {c.x - b.x, c.y - b.y};
        double b_ = acos(dot_product(ba, bc) / (magnitude(ba) * magnitude(bc)));

        point da = {a.x - d.x, a.y - d.y}, dc = {c.x - d.x, c.y - d.y};
        double d_ = acos(dot_product(da, dc) / (magnitude(da) * magnitude(dc)));
        double x = b_ + d_;
        //cout << "cos(B) = " << b_ << ", cos(D) = " << d_ << "\n";
        if (abs(x - PI) <= EPS) {
            cout << "D apartine cercului determinat de punctele A, B, C.";
        } else if (x < PI) {
            cout << "D apartine exteriorului cercului determinat de punctele A, B, C.";
        } else if (x > PI) {
            cout << "D apartine interiorului cercului determinat de punctele A, B, C.";
        }
        cout << ' ';

        if ((dist(a, b) + dist(c, d) - (dist(b, c) + dist(a, d))) <= EPS) {
            cout << "ABCD este circumscriptibil.";
        } else {
            cout << "ABCD nu este cicumscriptibil.";
        }

        cout << "\n\n";
    }
    return 0;
}
