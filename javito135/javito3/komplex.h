#pragma once

#include <iostream>

class komplex {
	double re, im;
public:
	komplex(double _re = 1.0, double _im = 0.0);
	komplex(const komplex &);

	komplex operator*(const komplex&) const;

	const komplex& operator=(const komplex&);

	friend std::ostream& operator<<(std::ostream &s, const komplex &_k);
};
