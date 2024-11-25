#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include "komplex.h"

// Függvény, amely egy vektorban összegyűjti azokra a komplex számokra hivatkozó iterátorokat, amelyeknek a valós része kisebb, mint a képzetes.
// A függvényt redundáns adattárolás mentesen kell megírni!

std::vector<std::list<komplex>::iterator> keres(std::list<komplex>& numbers) {
	std::vector<std::list<komplex>::iterator> eredmeny;

	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		if (it->Re() < it->Im()) {
			eredmeny.push_back(it);
		}
	}
	return eredmeny;
}



int main() {
	std::list<komplex> szamok;
	srand(time(0));
	for(unsigned int i = 0; i < 150; i++) {
		szamok.push_back(komplex(rand() % 100, rand() % 100));
	}
	for(auto k : szamok)
		std::cout << k << std::endl;

	// a számok megkeresése és kiírása a képernyőre

	auto list = keres(szamok);
	std::cout << "A 10 legkisebb szam:" << std::endl;
	for (auto it : list)
		std::cout << *it << std::endl;
}