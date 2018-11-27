#include <iostream>
#include <cassert>
#include "matris.h"
#include "karmasik.h"
using namespace std;

Matris::Matris(int satirP, int sutunP) {
	satir = satirP;
	sutun = sutunP;
	sayilar = new Karmasik[satir*sutun];
}

Matris& Matris::operator=(const Matris& dizi) {
	satir=dizi.satir;
	sutun=dizi.sutun;
	for(int i=0;i<satir*sutun;i++)
		sayilar[i]=dizi.sayilar[i];
	return *this;
}

Matris Matris::operator+(const Matris& dizi) const {
	assert(satir==dizi.satir && sutun==dizi.sutun);
	Matris toplam(satir,sutun);
	for(int i=0;i<satir*sutun;i++)
		toplam.sayilar[i] = sayilar[i]+dizi.sayilar[i];
	return toplam;
}

Matris Matris::operator*(const Matris& dizi) const {
	assert(sutun==dizi.satir);
	Matris carpim(satir,dizi.sutun);
	for (int i=0;i<satir;i++)
        for (int j=0;j<dizi.sutun;j++)
            for (int k=0;k<dizi.satir;k++)
                carpim.sayilar[i*carpim.sutun+j] = carpim.sayilar[i*carpim.sutun+j] + (sayilar[i*sutun+k] * dizi.sayilar[k*dizi.sutun+j]);
	return carpim;
}

Matris Matris::operator*(const double& skaler) const {
	Matris carpim(satir,sutun);
	for(int i=0;i<satir*sutun;i++)
		carpim.sayilar[i] = sayilar[i] * skaler;
	return carpim;
}

Matris::~Matris() {
	delete [] sayilar;
}
