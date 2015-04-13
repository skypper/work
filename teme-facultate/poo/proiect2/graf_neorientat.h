#ifndef GRAF_NEORIENTAT_H_INCLUDED
#define GRAF_NEORIENTAT_H_INCLUDED


#include <iostream>
#include <cstring>

#include "lista.h"
#include "coada.h"

#include "restrictii.h"

class graf_neorientat {
    friend class graf_neorientat_drumuri;

    int size_;
    int edges_no;

protected:
    lista<int> adj_l[MAXN];

    int marked[MAXN];
public:
    graf_neorientat(): size_(0), edges_no(0) {}
    graf_neorientat(int size): size_(size), edges_no(0) {}
    graf_neorientat(const graf_neorientat&);

    void add_edge(int, int);

    void init_cautare();
    void bfs(int);
    void dfs(int);

    int get_dim() {
        return size_;
    }

    friend istream& operator>>(istream&, graf_neorientat&);
    friend ostream& operator<<(ostream&, graf_neorientat&);

    friend graf_neorientat operator+(graf_neorientat&, graf_neorientat&);
protected:
    virtual void dfs_(int);
};

graf_neorientat::graf_neorientat(const graf_neorientat &G) {
    size_ = G.size_;
    edges_no = G.edges_no;
    for (int i = 1; i <= size_; i++) {
        marked[i] = G.marked[i];

        lista<int>::nod *p = G.adj_l[i].prim;
        while (p) {
            adj_l[i].adauga_nod(p->info);
            p = p->urm;
        }
    }
}

void graf_neorientat::add_edge(int x, int y) {
    adj_l[x].adauga_nod(y);
    adj_l[y].adauga_nod(x);

    edges_no++;
}

void graf_neorientat::init_cautare() {
    for (int i = 1; i <= size_; i++)
        marked[i] = 0;
}

void graf_neorientat::bfs(int sursa) {
    init_cautare();

    coada Q;

    Q.insereaza(sursa);
    marked[sursa] = 1;

    while (!Q.goala()) {
        int u = Q.prim->info;
        Q.sterge();

        cout << u << ' ';

        lista<int>::nod *p = adj_l[u].prim;
        while (p) {
            int v = p->info;
            if (!marked[v]) {
                Q.insereaza(v);
                marked[v] = 1;
            }
            p = p->urm;
        }
    }
}

void graf_neorientat::dfs(int sursa) {
    init_cautare();
    dfs_(sursa);
}

void graf_neorientat::dfs_(int nod) {
    marked[nod] = 1;

    cout << nod << " ";

    lista<int>::nod *p = adj_l[nod].prim;
    while (p) {
        if (!marked[p->info]) {
            dfs_(p->info);
        }
        p = p->urm;
    }
}

istream& operator>>(istream &stream, graf_neorientat &G) {
    int n, m;

    stream >> n >> m;

    G.size_ = n;

    int x, y;
    for (int i = 0; i < m; i++) {
        stream >> x >> y;

        G.add_edge(x, y);
    }

    return stream;
}

#include "graf_neorientat_drumuri.h"
#include "componente_conexe.h"
ostream& operator<<(ostream& stream, graf_neorientat &G) {
    stream << "## ## ##\nVarfuri: " << G.get_dim()
            << "\nMuchii: " << G.edges_no
            << "\n\nLista de adiacenta:\n";
    for (int i = 1; i <= G.get_dim(); i++) {
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
    for (int i = 1; i <= G.get_dim(); ++i) {
        for (int j = 1; j <= G.get_dim(); ++j) {
            stream << G2.adj_m[i][j] << ' ';
        }
        stream << '\n';
    }
    stream << "## ## ##\n";

    return stream;
}

graf_neorientat operator+(graf_neorientat &G1, graf_neorientat &G2) {
    graf_neorientat rezultat(G1);

    for (int i = 1; i <= rezultat.size_; ++i) {
        rezultat.adj_l[i] = G1.adj_l[i] + G2.adj_l[i];
    }

    return rezultat;
}

#endif
