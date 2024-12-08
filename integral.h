#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
	int liczba_przedzialow;  // <--- Liczba przydzia��w
	int liczba_watkow;       // <--- Liczba w�tk�w
	double wynik_pi;         // <--- Wynik oblicze� liczby pi
	double czas_obliczen;    // <--- Czas trwania oblicze�

	double calculatre_partial(int start, int end); // <--- Funkcja obliczaj�ca cz�� wyniku

public:
	Integral(int intervals, int threads); // <--- Konstruktor klasy 

	void oblicz(); // <--- Funkcja obliczaj�ca wynik

	double pobierz_wynik_pi(); // <--- Funkcja zwracaj�ca wynik
	double pobierz_czas_obliczen(); // <--- Funkcja zwracaj�ca czas trwania oblicze�
};