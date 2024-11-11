#include <iostream>
#include <fstream>
#include <locale>
#include <list>
#include <vector>
#include <algorithm>
#include "konyv.h"

template<class T>
void kiir(T tarolo) {
	for(auto konyv : tarolo)
		std::cout << konyv << std::endl;
}

int main() {
	setlocale(LC_ALL, "");
	std::ifstream input("konyvek.txt");
	std::vector<Konyv> konyvVektor;
	if(input.is_open()) {
		std::string szerzo, cim, str;
		int ar, oldalszam;
		while(input.good()) {
			std::getline(input, szerzo);
			std::getline(input, cim);
			std::getline(input, str);
			ar = std::stoi(str);
			std::getline(input, str);
			oldalszam = std::stoi(str);
			konyvVektor.push_back(Konyv(szerzo, cim, ar, oldalszam));
		}

		input.close();
	} else {
		std::cout << "Nem sikerült megnyitni az állományt" << std::endl;
		std::system("pause");
		return 2;
	}

	std::cout << "Eredeti vektor: " << std::endl;
	kiir(konyvVektor);
	std::cout << std::endl;

	// Ár szerint növekvő sorrendbe rendezni
	std::sort(konyvVektor.begin(), konyvVektor.end(), [](const Konyv &k1, const Konyv &k2) { return k1.getAr() < k2.getAr(); });

	std::cout << "Rendezve ár szerint " << std::endl;
	kiir(konyvVektor);
	std::cout << std::endl;

	// Oldalszám szerint csökkenő sorrendbe rendezni
	std::sort(konyvVektor.begin(), konyvVektor.end(), [](const Konyv &k1, const Konyv &k2) { return k1.getOldalszam() > k2.getOldalszam(); });

	std::cout << "Rendezve oldalszám szerint " << std::endl;
	kiir(konyvVektor);
	std::cout << std::endl;

	// Minden könyv árát 20%-al csökkenteni
	std::for_each(konyvVektor.begin(), konyvVektor.end(), [](Konyv &k1) { k1.setAr(k1.getAr() * 0.8); });

	std::cout << "Árak csökkentve " << std::endl;
	kiir(konyvVektor);
	std::cout << std::endl;

	std::list<Konyv> konyvLista;
	// minden 3250 Ft-nál olcsóbb könyvet átmásolni a konyvListába
	std::copy_if(konyvVektor.begin(), konyvVektor.end(), std::back_inserter(konyvLista), [](Konyv &k1) { return k1.getAr() < 3250; });

	std::cout << "3250 Ft-nál olcsóbb könyvek " << std::endl;
	kiir(konyvLista);
	std::cout << std::endl;

	std::system("pause");
	return 0;
}