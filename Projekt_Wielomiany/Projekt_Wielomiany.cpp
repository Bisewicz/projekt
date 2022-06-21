#include <iostream>
#include "Wielomian.h"

using namespace std;


int main()
{
	int najwyzsza{};
	cout << "Wpisz wartosc najwyzszej potegi dla:\n"
		"Pierwszego wielomianu: \t";
	cin >> najwyzsza;
	Wielomian pierwszy(najwyzsza);
	cout << "Drugiego wielomianu: \t";
	cin >> najwyzsza;
	Wielomian drugi(najwyzsza);
	cout << "\nPodaj wartosci wspolczynnikow a do n (wg wzoru: a(x^n)+b(x^n-1)+...+n(x^0) dla:\n"
		"Pierwszego wielomianu: \t";
	pierwszy.wprowadz_wielomian();
	cout << "Drugiego wielomianu: \t";
	drugi.wprowadz_wielomian();
	cout << "\nPierwszy wielomian to: \t";
	pierwszy.pokaz_wielomian();
	cout << "\nDrugi wielomian to: \t";
	drugi.pokaz_wielomian();
	cout << "\n\nSuma wielomianow: \t";
	sumaWielomianow(pierwszy, drugi).pokaz_wielomian();
	cout << "\nRoznica wielomianow: \t";
	roznicaWielomianow(pierwszy, drugi).pokaz_wielomian();
	cout << "\nIloczyn wielomianow: \t";
	mnozenieWielomianow(pierwszy, drugi).pokaz_wielomian();
	cout << "\nIloraz wielomianow: \t";
	dzielenieWielomianow(pierwszy, drugi).pokaz_wielomian();
	cout << endl;
}

