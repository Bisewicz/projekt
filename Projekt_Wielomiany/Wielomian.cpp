#include <iostream>
#include "Wielomian.h"

using namespace std;

void Wielomian::wprowadz_wielomian()
{
	for (int i = potega;i >= 0;i--)
	{
		cin >> wartosci[i];
	}
}

void Wielomian::pokaz_wielomian()
{
	for (int i = potega;i >= 0;i--)
	{
		if (wartosci[i] != 0 && wartosci[i] != 1)
		{
			if( wartosci[i] == -1&& i != 0)cout <<"-";
			else cout << wartosci[i];
		}
		else if (i == 0 && (wartosci[i] == 1 || wartosci[i] == -1))cout << wartosci[i];
		if (i > 1 && wartosci[i] != 0)cout << "x^" << i;
		else if ((i == 1|| i == -1)&& wartosci[i] != 0)cout << "x";
		if (wartosci[i - 1] > 0) cout << "+";
	}
}
