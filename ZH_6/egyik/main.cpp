#include <iostream>
#include <list>
#include <ctime>
#include "komplex.h"

// Függvény, amely megkeresi a 10 legkisebb komplex számot és visszaadja
// A függvényt redundáns adattárolás mentesre kell elkészíteni


int main() { 
	std::list<komplex> szamok;
	srand(time(0));
	for(unsigned int i = 0; i < 150; i++) {
		szamok.push_back(komplex(rand() % 100, rand() % 100));
	}
	
	// a 10 legkisebb komplex szám megkeresése és kiírása a képernyőre
}