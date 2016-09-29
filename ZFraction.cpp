#include "ZFraction.h"
#include <string>
#include <iostream>
#include <cstdlib>

//:: CONSTRUCTEURS
ZFraction::ZFraction (int const& num, int const& den) {
	if (den == 0) throw std::string("ERREUR - Division par zero");
	else if (den < 0) {
		_num = -num;
		_den = -den;
	}
	else {
		_num = num;
		_den = den;
	}

	reduce();
}
ZFraction::ZFraction (int const& num) : _num(num), _den(1) {
}
ZFraction::ZFraction () : _num(0), _den(1) {
}

//:: AFFICHAGE
void ZFraction::display(std::ostream& flux) const {
	if (_den != 1) flux << _num << '/' << _den;
	else flux << _num;
}

//:: FLUX
std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction) {
	fraction.display(flux);
	return flux;
}

// OPERATOR
ZFraction& ZFraction::operator+= (ZFraction const& fraction) {
	_num = fraction._den * _num + _den * fraction._num;
	_den *= fraction._den;

	reduce();
	return *this;
}
ZFraction& ZFraction::operator-= (ZFraction const& fraction) {
	_num = fraction._den * _num + _den * -fraction._num;
	_den *= fraction._den;

	reduce();
	return *this;
}
ZFraction& ZFraction::operator*= (ZFraction const& fraction) {
	_num*=fraction._num;
	_den*=fraction._den;

	reduce();
	return *this;
}
ZFraction& ZFraction::operator/= (ZFraction const& fraction) {
	if (fraction._num == 0) throw std::string("ERREUR - Division par zero");
	_num*=fraction._den;
	_den*=fraction._num;

	reduce();
	return *this;
}
ZFraction operator+(ZFraction const& f1, ZFraction const& f2) {
	ZFraction tmp(f1);
	return tmp+=f2;
}
ZFraction operator-(ZFraction const& f1, ZFraction const& f2) {
	ZFraction tmp(f1);
	return tmp-=f2;
}
ZFraction operator*(ZFraction const& f1, ZFraction const& f2) {
	ZFraction tmp(f1);
	return tmp*=f2;
}
ZFraction operator/(ZFraction const& f1, ZFraction const& f2) {
	ZFraction tmp(f1);
	return tmp/=f2;
}

//:: OPERATEUR DE COMPARAISON
bool operator==(ZFraction const& f1, ZFraction const& f2) {
	return (f1._num == f2._num && f1._den == f2._den);
}
bool operator!=(ZFraction const& f1, ZFraction const& f2) {
	return !(f1 == f2);
}
bool operator< (ZFraction const& f1, ZFraction const& f2) {
	return (f1._num / f1._den < f2._num / f2._den);
}
bool operator> (ZFraction const& f1, ZFraction const& f2) {
	return (f1._num / f1._den > f2._num / f2._den);
}
bool operator>=(ZFraction const& f1, ZFraction const& f2) {
	return !(f1 < f2);
}
bool operator<=(ZFraction const& f1, ZFraction const& f2) {
	return !(f2 < f1);
}

//:: PGCD & SIMPLIFY
void ZFraction::reduce () {
	//PGCD
	int a = (_num < 0)? -_num : _num, b = _den;
	while(a != b)
	    if(a > b) a -= b;
	    else b -= a;

	_num/=a;
	_den/=a;
}