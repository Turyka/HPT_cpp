#include <iostream>
#include <list>
#include <ctime>
#include "komplex.h"

// Függvény, amely megkeresi a 10 legkisebb komplex számot és visszaadja
// A függvényt redundáns adattárolás mentesre kell elkészíteni
std::list<std::list<komplex>::iterator> keres(std::list<komplex> &szamok) {
	std::list<std::list<komplex>::iterator> elsok;
	for(auto it = szamok.begin(); it != szamok.end(); it++) {
		auto it2 = elsok.begin();
		while(it2 != elsok.end() && **it2 < *it)
			it2++;
		elsok.insert(it2, it);
		if(elsok.size() == 10)
			elsok.pop_back();
	}
	return elsok;
}

int main() { 
	std::list<komplex> szamok;
	srand(time(0));
	for(unsigned int i = 0; i < 150; i++) {
		szamok.push_back(komplex(rand() % 100, rand() % 100));
	}
	for(auto k : szamok)
		std::cout << k << std::endl;
	
	// a 10 legkisebb komplex szám megkeresése és kiírása a képernyőre
	auto list = keres(szamok);
	std::cout << "A 10 legkisebb szam:" << std::endl;
	for(auto it : list)
		std::cout << *it << std::endl;
}