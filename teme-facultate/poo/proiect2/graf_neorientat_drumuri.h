#ifndef GRAF_NEORIENTAT_DRUMURI_H_INCLUDED
#define GRAF_NEORIENTAT_DRUMURI_H_INCLUDED

#include "graf_neorientat.h"

class graf_neorientat_drumuri {
public:
    bool adj_m[MAXN][MAXN];
    bool d[MAXN][MAXN];

    graf_neorientat_drumuri(graf_neorientat &G): adj_m{} {
        int n = G.size_;
        for (int i = 1; i <= n; i++) {
            lista<int>::nod *p = G.adj_l[i].prim;
            while (p) {
                adj_m[i][p->info] = 1;
                p = p->urm;
            }
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    adj_m[i][j] = adj_m[i][j] | (adj_m[i][k] & adj_m[k][j]);
    }
};

#endif // GRAF_NEORIENTAT_DRUMURI_H_INCLUDED
