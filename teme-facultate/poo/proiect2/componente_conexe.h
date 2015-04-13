#ifndef COMPONENTE_CONEXE_H
#define COMPONENTE_CONEXE_H

#include "graf_neorientat.h"

class componente_conexe : public graf_neorientat {
public:
    int nr_comp;
    lista<int> comp[MAXN];

    componente_conexe(graf_neorientat &G);

    void componente();
    bool este_conex();
private:
    void dfs(int);
};

componente_conexe::componente_conexe(graf_neorientat &G)
    : graf_neorientat(G), nr_comp(0) {
    componente();
}

void componente_conexe::componente() {
    init_cautare();
    for (int i = 1; i <= get_dim(); ++i) {
        if (!marked[i]) {
            nr_comp++;
            dfs(i);
        }
    }
}

bool componente_conexe::este_conex() {
    return nr_comp == 1;
}

void componente_conexe::dfs(int nod) {
    comp[nr_comp].adauga_nod(nod);
    marked[nod] = 1;

    lista<int>::nod *p = adj_l[nod].prim;
    while (p) {
        if (!marked[p->info]) {
            dfs(p->info);
        }
        p = p->urm;
    }
}

#endif // COMPONENTE_CONEXE_H
