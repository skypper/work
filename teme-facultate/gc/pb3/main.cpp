#include <iostream>
#include <fstream>
#include <cmath>

#define x first
#define y second

#define EPS 0.00001

using namespace std;

typedef pair<double, double> point;

double cross_product(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int orientation(const point &a, const point &b, const point &c) {
    double x = cross_product(a, b, c);
    if (abs(x) <= EPS) {
        return 0;
    } else if (x > 0) {
        return -1;
    } else {
        return 1;
    }
}

bool onSegment(const point &p, const point &q, const point &r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
       return true;
    }

    return false;
}

double det2(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool segment_contains(const point &a, const point &b, const point &m) {
    if ((a.x <= m.x && m.x <= b.x) || (b.x <= m.x && m.x <= a.x)) {
        return true;
    }
    return false;
}

int main()
{
    ifstream cin("input");

    int t;
    cin >> t;
    while (t--) {
        point p1, q1, p2, q2;
        cin >> p1.x >> p1.y >> q1.x >> q1.y >> p2.x >> p2.y >> q2.x >> q2.y;

        point m, m1, m2;
        bool intersect = false, intersect_point = false;

        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4) {
            intersect = intersect_point = true;

            point a = p1, b = q1, c = p2, d = q2;

            double a1 = a.y - b.y, b1 = b.x - a.x, c1 = (a.x * b.y - b.x * a.y);
            double a2 = c.y - d.y, b2 = d.x - c.x, c2 = (c.x * d.y - d.x * c.y);

            double num = det2(a1, b1, a2, b2);
            m = {det2(-c1, b1, -c2, b2) / num, det2(a1, -c1, a2, -c2) / num};
            /*if (num != 0) {
                m = {det2(-c1, b1, -c2, b2) / num, det2(a1, -c1, a2, -c2) / num};
            }*/
        }

        if (o1 == 0 && onSegment(p1, p2, q1)) {
            intersect = true;
        } else if (o2 == 0 && onSegment(p1, q2, q1)) {
            intersect = true;
        } else if (o3 == 0 && onSegment(p2, p1, q2)) {
            intersect = true;
        } else if (o4 == 0 && onSegment(p2, q1, q2)) {
            intersect = true;
        }

        if (intersect) {
            cout << "Cele doua segmente se intersecteaza. ";
            if (intersect_point) {
                cout << "Punctul de intersectie a celor doua segmente este: (" << m.x << ", " << m.y << ").";
            } else {
                if (segment_contains(p1, q1, p2) && segment_contains(p1, q1, q2)) {
                    // Segmentul P2-Q2 se afla in interiorul segmentului P1-Q1

                    m1 = p2;
                    m2 = q2;
                } else if (segment_contains(p2, q2, p1) && segment_contains(p2, q2, q1)) {
                    // Segmentul P1-Q1 se afla in interiorul segmentului P2-Q2

                    m1 = p1;
                    m2 = q1;
                } else {
                    // Cele doua segmente au aceeasi dreapta suport, se intersecteaza, dar niciuna
                    // nu contine pe cealalta

                    m1 = {max(p1.x, q1.x), max(p1.y, q1.y)};
                    m2 = {min(p2.x, q2.x), min(p2.y, q2.y)};
                }
                cout << "Intersectia celor doua segmente este determinata de segmentul determinat de punctele: ";
                cout << "(" << m1.x << ", " << m1.y << ") si (" << m2.x << ", " << m2.y << ").";
            }
        } else {
            cout << "Cele doua segmente nu se intersecteaza. ";
        }

        cout << "\n\n";
    }

    return 0;
}
