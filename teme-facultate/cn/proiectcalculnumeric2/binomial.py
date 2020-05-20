import numpy as np
from scipy.misc import comb

def binomial_matrix(n, p):
    A = np.zeros((n, n))

    for i in range(n):
        for j in range(n):
            A[i, j] = comb(p + j, i)

    return A