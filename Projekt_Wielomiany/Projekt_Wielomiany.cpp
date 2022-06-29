#include <iostream>
#include "Wielomian.h"
#include<vector>
using namespace std;

template <class A>
void zamien(A* a, A* b)
{
	A c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	vector<Wielomian>historia;
	start:
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
wzory:
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
wybory:
	cout <<endl <<"--------------------------------------------------"
		"\n1- Zamien wielomiany"
		"\n2- Zacznij od nowa"
		"\n3- Wyswietl historie"
		"\n4- Zapisz pierwszy wielomian"
		"\n5- Zapisz drugi wielomian"
		"\n6- Wyczysc historie"
		"\n0- Wyjdz"
		"\nWybor: ";
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
		case 1:
			zamien(&pierwszy, &drugi);
			goto wzory;
		case 2:
			goto start;
		case 3:
			cout << "----HISTORIA----";
			for (int i = 0; i < historia.size();i++)
			{
				cout << endl << i + 1 << " pozycja: ";
				historia[i].pokaz_wielomian();
			}
			cout << "\n----------------";
			goto wybory;
		case 4:
			historia.push_back(pierwszy);
			goto wybory;
		case 5:
			historia.push_back(drugi);
			goto wybory;
		case 6:
			historia.clear();
			goto wybory;
		case 0: return 0;
	}
}
