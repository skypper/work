#ifndef COMPONENTE_CONEXE_H
#define COMPONENTE_CONEXE_H

#include "graf_neorientat.h"

class componente_conexe : public graf_neorientat {
public:
    int nr_comp;
    lista<int> comp[MAXN];

    componente_conexe(graf_neorientat&);

    void componente();
    int este_conex() const;
private:
    void viziteaza_nod(int, int = 0);
};

componente_conexe::componente_conexe(graf_neorientat &G)
    : graf_neorientat(G), nr_comp(0) {
    componente();
}

void componente_conexe::componente() {
    init_cautare();
    for (int i = 1; i <= noduri(); ++i) {
        if (!vizitat(i)) {
            nr_comp++;
            dfs(i);
        }
    }
}

int componente_conexe::este_conex() const {
    return nr_comp == 1;
}

void componente_conexe::viziteaza_nod(int nod, int precendent) {
    comp[nr_comp].adauga_nod(nod);
    marcat[nod] = 1;
}

#endif // COMPONENTE_CONEXE_H
