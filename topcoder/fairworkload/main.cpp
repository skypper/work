#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class FairWorkload {
public:
    /**
    Binary search on the maximum number of folders a worker would have to look through
    */
    int getMostWork(vector<int> folders, int workers) {
        int n = folders.size();
        int lo = *max_element(folders.begin(), folders.end());
        int hi = accumulate(folders.begin(), folders.end(), 0);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int required = 1, workload = 0;
            for (int i = 0; i < n; ++i) {
                if (workload + folders[i] <= mid) {
                    // The current worker can still handle the load
                    workload += folders[i];
                } else {
                    // Asign a new worker
                    ++required;
                    workload = folders[i];
                }
            }

            if (required <= workers) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
} fw;

int main()
{
    ifstream f("fairworkload.in");
    int workers;
    vector<int> folders;

    f >> workers;

    int x;

    while (f >> x) {
        folders.push_back(x);
    }

    cout << fw.getMostWork(folders, workers);

    f.close();
    return 0;
}
