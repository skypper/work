#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <cstdlib>

#include "restrictii.h"

using namespace std;

template <class cheie>
class lista {
public:
    struct nod {
        cheie info;
        nod *urm;
    };

    nod *prim;
    nod *ultim;

    lista();
    lista(const lista<cheie>&);
    ~lista();
    lista<cheie>& operator()(lista<cheie>&);

    bool goala();
    void init(cheie);
    void adauga_ultim(cheie);
    void adauga_prim(cheie);
    void adauga_nod(cheie);
    void adauga_dupa(nod*, cheie);
    void adauga_in_fata(nod*, cheie);
    void afiseaza(ostream&) const;
    nod* cauta_dupa_cheie(cheie) const;
    nod* cauta_dupa_pozitie(int) const;
    void elimina_prim();
    void elimina_ultim();
    void elimina(nod*);
    void eliberare();
};


template <class cheie>
lista<cheie>::lista() {
    prim = ultim = NULL;
}

template <class cheie>
lista<cheie>::lista(const lista<cheie> &L) {
    lista<cheie>::nod *p = L.prim;
    while (p) {
        adauga_nod(p->info);
        p = p->urm;
    }
}

template <class cheie>
lista<cheie>::~lista() {
    eliberare();
}

template <class cheie>
bool lista<cheie>::goala() {
    return prim == NULL && ultim == NULL;
}

template <class cheie>
void lista<cheie>::init(cheie x) {
    prim = new nod;
    prim->info = x;
    prim->urm = NULL;
    ultim = prim;
}

template <class cheie>
void lista<cheie>::adauga_prim(cheie x) {
    if (goala()) {
        init(x);
    } else {
        nod *p = new nod;
        p->info = x;
        p->urm = prim;
        prim = p;
    }
}

template <class cheie>
void lista<cheie>::adauga_ultim(cheie x) {
    if (goala()) {
        init(x);
    } else {
        nod *p = new nod;
        p->info = x;
        p->urm = NULL;
        ultim->urm = p;
        ultim = p;
    }
}

template <class cheie>
void lista<cheie>::adauga_nod(cheie x) {
    adauga_ultim(x);
}

template <class cheie>
void lista<cheie>::adauga_dupa(nod* q, cheie x) {
    nod *p = new nod;
    p->info = x;
    p->urm = q->urm;
    q->urm = p;
    if (p == ultim) p = ultim;
}

template <class cheie>
void lista<cheie>::adauga_in_fata(nod* q, cheie x) {
    nod *p = new nod;
    p->info = q->info;
    p->urm = q->urm;
    q->urm = p;
    q->info = x;
    if (p == ultim) p = ultim;
}

template <class cheie>
void lista<cheie>::afiseaza(ostream& out) const {
    for (nod *p = prim; p != NULL; p = p->urm)
        out << p->info << " ";
    out << '\n';
}

template <class cheie>
typename lista<cheie>::nod* lista<cheie>::cauta_dupa_cheie(cheie x) const {
    nod *p;
    for (p = prim; p != NULL && p->info != x; p = p->urm);
    return p;
}

template <class cheie>
typename lista<cheie>::nod* lista<cheie>::cauta_dupa_pozitie(int poz) const {
    nod *p;
    int nr;
    for (p = prim, nr = 1; p != NULL && nr < poz; p = p->urm, nr++);
    return p;
}

template <class cheie>
void lista<cheie>::elimina_prim() {
    if (prim == ultim) {
        delete prim;
        delete ultim;
        prim = ultim = NULL;
    } else {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
}

template <class cheie>
void lista<cheie>::elimina_ultim() {
    if (prim->urm == ultim) {
        delete ultim;
        ultim = prim;
    } else {
        nod *p, *q = ultim;
        for (p = prim; p->urm->urm != NULL; p = p->urm);
        p->urm = NULL;
        ultim = p;
        delete q;
    }
}

template <class cheie>
void lista<cheie>::elimina(nod* p) {
    if (p == prim) {
        elimina_prim();
    } else if (p == ultim) {
        elimina_ultim();
    } else {
        nod *q = p->urm;
        p->info = p->urm->info;
        p->urm = p->urm->urm;
        delete q;
        if (p->urm == NULL) ultim = p;
    }
}

template <class cheie>
void lista<cheie>::eliberare() {
    nod *p = prim, *q;
    while (p != NULL) {
        q = p;
        p = p->urm;
        delete q;
    }
    prim = ultim = NULL;
}

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

/**
Interclasarea a doua liste neordonate
*/
lista<int> operator+(lista<int> &L1, lista<int> &L2) {
    lista<int> rezultat;

    int aux1[MAXN], aux2[MAXN], k = 0;
    lista<int>::nod *p1 = L1.prim;
    lista<int>::nod *p2 = L2.prim;
    while (p1 && p2) {
        aux1[k] = p1->info;
        aux2[k] = p2->info;
        k++;

        p1 = p1->urm;
        p2 = p2->urm;
    }

    qsort(aux1, k, sizeof(int), compare);
    qsort(aux2, k, sizeof(int), compare);

    return L1;
    int i, j;
    i = j = 0;

    while (i < k && j < k) {
        if (aux1[i] < aux2[j]) {
            rezultat.adauga_nod(aux1[i]);
            ++i;
        } else if (aux1[i] > aux2[j]) {
            rezultat.adauga_nod(aux2[j]);
            ++j;
        }
        else if (aux1[i] == aux2[j]) {
            rezultat.adauga_nod(aux1[i]);
            ++i, ++j;
        }
    }

    if (i < k)
        while (i < k) {
            rezultat.adauga_nod(aux1[i]);
            ++i;
        }
    if (j < k)
        while (j < k) {
            rezultat.adauga_nod(aux2[j]);
            ++j;
        }

    return rezultat;
}

template <class cheie>
lista<cheie>& lista<cheie>::operator()(lista<cheie> &L) {
    eliberare();

    lista<cheie>::nod *p = L.prim;
    while (p) {
        adauga_nod(p->info);
        p = p->urm;
    }
}

#endif // LISTA_H_INCLUDED
