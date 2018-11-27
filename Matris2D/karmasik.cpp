#include <iostream>
#include "karmasik.h"
using namespace std;

Karmasik::Karmasik(double gercekP, double sanalP) {
	gercek = gercekP;
	sanal = sanalP;
}

Karmasik& Karmasik::operator=(const Karmasik& sayi) {
	gercek = sayi.gercek;
	sanal = sayi.sanal;
	return *this;
}

Karmasik Karmasik::operator+(const Karmasik& sayi) const {
	Karmasik toplam;
	toplam.gercek = gercek + sayi.gercek;
	toplam.sanal = sanal + sayi.sanal;
	return toplam;
}

Karmasik Karmasik::operator*(const Karmasik& sayi) const {
   Karmasik carpim;
   carpim.gercek = (gercek * sayi.gercek) - (sanal * sayi.sanal);
   carpim.sanal = (gercek * sayi.sanal) + (sanal * sayi.gercek);
   return carpim;
}

Karmasik Karmasik::operator*(const double& skaler) const {
   Karmasik carpim;
   carpim.gercek = gercek * skaler;
   carpim.sanal = sanal * skaler;
   return carpim;
}
