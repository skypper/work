#include <iostream>
#include <fstream>

#include "graf_neorientat.h"

using namespace std;

int main()
{
    ifstream fin("graf_neorientat.in");
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
    //cout << "TESTARE ADUNARE GRAFURI\n";
    //graf_neorientat G4(G1);
    //graf_neorientat G5;
    //G5 = (G1 + G4);
    //cout << G5;

    fin.close();
    fout.close();

    return 0;
}
