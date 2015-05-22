#ifndef GRAF_NEORIENTAT_H_INCLUDED
#define GRAF_NEORIENTAT_H_INCLUDED

#include <iostream>
#include <cstring>

#include <exception>

#include "lista.h"
#include "coada.h"

#include "restrictii.h"

class graf_neorientat {
    friend class graf_neorientat_drumuri;

    int noduri_;
    int muchii_;

protected:
    lista<int> adj_l[MAXN];

    int marcat[MAXN];
public:
    graf_neorientat(): noduri_(0), muchii_(0) {}
    graf_neorientat(int noduri): noduri_(noduri), muchii_(0) {}
    graf_neorientat(const graf_neorientat&);

    void adauga_muchie(int, int);

    void init_cautare();
    void bfs(int);
    void dfs(int);

    int noduri() const;
    int muchii() const;

    friend istream& operator>>(istream&, graf_neorientat&);
    friend ostream& operator<<(ostream&, graf_neorientat&);

    friend graf_neorientat operator+(graf_neorientat&, graf_neorientat&);
private:
    void dfs_(int);
protected:
    int vizitat(int) const;
    virtual void viziteaza_nod(int, int = 0);
};

graf_neorientat::graf_neorientat(const graf_neorientat &G) {
    noduri_ = G.noduri_;
    muchii_ = G.muchii_;

    for (int i = 1; i <= noduri_; i++) {
        marcat[i] = G.marcat[i];

        lista<int>::nod *p = G.adj_l[i].prim;
        while (p) {
            adj_l[i].adauga_nod(p->info);
            p = p->urm;
        }
    }
}

void graf_neorientat::adauga_muchie(int x, int y) {
    adj_l[x].adauga_nod(y);
    adj_l[y].adauga_nod(x);

    muchii_++;
}

void graf_neorientat::init_cautare() {
    for (int i = 1; i <= noduri_; i++)
        marcat[i] = 0;
}

void graf_neorientat::bfs(int sursa) {
    init_cautare();

    coada<int> Q;

    Q.insereaza(sursa);
    viziteaza_nod(sursa);

    while (!Q.goala()) {
        int u = Q.prim->info;
        Q.sterge();

        lista<int>::nod *p = adj_l[u].prim;
        while (p) {
            int v = p->info;
            if (!vizitat(v)) {
                Q.insereaza(v);
                viziteaza_nod(v, u);
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
    viziteaza_nod(nod);

    lista<int>::nod *p = adj_l[nod].prim;
    while (p) {
        int v = p->info;
        if (!vizitat(v)) {
            dfs_(p->info);
        }
        p = p->urm;
    }
}

int graf_neorientat::noduri() const {
    return noduri_;
}

int graf_neorientat::muchii() const {
    return muchii_;
}

int graf_neorientat::vizitat(int nod) const {
    return marcat[nod];
}

void graf_neorientat::viziteaza_nod(int nod, int precedent) {
    marcat[nod] = 1;
    cout << nod << " ";
}

istream& operator>>(istream &stream, graf_neorientat &G) {
    int n, m;

    stream >> n >> m;

    G.noduri_ = n;

    int x, y;
    for (int i = 0; i < m; i++) {
        stream >> x >> y;

        G.adauga_muchie(x, y);
    }

    return stream;
}

graf_neorientat operator+(graf_neorientat &G1, graf_neorientat &G2) {
    if (G1.noduri_ != G2.noduri_) {
        throw new exception();
    }

    graf_neorientat rezultat;

    rezultat.noduri_ = G1.noduri_;

    int m = 0;
    for (int i = 1; i <= rezultat.noduri_; ++i) {
        rezultat.adj_l[i] = G1.adj_l[i] + G2.adj_l[i];
        m += rezultat.adj_l[i].lungime();
    }

    rezultat.muchii_ = m / 2;

    return rezultat;
}

#include "graf_neorientat_io.h"

#endif
