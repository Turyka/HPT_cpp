#pragma once
#include <string>
#include <iostream>

class Konyv {
	std::string szerzo;
	std::string cim;
	int ar;
	int oldalszam;
public:
	Konyv(std::string _szerzo, std::string _cim, int _ar, int _oldalszam) : szerzo(_szerzo), cim(_cim), ar(_ar), oldalszam(_oldalszam) {}

	std::string getSzerzo() const { return szerzo; }
	std::string getCim() const { return cim; }
	int getAr() const { return ar; }
	int getOldalszam() const { return oldalszam; }

	void setAr(int _ar) { ar = _ar; }

	friend std::ostream& operator<<(std::ostream &s, const Konyv &k) {
		s << k.szerzo << ": " << k.cim << ", " << k.ar << " Ft, " << k.oldalszam << " oldal";
		return s;
	}
};