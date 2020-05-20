import math
import numpy as np
import binomial

n = 4
p = 10

A = np.matrix([[2, 3, 1, 5], [6, 13, 5, 19], [2, 19, 10, 23], [4, 10, 11, 31]])


def lup(A):
    if A.shape[0] != A.shape[1]:
        return None

    n = A.shape[0]

    II = np.arange(n)

    A = A.astype('float')
    L = np.matrix(np.zeros((n, n)), dtype='float')
    U = np.matrix(np.zeros((n, n)), dtype='float')
    P = np.matrix(np.zeros((n, n)))

    for k in range(n):
        p = 0
        k2 = 0
        for i in range(k, n):
            if math.fabs(A[i, k]) > p:
                p = math.fabs(A[i, k])
                k2 = i

        if p == 0:
            print('Singular matrix.')
            return None

        II[k], II[k2] = II[k2], II[k]

        if k2 != k:
            for j in range(n):
                L[k, j], L[k2, j] = L[k2, j], L[k, j]
                A[k, j], A[k2, j] = A[k2, j], A[k, j]

        U[k, k] = A[k, k]
        for i in range(k + 1, n):
            L[i, k] = A[i, k] / A[k, k]
            U[k, i] = A[k, i]
        for i in range(k + 1, n):
            for j in range(k + 1, n):
                A[i, j] = A[i, j] - L[i, k] * U[k, j]


    for i in range(n):
        L[i, i] = 1
        P[i, II[i]] = 1

    return L, U, P

n = 5
p = 10
M = binomial.binomial_matrix(n, p)
#A = np.matmul(np.transpose(M), M)
#b = np.matmul(np.transpose(M), np.ones((n, 1)))
A = M
b = np.ones((n, 1))

(L, U, P) = lup(A)

LU = np.round(np.matmul(L, U))
PA = np.matmul(P, A)

for i in range(n):
    for j in range(n):
        print(L[i, j], end=' ')
    print()
print()
for i in range(n):
    for j in range(n):
        print(U[i, j], end=' ')
    print()
print()

print(LU == PA)

y = np.zeros((n, 1))
x = np.zeros((n, 1))

for i in range(n):
    y[i] = b[i]

    for j in range(i):
        y[i] -= L[i, j] * b[j]

for i in range(n - 1, -1, -1):
    x[i] = y[i]
    for j in range(i + 1, n):
        x[i] -= U[i, j] * y[j]
    x[i] /= U[i, i]

for i in range(len(x)):
    print(x[i], end=' ')
print('\n')

print(b == PA * x)