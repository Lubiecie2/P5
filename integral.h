#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
	int liczba_przedzialow;  // <--- Liczba przydzia³ów
	int liczba_watkow;       // <--- Liczba w¹tków
	double wynik_pi;         // <--- Wynik obliczeñ liczby pi
	double czas_obliczen;    // <--- Czas trwania obliczeñ

	double calculatre_partial(int start, int end); // <--- Funkcja obliczaj¹ca czêœæ wyniku

public:
	Integral(int intervals, int threads); // <--- Konstruktor klasy 

	void oblicz(); // <--- Funkcja obliczaj¹ca wynik

	double pobierz_wynik_pi(); // <--- Funkcja zwracaj¹ca wynik
	double pobierz_czas_obliczen(); // <--- Funkcja zwracaj¹ca czas trwania obliczeñ
};