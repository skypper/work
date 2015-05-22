#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

#include "graf_neorientat.h"
#include "componente_conexe.h"

class arbore : public graf_neorientat {
    int radacina;
    int TT[MAXN];

public:
    arbore(const graf_neorientat&, int);
    arbore(const arbore &T): graf_neorientat(T), radacina(T.radacina) {}

    void afiseaza_vector_tati(ostream&) const;
private:
    void viziteaza_nod(int, int = 0);
};

arbore::arbore(const graf_neorientat &T, int radacina): graf_neorientat(T), radacina(radacina) {
    componente_conexe G(*this);

    if (not(G.este_conex() && noduri() - 1 == muchii())) {
        throw new exception();
    }

    bfs(radacina);
}

void arbore::afiseaza_vector_tati(ostream &out) const {
    for (int i = 1; i <= noduri(); ++i) {
        out << TT[i] << " ";
    }
    out << '\n';
}

void arbore::viziteaza_nod(int nod, int tata) {
    marcat[nod] = 1;
    TT[nod] = tata;
}

#endif // ARBORE_H_INCLUDED
