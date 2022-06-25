
class Wielomian
{
	int potega;
	int* wartosci = new int[potega+1] {};
public:
	Wielomian(){}
	Wielomian(int n) :potega(n) {}
	~Wielomian() {}
	void wprowadz_wielomian();
	void pokaz_wielomian();
	friend Wielomian sumaWielomianow(Wielomian pierwszy, Wielomian drugi);
	friend Wielomian roznicaWielomianow(Wielomian pierwszy, Wielomian drugi);
	friend Wielomian mnozenieWielomianow(Wielomian pierwszy, Wielomian drugi);
	friend Wielomian dzielenieWielomianow(Wielomian pierwszy, Wielomian drugi);
};
