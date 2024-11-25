#include "teglalap.h"



Teglalap::Teglalap(double _szelesseg, double _magassag)
{
	szelesseg = _szelesseg;
	magassag = _magassag;
}

Teglalap::Teglalap(const Teglalap& c)
{
	szelesseg = c.szelesseg;
	magassag = c.magassag;
}



Teglalap Teglalap::operator*(int szorzo) const
{
	return Teglalap(szelesseg*szorzo, magassag*szorzo);
}

std::ostream& operator<<(std::ostream& os, const Teglalap& t) {
	os << "(" << t.szelesseg << ", " << t.magassag << ")";
	return os;
}
