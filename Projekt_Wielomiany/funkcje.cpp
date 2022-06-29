#include "Wielomian.h"
#include <iostream>

using namespace std;

template <class A>
void zamien(A* a, A* b)
{
	A c = *a;
	*a = *b;
	*b = c;
}

Wielomian sumaWielomianow(Wielomian pierwszy, Wielomian drugi)
{
	int wiekszapotega = 0;
	if (pierwszy.potega > drugi.potega) wiekszapotega = pierwszy.potega;
	else wiekszapotega = drugi.potega;
	Wielomian wynik_sumy(wiekszapotega);
	if (pierwszy.potega == wiekszapotega) {
		while (wiekszapotega > drugi.potega)
		{
			wynik_sumy.wartosci[wiekszapotega] = pierwszy.wartosci[wiekszapotega];
			wiekszapotega--;
		}
	}
	else {
		while (wiekszapotega > pierwszy.potega)
		{
			wynik_sumy.wartosci[wiekszapotega] = drugi.wartosci[wiekszapotega];
			wiekszapotega--;
		}
	}
	while (wiekszapotega >= 0)
	{
		wynik_sumy.wartosci[wiekszapotega] = (pierwszy.wartosci[wiekszapotega] + drugi.wartosci[wiekszapotega]);
		wiekszapotega--;
	}
	return wynik_sumy;
}
Wielomian roznicaWielomianow(Wielomian pierwszy, Wielomian drugi)
{
	int roznica_wielkosci = 0;
	if (pierwszy.potega == drugi.potega)
	{
		int i = pierwszy.potega;
		while ((pierwszy.wartosci[i] == drugi.wartosci[i])&&i>0)
		{
			roznica_wielkosci++;
			i--;
		}
		Wielomian wynik_odejmowania((pierwszy.potega) - (roznica_wielkosci));
		while (i>=0)
		{
			wynik_odejmowania.wartosci[i]=pierwszy.wartosci[i]-drugi.wartosci[i];
			i--;
		}
		return wynik_odejmowania;
	}
	else if (pierwszy.potega > drugi.potega)
	{
		Wielomian wynik_odejmowania(pierwszy.potega);
		int i = pierwszy.potega;
		while (i != drugi.potega)
		{
			wynik_odejmowania.wartosci[i] = pierwszy.wartosci[i];
			i--;
		}
		while (i >= 0)
		{
			wynik_odejmowania.wartosci[i] = (pierwszy.wartosci[i] - drugi.wartosci[i]);
			i--;
		}
		return wynik_odejmowania;
	}
	else if (pierwszy.potega < drugi.potega)
	{
		Wielomian wynik_odejmowania(drugi.potega);
		int i = drugi.potega;
		while (i != pierwszy.potega)
		{
			wynik_odejmowania.wartosci[i] = (-1)*(drugi.wartosci[i]);
			i--;
		}
		while (i >= 0)
		{
			wynik_odejmowania.wartosci[i]= (pierwszy.wartosci[i] - drugi.wartosci[i]);
			i--;
		}
		return wynik_odejmowania;
	}
}

Wielomian mnozenieWielomianow(Wielomian pierwszy, Wielomian drugi)
{
	int sumapoteg = (pierwszy.potega + drugi.potega);
	Wielomian wynik_mnozenia(sumapoteg);
	for (int i = pierwszy.potega;i >= 0;i--)
	{
		for (int j = drugi.potega;j >= 0;j--)
		{
			wynik_mnozenia.wartosci[i + j] += pierwszy.wartosci[i] * drugi.wartosci[j];
		}
	}
	return wynik_mnozenia;
}

Wielomian dzielenieWielomianow(Wielomian pierwszy, Wielomian drugi)
{
	int roznica_poteg = ((pierwszy.potega)- (drugi.potega));
	Wielomian wynik_dzielenia(roznica_poteg);
	Wielomian pomoc_1 = pierwszy;
	float reszta = 0;
	while(!((pomoc_1.potega==0)&& (pomoc_1.wartosci[0] == 0)))
	{
		Wielomian pomoc_mnoznik((pomoc_1.potega) - drugi.potega);
		float mnoznik = (pomoc_1.wartosci[pomoc_1.potega] / drugi.wartosci[drugi.potega]);
		wynik_dzielenia.wartosci[pomoc_mnoznik.potega] = mnoznik;
		pomoc_mnoznik.wartosci[pomoc_mnoznik.potega] = mnoznik;
		Wielomian pomoc_2 = mnozenieWielomianow(pomoc_mnoznik, drugi);
		pomoc_1 = roznicaWielomianow(pomoc_1, pomoc_2);
		if ((pomoc_1.potega < drugi.potega))
		{
			int i = pomoc_1.potega;
			cout << "(reszta=";
			while (i >= 0)
			{
				reszta = pomoc_1.wartosci[i];
				cout << reszta;
				if (i > 0)
				{
					cout << "x";
					if(i>1) cout<<"^"<< i;
				}
				if (pomoc_1.wartosci[i - 1] > 0)cout << '+';
				i--;
			}
			cout<< ") ";
			return wynik_dzielenia;
		}
	}
	return wynik_dzielenia;
}
