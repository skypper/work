import math

EPS = 0.000001


def f(x):
    return 4 * math.exp(-x) * math.sin(6 * x * math.sqrt(x)) - 1 / 5


def approximate_root(lo, hi):
    x0 = lo
    x1 = hi

    max_iter = 10000
    i = 0
    while i < max_iter and abs(x1 - x0) > EPS:
        x2 = x1 - f(x1) * (x1 -  x0) / (f(x1) - f(x0))
        x0 = x1
        x1 = x2

        i += 1

    return x1


print(approximate_root(0.0, 0.2))
