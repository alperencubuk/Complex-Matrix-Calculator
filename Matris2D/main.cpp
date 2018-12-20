#include <iostream>
#include <fstream>
#include "matris.h"
#include "karmasik.h"
using namespace std;

ostream& operator<<(ostream&, const Karmasik&);
istream& operator>>(istream&, Karmasik&);
ostream& operator<<(ostream&, const Matris&);
istream& operator>>(istream&, Matris&);

int main() {
	int secim,satir1,sutun1,satir2,sutun2;
	double skaler;
	cout<<"Matris Islemleri Uygulamasina Hosgeldiniz."<<endl
	<<"Alperen Cubuk tarafindan hazirlanmistir."<<endl<<endl
	<<"[1] Iki Karmasik Matrisi Carp"<<endl
	<<"[2] Bir Karmasik Matris ile Skaler Carp"<<endl
	<<"[3] Iki Karmasik Matrisi Topla"<<endl
	<<"[4] Bir Karmasik Matrisi Digerine Ata"<<endl
	<<"[5] Bir Karmasik Matris Yazdir"<<endl
	<<"[6] Elle Bir Karmasik Matris Girin"<<endl<<endl
	<<"Lutfen Islem Numarasi Giriniz: ";
	cin>>secim;
	if(secim==1) {
		cout<<endl<<"Matris icerikleri 'matris1.txt' ve 'matris2.txt' den okunacaktir."<<endl
		<<"Lutfen satir ve sutun bilgilerini giriniz."<<endl<<endl;
		cout<<"1. Matris Satir Sayisi: "; cin>>satir1;
		cout<<"1. Matris Sutun Sayisi: "; cin>>sutun1;
		cout<<"2. Matris Satir Sayisi: "; cin>>satir2;
		cout<<"2. Matris Sutun Sayisi: "; cin>>sutun2;
		cout<<endl;
		if(sutun1!=satir2) {
			cout<<"Iki matrisin carpilabilmesi icin birinci matrisin sutun sayisi ikinci matrisin satir sayisina esit olmalidir."<<endl;
		}
		else {
			Matris matris1(satir1,sutun1);
			Matris matris2(satir2,sutun2);
			ifstream dosya1("matris1.txt");
			dosya1>>matris1;
			dosya1.close();
			ifstream dosya2("matris2.txt");
			dosya2>>matris2;
			dosya2.close();
			cout<<"1. Matris:"<<endl<<endl<<matris1<<endl<<"2. Matris:"<<endl<<endl<<matris2<<endl;
			cout<<"Matrislerinizin carpiminin sonucu asagidadir:"
			<<endl<<endl<<matris1*matris2<<endl;
		}
	}
	else if(secim==2) {
		cout<<endl<<"Matris icerigi 'matris1.txt' den okunacaktir."<<endl
		<<"Lutfen satir ve sutun bilgilerini giriniz."<<endl<<endl;
		cout<<"Matris Satir Sayisi: "; cin>>satir1;
		cout<<"Matris Sutun Sayisi: "; cin>>sutun1;
		cout<<endl;
		Matris matris(satir1,sutun1);
		ifstream dosya("matris1.txt");
		dosya>>matris;
		dosya.close();
		cout<<"Matrisi carpmak istediginiz skaler sayiyi giriniz: "; cin>>skaler;
		cout<<endl<<"Matrisiniz:"<<endl<<endl<<matris<<endl;
		cout<<"Matrisinizin "<<skaler<<" ile carpiminin sonucu asagidadir:"
		<<endl<<endl<<matris*skaler<<endl;
	}
	else if(secim==3) {
		cout<<endl<<"Matris icerikleri 'matris1.txt' ve 'matris2.txt' den okunacaktir."<<endl
		<<"Lutfen satir ve sutun bilgilerini giriniz."<<endl<<endl;
		cout<<"1. Matris Satir Sayisi: "; cin>>satir1;
		cout<<"1. Matris Sutun Sayisi: "; cin>>sutun1;
		cout<<"2. Matris Satir Sayisi: "; cin>>satir2;
		cout<<"2. Matris Sutun Sayisi: "; cin>>sutun2;
		cout<<endl;
		if(satir1!=satir2 || sutun1!=sutun2) {
			cout<<"Iki matrisin toplanabilmesi icin satir ve sutun sayilari esit olmalidir."<<endl;
		}
		else {
		Matris matris1(satir1,sutun1);
		Matris matris2(satir2,sutun2);
		ifstream dosya1("matris1.txt");
		dosya1>>matris1;
		dosya1.close();
		ifstream dosya2("matris2.txt");
		dosya2>>matris2;
		dosya2.close();
		cout<<"1. Matris:"<<endl<<endl<<matris1<<endl<<"2. Matris:"<<endl<<endl<<matris2<<endl;
		cout<<"Matrislerinizin toplaminin sonucu asagidadir:"
		<<endl<<endl<<matris1+matris2<<endl;
		}
	}
	else if(secim==4) {
		cout<<endl<<"Matris icerigi 'matris1.txt' den okunacaktir."<<endl
		<<"Matrisiniz olusturulacak ve A matrisine kopyalanacaktir."<<endl<<endl;
		cout<<"Matrisinizin Satir Sayisi: "; cin>>satir1;
		cout<<"Matrisinizin Sutun Sayisi: "; cin>>sutun1;
		cout<<endl;
		Matris matris(satir1,sutun1);
		ifstream dosya("matris1.txt");
		dosya>>matris;
		dosya.close();
		Matris A;
		A=matris;
		cout<<"Matrisiniz:"<<endl<<endl<<matris<<endl;
		cout<<"Olusan kopya A matrisi asagidadir:"
		<<endl<<endl<<A<<endl;
	}
	else if(secim==5) {
		cout<<endl<<"Matris icerigi 'matris1.txt' den okunacaktir."<<endl
		<<"Matrisiniz istediginiz satir sutun sayilarina gore yazdirilacak."<<endl<<endl;
		cout<<"Matrisinizin Satir Sayisi: "; cin>>satir1;
		cout<<"Matrisinizin Sutun Sayisi: "; cin>>sutun1;
		cout<<endl;
		Matris matris(satir1,sutun1);
		ifstream dosya("matris1.txt");
		dosya>>matris;
		dosya.close();
		cout<<"Matrisiniz asagiya yazdirildi:"
		<<endl<<endl<<matris<<endl;
	}
	else if(secim==6) {
		cout<<endl<<"Elle matris girmek icin once satir ve sutun sayisi belirleyin."<<endl<<endl;
		cout<<"Matrisinizin Satir Sayisi: "; cin>>satir1;
		cout<<"Matrisinizin Sutun Sayisi: "; cin>>sutun1;
		cout<<endl;
		Matris matris(satir1,sutun1);
		cout<<"Matrisinizin elemanlarini (A+Bi) formunda giriniz:"<<endl
		<<"Ornek olarak: (3+2i) (4-7i) (0-1i) (6+0i) tarzinda."<<endl<<endl; cin>>matris;
		cout<<endl<<"Elle girilen matris asagiya yazdirilmistir."
		<<endl<<endl<<matris<<endl;
	}
	else
		cout<<"Hatali secim yaptiniz."<<endl;
	return 0;
}

ostream& operator<<(ostream& os, const Karmasik& sayi) {
    os<<"("<<sayi.gercek;
    if(sayi.sanal>=0)
    	os<<"+";
    os<<sayi.sanal<<"i)";
	return os;
}

istream& operator>>(istream& is, Karmasik& sayi) {
	char ch;
	is>>ch>>sayi.gercek>>sayi.sanal>>ch>>ch;
	return is;
}

ostream& operator<<(ostream& os, const Matris& dizi) {
	for(int i=0;i<dizi.satir;i++) {
		for(int j=0;j<dizi.sutun;j++)
			os<<dizi.sayilar[i][j]<<" ";
		os<<endl;
	}
	return os;
}

istream& operator>>(istream& is, Matris& dizi) {
	for(int i=0;i<dizi.satir;i++)
        for(int j=0;j<dizi.sutun;j++)
            is>>dizi.sayilar[i][j];
	return is;
}
