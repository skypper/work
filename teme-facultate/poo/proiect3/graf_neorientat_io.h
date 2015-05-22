#pragma once

#include "graf_neorientat_drumuri.h"
#include "componente_conexe.h"

ostream& operator<<(ostream& stream, graf_neorientat &G) {
    stream << "## ## ##\nVarfuri: " << G.noduri()
            << "\nMuchii: " << G.muchii_
            << "\n\nLista de adiacenta:\n";
    for (int i = 1; i <= G.noduri(); i++) {
        stream << ' ' << i << ": ";
        lista<int>::nod *p = G.adj_l[i].prim;
        while (p) {
            stream << p->info << ' ';
            p = p->urm;
        }
        stream << '\n';
    }

    componente_conexe G1(G);
    stream << "\nEste graful conex? " << (G1.este_conex()? "Da." : "Nu.")
            << "\nNumarul de componente conexe: " << G1.nr_comp
            << "\nComponentele conexe ale grafului: \n";
    for (int i = 1; i <= G1.nr_comp; ++i) {
        lista<int> L = G1.comp[i];

        stream << ' ' << i << ". ";
        if (!L.goala()) {
            L.afiseaza(stream);
        }
    }
    stream << '\n';

    graf_neorientat_drumuri G2(G1);
    stream << "Matricea drumurilor:\n";
    for (int i = 1; i <= G.noduri(); ++i) {
        for (int j = 1; j <= G.noduri(); ++j) {
            stream << G2.adj_m[i][j] << ' ';
        }
        stream << '\n';
    }
    stream << "## ## ##\n";

    return stream;
}
