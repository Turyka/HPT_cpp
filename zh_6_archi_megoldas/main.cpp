// kpt7.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "minmaxavg.h"


int main() {
	MinMax a({ 1, 4, 2, 6, 12, 34 });
	MinMax b({ 3, 2, 7, 6 });
	std::cout << "a: " << a.getMin() << "\t" << a.getMax() << endl;
	std::cout << "b: " << b.getMin() << "\t" << b.getMax() << endl;

	MinMaxAvg v2 = { 1,3,5,7 };
	std::cout << v2.getMin() << ", " << v2.getMax() << ", " << v2.getAtlag() << std::endl;

	return 0;
}

