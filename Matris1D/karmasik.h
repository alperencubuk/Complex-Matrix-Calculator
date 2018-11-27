#ifndef KARMASIK
#define KARMASIK
#include <iostream>
using namespace std;

class Karmasik {
   friend ostream& operator<<(ostream&, const Karmasik&);
   friend istream& operator>>(istream&, Karmasik&);
public:
	Karmasik(double gercekP=0, double sanalP=0);
	Karmasik& operator=(const Karmasik&);
	Karmasik operator+(const Karmasik&) const;
	Karmasik operator*(const Karmasik&) const;
	Karmasik operator*(const double&) const;
private:
	double gercek;
	double sanal;
};
#endif
