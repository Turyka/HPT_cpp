#pragma once
#include <iostream>

// ahol lehet (és értelmes) használjon "const" kulcsszót!
class Teglalap {
	double szelesseg, magassag;
public:
	// hozzon létre két paraméterű konstruktort, amit alapértelmezetten 2 szélességű és 1 magasságú téglalapot készít
	// 
	// 
	//Teglalap(double szelesseg = 2, double magassag = 1)
	//: szelesseg(szelesseg), magassag(magassag) {}
	//
	//
	Teglalap(double szelesseg = 2, double magassag = 1);
	// hozzon létre másoló konstruktort
	Teglalap(const Teglalap&);
	// hozzon létre * operátort, amely egy téglalap méretét arányosan megnöveli egy egész érték segítségével
	// például ha a téglalapot beszorozzuk 5-tel, akkor a szélesség és a magasságot is szorozza be 5-tel
	Teglalap operator*(int szorzo) const;
	friend std::ostream& operator<<(std::ostream& os, const Teglalap& t); // Kiíró operátor
	

	unsigned int getszelesseg() const { return szelesseg; }
	unsigned int getmagassag() const  {return magassag; }

	
		
	
	


	


	// készítsen << operátort, amely segítségével "(szelesseg, magassag)" formában ki lehet írni a téglalap adatait
};