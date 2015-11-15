#include <vector>

using namespace std;

#define MOD 65536

class BIT {
public:
	BIT(int n): n(n), data(n + 1, 0) {}
	void update(int idx, long long val) {
		while (idx <= n) {
			data[idx] += val;
			idx += lsb(idx);
		}
	}
	long long query(int idx) {
		long long sum = 0;
		while (idx > 0) {
			sum += data[idx];
			idx -= lsb(idx);
		}
		return sum;
	}
	long long query(int lo, int hi) {
		return query(hi) - query(lo);
	}
private:
	int n;
	vector<int> data;

	inline long long lsb(int x) {
		return x & -x;
	}
};
class FloatingMedian {
public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K) {
		long long ans = 0, sum = 0;
		BIT T(N);

		long long t = seed;
		T.update(0, t);
		for (int i = 1; i < N; ++i) {
			t = ((t * mul) % MOD + add) % MOD;
			T.update(i, t);
		}
		for (int i = 0; i < K; ++i) {
			sum = (sum + T.query(i + 1, i + K + 1)) % MOD;
		}

		ans = (ans + sum) % MOD;

		for (int i = 1; i < N - K; ++i) {
			sum = (sum - T.query(i - 1) + T.query(i + K + 1)) % MOD;
			ans = (ans + sum) % MOD;
		}

		return ans;
	}
};
