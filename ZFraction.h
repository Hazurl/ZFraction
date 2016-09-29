#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <iostream>

class ZFraction {

	public :
//:: CONSTRUCTEURS
	ZFraction (int const& num, int const& den);
	ZFraction (int const& num);
	ZFraction ();

//:: OPERTEUR ARITHMETIQUE
	ZFraction& operator+= (ZFraction const& fraction);
	ZFraction& operator-= (ZFraction const& fraction);
	ZFraction& operator*= (ZFraction const& fraction);
	ZFraction& operator/= (ZFraction const& fraction);

	private :
	int _num;
	int _den;

	void reduce();
	void display(std::ostream& flux) const;

//:: FRIEND
	friend std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction);
	friend bool operator==(ZFraction const& f1, ZFraction const& f2);
	friend bool operator!=(ZFraction const& f1, ZFraction const& f2);
	friend bool operator< (ZFraction const& f1, ZFraction const& f2);
	friend bool operator> (ZFraction const& f1, ZFraction const& f2);
	friend bool operator>=(ZFraction const& f1, ZFraction const& f2);
	friend bool operator<=(ZFraction const& f1, ZFraction const& f2);
};

//:: FLUX
std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction);

//:: OPERTEUR ARITHMETIQUE
ZFraction operator+(ZFraction const& f1, ZFraction const& f2);
ZFraction operator-(ZFraction const& f1, ZFraction const& f2);
ZFraction operator*(ZFraction const& f1, ZFraction const& f2);
ZFraction operator/(ZFraction const& f1, ZFraction const& f2);

//:: OPERATEUR DE COMPARAISON
bool operator==(ZFraction const& f1, ZFraction const& f2);
bool operator!=(ZFraction const& f1, ZFraction const& f2);
bool operator< (ZFraction const& f1, ZFraction const& f2);
bool operator> (ZFraction const& f1, ZFraction const& f2);
bool operator>=(ZFraction const& f1, ZFraction const& f2);
bool operator<=(ZFraction const& f1, ZFraction const& f2);

#endif