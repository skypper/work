from __future__ import division
import math


precision = 0.0000001
EPS = 0.000001


def f(x):
    return 4 * math.exp(-x) * math.sin(6 * x * math.sqrt(x)) - 1 / 5


def approximate_root(lo, hi, t_max):
    if f(lo) * f(hi) > 0:
        return None

    i = 0
    while (hi - lo) > 2 * EPS and i < t_max:
        mid = (lo + hi) / 2

        if f(mid) == 0:
            lo = hi = mid
        elif f(lo) * f(mid) < 0:
            hi = mid - EPS
        else:
            lo = mid + EPS
        
        i += 1
    return lo


for interval in range(12):
    interval_length = 3 / 12

    interval_start = interval * interval_length
    interval_end = (interval + 1) * interval_length - EPS
    root = approximate_root(interval_start, interval_end, 100000)

    if root:
        y_root = f(root)
        if abs(y_root) < 100 * EPS:
            # print('x = {:f} f(x) = {:f}'.format(root, y_root))
            print(root, ' ', y_root)
    else:
        print('No root for function f in range [{:f}, {:f}]'.format(interval_start, interval_end))

