from __future__ import division
import math

EPS = 0.000001


def f(x):
    return 4 * math.exp(-x) * math.sin(6 * x * math.sqrt(x)) - 1 / 5

def approximate_root(lo, hi):
    if f(lo) * f(hi) > 0:
        return None

    max_iter = 10000
    i = 0

    x0 = lo
    x1 = hi
    while i < max_iter:
        x2 = x1 - (x1 - x0) / (f(x1) - f(x0)) * f(x1)
        c = f(x2)

        if abs(c) < EPS:
            break

        if f(x0) * c < 0:
            x1 = x2
        else:
            x0 = x2

        i += 1

    return x2

print(approximate_root(0.0, 0.2))