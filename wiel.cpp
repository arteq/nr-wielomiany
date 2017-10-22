/*
 *  PROGRAM: InterpolacjaWielomianowa
 *  WERSJA: 0.1
 *  Autor: Artur GRĄCKI mailto: arteq(at)arteq(dot)org
 *  OSTATNIA MODYFIKACJA: 2011/11/25 (pią) 00:20:40
 *  KEYWORDS: interpolacja, wielomianowa, wielomian, lagrangea, metody, numeryczne, przybliżenie
 *  OPIS:  
 */


#include	<iostream>
#include	<fstream>
#include	<math.h>

using namespace std;

/* ====================================================================== */

double interpolacja (double x, int st, double *tab_x, double *tab_f) 
{
	double suma = 0;
	double L;

	for (int i=0; i<st; i++) 
	{
		L = 1;
		for (int j=0; j<st; j++) 
		{
			if (j != i)
				L = L * (x - tab_x[j]) / (tab_x[i] - tab_x[j]);
		}
		suma += tab_f[i]*L;
	}

	return suma;
}

/* ====================================================================== */

void wczytaj_dane(char plik[], double *dat_x, double *dat_y)
{
	ifstream fp;
	int i=0;

	fp.open(plik, ios::in);
	while ( !fp.eof() )
	{
		double x,y;
		fp >> x;
		fp >> y;

		dat_x[i] = x;
		dat_y[i] = y;

		cout << "X: " << dat_x[i] << "\tY: " << dat_y[i] << endl;
		i++;
	}

	fp.close();
}

/* ====================================================================== */

int rozmiar(char plik[])
{
	ifstream fp;
	int i=0;

	fp.open(plik, ios::in);
	while ( !fp.eof() )
	{
		double x,y;
		fp >> x;
		fp >> y;

		i++;
	}
	fp.close();

	return i;
}

/* ====================================================================== */

double blad(double x, double *dat_x, double *dat_y)
{
	double obliczone = interpolacja(x, 6, dat_x, dat_y);
	double prawdziwe = exp(x);

	double roznica = obliczone - prawdziwe;

	if (roznica >= 0) return roznica;
	else return (roznica * -1.0);
}

/* ====================================================================== */

int main()
{
	double punkt;
	double *dat_x, *dat_y;
	int ile;
	char nazwa[80];

	cout << "Podaj nazwe pliku do wczytania: ";
	cin >> nazwa;
	cout << endl;

	ile = rozmiar(nazwa);
	cout << "Plik zawiera: " << ile << " punktow danych\n" << endl;

	dat_x = new double[ile];
	dat_y = new double[ile];

	wczytaj_dane(nazwa, dat_x, dat_y );

	cout << "\nPodaj punkt do interpolacji: ";
	cin >> punkt;

	cout << "Wartosc wielomianu w punkcie x = " << punkt;
	cout << " wynosi: y = " << interpolacja(punkt, 6, dat_x, dat_y ) << endl;
	cout << "Calkowity blad wynosi: " << blad(punkt, dat_x, dat_y) << endl;

	delete dat_x;
	delete dat_y;
	return 0;
}
