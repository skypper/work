#include <iostream>
#include <fstream>

using namespace std;

int const MAXN = 110;

struct nod {
    int eticheta;
    nod *urm;
};

struct coada {
    nod *prim, *ultim;
};

int viz[MAXN], h;
coada adj[MAXN];

inline bool goala(coada Q) {
    return (Q.prim == NULL && Q.ultim == NULL);
}

void init(coada &Q) {
    Q.prim = Q.ultim = NULL;
}

void insereaza(int eticheta, coada &Q) {
    nod *t = new nod;
    t->eticheta = eticheta;
    t->urm = NULL;

    if (goala(Q)) {
        // Initializare coada
        Q.prim = Q.ultim = t;
    } else {
        Q.ultim->urm = t;
        Q.ultim = t;
    }
}

void sterge(coada &Q) {
    if (goala(Q)) return;
    if (Q.prim == Q.ultim) {
        Q.prim = Q.ultim = NULL;
    }
    else {
        nod *t = Q.prim;
        Q.prim = Q.prim->urm;
        delete t;
    }
}

void afiseaza(coada Q) {
    for (nod *p = Q.prim; p != NULL; p = p->urm) {
        cout << p->eticheta << ' ';
    }
}

void init_parcurgere() {
    for (int i = 0; i < MAXN; i++)
        viz[i] = 0;
}

void bfs(int sursa) {
    coada Q;
    init(Q);

    insereaza(sursa, Q);
    viz[sursa] = 1;
    while (!goala(Q)) {
        int u = Q.prim->eticheta;
        sterge(Q);

        cout << u << ' ';

        nod *p = adj[u].prim;
        while (p) {
            int v = p->eticheta;
            if (!viz[v]) {
                insereaza(v, Q);
            }
            p = p->urm;
        }
    }
}

void dfs(int u, int nivel = 0) {
    viz[u] = 1;

    cout << u << ' ';

    nod *p = adj[u].prim;
    while (p) {
        int v = p->eticheta;
        if (!viz[v]) {
            dfs(v, nivel + 1);
        }
        p = p->urm;
    }

    if (nivel > h)
        h = nivel;
}

void adauga_muchie(int x, int y) {
    insereaza(y, adj[x]);
}

int main() {
    ifstream f("arbori_oarecare.in");
    freopen("arbori_oarecare.out", "w", stdout);
    int n, m, radacina;
    f >> n >> radacina;

    m = n - 1; // Orice arbore cu n noduri are n - 1 muchii

    for (int i = 1; i <= m; i++) {
        int a, b;
        f >> a >> b;
        adauga_muchie(a, b);
    }
    f.close();

    cout << "Parcurgerea pe nivele: ";
    init_parcurgere();
    bfs(radacina);

    cout << '\n';

    cout << "Parcurgere in adancime: ";
    init_parcurgere();
    dfs(radacina);

    cout << "\nInaltimea arborelui este " << h << "." << '\n';

    coada frunze;
    init(frunze);
    for (int i = 1; i <= n; i++)
        if (goala(adj[i]))
            insereaza(i, frunze);

    cout << "Lista frunzelor: ";
    afiseaza(frunze);

    return 0;
}
