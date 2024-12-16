#include "integral.h"
#include <iostream>
#include <thread>  // <--- Biblioteka do obslugi watkow
#include <vector>  // <--- Biblioteka do obslugi wektorow
#include <cmath>   // <--- Biblioteka do obliczen matematycznych

Integral::Integral(long long int intervals, int threads)  // <--- Konstruktor klasy	
{
	liczba_przedzialow = intervals;  // <--- Liczba przydziału całkowania
	liczba_watkow = threads;         // <--- Liczba watkow do wykorzystania
	wynik_pi = 0;  		             // <--- Wynik obliczen liczby pi
	czas_obliczen = 0;               // <--- Czas trwania obliczen 
}

double Integral::calculate_partial(long long int start, long long int end)  // <--- Funkcja obliczajaca czesc calki dla zakresu przedzialu przez parametry
{
	double dx = 1.0 / liczba_przedzialow;  // <--- Dlugosc jednego podprzedzialu
	double sum = 0;                        // <--- Inicjalizacja sumy
	for (long long int i = start; i < end; i++)      // <--- Petla do iteracji po przydzielonym przedziale
	{
		double x = (i + 0.5) * dx;         // <--- Obliczanie srodka przedziału
		sum += 4.0 / (1.0 + x * x);        // <--- Obliczanie wartosci funkcji 4/(1+x^2) w punkcie x
	}
	return sum;                            // <--- Zwrocenie wartosci funkcji
}

void Integral::oblicz()  // <--- Funkcja wykonujaca glowne obliczenia rownloegle przy uzyciu wielu watkow
{
	auto start = std::chrono::high_resolution_clock::now();  // <--- Pomiar czasu rozpoczecia obliczen
	std::vector<std::thread> threads;   // <--- Wektor do przechowywania obiektow typu thread, kazdy
	//      obiekt odpowiada za jeden watek						
	std::vector<double> results(liczba_watkow);  // <--- Wektor do przechowywania wynikow czesciowych dla kazdego watku

	for (int i = 0; i < liczba_watkow; i++)                  // <--- Petla do tworzenia watkow, kazdy watek
	{                                                        //      oblicza czesc calki czesci calki w zakresie
		long long int start = i * liczba_przedzialow / liczba_watkow;
		long long int end = (i + 1) * liczba_przedzialow / liczba_watkow;

		threads.push_back(std::thread([this, start, end, i, &results]()  // <--- Tworzenie nowego watku 
			{                                                            // this przekazuje obiekt klasy Integral do watku
				results[i] = calculate_partial(start, end);    // <--- kazdy watek wywoluje funkcje calculatre_partial
			}));                                                //      i zapisuje wynik w wektorze results
	}
	for (auto& t : threads)  // <--- Petla przechodzi przez wszystkie watki i czeka na zakonczenie ich dzialania
	{
		t.join();  // <--- Dla kazdego watku wywoluje funkcje join, ktora blokuje glowny watek programu
	}              //      do czasu zakonczenia dzialania podrzednego watku

	wynik_pi = 0;   // <--- Inicjalizacja wyniku
	for (int i = 0; i < liczba_watkow; i++)   // <--- Petla sumuje wyniki czesciowe z kazdego watku
	{
		wynik_pi += results[i]; // <--- Sumowanie wynikow czesciowych
	}
	wynik_pi *= 1.0 / liczba_przedzialow;  // <--- Wynik koncowy jest mnozony przez dlugosc przedzialu

	auto end = std::chrono::high_resolution_clock::now();  // <--- Pomiar czasu zakonczenia obliczen
	czas_obliczen = std::chrono::duration<double>(end - start).count(); // <--- Roznica czasu pomiedzy startem i koncem 
}                                                                       //      to czas trwania obliczen.

double Integral::pobierz_wynik_pi()  // <--- Funkcja zwracajaca wynik obliczen liczby pi
{
	return wynik_pi;
}

double Integral::pobierz_czas_obliczen()   // <--- Funkcja zwracajaca czas trwania obliczen
{
	return czas_obliczen;
}
