#include "komplex.h"

komplex::komplex(double _re, double _im) {
	re = _re;
	im = _im;
}

komplex::komplex(const komplex &k) {
	re = k.re;
	im = k.im;
}

komplex komplex::operator*(const komplex &_k) const {
	komplex eredmeny;
	eredmeny.re = re * _k.re - im * _k.im;
	eredmeny.im = re * _k.im + im * _k.re;
	return eredmeny;
}

const komplex & komplex::operator=(const komplex &_k) {
	re = _k.re;
	im = _k.im;
	return *this;
}

bool komplex::operator<(const komplex &_k) const {
	return re * re + im * im < _k.re * _k.re + _k.im * _k.im;
}

bool komplex::operator>(const komplex &_k) const {
	return _k < *this;
}

std::ostream& operator<<(std::ostream &s, const komplex &_k) {
	s << _k.re << " + i * " << _k.im;
	return s;
}


