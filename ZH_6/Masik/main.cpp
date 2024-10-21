#include <iostream>
#include <list>
#include <ctime>
#include "komplex.h"

int main() {
    // 150 random komplex szám létrehozása és hozzáadása a listához
    std::list<komplex> szamok;
    srand(static_cast<unsigned int>(time(0)));
    for (unsigned int i = 0; i < 150; i++) {
        szamok.push_back(komplex(rand() % 100, rand() % 100));
    }

    // Lista rendezése a komplex számok abszolút értéke szerint
    szamok.sort();

    // Az első 10 legkisebb elem kiírása
    auto it = szamok.begin();
    for (int i = 0; i < 10 && it != szamok.end(); ++i, ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}