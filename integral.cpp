#include "integral.h"
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

Integral::Integral(int intervals, int threads)  // <--- Konstruktor klasy	
{
	liczba_przedzialow = intervals;  // <--- Liczba przydzia��w
	liczba_watkow = threads;         // <--- Liczba w�tk�w
	wynik_pi = 0;  		             // <--- Wynik oblicze� liczby pi
	czas_obliczen = 0;               // <--- Czas trwania oblicze� 
}

double Integral::calculatre_partial(int start, int end)  // <--- Funkcja obliczaj�ca warto�� liczby pi
{
	double dx = 1.0 / liczba_przedzialow;  // <--- D�ugo�� przedzia�u
	double sum = 0;                        // <--- Suma warto�ci funkcji
	for (int i = start; i < end; i++)      // <--- P�tla obliczaj�ca warto�� funkcji
	{
		double x = (i + 0.5) * dx;         // <--- Warto�� x
		sum += 4.0 / (1.0 + x * x);        // <--- Warto�� funkcji
	}
	return sum;                            // <--- Zwr�cenie warto�ci funkcji
}

void Integral::oblicz()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<std::thread> threads;
	std::vector<double> results(liczba_watkow);
	for (int i = 0; i < liczba_watkow; i++)
	{
		int start = i * liczba_przedzialow / liczba_watkow;
		int end = (i + 1) * liczba_przedzialow / liczba_watkow;
		threads.push_back(std::thread([this, start, end, i, &results]()
			{
				results[i] = calculatre_partial(start, end);
			}));
	}
	for (auto& t : threads)
	{
		t.join();
	}
	wynik_pi = 0;
	for (int i = 0; i < liczba_watkow; i++)
	{
		wynik_pi += results[i];
	}
	wynik_pi *= 1.0 / liczba_przedzialow;
	auto end = std::chrono::high_resolution_clock::now();
	czas_obliczen = std::chrono::duration<double>(end - start).count();
}

double Integral::pobierz_wynik_pi()
{
	return wynik_pi;
}

double Integral::pobierz_czas_obliczen()
{
	return czas_obliczen;
}