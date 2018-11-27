#ifndef MATRIS
#define MATRIS
#include "karmasik.h"
#include <iostream>
using namespace std;

class Matris {
   friend ostream& operator<<(ostream&, const Matris&);
   friend istream& operator>>(istream&, Matris&);
public:
	Matris(int satirP=0, int sutunP=0);
	Matris& operator=(const Matris&);
	Matris operator+(const Matris&) const;
	Matris operator*(const Matris&) const;
	Matris operator*(const double&) const;
	~Matris();
private:
	int satir;
	int sutun;
	Karmasik **sayilar;
};
#endif
