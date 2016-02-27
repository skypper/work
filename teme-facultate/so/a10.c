/**
A10. (6 puncte) Scrieti un program care sa sorteze prin interclasare un fisier
 de caractere in maniera descrisa mai jos.
  Sortarea prin interclasare presupune impartirea sirului in doua jumatati,
 sortarea fiecarei parti prin aceeasi metoda (deci recursiv), apoi
 interclasarea celor doua parti (care sunt acum sortate).
  Programul va lucra astfel: se imparte sirul in doua, se genereaza doua
 procese fiu (fork) care sorteaza cele doua jumatati in paralel, tatal ii
 asteapta sa se termine (wait sau waitpid), apoi interclaseaza jumatatile.
 Nu se vor folosi fisiere auxiliare.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <assert.h>

#define MAXN 101

#define SHMSZ     27

/**
Sort v[lo..hi], assuming that v[lo..mid] and v[(mid + 1)..hi] are already sorted, where mid = (lo + hi) / 2.
The procedure merges the two vectors.
*/
void sort(int *v, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;

    int aux[MAXN];
    int i = lo, j = mid + 1, k = 0;
    while (i <= mid && j <= hi) {
        if (v[i] < v[j]) {
            aux[k] = v[i];
            ++i;
        } else {
            aux[k] = v[j];
            ++j;
        }
        ++k;
    }
    if (i <= mid) {
        while (i <= mid) {
            aux[k] = v[i];
            ++i;
            ++k;
        }
    } else if (j <= hi) {
        while (j <= hi) {
            aux[k] = v[j];
            ++j;
            ++k;
        }
    }
    int q;
    for (q = 0; q < k; ++q) {
        v[lo + q] = aux[q];
    }
}

int is_sorted(int *v, int n) {
    int i;
    for (i = 1; i <= n - 1; ++i) {
        if (!(v[i] <= v[i + 1])) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, *v;

    int shmid;
    key_t key;
    int *shm;
    key = 5678;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    v = shm;


    freopen("input", "r", stdin);

    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }

    printf("Before: \n");
    for (i = 1; i <= n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    // parent process pid
    pid_t ppid = getpid();

    int lo = 1, hi = n;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        int lo2 = lo, hi2 = hi;

        lo = lo2;
        hi = mid;

        pid_t pid;
        if ((pid = fork()) > 0) {
            while (wait(NULL) > 0);
            printf("[Left Child] Sort v[%d..%d]\n", lo, hi);

            sort(v, lo, hi);
        }

        if (pid > 0) {
            lo = mid + 1;
            hi = hi2;

            if (fork() > 0) {
                while (wait(NULL) > 0);
                printf("[Right Child] Sort v[%d..%d]\n", lo, hi);

                sort(v, lo, hi);

                break;
            }
        }
    }

    // parent process
    if (ppid == getpid()) {
        printf("[Root] Sort v[1..%d]\n", n);
        sort(v, 1, n);

        printf("\nAfter: \n");
        for (i = 1; i <= n; ++i) {
            printf("%d ", v[i]);
        }
        putchar('\n');

        assert(is_sorted(v, n));
    }
    return 0;
}
