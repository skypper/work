#include <iostream>
#include <fstream>
#include <exception>

#include "graf_neorientat.h"
#include "arbore.h"

using namespace std;

int main() {
    lista<int> a;
    a.adauga_nod(1);
    a.adauga_nod(2);
    a.adauga_nod(3);
    a.adauga_nod(4);
    a.adauga_nod(5);
    for (int x : a) {
        cout << x << " ";
    }
    return 0;
}

int main2() {
    ifstream fin("graf_neorientat.in");
    ifstream fin2("graf_neorientat2.in");
    ifstream fin3("arbore.in");
    ofstream fout("graf_neorientat.out");

    graf_neorientat G1;

    // ## Citire/Scriere
    fin >> G1;
    // cin >> G1;
    cout << G1;
    // fout << G1;

    // ## Parcurgeri
    cout << "\nParcurgere in latime (pornind din nodul 1): ";
    G1.bfs(1);
    cout << "\nParcurgere in adancime (pornind din nodul 4): ";
    G1.dfs(4);

    cout << "\n\n";

    // ## Drumuri
    graf_neorientat_drumuri G2(G1);

    // ## Componente Conexe
    /*
    componente_conexe G3(G1);
    cout << "\nEste graful neorientat G3 conex? " << (G3.este_conex()? "Da" : "Nu") << ".\n";
    */

    // ## Adunare Grafuri
    cout << "TESTARE ADUNARE GRAFURI\n";
    graf_neorientat G4;
    graf_neorientat G5;
    fin2 >> G4;
    cout << G4;
    try {
        G5 = (G1 + G4);
    } catch (exception& e) {
        cerr << "Exceptie adunare grafuri!";
    }

    cout << "-- Primul graf:\n" << G1;
    cout << "-- Al doilea graf:\n" << G4;
    cout << "-- Graful rezultat:\n" << G5;


    // ## Arbori
    cout << "\n\nARBORI:\n";
    graf_neorientat G6;
    fin3 >> G6;
    try {
        arbore T1(G6, 1);
        cout << "Graful G6:\n" << G6;
        cout << "Vectorul de tati corespunzator arborelui indus de G6 este: ";
        T1.afiseaza_vector_tati(cout);
    } catch (exception& e) {
        cerr << "Exceptie arbore!";
    }


    fin.close();
    fin2.close();
    fin3.close();
    fout.close();

    return 0;
}
