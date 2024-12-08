#include <iostream>
#include "integral.h"

int main()
{
	int przedzialy, watki;

	std::cout << "Podaj liczbe przedzialow: ";
	std::cin >> przedzialy;
	std::cout << "Podaj liczbe watkow: ";
	std::cin >> watki;

	Integral calka(przedzialy, watki);
	calka.oblicz();

	std::cout << "Przyblizona wartosc liczby pi: " << calka.pobierz_wynik_pi() << std::endl;
	std::cout << "Czas obliczen: " << calka.pobierz_czas_obliczen() << " sekund" << std::endl;
}