#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED

#include "lista.h"

class coada {
public:
    struct nod {
        int info;
        nod *urm;
    };

    nod *prim, *ultim;

    coada() {
        init();
    }

    void insereaza(int x) {
        nod *t = new nod;
        t->info = x;
        t->urm = NULL;

        if (goala()) {
            // Initializare coada
            prim = ultim = t;
        } else {
            ultim->urm = t;
            ultim = t;
        }
    }
    void sterge() {
        if (goala()) return;
        if (prim == ultim) {
            prim = ultim = NULL;
        }
        else {
            nod *t = prim;
            prim = prim->urm;
            delete t;
        }
    }
    void afiseaza(ostream &stream) {
        for (nod *p = prim; p != NULL; p = p->urm)
            stream << p->info << ' ';
        stream << '\n';
    }
    bool goala() {
        return (prim == NULL && ultim == NULL);
    }
private:
    void init() {
        prim = ultim = NULL;
    }
};


#endif // COADA_H_INCLUDED
