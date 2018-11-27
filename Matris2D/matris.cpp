#include <iostream>
#include <cassert>
#include "matris.h"
#include "karmasik.h"
using namespace std;

Matris::Matris(int satirP, int sutunP) {
	satir = satirP;
	sutun = sutunP;
	sayilar = new Karmasik*[satir];
	for(int i=0;i<satir;i++)
        sayilar[i]=new Karmasik[sutun];
}

Matris& Matris::operator=(const Matris& dizi) {
	satir=dizi.satir;
	sutun=dizi.sutun;
	for(int i=0;i<satir;i++)
        for(int j=0;j<sutun;j++)
            sayilar[i][j]=dizi.sayilar[i][j];
	return *this;
}

Matris Matris::operator+(const Matris& dizi) const {
	assert(satir==dizi.satir && sutun==dizi.sutun);
	Matris toplam(satir,sutun);
	for(int i=0;i<satir;i++)
        for(int j=0;j<sutun;j++)
            toplam.sayilar[i][j] = sayilar[i][j]+dizi.sayilar[i][j];
	return toplam;
}

Matris Matris::operator*(const Matris& dizi) const {
	assert(sutun==dizi.satir);
	Matris carpim(satir,dizi.sutun);
	for (int i=0;i<satir;i++)
        for (int j=0;j<dizi.sutun;j++)
            for (int k=0;k<sutun;k++)
                carpim.sayilar[i][j] = carpim.sayilar[i][j] + (sayilar[i][k] * dizi.sayilar[k][j]);
	return carpim;
}

Matris Matris::operator*(const double& skaler) const {
	Matris carpim(satir,sutun);
	for(int i=0;i<satir;i++)
        for(int j=0;j<sutun;j++)
            carpim.sayilar[i][j] = sayilar[i][j] * skaler;
	return carpim;
}

Matris::~Matris() {
	for(int i=0;i<satir;i++)
        delete [] sayilar[i];
    delete [] sayilar;
}
