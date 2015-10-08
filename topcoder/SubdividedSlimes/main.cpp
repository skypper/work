#include <iostream>
#include <queue>

using namespace std;

class SubdividedSlimes {
public:
    int needCut(int S, int M) {
        int K = 0, mascots = 0;
        priority_queue<int> slimes;
        slimes.push(S);

        while (mascots < M) {
            int x = slimes.top();
            if (x == 1) {
                return -1;
            }
            slimes.pop();

            int slime1 = x / 2, slime2 = x - x / 2;
            mascots += slime1 * slime2;

            slimes.push(slime1);
            slimes.push(slime2);
            ++K;
        }

        return K;
    }
};

int main()
{
    SubdividedSlimes problem;
    int vals[][2] = {{3, 2}, {3, 3}, {3, 4}, {765, 271828}};
    for (int i = 0; i < 4; ++i) {
        cout << problem.needCut(vals[i][0], vals[i][1]) << endl;
    }
    return 0;
}
