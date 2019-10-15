#include "TSP.h"
#include "AntColony.cpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Please, insert file path!\n";
        system("PAUSE");
    }
    cout << "File: " << argv[2] << "\n";
    AntColony algorithm(argv[2]);
    algorithm.solve();
    system("PAUSE");
};