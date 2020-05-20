from __future__ import division
import math
from scipy.misc import derivative


EPS = 0.000001


def f(x):
    return 4 * math.exp(-x) * math.sin(6 * x * math.sqrt(x)) - 1 / 5

'''
def df(x):
    return -math.exp(-x) * (4 * math.sin(6 * x ** (3 / 2)) - 36 * math.sqrt(x) * math.cos(6 * x ** (3 / 2)))
'''

def approximate_root(x0):
    max_iter = 10000
    i = 0
    while i < max_iter:
        x1 = x0 - f(x0) / derivative(f, x0, dx=1e-6)

        if x1 < 0 or x1 > 3:
            return -1

        if abs(f(x1)) < EPS:
            break
        x0 = x1

        i += 1

    return x0

interval_count = 36
interval_length = 3 / interval_count
solutions = set()
for i in range(interval_count):
    point = i * interval_length + interval_length / 2
    solution = approximate_root(point)
    if solution != -1:
        solutions.add(round(solution, 2))
        print(solution)

print(len(solutions))
solutions = sorted(solutions)
for solution in solutions:
    print(solution)
