#include <iostream>
#include <fstream>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main()
{
    ifstream cin("input");

    int t;
    cin >> t;

    while (t--) {
        double x1, y1, z1, x2, y2, z2, x3, y3, z3;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;

        double alpha = -1, beta;

        if (x1 == x3 && y1 == y3 && z1 == z3) {
            cout << "A = C. A = 1 * C + 0 * B";
        } else {
            if (y1 - y3 != 0) {
                alpha = (y2 - y3) / (y1 - y3);
                if ((x2 - x3) == alpha * (x1 - x3) && (z2 - z3) == alpha * (z1 - z3)) {
                    beta = 1 - alpha;
                    cout << "Punctele sunt coliniare. B = " << alpha << " * A + " << beta << " * C";
                } else {
                    cout << "Punctele nu sunt coliniare.";
                }
            } else if (x1 - x3 != 0) {
                alpha = (x2 - x3) / (x1 - x3);
                if ((y2 - y3) == alpha * (y1 - y3) && (z2 - z3) == alpha * (z1 - z3)) {
                    beta = 1 - alpha;
                    cout << "Punctele sunt coliniare. B = " << alpha << " * A + " << beta << " * C";
                } else {
                    cout << "Punctele nu sunt coliniare.";
                }
            } else if (z1 - z3 != 0) {
                alpha = (z2 - z3) / (z1 - z3);
                if ((x2 - x3) == alpha * (z1 - z3) && (y2 - y3) == alpha * (y1 - y3)) {
                    beta = 1 - alpha;
                    cout << "Punctele sunt coliniare. B = " << alpha << " * A + " << beta << " * C";
                } else {
                    cout << "Punctele nu sunt coliniare.";
                }
            }
        }
        cout << "\n\n";
    }

    return 0;
}
