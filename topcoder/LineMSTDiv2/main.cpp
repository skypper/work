#include <iostream>

#define MOD 1000000007
#define ll long long

using namespace std;

class LineMSTDiv2 {
public:
    int count(int N) {
        ll result = 0;

        for (int edges = 0; edges < (1 << N - 1); ++edges) {
            ll f = 1;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 2; j < N; ++j) {
                    int ways = 2;
                    for (int k = i; k < j; ++k) {
                        if (1 << k & edges) {
                            ways = 1;
                        }
                    }
                    f = (f * ways) % MOD;
                }
            }

            result = (result + f) % MOD;
        }

        for (int i = 3; i <= N; ++i) {
            result = (result * i) % MOD;
        }

        return (int) result;
    }
};

int main()
{
    LineMSTDiv2 problem;
    int val[3] = {3, 2, 16};
    for (int i = 0; i < 3; ++i) {
        cout << problem.count(val[i]) << endl;
    }
    return 0;
}
